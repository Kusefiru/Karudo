#include <gb/gb.h>
#include <rand.h>
#include <gb/drawing.h>
#include <gb/cgb.h>
#include "chardata.h"
#include "map_functions.h"
#include "ram.h"

void game_init(void);
void interrupt_init(void);
void timer_interrupt(void);

void f_LoadSprites(void);
void f_GetJoypad(void);
void f_GetPlayerState(void);
void f_GetPlayerPos(void);
void f_MovePlayerSprites(void);

// ==========================================================================
// Global var
T_U32 G_TIMER;

T_PLAYER_DIRECTION G_PLAYER_DIRECTION;
T_PLAYER_DIRECTION G_PLAYER_LAST_DIR;
T_STATE *G_PLAYER_STATE_;
T_STATE *G_PLAYER_LAST_STATE_;
T_U08 G_PLAYER_TILECOUNT;
T_U08 G_PLAYER_X;
T_U16 G_PLAYER_NEW_X;
T_U08 G_PLAYER_Y;
T_U16 G_PLAYER_NEW_Y;
T_U08 G_PLAYER_CURR_METATILE;
T_U08 G_COLLIDE_1_X;
T_U08 G_COLLIDE_1_Y;
T_U08 G_BLOCKED_IN_DIR;
T_ANIM *G_PLAYER_ANIM;
T_U08 G_PLAYER_ANIM_TIMER;
T_U08 G_PLAYER_FRAME;
T_U08 G_PLAYER_TIME_BEFORE_ATK_ENDS;

T_U08 G_COLLIDE_2_X;
T_U08 G_COLLIDE_2_Y;
T_S08 G_PLAYER_VELOCITY_X;
T_S08 G_PLAYER_VELOCITY_Y;

T_U08 G_JOYPAD;
T_U08 G_LAST_JOYPAD;

// ==========================================================================
// This is the main function
// It will probably be moved to a mainloop function later one
void main(void)
{
    game_init();

    set_bkg_palette(0,5,area_tiles_palette);
    set_bkg_data(0,5,area_tiles);

    f_DisplayMap(map_room, metatiles);

    f_LoadSprites();

    set_sprite_tile(30, 0);
    set_sprite_prop(30, 0);

    while(1){
        // Memorize the previous value of important data
        G_PLAYER_LAST_STATE_ = G_PLAYER_STATE_;
        G_PLAYER_LAST_DIR    = G_PLAYER_DIRECTION;
        G_LAST_JOYPAD        = G_JOYPAD;

        // Read the joypad
        f_GetJoypad();

        // Update the player state
        f_GetPlayerState();

        // Update the player position
        f_GetPlayerPos();

        // Move the player sprites
        f_MovePlayerSprites();
        
        // Wait for vblank (ensure max 60fps)
        wait_vbl_done();
    }
}

// ==========================================================================
// This function load the sprites
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

// ==========================================================================
// This function read the joypad and temporarily handles the movement
void f_GetJoypad(void)
{
    G_JOYPAD = joypad();
}

