#pragma once
/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM */
/*******************************************************************************/

#include "codage_numerique.h"
#include "m_distributions.h"

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

void plateau_init(int plateau[], int nb_colonnes);

//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre al�atoire de pi�ces entre 1 et PLATEAU_MAX_PIECES = 35. (Module NIM)


int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne,
    int nb_pieces);
/*Applique des changements � la configuration du plateau de jeu en retirant "nb_pieces" de la colonne "colonne" du plateau.
La fonction s'assure que le jeu est valide et renvoie Vrai si le jeu d�sir� a pu s'appliquer � la configuration actuelle du jeu.
Pour �tre valide, la colonne doit exister et nombre de pi�ces retir�es doit �tre <= au nombre de pi�ces actuellement pr�sentes dans la colonne en question. (Module NIM)
*/

void plateau_supprimer_colonne(int plateau[], int nb_colonnes,
    int col_a_supprimer);

/*Supprime la colonne "col_a_supprimer" du plateau.On devra donc copier les valeurs de toutes les colonnes suivantes du plateau d�une position vers la gauche. (Module NIM)*/

int plateau_defragmenter(int plateau[], int nb_colonnes);

/*Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne".Le nombre de colonnes restant est retourn�. (Module NIM)*/

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes,
    int* choix_colonne, int* choix_nb_pieces);

/*Fonction qui effectue un jeu al�atoire en choisissant au hasard une colonne, puis au hasard le nombre de pi�ces � jouer de cette colonne. (Module NIM)*/

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau,
    int* choix_colonne, int* choix_nb_pieces);

/*Fonction qui d�termine quel doit �tre le jeu de l'ordinateur. Cette fonction impl�mente l'algorithme intelligent d�crit dans la partie 2 du TP.
Le choix de l'ordinateur sera stock� dans les deux r�f�rences "choix_colonne" et "choix_nb_pieces".

Si une erreur de produit, la fonction stocke la valeur aberrante - 1 dans les deux r�f�rences "choix_colonne" et "choix_nb_pieces".
NOTE : Dans la premi�re partie du TP, "niveau" est inutile et la fonction se contentera d�appeler la fonction "nim_choix_ia_aleatoire". (Module NIM)
*/
