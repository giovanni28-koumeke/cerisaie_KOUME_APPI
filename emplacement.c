/*
*File name : emplacement.c
*perpose : fichier d'impléméntation des fonctions
*Authors : KOUMEKE Giovanni & APPIAH Samuel
*Created : 13/O2/2026
*Update : 14/02/2026
*/

#include <stdio.h>
#include "emplacement.h"
#include "typeEmplacement.h"

/* 
   Fonction : ajouterEmplacement
   Rôle : Ajouter un nouvel emplacement
*/
void ajouterEmplacement() {

    FILE *f = fopen("emplacements.dat", "rb+");
    Emplacement e;

    if (f == NULL) {
        f = fopen("emplacements.dat", "wb+");
    }

    printf("Numero emplacement : ");
    scanf("%d", &e.numEmplacement);

    printf("Surface : ");
    scanf("%f", &e.surface);

    printf("Capacite : ");
    scanf("%d", &e.capacite);

    printf("Code type : ");
    scanf("%d", &e.codeType);

    if (trouverType(e.codeType) != -1) {

        e.estLibre = 1;

        fseek(f, (e.numEmplacement - 1) * sizeof(Emplacement), SEEK_SET);
        fwrite(&e, sizeof(Emplacement), 1, f);

        printf("Emplacement ajoute avec succes.\n");

    } else {
        printf("Type inexistant.\n");
    }

    fclose(f);
}
/*  FIN ajouterEmplacement  */


/* 
   Fonction : modifierEmplacement
   Rôle : Modifier un emplacement existant
*/
void modifierEmplacement() {

    FILE *f = fopen("emplacements.dat", "rb+");
    Emplacement e;
    int num;

    if (f != NULL) {

        printf("Numero emplacement a modifier : ");
        scanf("%d", &num);

        fseek(f, (num - 1) * sizeof(Emplacement), SEEK_SET);

        if (fread(&e, sizeof(Emplacement), 1, f) == 1) {

            printf("Nouvelle surface : ");
            scanf("%f", &e.surface);

            printf("Nouvelle capacite : ");
            scanf("%d", &e.capacite);

            printf("Nouveau code type : ");
            scanf("%d", &e.codeType);

            fseek(f, (num - 1) * sizeof(Emplacement), SEEK_SET);
            fwrite(&e, sizeof(Emplacement), 1, f);

            printf("Modification effectuee.\n");
        } else {
            printf("Emplacement introuvable.\n");
        }

        fclose(f);
    }
}
/*  FIN modifierEmplacement  */


/* 
   Fonction : supprimerEmplacement
   Rôle : Suppression logique
*/
void supprimerEmplacement() {

    FILE *f = fopen("emplacements.dat", "rb+");
    Emplacement e;
    int num;

    if (f != NULL) {

        printf("Numero emplacement a supprimer : ");
        scanf("%d", &num);

        fseek(f, (num - 1) * sizeof(Emplacement), SEEK_SET);

        if (fread(&e, sizeof(Emplacement), 1, f) == 1) {

            e.numEmplacement = 0;

            fseek(f, (num - 1) * sizeof(Emplacement), SEEK_SET);
            fwrite(&e, sizeof(Emplacement), 1, f);

            printf("Emplacement desactive.\n");
        }

        fclose(f);
    }
}
/*  FIN supprimerEmplacement  */


/* 
   Fonction : afficherEmplacements
   Rôle : Afficher tous les emplacements
*/
void afficherEmplacements() {

    FILE *f = fopen("emplacements.dat", "rb");
    Emplacement e;

    if (f != NULL) {

        printf("\n--- LISTE DES EMPLACEMENTS ---\n");

        while (fread(&e, sizeof(Emplacement), 1, f) == 1) {

            if (e.numEmplacement != 0) {

                printf("Num: %d | Surface: %.2f | Capacite: %d | Etat: %s\n",
                       e.numEmplacement,
                       e.surface,
                       e.capacite,
                       e.estLibre == 1 ? "Libre" : "Occupe");
            }
        }

        fclose(f);
    }
}
/*  FIN afficherEmplacements  */


/* 
   Fonction : attribuerEmplacement
   Rôle : Trouver un emplacement libre
*/
void attribuerEmplacement() {

    FILE *f = fopen("emplacements.dat", "rb+");
    Emplacement e;
    int typeRecherche;
    int nbPersonnes;
    int trouve = 0;

    if (f != NULL) {

        printf("Code type souhaite : ");
        scanf("%d", &typeRecherche);

        printf("Nombre de personnes : ");
        scanf("%d", &nbPersonnes);

        while (fread(&e, sizeof(Emplacement), 1, f) == 1 && trouve == 0) {

            if (e.codeType == typeRecherche &&
                e.capacite >= nbPersonnes &&
                e.estLibre == 1 &&
                e.numEmplacement != 0) {

                e.estLibre = 0;

                fseek(f, -sizeof(Emplacement), SEEK_CUR);
                fwrite(&e, sizeof(Emplacement), 1, f);

                printf("Emplacement attribue : %d\n", e.numEmplacement);
                trouve = 1;
            }
        }

        if (trouve == 0) {
            printf("Aucun emplacement disponible.\n");
        }

        fclose(f);
    }
}
/*  FIN attribuerEmplacement  */


/* 
   Fonction : libererEmplacement
   Rôle : Remettre un emplacement en libre
*/
void libererEmplacement() {

    FILE *f = fopen("emplacements.dat", "rb+");
    Emplacement e;
    int num;

    if (f != NULL) {

        printf("Numero emplacement a liberer : ");
        scanf("%d", &num);

        fseek(f, (num - 1) * sizeof(Emplacement), SEEK_SET);

        if (fread(&e, sizeof(Emplacement), 1, f) == 1) {

            e.estLibre = 1;

            fseek(f, (num - 1) * sizeof(Emplacement), SEEK_SET);
            fwrite(&e, sizeof(Emplacement), 1, f);

            printf("Emplacement libere.\n");
        }

        fclose(f);
    }
}
/*  FIN libererEmplacement */


/* 
   Fonction : listeParType
   Rôle : Afficher les emplacements d’un type
*/
void listeParType() {

    FILE *f = fopen("emplacements.dat", "rb");
    Emplacement e;
    int code;

    if (f != NULL) {

        printf("Code type : ");
        scanf("%d", &code);

        while (fread(&e, sizeof(Emplacement), 1, f) == 1) {

            if (e.codeType == code && e.numEmplacement != 0) {

                printf("Num: %d | Surface: %.2f | Capacite: %d | Etat: %s\n",
                       e.numEmplacement,
                       e.surface,
                       e.capacite,
                       e.estLibre == 1 ? "Libre" : "Occupe");
            }
        }

        fclose(f);
    }
}
/* FIN listeParType  */


/* 
   Fonction : rechercheTechnique
   Rôle : Recherche par surface et capacite
*/
void rechercheTechnique() {

    FILE *f = fopen("emplacements.dat", "rb");
    Emplacement e;
    float surfaceMin;
    int capaciteMin;

    if (f != NULL) {

        printf("Surface minimale : ");
        scanf("%f", &surfaceMin);

        printf("Capacite minimale : ");
        scanf("%d", &capaciteMin);

        while (fread(&e, sizeof(Emplacement), 1, f) == 1) {

            if (e.surface >= surfaceMin &&
                e.capacite >= capaciteMin &&
                e.numEmplacement != 0) {

                printf("Num: %d | Surface: %.2f | Capacite: %d\n",
                       e.numEmplacement,
                       e.surface,
                       e.capacite);
            }
        }

        fclose(f);
    }
}
/* FIN rechercheTechnique  */
