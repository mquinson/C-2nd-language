#ifndef VECTEUR_H
#define VECTEUR_H

#include <stddef.h>

typedef struct donnees_vecteur {
  size_t taille;
  double *donnees;
} vecteur_t;

/*
   allouer_vecteur
   description : alloue un vecteur en memoire
   parametres : la taille du vecteur
   valeur de retour : un vecteur de la taille demandee si l'allocation s'est
                      bien passee et le vecteur invalide si une erreur est survenue
   effets de bord : alloue de la memoire
*/
vecteur_t* allouer_vecteur(size_t taille);

/*
   liberer_vecteur
   description : libere un vecteur precedemment alloue par alloue_vecteur
   parametres : le vecteur
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void liberer_vecteur(vecteur_t* v);

/*
   acces_vecteur
   description : retourne un pointeur vers l'element d'indice i du vecteur
   parametres : le vecteur, l'indice de l'element souhaite
   valeur de retour : un pointeur vers double
   effets de bord : aucun
*/
double* acces_vecteur(vecteur_t* v, unsigned i);

/*
   taille_vecteur
   description : retourne le nombre de composantes d'un vecteur
   parametres : le vecteur
   valeur de retour : la taille du vecteur
   effets de bord : aucun
*/
size_t taille_vecteur(const vecteur_t* v);

#endif
