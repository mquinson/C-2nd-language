#include "matrice_dynamique.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c)
{
  matrice m;
  /* SOLUTION */
  int i, erreur=0;

  m = (matrice) malloc(sizeof(struct donnees_matrice));
  if (m != NULL)
    {
      m->donnees = (double **) malloc(sizeof(double *)*l);
      if (m->donnees == NULL)
        {
          free(m);
          m = NULL;
        }
      else
        {
          i=0;
          while ((i<l) && !erreur)
            {
              m->donnees[i] = (double *) malloc(sizeof(double)*c);
              if (m->donnees[i] == NULL)
                  erreur = 1;
              else
                  i++;
            }
          if (erreur)
            {
              while (i)
                {
                  i--;
                  free(m->donnees[i]);
                }
              free(m->donnees);
              free(m);
              m = NULL;
            }
          else
            {
              m->l = l;
              m->c = c;
            }
        }
    }
  else
      m = NULL;
  /* FIN */
  return m;
}

void liberer_matrice(matrice m)
{
  /* SOLUTION */
  int i;

  for (i=0; i<m->l; i++)
      free(m->donnees[i]);
  free(m->donnees);
  free(m);
  /* FIN */
}

int est_matrice_invalide(matrice m)
{
  int resultat;
  /* SOLUTION */
  resultat = (m->l==0) || (m->c == 0);
  /* FIN */
  return resultat;
}

double *acces_matrice(matrice m, int i, int j)
{
  double *resultat;
  /* SOLUTION */
  int nouveau_l, nouveau_c, k, erreur=0;
  double *nouveau_bloc;

  if ((i>=0) && (j>=0))
      if ((i<m->l) && (j<m->c))
          resultat = &m->donnees[i][j];
      else
        {
          if (i>=m->l)
            {
              nouveau_l = i+1;
              nouveau_bloc = realloc(m->donnees, nouveau_l*sizeof(double *));
              if (nouveau_bloc == NULL)
                  erreur = 1;
              else
                {
                  m->donnees = (double **) nouveau_bloc;
                  k = m->l;
                  while ((k<nouveau_l) && !erreur)
                    {
                      m->donnees[k] = (double *) malloc(sizeof(double)*m->c);
                      if (m->donnees[k] == NULL)
                          erreur = 1;
                      else
                          k++;
                    }
                  if (erreur)
                      while (k>m->l)
                        {
                          k--;
                          free(m->donnees[i]);
                        }
                  else
                      m->l = nouveau_l;
                }
            }
          if ((j>=m->c) && !erreur)
            {
              nouveau_c = j+1;
              k=0;
              while ((k<m->l) && !erreur)
                {
                  nouveau_bloc = realloc(m->donnees[k], nouveau_c*sizeof(double));
                  if (nouveau_bloc == NULL)
                      erreur = 1;
                  else
                    {
                      m->donnees[k] = (double *) nouveau_bloc;
                      k++; 
                    }
                }
              if (!erreur)
                  m->c = nouveau_c;
            }
          if (!erreur)
              resultat = &m->donnees[i][j];
          else
              resultat = NULL;
        }
  else
      resultat = NULL;
  /* FIN */
  return resultat;
}

int nb_lignes_matrice(matrice m)
{
  int resultat;
  /* SOLUTION */
  resultat = m->l;
  /* FIN */
  return resultat;
}

int nb_colonnes_matrice(matrice m)
{
  int resultat;
  /* SOLUTION */
  resultat = m->c;
  /* FIN */
  return resultat;
}
