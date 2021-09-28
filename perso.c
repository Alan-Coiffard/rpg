#include "include.h"

#define MAX 15
#define NBSTATS 5
#define STATMIN 5
#define INVENTAIREPLEIN 120

void voirInventaire(perso_s *perso){
	printf("\nInventaire : %d/%d kg\n", perso->poidInventaire, POIDMAX);
	for (int i = 0; i < perso->tailleInventaire; ++i)
	{
		/* code */
		printf("%d -> %s | %d kg| %d pv\n", i, perso->inventaire[i].nom, perso->inventaire[i].poid, perso->inventaire[i].dureeVie);
	}
}

int calculPoidInventaire(perso_s *perso){
	int tailleInventaire = perso->tailleInventaire;
	int poid = 0;
	for (int i = 0; i < tailleInventaire; ++i)
	{
		/* code */
		poid = perso->inventaire[i].poid;
	}
	return poid;
}

int inventairePlein(perso_s *perso, objet_s *objet){
	if (calculPoidInventaire(perso) + objet->poid > INVENTAIREPLEIN)
	{
		/* code */
		return -1;
	}
	return 0;
}

int ajoutObjet(objet_s *objet, perso_s *perso){
//	int res = inventairePlein(perso);
//	printf("debug %d\n", res);
	while(inventairePlein(perso, objet) == -1)
	{
		/* code */
		printf("L'objet %s est trop lourd (%d kg)\nPlace dans l'inventaire : %d/%d\n", objet->nom, objet->poid, perso->poidInventaire, POIDMAX);
		printf("Voulez vous enlever des objets dans votre inventaire ?(0 - oui | 1 - non)\n");
		int reponse;
		scanf("%d", &reponse);
		if (reponse == 1)
		{
			/* code */
			break;
		}
		reponse = -1;
		voirInventaire(perso);
		printf("Selectionnez le numéro de l'objet a supprimer : (-1 pour annuler)\n");
		scanf("%d", &reponse);
		while(reponse > perso->tailleInventaire-1){
			printf("Selectionnez un element dans l'inventaire (-1 pour annuler)\n");
			scanf("%d", &reponse);
		}
		perso->inventaire[reponse].poid = perso->inventaire[perso->tailleInventaire-1].poid;
		perso->inventaire[reponse].dureeVie = perso->inventaire[perso->tailleInventaire-1].dureeVie;
		strcpy(perso->inventaire[reponse].nom, perso->inventaire[perso->tailleInventaire-1].nom);
		perso->tailleInventaire -= 1;
		break;
	}
	if (inventairePlein(perso, objet) != -1)
	{
		/* code */
		perso->inventaire[perso->tailleInventaire].poid = objet->poid;
		perso->inventaire[perso->tailleInventaire].dureeVie = objet->dureeVie;
		strcpy(perso->inventaire[perso->tailleInventaire].nom, objet->nom);
		perso->tailleInventaire += 1;
		perso->poidInventaire += objet->poid;
		printf("Vous avez récupéré l'objet %s\n", objet->nom);
	}else {
		printf("Vous n'avez pas récupéré l'objet %s\n", objet->nom);
	}

	return 0;
}

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
	voirInventaire(perso);
}

int aleatoire(int min, int max){
	return (rand() % max) + min;
}

perso_s initPerso(){
	
	int stats[NBSTATS];
	srand(time(NULL));
	for (int i = 0; i < NBSTATS; ++i)
	{
		/* code */
		stats[i] = aleatoire(STATMIN, MAX);
	}

	perso_s personnage;

	personnage.pv = BASEPV;
	personnage.tailleInventaire = 0;
	personnage.poidInventaire = 0;


	printf("Quel est votre prenom ?\n");
	scanf("%s", personnage.prenom);

	printf("Quel est votre nom ?\n");
	scanf("%s", personnage.nom);
	
	printf("Tirage des stat du personnage...\n");



	distribStats(&personnage.caract, stats);


	return personnage;
}





