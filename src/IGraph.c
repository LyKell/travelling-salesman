/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

/* Inclusion du fichier necessaire */
#include "IGraph.h"


int afficher_carte(Carte carte){
    int i, taille_case = 0, centre, tmp_x, tmp_y;
    MLV_draw_filled_rectangle(0,0, TAILLE_FENETRE, TAILLE_FENETRE, MLV_COLOR_WHITE);
    taille_case = (carte.taille*2)/TAILLE_FENETRE;
    centre = carte.taille * taille_case;
    tmp_x = centre + ((carte.villes[0].x)*taille_case);
    tmp_y = centre + ((carte.villes[0].y)*taille_case);
    MLV_draw_filled_circle(tmp_x, tmp_y, 1, MLV_COLOR_GREEN);
    for (i = 1; i < carte.nb_villes-1; i++){
        tmp_x = centre + ((carte.villes[i].x)*taille_case);
        tmp_y = centre + ((carte.villes[i].y)*taille_case);
        MLV_draw_filled_circle(tmp_x, tmp_y, 1, MLV_COLOR_BLACK);
    }
    tmp_x = centre + ((carte.villes[carte.nb_villes-1].x)*taille_case);
    tmp_y = centre + ((carte.villes[carte.nb_villes-1].y)*taille_case);
    MLV_draw_filled_circle(tmp_x, tmp_y, 1, MLV_COLOR_RED);
    return 1;
}
