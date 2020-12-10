/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

/* Inclusion du fichier necessaire */
#include "Ville.h"

Commune allouer_ville(char nom_ville[], int x, int y){
    Commune tmp = (Ville *) malloc(sizeof(Ville));
    char *chaine = (char *) malloc((strlen(nom_ville)+1) * sizeof(char));
    if (tmp == NULL || chaine == NULL){
        return NULL;
    }
    strcpy(chaine, nom_ville);
    tmp->x = x;
    tmp->y = y;
    tmp->nom = chaine;
    return tmp;
}


int est_dans_villes(int x, int y, Ville villes[], int taille){
    int i;
    for (i = 0; i < taille; i++){
        if (villes[i].x == x && villes[i].y == y){
            return 0;
        }
    }
    return 1;
}
