 🏕️ Système de Gestion de Camping - La Cerisaie

📌 Présentation du Projet

Ce projet est une solution digitale développée en langage C pour automatiser la gestion quotidienne du camping "La Cerisaie". Il permet de gérer efficacement le parc d'emplacements, les tarifs et les séjours des clients, remplaçant ainsi les anciens processus manuels.

Ce travail a été réalisé dans le cadre d'un projet académique visant à mettre en pratique les concepts de modularisation, de structures de données et de manipulation de fichiers binaires à accès direct.

🚀 Fonctionnalités Implémentées

1. Fonctionnalité : Initialisation et Persistance
Cette fonctionnalité assure la rapidité des recherches demandée par l'énoncé.


Module de Chargement : Au démarrage, extrait les données de types.dat (caravane, tente, etc.) pour les placer dans un tableau en mémoire vive.


Module de Déchargement : Avant de quitter, enregistre les éventuelles modifications du tableau vers le fichier types.dat.

2. Fonctionnalité : Mise à jour du Parc
Permet d'administrer les ressources matérielles du camping.


Module d'Ajout : Enregistre un nouvel emplacement dans le fichier binaire avec sa surface et sa capacité.

Module de Modification : Permet de mettre à jour les caractéristiques techniques ou le type d'un emplacement spécifique via un accès direct par son numéro.

Module de Suppression : Désactive un emplacement (suppression logique) pour qu'il ne soit plus attribuable lors d'un séjour.

3. Fonctionnalité : Gestion de la Disponibilité
Répond au besoin de la direction d'attribuer un emplacement à l'arrivée d'un client.


Module d'Attribution : Recherche un emplacement libre correspondant au type souhaité et capable d'accueillir le nombre de personnes du groupe.


Module de Libération : Remet l'état de l'emplacement à "Libre" lors du départ du client et de l'édition de la facture.

4. Fonctionnalité : Consultation et Statistiques

Module de Liste par Type : Affiche tous les emplacements appartenant à une catégorie tarifaire précise (ex: tous les Bungalows).


Module de Recherche Technique : Permet de trouver un emplacement selon des critères de surface ou de capacité maximale

🛠 Architecture Technique

Le projet suit une approche modulaire pour garantir un code propre et maintenable :

typeEmplacement.h / .c : Gère le référentiel des catégories (Tente, Bungalow, etc.) et les prix.

emplacement.h / .c :  Gère les caractéristiques physiques des terrains.

main.c : Orchestre le menu principal et le flux de données.

📊 Jeu d'Essai (Données de Test)

Pour tester le programme, : nous avons préparer un jeu d'éssai que se trouve dans un autre fichier.

💻 Installation et Utilisation

Prérequis
Un compilateur C (GCC recommandé).

Compilation
Ouvrez votre terminal dans le dossier du projet et tapez : gcc main.c typeEmplacement.c emplacement.c -o camping

Exécution

📜 Principes de Codage Appliqués

Zéro Sauts Brusques : Aucune utilisation de break, continue ou return à l'intérieur des boucles pour garantir une logique fluide.

Documentation : Chaque bloc de code (if, while, fonctions) est commenté pour faciliter la lecture.

Gestion des Fichiers : Utilisation du mode binaire (rb, wb) pour l'intégrité des données.

👥 Auteur 

  KOUMEKE Koami Simon Giovanni
  
  APPIAH Kwame Nana Ayete Samuel
