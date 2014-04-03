#include "vecteur_dynamique.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille)
{
  vecteur v;
  /* SOLUTION */
  v = (vecteur) malloc(sizeof(struct donnees_vecteur));
  if (v == NULL)
      return NULL;
  else
    {
      v->donnees = (double *) malloc(sizeof(double)*taille);
      if (v->donnees == NULL)
        {
          free(v);
          v = NULL;
        }
      else
        {
          v->taille = taille;
        }
    }
  /* FIN */
  return v;
}

void liberer_vecteur(vecteur v)
{
  /* SOLUTION */
  free(v->donnees);
  free(v);
  /* FIN */
}

int est_vecteur_invalide(vecteur v)
{
  int resultat;
  /* SOLUTION */
  resultat = v == NULL;
  /* FIN */
  return resultat;
}

double *acces_vecteur(vecteur v, int i)
{
  double *resultat;
  /* SOLUTION */
  double *nouveau_bloc;
  int nouvelle_taille;

  if (i<0)
      resultat = NULL;
  else
    {
      if (i >= v->taille)
        {
          nouvelle_taille = v->taille*2;
          while (i>=nouvelle_taille)
              nouvelle_taille *= 2;
          nouveau_bloc = realloc(v->donnees, nouvelle_taille*sizeof(double));
          if (nouveau_bloc == NULL)
              resultat = NULL;
          else
            {
              v->donnees = nouveau_bloc;
              v->taille = nouvelle_taille;
              resultat = v->donnees+i;
            }
        }
      else
          resultat = v->donnees+i;
    }
  /* FIN */
  return resultat;
}

int taille_vecteur(vecteur v)
{
  int resultat;
  /* SOLUTION */
  resultat = v->taille;
  /* FIN */
  return resultat;
}
