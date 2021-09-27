#include "include.h"

#define MAX 15
#define NBSTATS 5
#define STATMIN 5

void voirAdversaire(adversaire_s *perso){
	printf("Nom : %s - Prenom : %s - vie : %d\n", perso->nom, perso->prenom, perso->pv);
	printf("Stats :\n");
	printf(" - Force : %d\n", perso->caract.force);
	printf(" - Vigilence : %d\n", perso->caract.vigilence);
	printf(" - Inteligence : %d\n", perso->caract.inteligence);
	printf(" - Vitalite : %d\n", perso->caract.vitalite);
	printf(" - Dexterite : %d\n", perso->caract.dexterite);
}

adversaire_s initAdversaire(char nom[], char prenom[]){
	int stats[NBSTATS];
	srand(time(NULL));
	for (int i = 0; i < NBSTATS; ++i)
	{
		/* code */
		stats[i] = (rand() % MAX)+STATMIN;
	}

	adversaire_s adversaire;

	adversaire.caract.force 		= stats[0];
	adversaire.caract.vigilence 	= stats[1];
	adversaire.caract.inteligence 	= stats[2];
	adversaire.caract.vitalite 		= stats[3];
	adversaire.caract.dexterite 	= stats[4];

	adversaire.pv = BASEPVADV;
	strcpy(adversaire.prenom, prenom);
	strcpy(adversaire.nom, nom);
	// adversaire.prenom = prenom;
	// adversaire.nom = nom;
 

	//distribStats(&personnage.caract, stats);


	return adversaire;
}





