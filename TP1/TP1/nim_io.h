
/*******************************************************************************/
/*  NIM_IO.h                                                                  */
/*  Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM_IO */
/*******************************************************************************/

#pragma once
#include "nim.h"
#include "WinConsole.H"
int lire_entier(int min, int max);
/*Demande � l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement). La fonction doit valider la saisie et redemander
� l'usager de saisir une valeur jusqu'� l'obtention d'une valeur satisfaisante.
(Module NIM_IO)
*/

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select);

/*Affiche la configuration du plateau � l'�cran. Elle affiche chaque colonne en mettant une pi�ce (�toile) par ligne,
selon le nombre de pi�ces pr�sentes dans la colonne en question. Les num�ros de colonnes ainsi qu�une colonne de chiffres � gauche indiquant
le nombre de pi�ces sont �galement affich�s.
Important : Toutes les pi�ces se trouvant dans la colonne "col_select" sont affich�s en BLANC sur la couleur de fond ROUGE(la colonne s�lectionn�e).
Le positionnement et l�affichage de l��toile doit �tre fait avec une sous - fonction priv�e(static).On laisse une marge au haut de l��cran pour l�affichage
des messages et des saisies. (Module NIM_IO)
*/

static int choisir_colonne(int plateau[], int nb_colonnes);

/*Permet de choisir une colonne du plateau de jeu avec les touches fl�ch�es(gauche, droite) ou l�espace(� �).
Au d�part, on commence par la colonne[0].La colonne actuellement s�lectionn�e sera toujours affich�e en ROUGE avec la fonction "plateau_afficher".
Le choix d�finitif est fait avec la touche ENTER et on retourne le num�ro de la colonne choisie. (Module NIM_IO)*/

void tour_humain(int plateau[], int nb_colonnes);

/*D�clenche le tour de l'humain en demandant � l'usager de choisir la colonne(avec un appel � "choisir_colonne") et le nombre
de pi�ces � retirer du plateau de jeu.Une fois le choix effectu�, la fonction doit faire appel � "nim_jouer_tour" pour appliquer
les changements au plateau. (Module NIM_IO) */

void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*D�clenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur, on fait appel � la fonction "nim_choix_ia".

Une fois le choix effectu�, la fonction doit faire appel � "nim_jouer_tour" pour appliquer les changements au plateau. (Module NIM_IO)*/

void demarrer_jeu(int niveau);

/*Fonction qui contr�le le jeu de nim : elle donne la main, tour � tour, � chacun des deux joueurs et d�clare le gagnant une fois la partie termin�e.
On quitte cette fonction quand la partie est termin�e.
Pour donner la main aux joueurs, on appelle les fonctions "tour_humain" et "tour_ia" en alternance.Apr�s chaque tour,
cette fonction se charge de d�fragmenter le plateau de jeu, de modifier la taille du plateau � l'�cran et d'afficher
la nouvelle configuration du plateau de jeu.
NOTE : Le param�tre "niveau" est inutile pour l�instant. (Module NIM_IO)*/
