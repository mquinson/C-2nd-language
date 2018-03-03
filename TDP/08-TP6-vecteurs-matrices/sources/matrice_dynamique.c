#include <stdlib.h>

#include "matrice_dynamique.h"

struct matrice {
  size_t l;
  size_t c;
  double **donnees;
};

matrice_t *allouer_matrice(size_t l, size_t c) {
  matrice_t *m;
  /* SOLUTION */
  unsigned i;

  m = malloc(sizeof(*m));
  if (!m)
    abort();

  m->donnees = malloc(sizeof(m->donnees) * l);
  if (!m->donnees)
    abort();

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

void liberer_matrice(matrice_t *m) {
  /* SOLUTION */
  unsigned i;

  for (i = 0; i < m->l; i++)
      free(m->donnees[i]);
  free(m->donnees);
  free(m);
  /* FIN */
}

double *acces_matrice(matrice_t *m, unsigned i, unsigned j) {
  double *resultat;
  /* SOLUTION */
  size_t nouveau_l, nouveau_c;
  unsigned k;
  double **nouvelle_matrice;
  double *nouvelle_ligne;

  if ((i<m->l) && (j<m->c))
    resultat = &m->donnees[i][j];
  else {
    if (i >= m->l) {
      nouveau_l = i + 1;
      nouvelle_matrice = realloc(m->donnees, nouveau_l * sizeof(*m->donnees));
      if (!nouvelle_matrice)
        abort();

      m->donnees = nouvelle_matrice;
      for (k = m->l; k < nouveau_l; k++) {
        m->donnees[k] = malloc(sizeof(*m->donnees[k]) * m->c);
        if (!m->donnees[k])
          abort();
      }

      m->l = nouveau_l;
    }
    if (j >= m->c) {
      nouveau_c = j + 1;
      for (k = 0; k < m->l; k++) {
        nouvelle_ligne = realloc(m->donnees[k], nouveau_c * sizeof(*m->donnees[k]));
        if (!nouvelle_ligne)
          abort();
        m->donnees[k] = nouvelle_ligne;
      }
      m->c = nouveau_c;
    }

    resultat = &m->donnees[i][j];
  }
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
