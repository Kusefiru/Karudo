/*  ==================================================================
 *  Ce fichier comprend La totalité des variables stockées en RAM et
 *  ne devant être modifiées sous aucun prétexte
 * 
 *  ==================================================================*/

#ifndef KARUDO_RAM_H
#define KARUDO_RAM_H

/*  ------------------------------------------------------------------
 *  Liste des includes
 *  ------------------------------------------------------------------*/
#include "my_types.h"

/*  ------------------------------------------------------------------
 *  Variables globales
 *  ------------------------------------------------------------------*/
extern T_U32 G_TIMER;

extern T_PLAYER_DIRECTION G_PLAYER_DIRECTION;
extern T_PLAYER_DIRECTION G_PLAYER_LAST_DIR;
extern T_STATE *G_PLAYER_STATE_;
extern T_STATE *G_PLAYER_LAST_STATE_;
extern T_U08 G_PLAYER_TILECOUNT;
extern T_U08 G_PLAYER_X;
extern T_U16 G_PLAYER_NEW_X;
extern T_U08 G_PLAYER_Y;
extern T_U16 G_PLAYER_NEW_Y;
extern T_U08 G_PLAYER_CURR_METATILE;
extern T_U08 G_COLLIDE_1_X;
extern T_U08 G_COLLIDE_1_Y;
extern T_ANIM *G_PLAYER_ANIM;
extern T_U08 G_PLAYER_ANIM_TIMER;
extern T_U08 G_PLAYER_FRAME;
extern T_U08 G_PLAYER_TIME_BEFORE_ATK_ENDS;

extern T_U08 G_COLLIDE_2_X;
extern T_U08 G_COLLIDE_2_Y;
extern T_S08 G_PLAYER_VELOCITY_X;
extern T_S08 G_PLAYER_VELOCITY_Y;

extern T_U08 G_JOYPAD;
extern T_U08 G_LAST_JOYPAD;

#endif