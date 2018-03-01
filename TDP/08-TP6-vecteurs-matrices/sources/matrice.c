#include <stdlib.h>

#include "matrice.h"

struct matrice {
  size_t l;
  size_t c;
  double **donnees;
};

matrice *allouer_matrice(size_t l, size_t c) {
  matrice *m;
  /* SOLUTION */
  unsigned i;

  m = malloc(sizeof(*m));
  if (!m)
    abort();

  m->donnees = malloc(sizeof(*m->donnees) * l);
  for (i = 0; i < l; i++) {
    m->donnees[i] = malloc(sizeof(*m->donnees[i]) * c);
    if (!m->donnees[i])
      abort();
  }

  m->l = l;
  m->c = c;
  /* FIN */
  return m;
}

void liberer_matrice(matrice *m) {
  /* SOLUTION */
  unsigned i;

  for (i = 0; i < m->l; i++) {
    free(m->donnees[i]);
  }
  free(m->donnees);
  free(m);
  /* FIN */
}

double *acces_matrice(matrice *m, unsigned i, unsigned j) {
  double *resultat;
  /* SOLUTION */
  if (i < m->l && j < m->c)
    resultat = m->donnees[i] + j;
  else
    resultat = NULL;
  /* FIN */
  return resultat;
}

size_t nb_lignes_matrice(const matrice *m) {
  size_t resultat;
  /* SOLUTION */
  resultat = m->l;
  /* FIN */
  return resultat;
}

size_t nb_colonnes_matrice(const matrice *m) {
  size_t resultat;
  /* SOLUTION */
  resultat = m->c;
  /* FIN */
  return resultat;
}
