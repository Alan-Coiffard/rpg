#include "include.h"

armes_s creerArme(char nom[], int poid, int dureeVie, int degats, int distance){

	armes_s armes_tmp;
	objet_s obj = creerObjet(nom, poid, dureeVie);

	armes_tmp.caraObj = obj;
	armes_tmp.degats = degats;
	armes_tmp.distance = distance;

	return armes_tmp;
}

void afficherArmes(armes_s *armes){
	printf("L'objet : %s\npoid : %dKg\ndurée de vie : %d dégats\nDégats : %d\n", 
		armes->caraObj.nom, armes->caraObj.poid, armes->caraObj.dureeVie, armes->degats);
	if (armes->distance != 0)
	{
		printf("Armes à distance\n");
	} else printf("Armes corps à corps\n");
} 
