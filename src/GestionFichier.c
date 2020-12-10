/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

/* Inclusion du fichier necessaire */
#include "GestionFichier.h"

/*
Algo différent de la lecture de fichier et de la création manuelle de carte.
En effet, ici on fait un seul malloc (plus important en taille cependant), car
on connait d'avance le nombre de ville qu'on va ajouter dans la liste, donc
cela peut nous éviter de faire de nombreux malloc.
*/
int creation_villes_aleatoires(FILE *fp, Carte *carte){
    /* Initialisation des variables */
    int i, nb_aleatoire, x, y, max_villes;
    char nom_ville[TAILLE_CHAINE] = "ville_", nom_ville_tmp[TAILLE_CHAINE], buffer[TAILLE_CHAINE];

    /* Récupération de la taille de la carte voulue (le nombre de point aléatoire )*/
    printf("Choisissez la taille de la carte souhaitée (entre 4 et 16) : ");
    scanf("%d", &(carte->taille));

    /* Calculs nécessaires */
    carte->nb_villes = 0;
    max_villes = ((carte->taille*2) + 1) * ((carte->taille*2) + 1);
    nb_aleatoire = MLV_get_random_integer(1, max_villes);
    carte->villes = (Ville *) malloc(sizeof(Ville) * nb_aleatoire);
    if (carte->villes == NULL)
        return 0;

    for (i = 0; i < nb_aleatoire; i++){
        /* recopie du nom (voir si pas simplifiable, mais visiblement non)*/
        strcpy(nom_ville_tmp, nom_ville);
        sprintf(buffer, "%d", i);
        strcat(nom_ville_tmp, buffer);
        carte->villes[i].nom = (char *) malloc(sizeof(char) * (strlen(nom_ville_tmp)+1));
        if (carte->villes[i].nom == NULL)
            return 0;
        strcpy(carte->villes[i].nom, nom_ville_tmp);

        /* Tirage aléatoire des coordonnées de la ville et association à la ville i */
        do {
            x = MLV_get_random_integer(-(carte->taille), carte->taille);
            y = MLV_get_random_integer(-(carte->taille), carte->taille);
        } while(est_dans_villes(x, y, carte->villes, carte->nb_villes) == 0);
        carte->villes[i].x = x;
        carte->villes[i].y = y;
        carte->nb_villes += 1;
        fprintf(fp, "%s %d %d\n", carte->villes[i].nom, carte->villes[i].x, carte->villes[i].y);
    }
    return 1;
}



/*
Algo différent de la la création aléatoire et de la création manuelle de carte.
En effet, ici on fait un premier malloc, puis des realloc de plus en plus grand car
on ne connait pas d'avance le nombre de ville qu'on va ajouter dans la liste, donc
cela peut nous éviter de faire de nombreux malloc (2 points de vue différents entre
lecture et création manuelle).
*/
int lire_fichier(FILE *fp, Carte *carte){
    char nom_ville[TAILLE_CHAINE];
    int x, y, err, i = 0, val_alloc = 2, taille_carte;

    carte->villes = (Ville *) malloc(sizeof(Ville)*val_alloc);

    while(1){
        err = fscanf(fp, "%s %d %d", nom_ville, &x, &y);
        if (err == EOF){
            break;
        }
        if (err != 3){
            printf("Fichier incorrect !");
            return 0;
        }
        if (i >= val_alloc){
            val_alloc *= 2;
            carte->villes = realloc(carte->villes, sizeof(Ville)*val_alloc);
        }
        carte->villes[i].x = x;
        carte->villes[i].y = y;
        carte->villes[i].nom = (char *) malloc(sizeof(char) * (strlen(nom_ville)+1));
        strcpy(carte->villes[i].nom, nom_ville);
        i++;
    }
    carte->nb_villes = i;
    taille_carte = trouver_taille_carte(i);
    carte->taille = taille_carte;

    return 1;
}
