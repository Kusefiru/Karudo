/*  ==================================================================
 *  Ce fichier comprend les fonctions de base relative aux maps
 * 
 *  ==================================================================*/

/*  ------------------------------------------------------------------
 *  Liste des includes
 *  ------------------------------------------------------------------*/
#include "map.h"
#include <gb/gb.h>

/*  ------------------------------------------------------------------
 *  Variables globales
 *  ------------------------------------------------------------------*/

/*  ------------------------------------------------------------------
 *  f_DisplayMap
 *  Cette fonction affiche à l'écran une map au format de base
 *  TODO : Remplacer la fonction de gbdk
 *  ------------------------------------------------------------------*/
void f_DisplayMap(
    T_U08 * mapAddress,     /* Adresse de la map */
    T_U08 * metaTileAddress /* Adresse du tableau des metatiles */
) {
    T_U08 i;
    T_U08 j;
    T_U08 * pointerOnMap;
    
    i = 0;
    j = 0;
    pointerOnMap = mapAddress;

    while(j != _DungeonMapHeight)
    {
        set_bkg_tiles(i, j, 2, 2, (metaTileAddress + *(pointerOnMap)*4));

        pointerOnMap++;
        i += 2;
        if(i%_DungeonMapWidth == 0)
        {
            i = 0;
            j += 2;
        }
    }
}