/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

#ifndef __VILLE__
#define __VILLE__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition des constantes */

/* Definition des structures */
typedef struct ville{
    int x, y;
    char *nom;
}Ville, *Commune;

/* Definition des fonctions */

/*
BUT		void
PARAM	void
RETOUR	void
*/
Commune allouer_ville(char nom_ville[], int x, int y);
/*
BUT		void
PARAM	void
RETOUR	void
*/
int est_dans_villes(int x, int y, Ville villes[], int taille);

#endif
