#include <stdlib.h>

#include "vecteur.h"

vecteur_t* allouer_vecteur(size_t taille) {
  vecteur_t* v = NULL;
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

void liberer_vecteur(vecteur_t* v) {
  /* SOLUTION */
  free(v->donnees);
  free(v);
  /* FIN */
}

double* acces_vecteur(vecteur_t* v, unsigned int i) {
  double* resultat = NULL;
  /* SOLUTION */
  if (i >= v->taille && v->dynamique) {
    resultat = v->donnees + i;
    size_t nouvelle_taille = v->taille * 2;
    while (i >= nouvelle_taille)
    	nouvelle_taille *= 2;
    double* nouveau_bloc = realloc(v->donnees, nouvelle_taille * sizeof(*v->donnees));
    if (nouveau_bloc == NULL) {
    	abort();
    }
    v->donnees = nouveau_bloc;
    v->taille = nouvelle_taille;
  }
  if (i < v->taille)
	  resultat = v->donnees + i;
  else
	  resultat = NULL;
  /* FIN */
  return resultat;
}

size_t taille_vecteur(const vecteur_t* v) {
  size_t resultat = 0;
  /* SOLUTION */
  resultat = v->taille;
  /* FIN */
  return resultat;
}

void vecteur_rend_dynamique(vecteur_t* v) {
  v->dynamique = 1;
}
