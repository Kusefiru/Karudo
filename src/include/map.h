/*  ==================================================================
 *  Header associé à map.c
 * 
 *  ==================================================================*/

#ifndef MAP_H
#define MAP_H

/*  ------------------------------------------------------------------
 *  Liste des includes
 *  ------------------------------------------------------------------*/
#include "my_types.h"
#include "room_map.h"

/*  ------------------------------------------------------------------
 *  Liste des defines
 *  ------------------------------------------------------------------*/
#define _DungeonMapWidth  20                            // Largeur d'une salle de donjon
#define _DungeonMapHeight 16                            // Hauteur d'une salle de donjon (18 tiles - 2 d'UID)

#define _DungeonMapMetaWidth (_DungeonMapWidth/2)       // Largeur du tableau de metatiles d'une salle
#define _DungeonMapMetaHeight (_DungeonMapHeight/2)     // Hauteur du tableau de metatiles d'une salle   

/*  ------------------------------------------------------------------
 *  Variables globales
 *  ------------------------------------------------------------------*/


/*  ------------------------------------------------------------------
 *  Prototypes de fonction
 *  ------------------------------------------------------------------*/
/*  ------------------------------------------------------------------
 *  f_DisplayMap
 *  Cette fonction affiche à l'écran une map au format de base
 *  (décodage des métatiles - TODO)
 *  ------------------------------------------------------------------*/
void f_DisplayMap(T_U08 *, T_U08 *);

#endif