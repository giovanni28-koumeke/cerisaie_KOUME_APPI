/*
*File name : typeEmplacement.c
*perpose : fichier d'implatation des fonctions
*Authors : KOUMEKE Giovanni & APPIAH Samuel
*Created : 13/O2/2026
*Update : 13/02/2026
*/

#include <stdio.h>
#include <string.h>
#include "typeEmplacement.h"

Type_Emplacement tabTypes[MAX_TYPES];
int nbTypes = 0;

/* Module : Charge les données du fichier binaire vers le tableau RAM */
void chargerTypes() {
    FILE *f = fopen("types.dat", "rb");
    nbTypes = 0;
    
    if (f != NULL) {
        int stop = 0; // Drapeau pour contrôler la boucle
        
        while (stop == 0 && nbTypes < MAX_TYPES) {
            // fread renvoie le nombre d'éléments lus (doit être 1)
            if (fread(&tabTypes[nbTypes], sizeof(Type_Emplacement), 1, f) != 1) {
                stop = 1; 
            } else {
                nbTypes++;
            } // fin if lecture
        } // fin while
        
        fclose(f);
    } else {
        printf("Info : Fichier 'types.dat' non trouve.\n");
    } // fin if fichier
} // fin fonction chargerTypes

/* Module : Sauvegarde le tableau RAM vers le fichier binaire */
void sauvegarderTypes() {
    FILE *f = fopen("types.dat", "wb");
    
    if (f != NULL) {
        fwrite(tabTypes, sizeof(Type_Emplacement), nbTypes, f);
        fclose(f);
    } // fin if
} // fin fonction sauvegarderTypes

/* Module : Affiche la liste des tarifs stockés en mémoire */
void afficherTypes() {
    int i = 0;
    printf("\n--- LISTE DES TARIFS (TYPE D'EMPLACEMENT) ---\n");
    
    while (i < nbTypes) {
        printf("Code: %d | Nom: %-12s | Prix: %.2f EUR/jour/pers\n", 
                tabTypes[i].codeType, 
                tabTypes[i].nomType, 
                tabTypes[i].prixJourPersonne);
        i++;
    } // fin while
} // fin fonction afficherTypes

/* Module : Recherche un type par son code et retourne son indice */
int trouverType(int code) {
    int indiceTrouve = -1;
    int i = 0;
    
    while (i < nbTypes && indiceTrouve == -1) {
        if (tabTypes[i].codeType == code) {
            indiceTrouve = i;
        } // fin if
        i++;
    } // fin while
    
    return indiceTrouve;
} // fin fonction trouverType