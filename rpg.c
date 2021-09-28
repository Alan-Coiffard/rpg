#include "include.h"

#define MAX 20
#define MIN 1

void clear(){
	printf("\033[H\033[2J");
}

void start(){
	printf("Bienvenue sur ce RPG en c\n");
	
	perso_s monPerso = initPerso();
	//voirPerso(&monPerso);
	adversaire_s monAdversaire = initAdversaire("ITA", "Algo");
	printf("Bonjour %s. Votre premier adversaire est : \n", monPerso.prenom);
	clear();
	//voirAdversaire(&monAdversaire);
	//printf("\n");
	combat(&monPerso, &monAdversaire);
	//voirPerso(&monPerso);
	//voirAdversaire(&monAdversaire);
	
	objet_s premierObjet = creerObjet("table", 10, 10);
	objet_s lourdObjet = creerObjet("table", 120, 210);
	afficherObjet(&premierObjet);
	afficherObjet(&lourdObjet);
	ajoutObjet(&premierObjet, &monPerso);
	voirPerso(&monPerso);
	ajoutObjet(&lourdObjet, &monPerso);
	voirPerso(&monPerso);
//arme(char nom[], int poid, int dureeVie, int degats, int distance);
/*
	armes_s monArme = creerArme("épée", 5, 50, 25, 0);
	afficherArmes(&monArme);
	armes_s monArme2 = creerArme("arc", 5, 50, 25, 1);
	afficherArmes(&monArme2);
*/

}

int main(void)
{

	start();

  	return(EXIT_SUCCESS);
}


