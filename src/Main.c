/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 09-04-2019
 * Modification : 09-04-2019 */

/* Inclusion des bibliotheques et fichiers nécessaires */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "IGraph.h"
#include "GestionFichier.h"
#include "Visite.h"



/* Déclaration des prototypes */

/*
BUT		Fonction principale du programme.
PARAM	argc : Nombre d'arguments
        argv : Les arguments
RETOUR	EXIT_SUCCESS : Le programme s'est déroulé sans accroc
        EXIT_FAILURE : Quelque chose de signalé s'est déroulé.
*/
int main(int argc, char *argv[]);
/*
BUT		Fonction permettant de verifier la validité des arguments donné.
PARAM	argc : Nombre d'arguments
        argv : Les arguments
RETOUR	1 : Un des arguments est incorrect.
        0 : Tous les arguments sont corrects.
*/
int verifier_arguments(int argc, char *argv[]);
/*
BUT		Fonction permettant de choisir le mode souhaité.
PARAM	*argv : L'argument du mode
RETOUR	1 : aucun mode n'a été choisi.
        0 : tout s'est bien passé.
*/
int choisir_mode(char *argv, char *str);




int main(int argc, char *argv[]){
    int err;
    char str[TAILLE_CHAINE] = "../fichiers/";

    err = verifier_arguments(argc, argv);
    if (err == 1){
        return EXIT_FAILURE;
    }

    strcat(str, argv[2]);

    err = choisir_mode(argv[1], str);
    if (err == 1){
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}




int verifier_arguments(int argc, char *argv[]){
    /* Vérification du bon nombre d'arguments */
    if (argc != 3){
        printf("Nombre d'arguments invalide !\n");
        return 1;
    }

    /* Vérification de l'extension du fichier */
    if (argv[2][strlen(argv[2])-4] != '.' || argv[2][strlen(argv[2])-3] != 'p' ||
    argv[2][strlen(argv[2])-2] != 'v' || argv[2][strlen(argv[2])-1] != 'c'){
        printf("L'extension du fichier n'est pas bonne !\n");
        return 1;
    }
    return 0;
}


int choisir_mode(char *argv, char *str){
    int taille_case = 0;
    FILE *fp;
    Carte carte = {0};

    if(strcmp(argv, "-cm") == 0){
        printf("Mode Création Manuelle :\n");
        fp = fopen(str, "w");
    }
    else if (strcmp(argv, "-ca") == 0){
        printf("Mode Création Aléatoire :\n");
        fp = fopen(str, "w");
        creation_villes_aleatoires(fp, &carte);
    }
    else if (strcmp(argv, "-vi") == 0){
        printf("Mode Visite :\n");
        fp = fopen(str, "r");
        lire_fichier(fp, &carte);
        lire_villes_dans_carte(carte);
        MLV_create_window("PVC","PVC", TAILLE_FENETRE, TAILLE_FENETRE);
        taille_case = afficher_carte(carte);
        printf("%d\n", taille_case);
        MLV_actualise_window();
        MLV_wait_seconds(5);
        MLV_free_window();
    }
    else {
        printf("Précisez le mode d'utilisation du programme :\n-cm : Mode Création Manuelle\n-ca : Mode Création Aléatoire\n-vi : Mode Visite\n");
        return 1;
    }

    return 0;
}
