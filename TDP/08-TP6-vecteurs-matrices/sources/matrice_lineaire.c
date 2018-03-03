#include <stdlib.h>

#include "matrice_lineaire.h"

struct matrice {
  size_t l;
  size_t c;
  double *donnees;
};

matrice_t *allouer_matrice(size_t l, size_t c) {
  matrice_t *m;
  /* SOLUTION */
  m = malloc(sizeof(*m));
  if (!m)
    abort();

  m->donnees = malloc(sizeof(*m->donnees) * l * c);
  if (!m->donnees)
    abort();

  m->l = l;
  m->c = c;
  /* FIN */
  return m;
}

void liberer_matrice(matrice_t *m) {
  /* SOLUTION */
  free(m->donnees);
  free(m);
  /* FIN */
}

double *acces_matrice(matrice_t *m, unsigned i, unsigned j) {
  double *resultat;
  /* SOLUTION */
  if (i < m->l && j < m->c)
    resultat = m->donnees + i * m->c + j;
  else
    resultat = NULL;
  /* FIN */
  return resultat;
}

size_t nb_lignes_matrice(const matrice_t *m) {
  size_t resultat;
  /* SOLUTION */
  resultat = m->l;
  /* FIN */
  return resultat;
}

size_t nb_colonnes_matrice(const matrice_t *m) {
  size_t resultat;
  /* SOLUTION */
  resultat = m->c;
  /* FIN */
  return resultat;
}
