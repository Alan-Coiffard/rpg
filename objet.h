#ifndef __OBJH
#define __OBJH

#define TAILLECHAINE 255

struct objet {
	char nom[TAILLECHAINE];
	int poid;
	int dureeVie;
};
typedef struct objet objet_s;

objet_s creerObjet(char nom[TAILLECHAINE], int poid, int dureeVie);
void afficherObjet(objet_s *objet);


#endif