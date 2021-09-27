#include "include.h"

objet_s creerObjet(char nom[TAILLECHAINE], int poid, int dureeVie){
	objet_s obj_tmp;
	strcpy(obj_tmp.nom, nom);
	obj_tmp.poid 		= poid;
	obj_tmp.dureeVie 	= dureeVie;

	return obj_tmp;
}

void afficherObjet(objet_s *objet){
	printf("L'objet : %s\npoid : %dKg\ndurée de vie : %d dégats\n", objet->nom, objet->poid, objet->dureeVie);
}
