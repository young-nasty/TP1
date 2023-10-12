
#include "nim.h"

void plateau_init(int plateau[], int nb_colonnes) {
	srand(time(NULL));

	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = rand() % (PLATEAU_MAX_PIECES - 1 + 1) + 1;
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