// ==========================================================================
// This function handles the current player state
// In the future, multiple functions may handle the player state depending
//   on the game state (in town, in battle, etc...)
void f_GetPlayerState(void)
{
    // ==========================================================================
    // Here we handle if the player state needs to change
    // If the player moved during this cycle, the state is IS_MOVING
    // To move later on its own function... ?

    // If the player pressed A and A was not pressed
    if((J_A & G_JOYPAD) && !(J_A & G_LAST_JOYPAD)){
        // If the current frame allows to move to the next attack
        if(G_PLAYER_TIME_BEFORE_ATK_ENDS < D_TIME_BEFORE_END){
            // If it is A & Right
            if(G_JOYPAD & J_RIGHT){
                G_PLAYER_STATE_ = G_PLAYER_STATE_->NextState_Right;
            }
            // If it is A & Left
            else if(G_JOYPAD & J_LEFT){
                G_PLAYER_STATE_ = G_PLAYER_STATE_->NextState_Left;
            }
            // If it is A & Up
            else if(G_JOYPAD & J_UP){
                G_PLAYER_STATE_ = G_PLAYER_STATE_->NextState_Up;
            }
            // If it is A & Down
            else if(G_JOYPAD & J_DOWN){
                G_PLAYER_STATE_ = G_PLAYER_STATE_->NextState_Down;
            }
            // If it is only A
            else{
                G_PLAYER_STATE_ = G_PLAYER_STATE_->NextState_Idle;
            }
        }
    }
    // Else if A was not pressed
    else{
        // If the player is not attacking
        if (0U == G_PLAYER_TIME_BEFORE_ATK_ENDS){
            G_PLAYER_STATE_ = &STATE_IDLE;
            // If movement has been inputted
            if(G_JOYPAD & 0x0FU){
                G_PLAYER_STATE_ = &STATE_MOVE;
                // Now check the direction
                // If the current direction is no longer pressed
                if(0U == ((G_JOYPAD >> G_PLAYER_DIRECTION)&0x01U)){
                    // If the player is moving Right
                    if(G_JOYPAD & J_RIGHT){
                        G_PLAYER_DIRECTION = 0U;
                    }
                    // If the player is moving Left
                    else if(G_JOYPAD & J_LEFT){
                        G_PLAYER_DIRECTION = 1U;
                    }
                    // If the player is moving Up
                    else if(G_JOYPAD & J_UP){
                        G_PLAYER_DIRECTION = 2U;
                    }
                    // If the player is moving Down
                    else if(G_JOYPAD & J_DOWN){
                        G_PLAYER_DIRECTION = 3U;
                    }
                }
            }
        }
    }

    // If the player state is null (no next move), go back to idle mode
    // This will induce one frame where the player is idling even if they move during it but well...
    // One solution would be to jump into the previous if...
    if(0U == G_PLAYER_STATE_){
        G_PLAYER_STATE_ = &STATE_IDLE;
    }

    // ==========================================================================
    // If the player state has changed
    if(G_PLAYER_LAST_STATE_ != G_PLAYER_STATE_){
        // If the player is idle
        if(&STATE_IDLE == G_PLAYER_STATE_){
            G_PLAYER_ANIM = G_PLAYER_STATE_->Anim + G_PLAYER_DIRECTION;
            // If the previous state was an attack
            // (we check only if it wasn't STATE_MOVE since if we are here, the previous state wasn't STATE_IDLE)
            if(G_PLAYER_LAST_STATE_ != &STATE_MOVE){
                G_PLAYER_TIME_BEFORE_ATK_ENDS = D_COOLDOWN_BEFORE_NEXT;
            }
        }
        // Else if the player is moving
        else if(&STATE_MOVE == G_PLAYER_STATE_){
            G_PLAYER_ANIM = G_PLAYER_STATE_->Anim + G_PLAYER_DIRECTION;
        }
        // Else if the player is attacking
        else{
            G_PLAYER_ANIM = G_PLAYER_STATE_->Anim; // + G_PLAYER_DIRECTION;
            // Calculate the length of the move
            G_PLAYER_TIME_BEFORE_ATK_ENDS = G_PLAYER_ANIM->NbFrame * G_PLAYER_ANIM->FrameLength;
        }

        G_PLAYER_ANIM_TIMER = 0U;
        G_PLAYER_FRAME = G_PLAYER_ANIM->NbFrame-1U;
    }
    // Else if the player direction has changed (only applies when moving or idle)
    // We put an "else if" here because if the player state change, direction will be updated as well
    else if(G_PLAYER_LAST_DIR != G_PLAYER_DIRECTION){
        // If the player is idle
        if(&STATE_IDLE == G_PLAYER_STATE_){
            G_PLAYER_ANIM = G_PLAYER_STATE_->Anim + G_PLAYER_DIRECTION;
        }
        // Else if the player is moving
        else if(&STATE_MOVE == G_PLAYER_STATE_){
            G_PLAYER_ANIM = G_PLAYER_STATE_->Anim + G_PLAYER_DIRECTION;
        }

        G_PLAYER_ANIM_TIMER = 0U;
        G_PLAYER_FRAME = G_PLAYER_ANIM->NbFrame-1U;
    }
}

