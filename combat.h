#ifndef __COMBATH
#define __COMBATH
#include "include.h"

int tirageAlea();
void messagePause(char message[], int tirage);
int attaque(perso_s *personnage, adversaire_s *adversaire);
void soins(perso_s *personnage);
int attaqueEnnemie(adversaire_s *adversaire, perso_s *personnage);

int choixUn(perso_s *monPerso, adversaire_s *monAdversaire);
int choixDeux(perso_s *monPerso, adversaire_s *monAdversaire);

void voirVie(perso_s *personnage, adversaire_s *adversaire);

void combat(perso_s *monPerso, adversaire_s *monAdversaire);



#endif