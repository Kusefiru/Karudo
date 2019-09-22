#include <gb/gb.h>
#include <rand.h>
#include <gb/drawing.h>
#include <gb/cgb.h>
#include "room.h"
#include "map.h"

#define MAX_ROOMS 0x20U

void game_init(void);
void interrupt_init(void);
void timer_interrupt(void);

void f_LoadSprites(void);
void f_MoveCharacter(void);

T_S08 TIMER_MOVE;
T_U32 GLOBAL_TIMER;

T_U16 seed;
T_U08 is_taken[256];			// keep track of the taken spots
/* For each room :
	link_map[room+(0-3)] : index of the room linked to the north, east, south and west
	link_map[room+(4-5)] : position X and Y of the current room
	link_map[room+6]	 : hold if the map contains a center of interest (0: Start; 1: Exit; 2: Chest)
*/
T_U08 link_map[MAX_ROOMS*8];

T_U08 CHAR_X;
T_U08 CHAR_Y;
T_U08 CHAR_LAST_ANIM;
T_U08 CHAR_FRAME;

// temp data for testing
T_U08 character_tiles[] =
{
	0xFF,0xFF,0x80,0x80,0x80,0x80,0x80,0x80,
	0x80,0x80,0x83,0x83,0x8E,0x8E,0x80,0x80,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
	0x8F,0x8F,0x80,0x80,0x80,0x80,0xFF,0xFF,
	0xFF,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,
	0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0x81,0x81,
	0x81,0x81,0x81,0x81,0x81,0x81,0xBD,0xBD,
	0xE1,0xE1,0x01,0x01,0x01,0x01,0xFF,0xFF,

	0xFF,0xFF,0x80,0x80,0x80,0x80,0x83,0x83,
	0x86,0x86,0x84,0x84,0x80,0x80,0x80,0x80,
	0x81,0x81,0x83,0x83,0x8E,0x8E,0x98,0x98,
	0x9F,0x9F,0x80,0x80,0x80,0x80,0xFF,0xFF,
	0xFF,0xFF,0x01,0x01,0x01,0x01,0x81,0x81,
	0xC1,0xC1,0x41,0x41,0xC1,0xC1,0x81,0x81,
	0x81,0x81,0x01,0x01,0x01,0x01,0x71,0x71,
	0xC1,0xC1,0x01,0x01,0x01,0x01,0xFF,0xFF,

	0xFF,0xFF,0x80,0x80,0x80,0x80,0x87,0x87,
	0x84,0x84,0x80,0x80,0x80,0x80,0x81,0x81,
	0x80,0x80,0x80,0x80,0x88,0x88,0x8F,0x8F,
	0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0xFF,
	0xFF,0xFF,0x01,0x01,0x01,0x01,0xE1,0xE1,
	0x21,0x21,0x61,0x61,0xE1,0xE1,0xB1,0xB1,
	0x11,0x11,0x11,0x11,0x31,0x31,0xE1,0xE1,
	0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0xFF,
	
	0xFF,0xFF,0x80,0x80,0x80,0x80,0x81,0x81,
	0x87,0x87,0x8C,0x8C,0x98,0x98,0xB0,0xB0,
	0xBF,0xBF,0x80,0x80,0x80,0x80,0x80,0x80,
	0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0xFF,
	0xFF,0xFF,0x01,0x01,0xC1,0xC1,0xC1,0xC1,
	0x41,0x41,0x41,0x41,0x41,0x41,0x71,0x71,
	0xC1,0xC1,0x41,0x41,0x41,0x41,0x41,0x41,
	0x61,0x61,0x01,0x01,0x01,0x01,0xFF,0xFF
};

const T_U16 marisa_palette[] =
{
	31744, 32767, 6342, 0,
	31744, 924, 6342, 0
};

void main(void)
{
	game_init();

	set_bkg_palette(0,5,area_tiles_palette);
	set_bkg_data(0,5,area_tiles);

	CHAR_X 		= 64;
	CHAR_Y		= 64;
	CHAR_LAST_ANIM	= 0;
	CHAR_FRAME  = 0;

	f_DisplayMap(map_room, metatiles);

	f_LoadSprites();

	while(1){
		f_MoveCharacter();

		// Update du compteur avant changement de frame
		CHAR_LAST_ANIM++;

		// Attends la vblank avant de repasser la boucle (pour garder 60fps)
		wait_vbl_done();
	}

	// f_DisplayMap(0);
}

