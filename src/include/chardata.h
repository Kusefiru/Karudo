/*  ==================================================================
 *  Header contenant les sprites du perso
 * 
 *  ==================================================================*/

#ifndef CHARDATA_H
#define CHARDATA_H

#include "my_types.h"

const T_U16 Player_Palette[] =
{
    32767, 21375, 8541, 1057
};

const T_U16 Sword_Palette[] =
{
    32767, 736, 25535, 0
};

const T_U08 Player_Tiles_Walk_Front[] =
{
    // top-left, frame 0
    0x07,0x07,0x3C,0x3F,0x26,0x3B,0x34,0x3F,
    0x49,0x7F,0x4B,0x7F,0x6F,0x7C,0x7F,0x52,

    // bottom-left, frame 0
    // bottom-right, frame 0 (flip X)
    0x3F,0x32,0x3E,0x39,0x7F,0x4F,0x7B,0x4F,
    0x3F,0x39,0x1F,0x1F,0x13,0x1D,0x0E,0x0E,

    // top-right, frame 0
    0xC0,0xC0,0x30,0xF0,0x28,0xD8,0x04,0xFC,
    0x44,0xFC,0x62,0xFE,0xF6,0x9E,0xFE,0x4A,

    // top-left, frame 1
    0x00,0x00,0x07,0x07,0x3C,0x3F,0x26,0x3B,
    0x34,0x3F,0x49,0x7F,0x4B,0x7F,0x6F,0x7C,

    // bottom-left, frame 1
    0x7F,0x52,0x7F,0x72,0x7E,0x79,0x3F,0x3F,
    0x1F,0x1B,0x0E,0x0F,0x09,0x0F,0x07,0x07,

    // top-right, frame 1
    0x00,0x00,0xC0,0xC0,0x30,0xF0,0x28,0xD8,
    0x04,0xFC,0x44,0xFC,0x62,0xFE,0xF6,0x9E,

    // bottom-right, frame 1
    0xFE,0x4A,0xFC,0x4C,0x7C,0x9C,0xFC,0xF4,
    0xFC,0xCC,0x78,0xC8,0xB0,0xB0,0x00,0x00

    // frame 2 = frame 0
    // frame 3 = frame 1 with both bottom inverted
};

const T_U08 Player_Tiles_Walk_Side[] =
{
    // top-left, frame 0
    0x13,0x13,0x2C,0x3F,0x22,0x3F,0x30,0x3F,
    0x40,0x7F,0x2E,0x39,0x3F,0x35,0x1F,0x14,

    // bottom-left, frame 0
    0x1F,0x10,0x0B,0x0C,0x07,0x07,0x03,0x03,
    0x03,0x03,0x04,0x07,0x07,0x04,0x03,0x03,

    // top-right, frame 0
    0xC0,0xC0,0x30,0xF0,0x08,0xF8,0x04,0xFC,
    0x04,0xFC,0x14,0xFC,0x94,0xFC,0xF8,0xA8,

    // bottom-right, frame 0
    0xF0,0x30,0xF8,0x68,0xC8,0xF8,0xF8,0x28,
    0xE8,0x38,0xF0,0xF0,0xA0,0x60,0xC0,0xC0,

    // top-left, frame 1
    0x00,0x00,0x13,0x13,0x2C,0x3F,0x22,0x3F,
    0x30,0x3F,0x40,0x7F,0x2E,0x39,0x3F,0x35,

    // bottom-left, frame 1
    0x1F,0x14,0x1F,0x10,0x0B,0x0C,0x07,0x07,
    0x1F,0x1F,0x24,0x3F,0x13,0x1F,0x0E,0x0E,

    // top-right, frame 1
    0x00,0x00,0xC0,0xC0,0x30,0xF0,0x08,0xF8,
    0x04,0xFC,0x04,0xFC,0x14,0xFC,0x94,0xFC,

    // bottom-right, frame 1
    0xF8,0xA8,0xF0,0x30,0xF8,0x68,0xE8,0xF8,
    0xF8,0x98,0xF4,0x9C,0xE4,0xFC,0x18,0x18

    // frame 2 = frame 0
    // frame 3 = frame 1
    // so basically the side walk animation is two frames
};

