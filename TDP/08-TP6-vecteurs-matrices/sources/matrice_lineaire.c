#include "matrice_lineaire.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c)
{
  matrice m;
  /* SOLUTION */
  m.donnees = (double *) malloc(sizeof(double)*l*c);
  if (m.donnees == NULL)
    {
      m.l = 0;
      m.c = 0;
    }
  else
    {
      m.l = l;
      m.c = c;
    }
  /* FIN */
  return m;
}

void liberer_matrice(matrice m)
{
  /* SOLUTION */
  free(m.donnees);
  /* FIN */
}

int est_matrice_invalide(matrice m)
{
  int resultat;
  /* SOLUTION */
  resultat = (m.l==0) || (m.c == 0);
  /* FIN */
  return resultat;
}

double *acces_matrice(matrice m, int i, int j)
{
  double *resultat;
  /* SOLUTION */
  resultat = m.donnees+i*m.c+j;
  /* FIN */
  return resultat;
}

int nb_lignes_matrice(matrice m)
{
  int resultat;
  /* SOLUTION */
  resultat = m.l;
  /* FIN */
  return resultat;
}

int nb_colonnes_matrice(matrice m)
{
  int resultat;
  /* SOLUTION */
  resultat = m.c;
  /* FIN */
  return resultat;
}
