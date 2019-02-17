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

void display_map(void);

T_S08  TIMER_MOVE;
T_U32 GLOBAL_TIMER;

T_U16 seed;
T_U08 is_taken[256];			// keep track of the taken spots
/* For each room :
	link_map[room+(0-3)] : index of the room linked to the north, east, south and west
	link_map[room+(4-5)] : position X and Y of the current room
	link_map[room+6]	 : hold if the map contains a center of interest (0: Start; 1: Exit; 2: Chest)
*/
T_U08 link_map[MAX_ROOMS*8];	

void main(void)
{
	game_init();

	set_bkg_palette(0,5,area_tiles_palette);
	set_bkg_data(0,5,area_tiles);

	f_DisplayMap(map_room, metatiles);

	// f_DisplayMap(0);
}

void display_map(void)
{
	set_bkg_palette(0,5,area_tiles_palette);
	set_bkg_data(0,5,area_tiles);

	VBK_REG = 1;
	set_bkg_tiles(0, 0, _DungeonMapWidth, _DungeonMapHeight, map_room);
	VBK_REG = 0;
	set_bkg_tiles(0, 0, _DungeonMapWidth, _DungeonMapHeight, map_room);
	SHOW_BKG;
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