// ==========================================================================
// This function handles the player position depending on the joypad
//   and its current state
void f_GetPlayerPos(void)
{
    // If the input on left and right has changed
    if((G_JOYPAD ^ G_LAST_JOYPAD)&(J_LEFT|J_RIGHT)){
        // Reset the X velocity
        G_PLAYER_VELOCITY_X = 0;
    }
    // If the player is pressing right
    if(G_JOYPAD & J_RIGHT){
        // If the maximum speed on X hasn't been reached
        if(D_MAX_SPEED_X != G_PLAYER_VELOCITY_X){
            // Increment the X speed
            G_PLAYER_VELOCITY_X += 1;
        }
    }
    // If the player is pressing left
    if(G_JOYPAD & J_LEFT){
        // If the maximum speed on -X hasn't been reached
        if(-D_MAX_SPEED_X != G_PLAYER_VELOCITY_X){
            // Increment the -X speed
            G_PLAYER_VELOCITY_X -= 1;
        }
    }

    // If the input on up and down has changed
    if((G_JOYPAD ^ G_LAST_JOYPAD)&(J_UP|J_DOWN)){
        // Reset the Y velocity
        G_PLAYER_VELOCITY_Y = 0;
    }
    // If the player is pressing down
    if(G_JOYPAD & J_DOWN){
        // If the maximum speed on Y hasn't been reached
        if(D_MAX_SPEED_Y != G_PLAYER_VELOCITY_Y){
            // Increment the Y speed
            G_PLAYER_VELOCITY_Y += 1;
        }
    }
    // If the player is pressing up
    if(G_JOYPAD & J_UP){
        // If the maximum speed on -Y hasn't been reached
        if(-D_MAX_SPEED_Y != G_PLAYER_VELOCITY_Y){
            // Increment the -Y speed
            G_PLAYER_VELOCITY_Y -= 1;
        }
    }

    // Here in the future we will take care of alternate states
    // For exemple, slow down the player if they are attacking
    //   or immobilize them during specific actions

    // The player position corresponds to the upper part of the counters
    // Potentially, we can extract this value directly instead of having two vars
    // Increment the X counter and thus the X position of the player
    G_PLAYER_NEW_X += (T_U16)(G_PLAYER_VELOCITY_X*16);
    G_PLAYER_X = (T_U08)((G_PLAYER_NEW_X & 0xFF00) >> 8);

    // Calculate the current player top-left metatile (with only X updated)
    G_PLAYER_CURR_METATILE = ((G_PLAYER_Y-16) >> 4);
    G_PLAYER_CURR_METATILE *= 10;
    G_PLAYER_CURR_METATILE += ((G_PLAYER_X-8) >> 4);

    // If the player goes right
    if (G_PLAYER_VELOCITY_X > 0) {
        // If the top-right metatile is solid
        if (map_room[G_PLAYER_CURR_METATILE+1] <= 1) {
            // Push the player right next to that metatile
            G_PLAYER_X = (((G_PLAYER_X-8) >> 4) << 4) + 8; // 8 for screen x-offset
            G_PLAYER_NEW_X = (T_U16)(G_PLAYER_X << 8);
            G_PLAYER_VELOCITY_X = 0;
        // Else if the player is not contained in one metatile and the bottom-right is solid
        } else if ((G_PLAYER_Y % 16 != 0) && (map_room[G_PLAYER_CURR_METATILE+11] <= 1)) {
            G_PLAYER_X = (((G_PLAYER_X-8) >> 4) << 4) + 8; // 8 for screen x-offset
            G_PLAYER_NEW_X = (T_U16)(G_PLAYER_X << 8);
            G_PLAYER_VELOCITY_X = 0;
        }
    // Else if the player goes left
    } else if (G_PLAYER_VELOCITY_X < 0) {
        // If the top-left is solid
        if (map_room[G_PLAYER_CURR_METATILE] <= 1) {
            // Push the player right next to that metatile
            G_PLAYER_X = (((G_PLAYER_X-8) >> 4) << 4) + 24; // 16 for tile + 8 for screen x-offset
            G_PLAYER_NEW_X = (T_U16)(G_PLAYER_X << 8);
            G_PLAYER_VELOCITY_X = 0;
        // Else if the player is not contained in one metatile and the bottom-left is solid
        } else if ((G_PLAYER_Y % 16 != 0) && (map_room[G_PLAYER_CURR_METATILE+10] <= 1)) {
            G_PLAYER_X = (((G_PLAYER_X-8) >> 4) << 4) + 24; // 16 for tile + 8 for screen x-offset
            G_PLAYER_NEW_X = (T_U16)(G_PLAYER_X << 8);
            G_PLAYER_VELOCITY_X = 0;
        }
    }

    // Increment the Y counter and thus the Y position of the player
    G_PLAYER_NEW_Y += (T_U16)(G_PLAYER_VELOCITY_Y*16);
    G_PLAYER_Y = (T_U08)((G_PLAYER_NEW_Y & 0xFF00) >> 8);

    // Calculate the current player top-left metatile (with only Y updated)
    G_PLAYER_CURR_METATILE = ((G_PLAYER_Y-16) >> 4);
    G_PLAYER_CURR_METATILE *= 10;
    G_PLAYER_CURR_METATILE += ((G_PLAYER_X-8) >> 4);
    
    // If the player goes down
    if (G_PLAYER_VELOCITY_Y > 0) {
        // If the bottom_left is solid
        if (map_room[G_PLAYER_CURR_METATILE+10] <= 1) {
            // Push the player right next to that metatile
            G_PLAYER_Y = (((G_PLAYER_Y-16) >> 4) << 4) + 16; // 16 for screen y-offset
            G_PLAYER_NEW_Y = (T_U16)(G_PLAYER_Y << 8);
            G_PLAYER_VELOCITY_Y = 0;
        // Else if the player is not contained in one metatile and the bottom-right is solid
        } else if (((G_PLAYER_X-8) % 16 != 0) && (map_room[G_PLAYER_CURR_METATILE+11] <= 1)) {
            G_PLAYER_Y = (((G_PLAYER_Y-16) >> 4) << 4) + 16; // 16 for screen y-offset
            G_PLAYER_NEW_Y = (T_U16)(G_PLAYER_Y << 8);
            G_PLAYER_VELOCITY_Y = 0;
        }
    // Else if the player goes up
    } else if (G_PLAYER_VELOCITY_Y < 0) {
        // If the top-left is solid
        if (map_room[G_PLAYER_CURR_METATILE] <= 1) {
            // Push the player right next to that metatile
            G_PLAYER_Y = (((G_PLAYER_Y-16) >> 4) << 4) + 32; // 16 for tile + 16 for screen y-offset
            G_PLAYER_NEW_Y = (T_U16)(G_PLAYER_Y << 8);
            G_PLAYER_VELOCITY_Y = 0;
        // Else if the player is not contained in one metatile and the top-right is solid
        } else if (((G_PLAYER_X-8) % 16 != 0) && (map_room[G_PLAYER_CURR_METATILE+1] <= 1)) {
            G_PLAYER_Y = (((G_PLAYER_Y-16) >> 4) << 4) + 32; // 16 for tile + 16 for screen y-offset
            G_PLAYER_NEW_Y = (T_U16)(G_PLAYER_Y << 8);
            G_PLAYER_VELOCITY_Y = 0;
        }
    }
}

