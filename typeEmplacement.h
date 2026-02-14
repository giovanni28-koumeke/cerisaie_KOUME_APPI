/*
*File name : typeEmplacement.h
*perpose : fichier de déclaration des prototypes des fonctions
*Authors : KOUMEKE Giovanni & APPIAH Samuel
*Created : 13/O2/2026
*Update : 13/02/2026
*/

#ifndef TYPE_EMPLACEMENT_H
#define TYPE_EMPLACEMENT_H

#define MAX_TYPES 10

/* Structure définissant une catégorie d'emplacement et son prix */
typedef struct {
    int codeType;               
    char nomType[20];           
    float prixJourPersonne;     
} Type_Emplacement;

/* Variables partagées entre les fichiers */
extern Type_Emplacement tabTypes[MAX_TYPES];
extern int nbTypes;

/* Fonctions de gestion du référentiel */
void chargerTypes();
void sauvegarderTypes();
void afficherTypes();
int trouverType(int code);

#endif // Fin du header