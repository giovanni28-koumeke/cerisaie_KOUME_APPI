/*
*File name : main.c
*perpose : fichier d'appelle des fonctions
*Authors : KOUMEKE Giovanni & APPIAH Samuel
*Created : 13/O2/2026
*Update : 13/02/2026
*/

#include <stdio.h>
#include "typeEmplacement.h"

int main() {
    int choix = -1;

    // Initialisation au démarrage
    chargerTypes();

    // Boucle principale du programme
    while (choix != 0) {
        printf("\nMENU PRINCIPAL - LA CERISAIE\n");
        printf("1. Voir les tarifs\n");
        printf("0. Quitter et sauvegarder\n");
        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            afficherTypes();
        } else if (choix == 0) {
            sauvegarderTypes();
            printf("Donnees enregistrees. Fin du programme.\n");
        } else {
            printf("Option non reconnue.\n");
        } // fin if choix
    } // fin while principal

    return 0;
} // fin fonction main