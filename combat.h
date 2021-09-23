#ifndef __COMBATH
#define __COMBATH
#include "adversaire.h"
#include "perso.h"  

int tirageAlea();
void messagePause(char message[], int tirage);
int attaque(perso_s *personnage, adversaire_s *adversaire);
void soins(perso_s *personnage);
int attaqueEnnemie(adversaire_s *adversaire, perso_s *personnage);


#endif