#include "include.h"

#define MAX 20
#define MIN 1

void clear(){
	printf("\033[H\033[2J");
}

void start(){
	printf("Bienvenue sur ce RPG en c\n");
	
	//init du perso principal
	perso_s monPerso = initPerso();
	voirPerso(&monPerso);

	//init de l'adversaire de facon alea
	adversaire_s monAdversaire = initAdversaire("Un", "méchant");

	//mise en place du combat
	//combat(&monPerso, &monAdversaire);

	//création d'objet et test de l'ajout et suppression	
	objet_s premierObjet = creerObjet("chaise", 10, 10);
	objet_s lourdObjet = creerObjet("table", 120, 210);
	//afficherObjet(&premierObjet);
	//afficherObjet(&lourdObjet);
	//ajoutObjet(&premierObjet, &monPerso);
	//voirPerso(&monPerso);
	//ajoutObjet(&lourdObjet, &monPerso);
	//voirPerso(&monPerso);

//definition des arme avec arguments
//arme(char nom[], int poid, int dureeVie, int degats, int distance);

/*
	armes_s monArme = creerArme("épée", 5, 50, 25, 0);
	prendreArme(&monPerso, &monArme);
	voirPerso(&monPerso);
*/


}

int main(void)
{

	start();

  	return(EXIT_SUCCESS);
}


