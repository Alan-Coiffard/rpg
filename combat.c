#include "include.h"


#define MAX 20
#define MIN 1


int tirageAlea(){
	srand(time(NULL));
	
	return (rand() % (MAX + 1 - MIN)) + MIN;;
}

void messagePause(char message[], int tirage){
	if (tirage >= 0)
	{
		printf("%s %d\n", message, tirage);
	}else {
		printf("%s\n", message);
	}
	while(1){
		if(getchar()==10 || getchar()==13) break;//32==esp
	}
}

int attaque(perso_s *personnage, adversaire_s *adversaire){
	printf("\033[H\033[2J");
	printf("Tu attaque\n");
	messagePause("Fais un jet de dexterite", -1);
	
	int tirageMonPerso 	= tirageAlea();

	messagePause("Tu as fais", tirageMonPerso);

	int tirageMonAdv	= tirageAlea();

	if (tirageMonPerso == MAX)
	{
		/* code */
		messagePause("Tu as raté totalement...", -1);
		personnage->pv -= 10;
		return 0;
	}
	if (tirageMonAdv == MAX)
	{
		/* code */
		messagePause("Ton adversaire a totalement raté...", -1);
		return personnage->caract.force * 3;
	}
	if (tirageMonPerso == MIN && tirageMonAdv != MIN)
	{
		/* code */
		messagePause("Réussite critique...", -1);
		return personnage->caract.force * 3;
	}
	if (tirageMonPerso != MIN && tirageMonAdv == MIN)
	{
		/* code */
		messagePause("Ton adversaire a esquivé...", -1);
		return 0;
	}
	
	int diffMonPerso = personnage->caract.dexterite - tirageMonPerso;
	int diffMonAdv = adversaire->caract.dexterite - tirageMonAdv;
	if (diffMonPerso > diffMonAdv)
	{
		/* code */
		messagePause("Tu as touché ton adversaire", -1);
		return personnage->caract.force * 1;
	}else {
		messagePause("Tu as raté ton adversaire...", -1);
		return 0;
	}
}

void soins(perso_s *personnage){
	printf("\033[H\033[2J");
	messagePause("Fais un jet d'intélligence", -1);
	
	int tirageMonPerso 	= tirageAlea();

	messagePause("Tu as fais", tirageMonPerso);

	if (tirageMonPerso == MAX)
	{
		/* code */
		messagePause("Echec critique...", -1);
		printf("Tu perd 20 pv\n");
		personnage->pv -= 20;
	}
	if (tirageMonPerso == MIN)
	{
		/* code */
		messagePause("Réussite critique...", -1);
		printf("Tu gagne 50 pv\n");
		if ((personnage->pv + 50) > 100)
		{
			/* code */
			personnage->pv = 100;
		}else personnage->pv += 50;
	}
	if (tirageMonPerso <= personnage->caract.inteligence)
	{
		/* code */
		printf("Tu gagne %d pv\n", personnage->caract.inteligence);
		messagePause("", -1);
		if ((personnage->pv + personnage->caract.inteligence) > 100)
		{
			/* code */
			messagePause("Tu es au max de tes pv", -1);
			personnage->pv = 100;
		}else personnage->pv += personnage->caract.inteligence;		
	} else {
		messagePause("Tu ne récupère pas de pv", -1);
	}

}

int attaqueEnnemie(adversaire_s *adversaire, perso_s *personnage){
	printf("\033[H\033[2J");
	printf("Il attaque\n");
	
	messagePause("Fais un jet de dexterite", -1);
	
	int tirageMonPerso 	= tirageAlea();

	messagePause("Tu as fais", tirageMonPerso);

	int tirageMonAdv	= tirageAlea();

	if (tirageMonPerso == MAX)
	{
		/* code */
		messagePause("Tu as raté totalement...", -1);
		return adversaire->caract.force * 3;

	}
	if (tirageMonAdv == MAX)
	{
		/* code */
		messagePause("Ton adversaire a totalement raté...", -1);
		adversaire->pv -= 10;
		return 0;	
	}
	if (tirageMonPerso == MIN && tirageMonAdv != MIN)
	{
		/* code */
		messagePause("Réussite critique...", -1);
		return 0;
	}
	if (tirageMonPerso != MIN && tirageMonAdv == MIN)
	{
		/* code */
		messagePause("Ton adversaire est fort...", -1);
		return adversaire->caract.force * 3;
	}
	int diffMonPerso = personnage->caract.dexterite - tirageMonPerso;
	int diffMonAdv = adversaire->caract.dexterite - tirageMonAdv;
	if (diffMonPerso > diffMonAdv)
	{
		/* code */
		messagePause("Tu as esquivé...", -1);
		return 0;
	}else {
		messagePause("Tu n'as pas esquivé...", -1);
		return adversaire->caract.force * 1;
	}
}

int choixUn(perso_s *monPerso, adversaire_s *monAdversaire){
		/* code */ 
	int degat = attaque(monPerso, monAdversaire);
	messagePause("Il prend ", degat);
	monAdversaire->pv = monAdversaire->pv - degat;
	if (monAdversaire->pv <= 0)
	{
		/* code */
		messagePause("Bien joué, tu viens de battre ton premier adversaire !", -1);
		return -1;
	}


	degat = attaqueEnnemie(monAdversaire, monPerso);
	messagePause("Tu prend ", degat);
	monPerso->pv = monPerso->pv - degat;
	if (monPerso->pv <= 0)
	{
		/* code */
		messagePause("You died !", -1);
		return -1;
	}
}

int choixDeux(perso_s *monPerso, adversaire_s *monAdversaire){
	soins(monPerso);

	int degat = attaqueEnnemie(monAdversaire, monPerso);
	messagePause("Tu prend ", degat);
	monPerso->pv = monPerso->pv - degat;
	if (monPerso->pv <= 0)
	{
		/* code */
		messagePause("You died !", -1);
		return -1;
	}
}

void voirVie(perso_s *personnage, adversaire_s *adversaire){
	printf("Mes pv : %d | Ses pv : %d\n", personnage->pv, adversaire->pv);
}

void combat(perso_s *monPerso, adversaire_s *monAdversaire){
	int reponse;
	int result = 0;
	while(monAdversaire->pv > 0 || monPerso->pv > 0 || reponse == 0){
		printf("\033[H\033[2J");
		if (result == -1)
		{
			/* code */
			break;
		}
		voirVie(monPerso, monAdversaire);
		printf("Actions : \n");
		printf(" - Fuite 	-> 0\n");
		printf(" - Attaque 	-> 1\n");
		printf(" - Soin 	-> 2\n");
		scanf("%d", &reponse);
		printf("%d\n", result);
		if (reponse == 0)
		{
			break;
		}
		switch(reponse)
	   	{
		   	case 1 : result = choixUn(monPerso, monAdversaire); break;
		   	case 2 : result = choixDeux(monPerso, monAdversaire); break;
		   	default : printf("erreur interne du logiciel numéro %d invalide\n", reponse);
	   	}
	}
}