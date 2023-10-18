
/*******************************************************************************/
/*  NIM_IO.h                                                                  */
/*  Ce module contient les fonctions necéssaires à l'implémantation du jeu NIM_IO */
/*******************************************************************************/

#pragma once
#include "nim.h"
#include "WinConsole.H"
int lire_entier(int min, int max);
/*Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement). La fonction doit valider la saisie et redemander
à l'usager de saisir une valeur jusqu'à l'obtention d'une valeur satisfaisante.
(Module NIM_IO)
*/

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select);

/*Affiche la configuration du plateau à l'écran. Elle affiche chaque colonne en mettant une pièce (étoile) par ligne,
selon le nombre de pièces présentes dans la colonne en question. Les numéros de colonnes ainsi qu’une colonne de chiffres à gauche indiquant
le nombre de pièces sont également affichés.
Important : Toutes les pièces se trouvant dans la colonne "col_select" sont affichés en BLANC sur la couleur de fond ROUGE(la colonne sélectionnée).
Le positionnement et l’affichage de l’étoile doit être fait avec une sous - fonction privée(static).On laisse une marge au haut de l’écran pour l’affichage
des messages et des saisies. (Module NIM_IO)
*/

static int choisir_colonne(int plateau[], int nb_colonnes);

/*Permet de choisir une colonne du plateau de jeu avec les touches fléchées(gauche, droite) ou l’espace(‘ ‘).
Au départ, on commence par la colonne[0].La colonne actuellement sélectionnée sera toujours affichée en ROUGE avec la fonction "plateau_afficher".
Le choix définitif est fait avec la touche ENTER et on retourne le numéro de la colonne choisie. (Module NIM_IO)*/

void tour_humain(int plateau[], int nb_colonnes);

/*Déclenche le tour de l'humain en demandant à l'usager de choisir la colonne(avec un appel à "choisir_colonne") et le nombre
de pièces à retirer du plateau de jeu.Une fois le choix effectué, la fonction doit faire appel à "nim_jouer_tour" pour appliquer
les changements au plateau. (Module NIM_IO) */

void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*Déclenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur, on fait appel à la fonction "nim_choix_ia".

Une fois le choix effectué, la fonction doit faire appel à "nim_jouer_tour" pour appliquer les changements au plateau. (Module NIM_IO)*/

void demarrer_jeu(int niveau);

/*Fonction qui contrôle le jeu de nim : elle donne la main, tour à tour, à chacun des deux joueurs et déclare le gagnant une fois la partie terminée.
On quitte cette fonction quand la partie est terminée.
Pour donner la main aux joueurs, on appelle les fonctions "tour_humain" et "tour_ia" en alternance.Après chaque tour,
cette fonction se charge de défragmenter le plateau de jeu, de modifier la taille du plateau à l'écran et d'afficher
la nouvelle configuration du plateau de jeu.
NOTE : Le paramètre "niveau" est inutile pour l’instant. (Module NIM_IO)*/
