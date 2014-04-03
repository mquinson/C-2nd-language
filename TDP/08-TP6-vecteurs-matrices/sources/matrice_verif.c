#include "matrice.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c)
{
  matrice m;
  /* SOLUTION */
  int i, erreur=0;

  m.donnees = (double **) malloc(sizeof(double *)*l);
  if (m.donnees == NULL)
    {
      m.l = 0;
      m.c = 0;
    }
  else
    {
      i=0;
      while ((i<l) && !erreur)
        {
          m.donnees[i] = (double *) malloc(sizeof(double)*c);
          if (m.donnees[i] == NULL)
              erreur = 1;
          else
              i++;
        }
      if (erreur)
        {
          while (i)
            {
              i--;
              free(m.donnees[i]);
            }
          free(m.donnees);
          m.l = 0;
          m.c = 0;
        }
      else
        {
          m.l = l;
          m.c = c;
        }
    }
  /* FIN */
  return m;
}

void liberer_matrice(matrice m)
{
  /* SOLUTION */
  int i;

  for (i=0; i<m.l; i++)
      free(m.donnees[i]);
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
  if ((i>=0) && (j>=0) && (i<m.l) && (j<m.c))
      resultat = &m.donnees[i][j];
  else
      resultat = NULL;
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
