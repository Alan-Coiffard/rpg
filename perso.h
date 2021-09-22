#ifndef __PERSOH
#define __PERSOH
  
#define BASEPV 100
#define TAILLECHAINE 255

struct caracteristiques {
	int force, vigilence, inteligence, vitalite, dexterite;
};
typedef struct caracteristiques caracteristiques_s;

struct perso {
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	caracteristiques_s caract;
	int pv;
};

typedef struct perso perso_s;

perso_s initPerso();

void voirPerso(perso_s *personnage);



#endif