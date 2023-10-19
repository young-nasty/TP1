
#include "nim.h"

void plateau_init(int plateau[], int nb_colonnes) {
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randint(1, PLATEAU_MAX_PIECES);
	}
}

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne,
	int nb_pieces) {

	if (colonne <= nb_colonnes && nb_pieces <= plateau[colonne]) {
		plateau[colonne] = plateau[colonne] - nb_pieces;
		return TRUE;
	}
	else {
		return FALSE;
	}

}

void plateau_supprimer_colonne(int plateau[], int nb_colonnes,
	int col_a_supprimer) {
	int i;

	for (i = 0; i < nb_colonnes - col_a_supprimer; i++) {
		plateau[col_a_supprimer + i] = plateau[col_a_supprimer + i + 1];
	}
}

int plateau_defragmenter(int plateau[], int nb_colonnes) {
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		if (!plateau[i])
			plateau_supprimer_colonne(plateau, nb_colonnes, i);
			nb_colonnes = nb_colonnes - 1;
	}

	return nb_colonnes;
}

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes,
	int* choix_colonne, int* choix_nb_pieces) {

	*choix_colonne = md_randint(0, (nb_colonnes - 1));
	*choix_nb_pieces = md_randint(1, plateau[*choix_colonne]);
}

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau,
	int* choix_colonne, int* choix_nb_pieces) {
	


	switch (niveau) {
	case 0 : 
		nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
		break;

	case 1 :
		if (md_randint(0, 1)) {
			// ia intelligent ici
		}
		else
		{
			nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
		}
		break;

	case 2 : 
		// ia intelligent ici
		break;

	default: 
		*choix_colonne = -1;
		*choix_nb_pieces = -1;
	}
}