void f_LoadSprites(void)
{
	UINT8 k;
	SPRITES_8x8;

	for(k=0;k!=8;k++){
		set_sprite_palette_entry((k>>2),k%4,character_tiles[k]);
	}

	set_data(0x8000,character_tiles,16);
	set_data(0x8010,character_tiles+0x10U,16);
	set_data(0x8020,character_tiles+0x20U,16);
	set_data(0x8030,character_tiles+0x30U,16);

	set_data(0x8040,character_tiles+0x40U,16);
	set_data(0x8050,character_tiles+0x50U,16);
	set_data(0x8060,character_tiles+0x60U,16);
	set_data(0x8070,character_tiles+0x70U,16);

	set_data(0x8080,character_tiles+0x80U,16);
	set_data(0x8090,character_tiles+0x90U,16);
	set_data(0x80A0,character_tiles+0xA0U,16);
	set_data(0x80B0,character_tiles+0xB0U,16);

	set_data(0x80C0,character_tiles+0xC0U,16);
	set_data(0x80D0,character_tiles+0xD0U,16);
	set_data(0x80E0,character_tiles+0xE0U,16);
	set_data(0x80F0,character_tiles+0xF0U,16);

	set_sprite_tile(0,0);				// S0 is the first tile of the sprite VRAM
	set_sprite_prop(0,0);				// S0 got palette 0
	move_sprite(0,CHAR_X,CHAR_Y);		// Move sprite to its initial position (given in level initialization)
	set_sprite_tile(1,2);				// S1 is the second tile of the sprite VRAM
	set_sprite_prop(1,0);				// S1 got palette 0
	move_sprite(1,CHAR_X+8,CHAR_Y);		// etc...
	set_sprite_tile(2,1);
	set_sprite_prop(2,0);
	move_sprite(2,CHAR_X,CHAR_Y+8);
	set_sprite_tile(3,3);
	set_sprite_prop(3,0);
	move_sprite(3,CHAR_X+8,CHAR_Y+8);

	SHOW_SPRITES;
}

void f_MoveCharacter(void)
{
	// will be joypad_update or similar
	if(joypad() & J_RIGHT)
	{
		CHAR_X++;
		if(CHAR_X==137) CHAR_X--;
	}
	if(joypad() & J_LEFT)
	{
		CHAR_X--;
		if(CHAR_X==23) CHAR_X++;
	}
	if(joypad() & J_UP)
	{
		CHAR_Y--;
		if(CHAR_Y==31) CHAR_Y++;
	}
	if(joypad() & J_DOWN)
	{
		CHAR_Y++;
		if(CHAR_Y==113) CHAR_Y--;
	}

	// will be update sprites or similar
	if(16U == CHAR_LAST_ANIM){
		CHAR_FRAME++;
		if(4U == CHAR_FRAME){
			CHAR_FRAME = 0U;
		}
		// On update les sprites et palettes
		set_sprite_tile(0,0+(CHAR_FRAME<<2));
		set_sprite_tile(1,2+(CHAR_FRAME<<2));
		set_sprite_tile(2,1+(CHAR_FRAME<<2));
		set_sprite_tile(3,3+(CHAR_FRAME<<2));

		// On remet à 0 le compteur de changement de frame
		CHAR_LAST_ANIM = 0U;
	}
	
	// will be move character or similar
	move_sprite(0,CHAR_X,CHAR_Y);
	move_sprite(1,CHAR_X+8,CHAR_Y);
	move_sprite(2,CHAR_X,CHAR_Y+8);
	move_sprite(3,CHAR_X+8,CHAR_Y+8);
}

void game_init(void)
{
	GLOBAL_TIMER = 0;
	TAC_REG = 0x07U;

	interrupt_init();
}

void interrupt_init(void)
{
	disable_interrupts();
	add_TIM(timer_interrupt);
	add_VBL(timer_interrupt);
    enable_interrupts();

    set_interrupts(VBL_IFLAG | TIM_IFLAG);
}

void timer_interrupt(void)
{
	GLOBAL_TIMER++;
	TIMER_MOVE++;
}