
#include "nim.h"

void plateau_init(int plateau[], int nb_colonnes) {
	srand(time(NULL));

	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = rand() % (PLATEAU_MAX_PIECES - 1 + 1) + 1;
	}
}