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
 *  -- Property     : Sprite properties for the tile
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
 *  -- FrameLength  : Length of the frame,
 *  -- *AddrFrame   : Adresse to the frame structure,
 */
typedef struct
{
    T_U08 NbTiles;
    T_U08 NbFrame;
    T_U08 FrameLength;
    T_ANIM_FRAME *AddrFrame;
} T_ANIM;

/** Attack structure.
 *  This describes the details of an attack done by the player
 */
typedef struct
{
    T_ANIM *Anim;
    T_U08 HitboxX;
    T_U08 HitboxY;
    T_U08 HitboxWidth;
    T_U08 HitboxLength;
    T_U08 Damages;
} T_Attack;

/** Attack structure.
 *  This describes the details of an attack done by the player
 */
typedef struct
{
    T_ANIM *Anim;
    T_U08  Direction;
} T_Combo;

/** State structure.
 *  This describes a collection of frames for a complete animation.
 *  -- *Anim            : Address of the front animation for this state,
 *  -- *NextState_Down  : Next state if A & Down are pressed,
 *  -- *NextState_Up    : Next state if A & Up are pressed,
 *  -- *NextState_Left  : Next state if A & Left are pressed,
 *  -- *NextState_Right : Next state if A & Right are pressed,
 *  -- *NextState_Idle  : Next state if only A is pressed
 */
typedef struct T_STATE
{
    T_ANIM *Anim;
    struct T_STATE *NextState_Down;
    struct T_STATE *NextState_Up;
    struct T_STATE *NextState_Left;
    struct T_STATE *NextState_Right;
    struct T_STATE *NextState_Idle;
} T_STATE;

// 0 -> Retour en state IDLE


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

/** Player direction enum.
 */
typedef enum
{
    IS_FACING_DOWN  = 0,
    IS_FACING_UP    = 1,
    IS_FACING_LEFT  = 2,
    IS_FACING_RIGHT = 3
} T_PLAYER_DIRECTION;

/*  ------------------------------------------------------------------
 *  Valeurs importantes
 *  ------------------------------------------------------------------*/
#define D_TIME_BEFORE_NEXT  6

/*  ------------------------------------------------------------------
 *  Adresses importantes
 *  ------------------------------------------------------------------*/
#define GBC_BG_MAP_DATA_1   0x9800
#define GBC_BG_MAP_DATA_2   0x9C00

#endif