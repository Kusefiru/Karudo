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

#define TIME_BEFORE_NEXT_ATTACK 16

T_U32 G_TIMER;

T_PLAYER_STATE G_PLAYER_STATE;
T_PLAYER_STATE G_PLAYER_LAST_STATE;
T_PLAYER_DIRECTION G_PLAYER_DIRECTION;
T_PLAYER_DIRECTION G_PLAYER_LAST_DIR;
T_U08 G_PLAYER_TILECOUNT;
T_U08 G_PLAYER_X;
T_U08 G_PLAYER_Y;
T_U08 G_PLAYER_ANIM_TIMER;
T_U08 G_PLAYER_FRAME;
T_U08 G_PLAYER_COMBO;
T_U08 G_PLAYER_ATK_SINCE;
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

    set_data(0x8160,Sword_Tiles,16);
    set_data(0x8170,Sword_Tiles+0x10U,16);
    set_data(0x8180,Sword_Tiles+0x20U,16);
    set_data(0x8190,Sword_Tiles+0x30U,16);
    set_data(0x81A0,Sword_Tiles+0x40U,16);
    set_data(0x81B0,Sword_Tiles+0x50U,16);
    set_data(0x81C0,Sword_Tiles+0x60U,16);

    set_sprite_palette(0, 1, Player_Palette);
    set_sprite_palette(1, 1, Sword_Palette);

    i = 0;
    while(i < G_PLAYER_ANIM->NbTiles){
        set_sprite_tile(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->TileNb);
        set_sprite_prop(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->Property);
        move_sprite(i, G_PLAYER_X+(G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosX, G_PLAYER_Y+(G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->PosY);
        i++;
    }

    // Set the initial number of tiles for the player
    G_PLAYER_TILECOUNT = G_PLAYER_ANIM->NbTiles;

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
    // Only has_moved should be updated here, coordinates update should
    //    be moved once a proper collision detection system is made.
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
    if(joypad() & J_A){
        has_moved |= 0x10U;
    }

    // If the player moved during this cycle, the state is IS_MOVING
    // To move later on its own function... ?
    if(IS_ATTACKING != G_PLAYER_STATE){
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
                else if(has_moved & 0x08U){
                    G_PLAYER_DIRECTION = 3U;
                }
            }
            G_PLAYER_STATE = IS_MOVING;

            if(has_moved & 0x10U){
                G_PLAYER_STATE = IS_ATTACKING;
            }
        }
    }

    // If the current state has changed
    if(	(G_PLAYER_STATE != G_PLAYER_LAST_STATE) ||
        (G_PLAYER_DIRECTION != G_PLAYER_LAST_DIR)){
        // Point to the new animation cycle
        switch(G_PLAYER_STATE){
            case IS_IDLE:
                G_PLAYER_ANIM = &A_PLAYER_IDLE_FRONT + G_PLAYER_DIRECTION;
                break;
            case IS_MOVING:
                G_PLAYER_ANIM = &A_PLAYER_WALKING_FRONT + G_PLAYER_DIRECTION;
                break;
            case IS_ATTACKING:
                G_PLAYER_ANIM = &A_PLAYER_SWORD_1_FRONT;
                G_PLAYER_ATK_SINCE = 0U;
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

            // if the player was attacking, we reset its state to idle
            if((IS_ATTACKING == G_PLAYER_STATE) &&
               (0 != G_PLAYER_ATK_SINCE)){
                G_PLAYER_STATE = IS_IDLE;
                G_PLAYER_ANIM = &A_PLAYER_IDLE_FRONT + G_PLAYER_DIRECTION;
            }
        }

        // Reset the animation timer
        G_PLAYER_ANIM_TIMER = G_PLAYER_ANIM->FrameLength;

        // Update the current player sprites
        // To move later on its own function... ?
        i = 0;
        while(i < G_PLAYER_ANIM->NbTiles){
            // Set the correct tile of the sprite
            // Address of current animation frame table + i (sprite number) + current frame * number of tiles for one frame
            set_sprite_tile(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->TileNb);
            set_sprite_prop(i, (G_PLAYER_ANIM->AddrFrame + i + G_PLAYER_FRAME*G_PLAYER_ANIM->NbTiles)->Property);
            i++;
        }

        // If we set less tiles than on the previous frame
        while(G_PLAYER_TILECOUNT > i){
            // We move all the remaining not used tiles to the corner of the screen
            move_sprite(i, 0, 0);
            i++;
        }

        // Update the current number of tiles in the frame
        G_PLAYER_TILECOUNT = G_PLAYER_ANIM->NbTiles;
    }

    // Decrement the animation timer
    G_PLAYER_ANIM_TIMER--;
    G_PLAYER_ATK_SINCE++;

    // Update the player position
    // To move later on its own function... ?
    i = 0;
    while(i < G_PLAYER_ANIM->NbTiles){
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
    G_PLAYER_COMBO      = 0;
    G_PLAYER_ATK_SINCE  = 0;
    G_PLAYER_ANIM       = &A_PLAYER_IDLE_FRONT;
    G_PLAYER_ANIM_TIMER = 0;
    G_PLAYER_TILECOUNT  = 0;
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