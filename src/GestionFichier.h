/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

#ifndef __GESTIONFICHIER__
#define __GESTIONFICHIER__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "Visite.h"

/* Definition des constantes */
#define TAILLE_CHAINE 100

/* Definition des structures */

/* Definition des fonctions */

/*
BUT		void
PARAM	void
RETOUR	void
*/
int creation_villes_aleatoires(FILE *fp, Carte *carte);
/*
BUT		void
PARAM	void
RETOUR	void
*/
int lire_fichier(FILE *fp, Carte *carte);

#endif
