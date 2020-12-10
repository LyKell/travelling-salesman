/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

/* Inclusion du fichier necessaire */
#include "Carte.h"

void lire_villes_dans_carte(Carte carte){
    int i;
    for (i = 0; i < carte.nb_villes; i++){
        printf("%s %d %d\n", carte.villes[i].nom, carte.villes[i].x, carte.villes[i].y);
    }
}

int trouver_taille_carte(int val){
    int i;
    for (i = 0; ((i*2)+1)*((i*2)+1) < val; i++){

    }
    return i;
}