// ==========================================================================
// This function handles the animation and the position of the player sprites
void f_MovePlayerSprites(void){
    T_U08 i;

    // ==========================================================================
    // If the animation timer is 0
    if(0U == G_PLAYER_ANIM_TIMER){
        // Increment the current frame
        G_PLAYER_FRAME++;
        // Or if it reached the end of the cycle, reset it
        if(G_PLAYER_FRAME == G_PLAYER_ANIM->NbFrame){
            G_PLAYER_FRAME = 0U;
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

    // ==========================================================================
    // Then we update our global values...
    G_PLAYER_ANIM_TIMER--;

    // Update the G_PLAYER_TIME_BEFORE_ATK_ENDS var only if it is different from 0
    if(0U != G_PLAYER_TIME_BEFORE_ATK_ENDS){
        G_PLAYER_TIME_BEFORE_ATK_ENDS--;
    }

    // ==========================================================================
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

// ==========================================================================
// This function initialize some values
void game_init(void)
{
    G_TIMER             = 0;
    G_PLAYER_DIRECTION  = IS_FACING_DOWN;
    G_PLAYER_LAST_DIR   = IS_FACING_DOWN;
    G_PLAYER_FRAME      = 0;
    G_PLAYER_TIME_BEFORE_ATK_ENDS   = 0;
    G_PLAYER_ANIM       = &A_PLAYER_IDLE_FRONT;
    G_PLAYER_ANIM_TIMER = 0;
    G_PLAYER_TILECOUNT  = 0;
    G_PLAYER_X 		    = 0x40U;
    G_PLAYER_NEW_X      = 0x4000U;
    G_PLAYER_Y		    = 0x40U;
    G_PLAYER_NEW_Y      = 0x4000U;
    G_PLAYER_STATE_     = &STATE_IDLE;
    G_PLAYER_LAST_STATE_= &STATE_IDLE;

    G_PLAYER_VELOCITY_X       = 0;
    G_PLAYER_VELOCITY_Y       = 0;

    G_JOYPAD            = 0U;
    G_LAST_JOYPAD       = 0U;

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