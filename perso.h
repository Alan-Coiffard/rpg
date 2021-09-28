#ifndef __PERSOH
#define __PERSOH
  
#define BASEPV 100
#define TAILLECHAINE 255
#define POIDMAX 120

#include "objet.h"
#include "armes.h"

struct caracteristiques {
	int force, vigilence, inteligence, vitalite, dexterite;
};
typedef struct caracteristiques caracteristiques_s;

struct perso {
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	caracteristiques_s caract;
	int pv;
	objet_s inventaire[200];
	int tailleInventaire;
	int poidInventaire;
	armes_s arme;
};

typedef struct perso perso_s;

perso_s initPerso();

void voirPerso(perso_s *personnage);

int ajoutObjet(objet_s *objet, perso_s *perso);

armes_s ajouterArme(armes_s *arme);

void prendreArme(perso_s *perso, armes_s *arme);

#endif