const T_U08 Player_Tiles_Walk_Back[] =
{
    // top-left, frame 0
    0x13,0x13,0x2C,0x3F,0x22,0x3F,0x38,0x37,
    0x40,0x7F,0x24,0x3B,0x70,0x5F,0x60,0x5F,

    // bottom-left, frame 0
    // bottom-right, frame 0 (flip X)
    0x30,0x3F,0x3A,0x3F,0x7F,0x5F,0x79,0x5E,
    0x3C,0x3F,0x17,0x1F,0x11,0x1F,0x0E,0x0E,

    // top-right, frame 0
    0xC0,0xC0,0x30,0xF0,0x08,0xF8,0x14,0xEC,
    0x04,0xFC,0x24,0xDC,0x0E,0xFA,0x06,0xFA,

    // top-left, frame 1
    0x00,0x00,0x13,0x13,0x2C,0x3F,0x22,0x3F,
    0x38,0x37,0x40,0x7F,0x24,0x3B,0x70,0x5F,

    // bottom-left, frame 1
    0x60,0x5F,0x70,0x7F,0x7A,0x6F,0x3F,0x3F,
    0x19,0x1E,0x0C,0x0F,0x0B,0x0F,0x07,0x07,

    // top-right, frame 1
    0x00,0x00,0xC0,0xC0,0x30,0xF0,0x08,0xF8,
    0x14,0xEC,0x04,0xFC,0x24,0xDC,0x0E,0xFA,

    // bottom-right, frame 1
    0x06,0xFA,0x0C,0xFC,0x5C,0xFC,0xFE,0xF2,
    0x9E,0x72,0x3C,0xFC,0xC0,0xC0,0x00,0x00

    // frame 2 = frame 0
    // frame 3 = frame 1 with both bottom inverted
};

