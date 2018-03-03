#include <stdlib.h>

#include "matrice_lineaire.h"

struct matrice {
  size_t l;
  size_t c;
  double* donnees;
  int dynamique;
};

matrice_t* allouer_matrice(size_t l, size_t c) {
  matrice_t* m;
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

void liberer_matrice(matrice_t* m) {
  /* SOLUTION */
  free(m->donnees);
  free(m);
  /* FIN */
}

double* acces_matrice(matrice_t* m, unsigned int i, unsigned int j) {
  double* resultat = NULL;
  /* SOLUTION */
  if (i < m->l && j < m->c)
    resultat = m->donnees + i * m->c + j;
  else if (m->dynamique) {
    size_t nouveau_l = (i >= m->l) ? i + 1 : m->l;
    size_t nouveau_c = (j >= m->c) ? j + 1 : m->c;
    double* nouveau_bloc = malloc(sizeof(*m->donnees) * nouveau_l * nouveau_c);
    if (!nouveau_bloc) {
      abort();
    }
    for (unsigned int k = 0; k < m->l; k++)
      for (unsigned int l = 0; l < m->c; l++)
        nouveau_bloc[k * nouveau_c + l] = m->donnees[k * m->c + l];
    free(m->donnees);
    m->donnees = nouveau_bloc;
    m->l = nouveau_l;
    m->c = nouveau_c;
    resultat = m->donnees + i * m->c + j;

  } else {
    resultat = NULL;
  }
  /* FIN */
  return resultat;
}

size_t nb_lignes_matrice(const matrice_t* m) {
  size_t resultat = 0;
  /* SOLUTION */
  resultat = m->l;
  /* FIN */
  return resultat;
}

size_t nb_colonnes_matrice(const matrice_t* m) {
  size_t resultat = 0;
  /* SOLUTION */
  resultat = m->c;
  /* FIN */
  return resultat;
}

void matrice_rend_dynamique(matrice_t* m) {
  m->dynamique = 1;
}
