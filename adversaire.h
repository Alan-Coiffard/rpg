#ifndef __ADVH
#define __ADVH

  
#define BASEPVADV 150
#define TAILLECHAINE 255

struct caracteristiquesAdv {
	int force, vigilence, inteligence, vitalite, dexterite;
};
typedef struct caracteristiquesAdv caracteristiques_adv_s;

struct adversaire {
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	caracteristiques_adv_s caract;
	int pv;
};

typedef struct adversaire adversaire_s;

adversaire_s initAdversaire(char nom[], char prenom[]);

void voirAdversaire(adversaire_s *adversaire);


#endif