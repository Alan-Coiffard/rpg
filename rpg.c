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
	//voirPerso(&monPerso);

	//init de l'adversaire de facon alea
	adversaire_s monAdversaire = initAdversaire("Un", "méchant");

	//création d'objet	
	objet_s premierObjet = creerObjet("chaise", 10, 10);
	objet_s lourdObjet = creerObjet("table", 120, 210);

	//création arme
	armes_s monArme = creerArme("épée", 5, 50, 25, 0);

	clear();
	int reponse;
	
	while(1){

		printf("Pour aller plus loins : \n");
		printf("-1 - stop\n");
		printf("0 - combat\n");
		printf("1 - arme\n");
		printf("2 - objets\n");
		printf("3 - afficher perso\n");
		scanf("%d", &reponse);
		if (reponse == -1)
		{
			/* code */
			break;
		}
		switch(reponse)
	   	{
		   	case 0 : clear(); combat(&monPerso, &monAdversaire); 	break;
		   	case 1 : clear(); prendreArme(&monPerso, &monArme); 	break;
		   	case 2 : clear(); ajoutObjet(&lourdObjet, &monPerso);	break;
		   	case 3 : clear(); voirPerso(&monPerso);					break;
		   	default : printf("erreur interne du logiciel numéro %d invalide\n", reponse);
	   	}
	}



}

int main(void)
{

	start();

  	return(EXIT_SUCCESS);
}


