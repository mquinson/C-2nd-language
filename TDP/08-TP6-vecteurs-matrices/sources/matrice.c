#include <stdlib.h>

#include "matrice.h"

struct matrice {
  size_t l;
  size_t c;
  double **donnees;
  int dynamique;
};

matrice *allouer_matrice(size_t l, size_t c) {
  matrice *m;
  /* SOLUTION */
  unsigned i;

  m = malloc(sizeof(*m));
  if (!m)
    abort();

  m->donnees = malloc(sizeof(*m->donnees) * l);
  if (m->donnees == NULL)
	  abort();
  for (i = 0; i < l; i++) {
    m->donnees[i] = malloc(sizeof(*m->donnees[i]) * c);
    if (m->donnees[i] == NULL)
      abort();
  }

  m->l = l;
  m->c = c;
  m->dynamique = 0;
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
    resultat = & m->donnees[i][j];
  else if (m->dynamique == 0)
    resultat = NULL;
  else {

    if (i >= m->l) {
      size_t nouveau_l = i + 1;
      m->donnees = realloc(m->donnees, nouveau_l * sizeof(*m->donnees));
      if (m->donnees == NULL)
        abort();

      for (unsigned int k = m->l; k < nouveau_l; k++) {
        m->donnees[k] = malloc(sizeof(*m->donnees[k]) * m->c);
        if (m->donnees[k] == NULL)
          abort();
      }

      m->l = nouveau_l;
    }
    if (j >= m->c) {
      size_t nouveau_c = j + 1;
      for (unsigned int k = 0; k < m->l; k++) {
        m->donnees[k] = realloc(m->donnees[k], nouveau_c * sizeof(*m->donnees[k]));
        if (m->donnees[k] == NULL)
          abort();
      }
      m->c = nouveau_c;
    }

    resultat = & m->donnees[i][j];
  }
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

void matrice_rend_dynamique(matrice* m) {
  m->dynamique = 1;
}
