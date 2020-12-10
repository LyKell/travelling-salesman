/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

#ifndef __CARTE__
#define __CARTE__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include "Ville.h"

/* Definition des constantes */
#define TAILLE_MAX 16
#define TAILLE_MIN 4

/* Definition des structures */
typedef struct carte{
    int taille;
    int nb_villes;
    Ville *villes;
}Carte;

/* Definition des fonctions */

/*
BUT		void
PARAM	void
RETOUR	void
*/
void lire_villes_dans_carte(Carte carte);
/*
BUT		void
PARAM	void
RETOUR	void
*/
int trouver_taille_carte(int val);

#endif
