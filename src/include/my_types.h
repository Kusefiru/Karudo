/*  ==================================================================
 *  Ce fichier comprend mes définitions des types
 * 
 *  ==================================================================*/

#ifndef MY_TYPES_H
#define MY_TYPES_H

/*  ------------------------------------------------------------------
 *  Définition des types
 *  ------------------------------------------------------------------*/

/** Signed eight bit.
 */
typedef char          	T_S08;
/** Unsigned eight bit.
 */
typedef unsigned char 	T_U08;
/** Signed sixteen bit.
 */
typedef int           	T_S16;
/** Unsigned sixteen bit.
 */
typedef unsigned int  	T_U16;
/** Signed 32 bit.
 */
typedef long          	T_S32;
/** Unsigned 32 bit.
 */
typedef unsigned long 	T_U32;

/** Frame structure.
 *  This describes a sprite which is part of or a whole frame.
 *  -- TileNb       : Index of the tile,
 *  -- PosX         : X Coordinate relative to the whole frame,
 *  -- PosY         : Y Coordinate relative to the whole frame,
 */
typedef struct
{
    T_U08 TileNb;
    T_U08 Property;
    T_U08 PosX;
    T_U08 PosY;
} T_ANIM_FRAME;

/** Animation structure.
 *  This describes a collection of frames for a complete animation.
 *  -- NbTiles      : Number of tiles to make one whole frame,
 *  -- NbFrame      : Number of frames in the animation,
 *  -- *AddrFrame   : Adresse to the frame structure,
 */
typedef struct
{
    T_U08 NbTiles;
	T_U08 NbFrame;
	T_ANIM_FRAME *AddrFrame;
} T_ANIM;

/** Player states enum.
 *  -- IS_IDLE      : For when the player does nothing,
 *  -- IS_MOVING    : For when the player is simply walking,
 *  -- IS_ATTACKING : For when the player is attacking,
 */
typedef enum
{
    IS_IDLE      = 0,
    IS_MOVING    = 1,
    IS_ATTACKING = 2
} T_PLAYER_STATE;

typedef enum
{
    IS_FACING_DOWN  = 0,
    IS_FACING_UP    = 1,
    IS_FACING_LEFT  = 2,
    IS_FACING_RIGHT = 3
} T_PLAYER_DIRECTION;


/*  ------------------------------------------------------------------
 *  Adresses importantes
 *  ------------------------------------------------------------------*/
#define GBC_BG_MAP_DATA_1   0x9800
#define GBC_BG_MAP_DATA_2   0x9C00

#endif