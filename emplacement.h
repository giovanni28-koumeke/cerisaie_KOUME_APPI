/*
*File name : emplacement.h
*perpose : fichier  de déclaration des prototypes des fonctions
*Authors : KOUMEKE Giovanni & APPIAH Samuel
*Created : 13/O2/2026
*Update : 14/02/2026
*/

#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

/* Structure définissant un emplacement du camping */
typedef struct {
    int numEmplacement;
    float surface;
    int capacite;
    int codeType;      // clé étrangère vers Type_Emplacement
    int estLibre;      // 1 = libre | 0 = occupé
} Emplacement;

/* Modules de gestion du parc */
void ajouterEmplacement();
void modifierEmplacement();
void supprimerEmplacement();
void afficherEmplacements();

/* Modules de disponibilité */
void attribuerEmplacement();
void libererEmplacement();

/* Modules consultation */
void listeParType();
void rechercheTechnique();

#endif
