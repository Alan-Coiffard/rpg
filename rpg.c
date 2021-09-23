#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 20
#define MIN 1

#include "perso.h"
#include "adversaire.h"

int tirageAlea(){
	srand(time(NULL));
	
	return (rand() % (MAX + 1 - MIN)) + MIN;;
}

void messagePause(char message[], int tirage){
	if (tirage >= 0)
	{
		printf("%s %d \n(\"entrer\" pour continuez)\n", message, tirage);
	}else {
		printf("%s \n(\"entrer\" pour continuez)\n", message);
	}
	while(1){
		if(getchar()==10 || getchar()==13) break;//32==esp
	}
}

int attaque(perso_s *personnage, adversaire_s *adversaire){
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
	if (tirageMonPerso == 0 && tirageMonAdv != 0)
	{
		/* code */
		messagePause("Réussite critique...", -1);
		return personnage->caract.force * 3;
	}
	if (tirageMonPerso != 0 && tirageMonAdv == 0)
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

int defense(int degat, adversaire_s monAdversaire){
	messagePause("Ton adversaire fait un jet de vitalite", -1);
	
	int tirageVitaAdver = tirageAlea();
	if (1)
	{
		/* code */
		printf(" coucou ");
	}
}

int attaqueEnnemie(adversaire_s *adversaire, perso_s *personnage){
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

void choixUn(perso_s *monPerso, adversaire_s *monAdversaire){
		/* code */
	int degat = attaque(monPerso, monAdversaire);
	messagePause("Il prend ", degat);
	monAdversaire->pv = monAdversaire->pv - degat;

	degat = attaqueEnnemie(monAdversaire, monPerso);
	messagePause("Tu prend ", degat);
	monPerso->pv = monPerso->pv - degat;
}


void combat(perso_s *monPerso, adversaire_s *monAdversaire){
	int reponse;
	while(monAdversaire->pv > 0 || monPerso->pv > 0 || reponse == 0){
		printf("Veut tu attaquer ? 1 oui - 0 non\n");
		scanf("%d", &reponse);
		if (reponse == 0)
		{
			break;
		}
		switch(reponse)
	   	{
		   	case 1 : choixUn(monPerso, monAdversaire); break;
		   	case 2 : printf("WIP\n"); break;
		   	default : printf("erreur interne du logiciel numéro xx\n");
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


