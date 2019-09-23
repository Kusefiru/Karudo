#include <gb/gb.h>
#include <rand.h>
#include <gb/drawing.h>
#include <gb/cgb.h>
#include "room.h"
#include "map.h"

void game_init(void);
void interrupt_init(void);
void timer_interrupt(void);

void f_LoadSprites(void);
void f_MoveCharacter(void);

// temp data for testing
const T_U08 character_tiles[] =
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

const T_U08 character_tiles_attack[] =
{
	0xFF,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xE0,
	0x80,0xE0,0x83,0xE3,0x8E,0xEE,0x80,0xE0,
	0x80,0xE0,0x80,0xE0,0x80,0xE0,0x80,0xE0,
	0x8F,0xEF,0x80,0xFF,0x80,0xFF,0xFF,0xFF,
	0xFF,0xFF,0x01,0xFF,0x01,0xFF,0x01,0x07,
	0xC1,0xC7,0xC1,0xC7,0xC1,0xC7,0x81,0x87,
	0x81,0x87,0x81,0x87,0x81,0x87,0xBD,0xBF,
	0xE1,0xE7,0x01,0xFF,0x01,0xFF,0xFF,0xFF,

	0xFF,0xFF,0x80,0xFF,0x80,0xFF,0x83,0xE3,
	0x86,0xE6,0x84,0xE4,0x80,0xE0,0x80,0xE0,
	0x81,0xE1,0x83,0xE3,0x8E,0xEE,0x98,0xF8,
	0x9F,0xFF,0x80,0xFF,0x80,0xFF,0xFF,0xFF,
	0xFF,0xFF,0x01,0xFF,0x01,0xFF,0x81,0x87,
	0xC1,0xC7,0x41,0x47,0xC1,0xC7,0x81,0x87,
	0x81,0x87,0x01,0x07,0x01,0x07,0x71,0x77,
	0xC1,0xC7,0x01,0xFF,0x01,0xFF,0xFF,0xFF,

	0xFF,0xFF,0x80,0xFF,0x80,0xFF,0x87,0xE7,
	0x84,0xE4,0x80,0xE0,0x80,0xE0,0x81,0xE1,
	0x80,0xE0,0x80,0xE0,0x88,0xE8,0x8F,0xEF,
	0x80,0xE0,0x80,0xFF,0x80,0xFF,0xFF,0xFF,
	0xFF,0xFF,0x01,0xFF,0x01,0xFF,0xE1,0xE7,
	0x21,0x27,0x61,0x67,0xE1,0xE7,0xB1,0xB7,
	0x11,0x17,0x11,0x17,0x31,0x37,0xE1,0xE7,
	0x01,0x07,0x01,0xFF,0x01,0xFF,0xFF,0xFF
};

