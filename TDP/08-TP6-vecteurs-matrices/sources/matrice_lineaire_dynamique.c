#include "matrice_lineaire_dynamique.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c)
{
  matrice m;
  /* SOLUTION */
  m = (matrice) malloc(sizeof(struct donnees_matrice));
  if (m != NULL)
    {
      m->donnees = (double *) malloc(sizeof(double)*l*c);
      if (m->donnees == NULL)
        {
          free(m);
          m = NULL;
        }
      else
        {
          m->l = l;
          m->c = c;
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
  int nouveau_l, nouveau_c, k, l;
  double *nouveau_bloc;

  if ((i<0) || (j<0))
      resultat = NULL;
  else
      if ((i >= m->l) || (j >= m->c))
        {
          nouveau_l = (i>=m->l)?i+1:m->l;
          nouveau_c = (j>=m->c)?j+1:m->c;
          nouveau_bloc = (double *) malloc(sizeof(double)*nouveau_l*nouveau_c);
          if (nouveau_bloc != NULL)
            {
              for (k=0; k<m->l; k++)
                  for (l=0; l<m->c; l++)
                      nouveau_bloc[k*nouveau_c+l] = m->donnees[k*m->c+l];
              free(m->donnees);
              m->donnees = nouveau_bloc;
              m->l = nouveau_l;
              m->c = nouveau_c;
              resultat = m->donnees+i*m->c+j;
            }
          else
              resultat = NULL;
        }
      else
          resultat = m->donnees+i*m->c+j;
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
