#ifndef __ARMESH
#define __ARMESH

#include "objet.h"

struct armes {
	objet_s caraObj;
	int degats;
	int distance;
};
typedef struct armes armes_s;

armes_s creerArme(char nom[], int poid, int dureeVie, int degats, int distance);
void afficherArmes(armes_s *armes);


#endif