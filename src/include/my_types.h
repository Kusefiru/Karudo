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

/*  ------------------------------------------------------------------
 *  Adresses importantes
 *  ------------------------------------------------------------------*/
#define GBC_BG_MAP_DATA_1   0x9800
#define GBC_BG_MAP_DATA_2   0x9C00

#endif