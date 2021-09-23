#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 20
#define MIN 1

#include "perso.h"
#include "adversaire.h"
#include "combat.h"

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