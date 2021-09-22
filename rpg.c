#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 20

#include "perso.h"
#include "adversaire.h"

int tirageAlea(){
	srand(time(NULL));
	
	return (rand() % MAX);
}

void messagePause(char message[], int tirage){
	if (tirage >= 0)
	{
		printf("%s %d \n(entrez espace pour continuez)", message, tirage);
	}else {
		printf("%s \n(entrez espace pour continuez)", message);
	}
	while(1){
		if(getchar()==32) break;//27==esc
	}
}

int attaque(perso_s *personnage, adversaire_s *adversaire){
	messagePause("Fais un jet de dexterite", -1);
	
	int tirageMonPerso 	= tirageAlea();

	messagePause("Tu as fais", tirageMonPerso);

	int tirageMonAdv	= tirageAlea();


	if (tirageMonAdv > adversaire->caract.dexterite)
	{
		/* code */
		if (tirageMonAdv == 20)
		{
			/* code */
			messagePause("Ton adversaire a totalement raté...", -1);
			return tirageAlea() * 3;
		}
		if (tirageMonPerso < personnage->caract.dexterite)
		{
			/* code */
			messagePause("Ton adversaire a esquivé...", -1);
			return 0;
		}
		messagePause("Tu as touché ton adversaire", -1);
		return tirageAlea() * 1.5;
	}
	messagePause("Tu as touché ton adversaire", -1);
	int diffMonPerso = personnage->caract.dexterite - tirageMonPerso;
	int diffMonAdv = adversaire->caract.dexterite - tirageMonAdv;
	if (diffMonPerso > diffMonAdv)
	{
		/* code */
		return tirageAlea() * 1;
	}else {
		return tirageAlea() * 0.5;
	}
}
int attaqueEnnemie(adversaire_s *adversaire, perso_s *personnage){
	messagePause("Fais un jet de dexterite", -1);
	
	int tirageMonPerso 	= tirageAlea();

	messagePause("Tu as fais", tirageMonPerso);

	int tirageMonAdv	= tirageAlea();


	if (tirageMonPerso > personnage->caract.dexterite)
	{
		/* code */
		if (tirageMonPerso == 20)
		{
			/* code */
			messagePause("Tu as totalement raté...", -1);
			return tirageAlea() * 3;
		}
		if (tirageMonPerso < personnage->caract.dexterite)
		{
			/* code */
			messagePause("Tu as esquivé...", -1);
			return 0;
		}
		messagePause("Tu as été touché par ton adversaire", -1);
		return tirageAlea() * 1.5;
	}
	messagePause("Tu as été touché par ton adversaire", -1);
	int diffMonPerso = personnage->caract.dexterite - tirageMonPerso;
	int diffMonAdv = adversaire->caract.dexterite - tirageMonAdv;
	if (diffMonPerso > diffMonAdv)
	{
		/* code */
		return tirageAlea() * 1;
	}else {
		return tirageAlea() * 0.5;
	}
}


void combat(perso_s *monPerso, adversaire_s *monAdversaire){
	while(monAdversaire->pv > 0 || monPerso->pv > 0){
		int reponse;
		printf("Veut tu attaquer ? 1 oui - 0 non\n");
		scanf("%d", &reponse);
		if (reponse != 0)
		{
			/* code */
			int degat = attaque(monPerso, monAdversaire);
			messagePause("Il prend ", degat);
			monAdversaire->pv = monAdversaire->pv - degat;

			degat = attaqueEnnemie(monAdversaire, monPerso);
			messagePause("Tu prend ", degat);
			monPerso->pv = monPerso->pv - degat;
		} else {
			break;
		}
	}
	//monPerso.pv -= attaque(&monAdversaire, &monPerso);
}

void start(){
	printf("Bienvenue sur ce RPG en c\n");
	perso_s monPerso = initPerso();
	//voirPerso(&monPerso);
	adversaire_s monAdversaire = initAdversaire("ITA", "Algo");
	printf("Bonjour %s. Votre premier adversaire est : \n", monPerso.prenom);
	voirAdversaire(&monAdversaire);

	combat(&monPerso, &monAdversaire);
	voirPerso(&monPerso);
	voirAdversaire(&monAdversaire);

}

int main(void)
{

	start();

  	return(EXIT_SUCCESS);
}


