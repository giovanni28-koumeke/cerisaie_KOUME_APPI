/*
*File name : main.c
*perpose : fichier d'appelle des fonctions
*Authors : KOUMEKE Giovanni & APPIAH Samuel
*Created : 13/O2/2026
*Update : 13/02/2026
*/
#include <stdio.h>
#include "typeEmplacement.h"
#include "emplacement.h"

int main() {

    int choix = -1;

    chargerTypes();

    while (choix != 0) {

        printf("\n===== MENU PRINCIPAL - LA CERISAIE =====\n");
        printf("1. Voir les tarifs\n");
        printf("2. Ajouter emplacement\n");
        printf("3. Modifier emplacement\n");
        printf("4. Supprimer emplacement\n");
        printf("5. Afficher tous les emplacements\n");
        printf("6. Attribuer emplacement\n");
        printf("7. Liberer emplacement\n");
        printf("8. Liste par type\n");
        printf("9. Recherche technique\n");
        printf("0. Quitter et sauvegarder\n");
        printf("Choix : ");

        scanf("%d", &choix);

        if (choix == 1) {
            afficherTypes();
        }
        else if (choix == 2) {
            ajouterEmplacement();
        }
        else if (choix == 3) {
            modifierEmplacement();
        }
        else if (choix == 4) {
            supprimerEmplacement();
        }
        else if (choix == 5) {
            afficherEmplacements();
        }
        else if (choix == 6) {
            attribuerEmplacement();
        }
        else if (choix == 7) {
            libererEmplacement();
        }
        else if (choix == 8) {
            listeParType();
        }
        else if (choix == 9) {
            rechercheTechnique();
        }
        else if (choix == 0) {
            sauvegarderTypes();
            printf("Donnees enregistrees. Fin du programme.\n");
        }
        else {
            printf("Option non reconnue.\n");
        }
    }

}
