#include "nim_io.h"

int lire_entier(int min, int max) {
	/*Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement). La fonction doit valider la saisie et redemander
	à l'usager de saisir une valeur jusqu'à l'obtention d'une valeur satisfaisante.
	(Module NIM_IO)
	*/
	int entier = 0;

	do {
		printf("\n Saisir une valeur entre : %d et %d\n", min, max);
		scanf("%d", &entier);

		if (entier > max || entier < min) {
			printf("\n Valeur incorrecte, recommencez svp");
		}

	} while (entier < min || entier > max);

	return entier;

}