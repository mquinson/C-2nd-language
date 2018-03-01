#include <stdlib.h>

#include "vecteur_dynamique.h"

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
  double *nouveau_bloc;
  size_t nouvelle_taille;

  if (i >= v->taille) {
    nouvelle_taille = v->taille * 2;
    while (i >= nouvelle_taille)
      nouvelle_taille *= 2;
    nouveau_bloc = realloc(v->donnees, nouvelle_taille * sizeof(*v->donnees));
    if (!nouveau_bloc) {
      abort();
    }
    v->donnees = nouveau_bloc;
    v->taille = nouvelle_taille;
    resultat = v->donnees + i;
  } else
    resultat = v->donnees + i;
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
