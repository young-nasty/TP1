#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "nim_io.h"
#include "WinConsole.H"
#include "m_distributions.h"

int main(void){
	int choix, i, nb_colonnes;
	int plateau[PLATEAU_MAX_COLONNES] = { 0 };

	printf("Quelle fonction voulez-vous tester?\n1. plateau_init\n");
	scanf("%d", &choix);

	switch (choix) {
	case 1 :
		printf("Choisissez un nombre de colonnes entre 1 et %d: ", PLATEAU_MAX_COLONNES);
		scanf("%d", &nb_colonnes);

		plateau_init(plateau, nb_colonnes);

		for (i = 0; i < nb_colonnes; i++) {
			printf("%d\n", plateau[i]);
		}
		system("pause");
		break;
	default :
		break;
	}

}