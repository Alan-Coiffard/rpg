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

void choixUn(perso_s *monPerso, adversaire_s *monAdversaire){
		/* code */ 
	int degat = attaque(monPerso, monAdversaire);
	messagePause("Il prend ", degat);
	monAdversaire->pv = monAdversaire->pv - degat;

	degat = attaqueEnnemie(monAdversaire, monPerso);
	messagePause("Tu prend ", degat);
	monPerso->pv = monPerso->pv - degat;
}

void choixDeux(perso_s *monPerso, adversaire_s *monAdversaire){
	soins(monPerso);

	int degat = attaqueEnnemie(monAdversaire, monPerso);
	messagePause("Tu prend ", degat);
	monPerso->pv = monPerso->pv - degat;
}

void voirVie(perso_s *personnage, adversaire_s *adversaire){
	printf("Mes pv : %d | Ses pv : %d\n", personnage->pv, adversaire->pv);
}

void combat(perso_s *monPerso, adversaire_s *monAdversaire){
	int reponse;
	while(monAdversaire->pv > 0 || monPerso->pv > 0 || reponse == 0){
		printf("\033[H\033[2J");
		voirVie(monPerso, monAdversaire);
		printf("Actions : \n");
		printf(" - Fuite 	-> 0\n");
		printf(" - Attaque 	-> 1\n");
		printf(" - Soin 	-> 2\n");
		scanf("%d", &reponse);
		if (reponse == 0)
		{
			break;
		}
		switch(reponse)
	   	{
		   	case 1 : choixUn(monPerso, monAdversaire); break;
		   	case 2 : choixDeux(monPerso, monAdversaire); break;
		   	default : printf("erreur interne du logiciel numéro %d invalide\n", reponse);
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
	printf("\033[H\033[2J");
	voirAdversaire(&monAdversaire);
	printf("\n");
	combat(&monPerso, &monAdversaire);
	voirPerso(&monPerso);
	voirAdversaire(&monAdversaire);

}

int main(void)
{

	start();

  	return(EXIT_SUCCESS);
}


