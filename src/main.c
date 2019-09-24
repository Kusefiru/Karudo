#include <gb/gb.h>
#include <rand.h>
#include <gb/drawing.h>
#include <gb/cgb.h>
#include "room.h"
#include "map.h"
#include "chardata.h"

void game_init(void);
void interrupt_init(void);
void timer_interrupt(void);

void f_LoadSprites(void);
void f_MoveCharacter(void);

T_U32 G_TIMER;

T_PLAYER_STATE G_PLAYER_STATE;
T_PLAYER_STATE G_PLAYER_LAST_STATE;
T_PLAYER_DIRECTION G_PLAYER_DIRECTION;
T_PLAYER_DIRECTION G_PLAYER_LAST_DIR;
T_U08 G_PLAYER_X;
T_U08 G_PLAYER_Y;
T_U08 G_PLAYER_ANIM_TIMER;
T_U08 G_PLAYER_FRAME;
T_ANIM *G_PLAYER_ANIM;

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
        G_PLAYER_LAST_DIR   = G_PLAYER_DIRECTION;

        // On check le joypad
        f_MoveCharacter();
        
        // Attends la vblank avant de repasser la boucle (pour garder 60fps)
        wait_vbl_done();
    }
}

void f_LoadSprites(void)
{
    T_U08 i;

    SPRITES_8x8;

    set_data(0x8000,Player_Tiles_Walk_Front,16);
    set_data(0x8010,Player_Tiles_Walk_Front+0x10U,16);
    set_data(0x8020,Player_Tiles_Walk_Front+0x20U,16);
    set_data(0x8030,Player_Tiles_Walk_Front+0x30U,16);
    set_data(0x8040,Player_Tiles_Walk_Front+0x40U,16);
    set_data(0x8050,Player_Tiles_Walk_Front+0x50U,16);
    set_data(0x8060,Player_Tiles_Walk_Front+0x60U,16);

    set_data(0x8070,Player_Tiles_Walk_Side,16);
    set_data(0x8080,Player_Tiles_Walk_Side+0x10U,16);
    set_data(0x8090,Player_Tiles_Walk_Side+0x20U,16);
    set_data(0x80A0,Player_Tiles_Walk_Side+0x30U,16);
    set_data(0x80B0,Player_Tiles_Walk_Side+0x40U,16);
    set_data(0x80C0,Player_Tiles_Walk_Side+0x50U,16);
    set_data(0x80D0,Player_Tiles_Walk_Side+0x60U,16);
    set_data(0x80E0,Player_Tiles_Walk_Side+0x70U,16);

    set_data(0x80F0,Player_Tiles_Walk_Back,16);
    set_data(0x8100,Player_Tiles_Walk_Back+0x10U,16);
    set_data(0x8110,Player_Tiles_Walk_Back+0x20U,16);
    set_data(0x8120,Player_Tiles_Walk_Back+0x30U,16);
    set_data(0x8130,Player_Tiles_Walk_Back+0x40U,16);
    set_data(0x8140,Player_Tiles_Walk_Back+0x50U,16);
    set_data(0x8150,Player_Tiles_Walk_Back+0x60U,16);

    set_sprite_palette(0, 1, Player_Palette);

    i = 0;
    while(i < 4){
        set_sprite_tile(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->TileNb);
        set_sprite_prop(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->Property);
        move_sprite(i, G_PLAYER_X+(G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosX, G_PLAYER_Y+(G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosY);
        i++;
    }

    SHOW_SPRITES;
}

void f_MoveCharacter(void)
{
    // bit field to memorize which direction the player moved
    // bit 0 : down
    // bit 1 : up
    // bit 2 : left
    // bit 3 : right
    T_U08 has_moved = 0x00U;

    T_U08 update_sprite = 0U;
    T_U08 i;

    // Will be joypad_update or similar
    if(joypad() & J_RIGHT){
        has_moved |= 0x08U;
        G_PLAYER_X++;
        if(G_PLAYER_X==137) G_PLAYER_X--;
    }
    if(joypad() & J_LEFT){
        has_moved |= 0x04U;
        G_PLAYER_X--;
        if(G_PLAYER_X==23) G_PLAYER_X++;
    }
    if(joypad() & J_UP){
        has_moved |= 0x02U;
        G_PLAYER_Y--;
        if(G_PLAYER_Y==31) G_PLAYER_Y++;
    }
    if(joypad() & J_DOWN){
        has_moved |= 0x01U;
        G_PLAYER_Y++;
        if(G_PLAYER_Y==113) G_PLAYER_Y--;
    }

    // If the player moved during this cycle, the state is IS_MOVING
    // To move later on its own function... ?
    if(0U == has_moved){
        G_PLAYER_STATE = IS_IDLE;
    }
    else{
        if(0U == ((has_moved >> G_PLAYER_DIRECTION)&0x01U)){
            if(has_moved & 0x01U){
                G_PLAYER_DIRECTION = 0U;
            }
            else if(has_moved & 0x02U){
                G_PLAYER_DIRECTION = 1U;
            }
            else if(has_moved & 0x04U){
                G_PLAYER_DIRECTION = 2U;
            }
            else{
                G_PLAYER_DIRECTION = 3U;
            }
        }
        G_PLAYER_STATE = IS_MOVING;
    }

    // If the current state has changed
    if(	(G_PLAYER_STATE != G_PLAYER_LAST_STATE) ||
        (G_PLAYER_DIRECTION != G_PLAYER_LAST_DIR)){
        // Point to the new animation cycle
        switch(G_PLAYER_STATE){
            case IS_IDLE:
                switch(G_PLAYER_DIRECTION){
                    case IS_FACING_DOWN:
                        G_PLAYER_ANIM = &A_PLAYER_IDLE_FRONT;
                        break;
                    case IS_FACING_UP:
                        G_PLAYER_ANIM = &A_PLAYER_IDLE_BACK;
                        break;
                    case IS_FACING_LEFT:
                        G_PLAYER_ANIM = &A_PLAYER_IDLE_LEFT;
                        break;
                    case IS_FACING_RIGHT:
                        G_PLAYER_ANIM = &A_PLAYER_IDLE_RIGHT;
                }
                break;
            case IS_MOVING:
                switch(G_PLAYER_DIRECTION){
                    case IS_FACING_DOWN:
                        G_PLAYER_ANIM = &A_PLAYER_WALKING_FRONT;
                        break;
                    case IS_FACING_UP:
                        G_PLAYER_ANIM = &A_PLAYER_WALKING_BACK;
                        break;
                    case IS_FACING_LEFT:
                        G_PLAYER_ANIM = &A_PLAYER_WALKING_LEFT;
                        break;
                    case IS_FACING_RIGHT:
                        G_PLAYER_ANIM = &A_PLAYER_WALKING_RIGHT;
                }
                break;
        }

        // Reset the animation timer and current frame
        // We actually force the animation timer to 0 and the frame
        // to the last one of the animation to reset it just after
        G_PLAYER_ANIM_TIMER = 0U;
        G_PLAYER_FRAME = G_PLAYER_ANIM->NbFrame-1U;
    }

    // If the animation timer is 0
    if(0U == G_PLAYER_ANIM_TIMER){
        // Increment the current frame
        G_PLAYER_FRAME++;
        // Or if it reached the end of the cycle, reset it
        if(G_PLAYER_FRAME == G_PLAYER_ANIM->NbFrame){
            G_PLAYER_FRAME = 0U;
        }

        // Reset the animation timer
        G_PLAYER_ANIM_TIMER = 16U;

        // Update the current player sprites
        // To move later on its own function... ?
        i = 0;
        while(i < 4){
            // Set the correct tile of the sprite
            // Address of current animation frame table + i (sprite number) + current frame * number of tiles for one frame
            set_sprite_tile(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->TileNb);
            set_sprite_prop(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->Property);
            i++;
        }
    }

    // Decrement the animation timer
    G_PLAYER_ANIM_TIMER--;

    // Update the player position
    // To move later on its own function... ?
    i = 0;
    while(i < 4){
        // Move the X and Y coordinates of the sprite
        // Player coordinate + value at : Address of current animation frame table + i (sprite number) + current frame * number of tiles for one frame
        move_sprite(i, G_PLAYER_X+(G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosX, G_PLAYER_Y+(G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosY);
        i++;
    }
}


void game_init(void)
{
    G_TIMER             = 0;
    G_PLAYER_STATE      = 0;
    G_PLAYER_LAST_STATE = 0;
    G_PLAYER_DIRECTION  = 0;
    G_PLAYER_LAST_DIR   = 0;
    G_PLAYER_FRAME      = 0;
    G_PLAYER_ANIM       = &A_PLAYER_IDLE_FRONT;
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