T_U08 sword_tiles[] =
{
	0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x03,
	0x03,0x04,0x00,0x0F,0x00,0x1F,0x00,0x3E,
	0x00,0x3C,0x00,0x70,0x00,0xE0,0x00,0xC0,
	0x01,0x02,0xF3,0x04,0xF3,0x0C,0x06,0x38,
	0x1E,0x60,0x32,0xCC,0x67,0x98,0xC3,0x30,
	0x81,0x60,0x00,0xC0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

T_U32 G_TIMER;

T_PLAYER_STATE G_PLAYER_STATE;
T_PLAYER_STATE G_PLAYER_LAST_STATE;
T_U08 G_PLAYER_X;
T_U08 G_PLAYER_Y;
T_U08 G_PLAYER_ANIM_TIMER;
T_U08 G_PLAYER_FRAME;
T_ANIM *G_PLAYER_ANIM;

const T_ANIM_FRAME G_PlayerIdleFrames[] =
{
    {0, 0, 0},
    {1, 0, 8},
    {2, 8, 0},
    {3, 8, 8}
};

const T_ANIM_FRAME G_PlayerMovingFrames[] =
{
    {0, 0, 0},
    {1, 0, 8},
    {2, 8, 0},
    {3, 8, 8},
    {4, 0, 0},
    {5, 0, 8},
    {6, 8, 0},
    {7, 8, 8},
    {8, 0, 0},
    {9, 0, 8},
    {10, 8, 0},
    {11, 8, 8},
    {12, 0, 0},
    {13, 0, 8},
    {14, 8, 0},
    {15, 8, 8}
};

T_ANIM A_PLAYER_IDLE = {4, 1, G_PlayerIdleFrames};
T_ANIM A_PLAYER_MOVING = {4, 4, G_PlayerMovingFrames};

void main(void)
{
	game_init();

	set_bkg_palette(0,5,area_tiles_palette);
	set_bkg_data(0,5,area_tiles);

	f_DisplayMap(map_room, metatiles);

	f_LoadSprites();

	while(1){
        // On mémorise l'état précédent (peut être utile pour les sorties d'état)
        G_PLAYER_LAST_STATE = G_PLAYER_STATE;

        // On check le joypad
		f_MoveCharacter();

		// Update du compteur avant changement de frame

		
        // Attends la vblank avant de repasser la boucle (pour garder 60fps)
		wait_vbl_done();
	}
}

void f_LoadSprites(void)
{
    SPRITES_8x8;

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
	move_sprite(0,G_PLAYER_X,G_PLAYER_X);		// Move sprite to its initial position (given in level initialization)
	set_sprite_tile(1,2);				// S1 is the second tile of the sprite VRAM
	set_sprite_prop(1,0);				// S1 got palette 0
	move_sprite(1,G_PLAYER_X+8,G_PLAYER_X);		// etc...
	set_sprite_tile(2,1);
	set_sprite_prop(2,0);
	move_sprite(2,G_PLAYER_X,G_PLAYER_X+8);
	set_sprite_tile(3,3);
	set_sprite_prop(3,0);
	move_sprite(3,G_PLAYER_X+8,G_PLAYER_X+8);

    SHOW_SPRITES;
}

void f_MoveCharacter(void)
{
	T_U08 has_moved = 0U;
    T_U08 update_sprite = 0U;
    T_S08 i;

	// will be joypad_update or similar
	if(joypad() & J_RIGHT){
		G_PLAYER_X++;
		has_moved = 1;
		if(G_PLAYER_X==137) G_PLAYER_X--;
	}
	if(joypad() & J_LEFT){
		G_PLAYER_X--;
		has_moved = 1;
		if(G_PLAYER_X==23) G_PLAYER_X++;
	}
	if(joypad() & J_UP){
		G_PLAYER_Y--;
		has_moved = 1;
		if(G_PLAYER_Y==31) G_PLAYER_Y++;
	}
	if(joypad() & J_DOWN){
		G_PLAYER_Y++;
		has_moved = 1;
		if(G_PLAYER_Y==113) G_PLAYER_Y--;
	}

    if(1U == has_moved){
        G_PLAYER_STATE = IS_MOVING;
    }
    else{
        G_PLAYER_STATE = IS_IDLE;
    }

    if(G_PLAYER_STATE != G_PLAYER_LAST_STATE){
        G_PLAYER_ANIM_TIMER = 0U;
        G_PLAYER_FRAME = 0U;
        switch(G_PLAYER_STATE){
            case IS_IDLE:
                G_PLAYER_ANIM = &A_PLAYER_IDLE;
                break;
            case IS_MOVING:
                G_PLAYER_ANIM = &A_PLAYER_MOVING;
                break;
        }
    }

    if(0U == G_PLAYER_ANIM_TIMER){
        G_PLAYER_FRAME++;
        if(G_PLAYER_FRAME == G_PLAYER_ANIM->NbFrame){
            G_PLAYER_FRAME = 0U;
        }
        G_PLAYER_ANIM_TIMER = 17U;

        // update des sprites
        i = 0;
        while(i < 4){
            set_sprite_tile(i, (G_PLAYER_ANIM->AddrFrame + (i*3) + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->TileNb);
            i++;
        }
    }

    G_PLAYER_ANIM_TIMER--;

    i = 0;
    while(i < 4){
        move_sprite(i, G_PLAYER_X+(G_PLAYER_ANIM->AddrFrame + (i*3) + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosX, G_PLAYER_Y+(G_PLAYER_ANIM->AddrFrame + (i*3) + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosY);
        i++;
    }
}


void game_init(void)
{
	G_TIMER             = 0;
    G_PLAYER_STATE      = 0;
    G_PLAYER_LAST_STATE = 0;
    G_PLAYER_FRAME      = 0;
    G_PLAYER_ANIM       = 0;
    G_PLAYER_ANIM_TIMER = 0;
    G_PLAYER_X 		    = 64U;
	G_PLAYER_Y		    = 64U;

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
	G_TIMER++;
}