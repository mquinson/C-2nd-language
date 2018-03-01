#include <stdlib.h>

#include "vecteur.h"

vecteur *allouer_vecteur(size_t taille) {
  vecteur *v;
  /* SOLUTION */
  v = malloc(sizeof(*v));
  if (!v)
    abort();

  v->donnees = malloc(sizeof(*v->donnees) * taille);
  if (!v->donnees)
    abort();

  v->taille = taille;
  /* FIN */
  return v;
}

void liberer_vecteur(vecteur *v) {
  /* SOLUTION */
  free(v->donnees);
  free(v);
  /* FIN */
}

double *acces_vecteur(vecteur *v, unsigned i) {
  double *resultat;
  /* SOLUTION */
  if (i < v->taille)
    resultat = v->donnees + i;
  else
    resultat = NULL;
  /* FIN */
  return resultat;
}

size_t taille_vecteur(const vecteur *v) {
  size_t resultat;
  /* SOLUTION */
  resultat = v->taille;
  /* FIN */
  return resultat;
}
