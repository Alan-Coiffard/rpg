#include "include.h"

#define MAX 15
#define NBSTATS 5
#define STATMIN 5

void afficheTableau(int stats[]){
	for (int i = 0; i < NBSTATS; ++i)
	{
		/* code */
		printf(" %d | ",stats[i]);
	}
	printf("\n");
}

int statTrouve(int stat[], int val){
	int valeurChoisie;
	if (val < STATMIN)
	{
		/* code */
		return -1;
	}
	for (int i = 0; i < NBSTATS; ++i)
	{
		if (stat[i] == val)
		{
			/* code */
			valeurChoisie = stat[i];
			stat[i] = 0;
			return valeurChoisie;
		}
	}
	return -1;
}

int statAdd(caracteristiques_s *cara, int tirage[]){
	afficheTableau(tirage);
	int stat;
	scanf("%d", &stat);
	int res = statTrouve(tirage, stat);
	while(res == -1)
	{
		/* code */
		printf("Veuillez choisir une stat du tableau et qui n'a pas été déjà utilisée\n");
		scanf("%d", &stat);
		res = statTrouve(tirage, stat);
	}
	return res;
} 

void distribStats(caracteristiques_s *cara, int tirage[]){
	printf("Les caractéristiques : \n| force, vigilence, inteligence, vitalite, dexterite |\n");
		printf("Combien de force voulez vous ?\n");
	cara->force = statAdd(cara, tirage);
		printf("Combien de vigilence voulez vous ?\n");
	cara->vigilence = statAdd(cara, tirage);
		printf("Combien de inteligence voulez vous ?\n");
	cara->inteligence = statAdd(cara, tirage);
		printf("Combien de vitalite voulez vous ?\n");
	cara->vitalite = statAdd(cara, tirage);
		printf("Combien de dexterite voulez vous ?\n");
	cara->dexterite = statAdd(cara, tirage);


}

void voirPerso(perso_s *perso){
	printf("Nom : %s - Prenom : %s - vie : %d\n", perso->nom, perso->prenom, perso->pv);
	printf("Stats :\n");
	printf(" - Force : %d\n", perso->caract.force);
	printf(" - Vigilence : %d\n", perso->caract.vigilence);
	printf(" - Inteligence : %d\n", perso->caract.inteligence);
	printf(" - Vitalite : %d\n", perso->caract.vitalite);
	printf(" - Dexterite : %d\n", perso->caract.dexterite);
}

perso_s initPerso(){
	
	int stats[NBSTATS];
	srand(time(NULL));
	for (int i = 0; i < NBSTATS; ++i)
	{
		/* code */
		stats[i] = (rand() % MAX)+STATMIN;
	}

	perso_s personnage;

	personnage.pv = BASEPV;


	printf("Quel est votre prenom ?\n");
	scanf("%s", personnage.prenom);

	printf("Quel est votre nom ?\n");
	scanf("%s", personnage.nom);
	
	printf("Tirage des stat du personnage...\n");



	distribStats(&personnage.caract, stats);


	return personnage;
}