const T_U08 Sword_Tiles[] =
{
    // sword handle, diagonal top right -> bottom left
    0x1E,0x1E,0x2F,0x31,0x1F,0x1D,0x27,0x3D,
    0x45,0x7F,0x8A,0xFA,0x10,0xF0,0x20,0xE0,

    // sword tip, diagonal top right -> bottom left
    0x04,0x07,0x08,0x0F,0x11,0x1F,0x12,0x1E,
    0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,

    // sweep up, diagonal top right -> bottom left
    0x10,0x08,0x10,0x08,0x00,0x08,0x08,0x14,
    0x08,0x14,0x04,0x0A,0x07,0x09,0x02,0x06,

    // sweep down, diagonal top right -> bottom left
    0x40,0x40,0xC0,0xA0,0x60,0x98,0x18,0x67,
    0x07,0x18,0x00,0x00,0x00,0x00,0x00,0x00,

    // sword handle, frame 1
    0x3C,0x24,0x7E,0x42,0xBD,0xDB,0xE7,0xFF,
    0x24,0x3C,0x24,0x3C,0x24,0x3C,0x24,0x3C,

    // sword tip, frame 1
    0x24,0x3C,0x24,0x3C,0x24,0x3C,0x24,0x3C,
    0x24,0x3C,0x24,0x3C,0x24,0x3C,0x18,0x18,

    // empty tile needed for frame 1
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const T_ANIM_FRAME G_PlayerIdleFramesFront[] =
{
    {   0   ,0          ,0  ,0},
    {   1   ,0          ,0  ,8},
    {   2   ,0          ,8  ,0},
    {   1   ,S_FLIPX    ,8  ,8}
};

const T_ANIM_FRAME G_PlayerIdleFramesLeft[] =
{
    {   7   ,0          ,0  ,0},
    {   8   ,0          ,0  ,8},
    {   9   ,0          ,8  ,0},
    {  10   ,0          ,8  ,8}
};

const T_ANIM_FRAME G_PlayerIdleFramesRight[] =
{
    {   9   ,S_FLIPX    ,0  ,0},
    {  10   ,S_FLIPX    ,0  ,8},
    {   7   ,S_FLIPX    ,8  ,0},
    {   8   ,S_FLIPX    ,8  ,8}
};

const T_ANIM_FRAME G_PlayerIdleFramesBack[] =
{
    {  15   ,0          ,0  ,0},
    {  16   ,0          ,0  ,8},
    {  17   ,0          ,8  ,0},
    {  16   ,S_FLIPX    ,8  ,8}
};

const T_ANIM_FRAME G_PlayerWalkingFramesFront[] =
{
    {   0   ,0          ,0  ,0},
    {   1   ,0          ,0  ,8},
    {   2   ,0          ,8  ,0},
    {   1   ,S_FLIPX    ,8  ,8},

    {   3   ,0          ,0  ,0},
    {   4   ,0          ,0  ,8},
    {   5   ,0          ,8  ,0},
    {   6   ,0          ,8  ,8},

    {   0   ,0          ,0  ,0},
    {   1   ,0          ,0  ,8},
    {   2   ,0          ,8  ,0},
    {   1   ,S_FLIPX    ,8  ,8},

    {   3   ,0          ,0  ,0},
    {   6   ,S_FLIPX    ,0  ,8},
    {   5   ,0          ,8  ,0},
    {   4   ,S_FLIPX    ,8  ,8},
};

const T_ANIM_FRAME G_PlayerWalkingFramesLeft[] =
{
    {   7   ,0          ,0  ,0},
    {   8   ,0          ,0  ,8},
    {   9   ,0          ,8  ,0},
    {  10   ,0          ,8  ,8},

    {  11   ,0          ,0  ,0},
    {  12   ,0          ,0  ,8},
    {  13   ,0          ,8  ,0},
    {  14   ,0          ,8  ,8}
};

const T_ANIM_FRAME G_PlayerWalkingFramesRight[] =
{
    {   9   ,S_FLIPX    ,0  ,0},
    {  10   ,S_FLIPX    ,0  ,8},
    {   7   ,S_FLIPX    ,8  ,0},
    {   8   ,S_FLIPX    ,8  ,8},

    {  13   ,S_FLIPX    ,0  ,0},
    {  14   ,S_FLIPX    ,0  ,8},
    {  11   ,S_FLIPX    ,8  ,0},
    {  12   ,S_FLIPX    ,8  ,8}
};

const T_ANIM_FRAME G_PlayerWalkingFramesBack[] =
{
    {  15   ,0          ,0  ,0},
    {  16   ,0          ,0  ,8},
    {  17   ,0          ,8  ,0},
    {  16   ,S_FLIPX    ,8  ,8},

    {  18   ,0          ,0  ,0},
    {  19   ,0          ,0  ,8},
    {  20   ,0          ,8  ,0},
    {  21   ,0          ,8  ,8},

    {  15   ,0          ,0  ,0},
    {  16   ,0          ,0  ,8},
    {  17   ,0          ,8  ,0},
    {  16   ,S_FLIPX    ,8  ,8},

    {  18   ,0          ,0  ,0},
    {  21   ,S_FLIPX    ,0  ,8},
    {  20   ,0          ,8  ,0},
    {  19   ,S_FLIPX    ,8  ,8},
};

const T_ANIM_FRAME G_PlayerAttackingFramesFront_1[] =
{
    {  22   ,S_FLIPX|0x01U  ,12 ,12},
    {  24   ,S_FLIPX|0x01U  ,20 ,12},
    {  25   ,S_FLIPX|0x01U  ,12 ,20},
    {  23   ,S_FLIPX|0x01U  ,20 ,20},
    {   0   ,0          ,0  ,0},
    {   1   ,0          ,0  ,8},
    {   2   ,0          ,8  ,0},
    {   1   ,S_FLIPX    ,8  ,8},

    {  26   ,0x01U      ,8  ,12},
    {  27   ,0x01U      ,8  ,20},
    {  28   ,0x01U      ,0  ,0 },
    {  28   ,0x01U      ,0  ,0 },
    {   0   ,0          ,0  ,0},
    {   1   ,0          ,0  ,8},
    {   2   ,0          ,8  ,0},
    {   1   ,S_FLIPX    ,8  ,8},
    
    {  24   ,0x01U      ,-4 ,12},
    {  23   ,0x01U      ,-4 ,20},
    {  22   ,0x01U      ,4  ,12},
    {  25   ,0x01U      ,4  ,20},
    {   0   ,0          ,0  ,0},
    {   1   ,0          ,0  ,8},
    {   2   ,0          ,8  ,0},
    {   1   ,S_FLIPX    ,8  ,8}
};

const T_ANIM_FRAME G_PlayerAttackingFramesFront_2[] =
{
    {  22   ,S_FLIPX|0x01U  ,12 ,12},
    {  24   ,S_FLIPX|0x01U  ,20 ,12},
    {  25   ,S_FLIPX|0x01U  ,12 ,20},
    {  23   ,S_FLIPX|0x01U  ,20 ,20},
    {   0   ,0x01U          ,0  ,0},
    {   1   ,0x01U          ,0  ,8},
    {   2   ,0x01U          ,8  ,0},
    {   1   ,S_FLIPX|0x01U  ,8  ,8},

    {  26   ,0x01U      ,8  ,12},
    {  27   ,0x01U      ,8  ,20},
    {  28   ,0x01U      ,0  ,0 },
    {  28   ,0x01U      ,0  ,0 },
    {   0   ,0x01U          ,0  ,0},
    {   1   ,0x01U          ,0  ,8},
    {   2   ,0x01U          ,8  ,0},
    {   1   ,S_FLIPX|0x01U  ,8  ,8},
    
    {  24   ,0x01U      ,-4 ,12},
    {  23   ,0x01U      ,-4 ,20},
    {  22   ,0x01U      ,4  ,12},
    {  25   ,0x01U      ,4  ,20},
    {   0   ,0x01U          ,0  ,0},
    {   1   ,0x01U          ,0  ,8},
    {   2   ,0x01U          ,8  ,0},
    {   1   ,S_FLIPX|0x01U  ,8  ,8}
};

T_ANIM A_PLAYER_IDLE_RIGHT = {4, 1, 16, G_PlayerIdleFramesRight};
T_ANIM A_PLAYER_IDLE_LEFT  = {4, 1, 16, G_PlayerIdleFramesLeft};
T_ANIM A_PLAYER_IDLE_BACK  = {4, 1, 16, G_PlayerIdleFramesBack};
T_ANIM A_PLAYER_IDLE_FRONT = {4, 1, 16, G_PlayerIdleFramesFront};

T_ANIM A_PLAYER_WALKING_RIGHT = {4, 2, 16, G_PlayerWalkingFramesRight};
T_ANIM A_PLAYER_WALKING_LEFT  = {4, 2, 16, G_PlayerWalkingFramesLeft};
T_ANIM A_PLAYER_WALKING_BACK  = {4, 4, 16, G_PlayerWalkingFramesBack};
T_ANIM A_PLAYER_WALKING_FRONT = {4, 4, 16, G_PlayerWalkingFramesFront};

T_ANIM A_PLAYER_SWORD_1_FRONT = {8, 3, 8, G_PlayerAttackingFramesFront_1};
T_ANIM A_PLAYER_SWORD_2_FRONT = {8, 3, 6, G_PlayerAttackingFramesFront_2};

// T_ANIM T_PLAYER_COMBO[] = 
// {
//     {&A_PLAYER_SWORD_1_FRONT, 0},
//     {&A_PLAYER_SWORD_2_FRONT, 0}
// };

T_STATE STATE_IDLE  = {&A_PLAYER_IDLE_RIGHT, 0, 0, 0, 0, &STATE_ATK_1};
T_STATE STATE_MOVE  = {&A_PLAYER_WALKING_RIGHT, &STATE_ATK_1, &STATE_ATK_1, &STATE_ATK_1, &STATE_ATK_1, &STATE_ATK_1};
T_STATE STATE_ATK_1 = {&A_PLAYER_SWORD_1_FRONT, &STATE_ATK_2, &STATE_ATK_2, &STATE_ATK_2, &STATE_ATK_2, &STATE_ATK_2};
T_STATE STATE_ATK_2 = {&A_PLAYER_SWORD_2_FRONT, 0, 0, 0, 0, 0};

T_U08 T_PLAYER_COMBO_LENGTH = 2;

#endif