#include "vecteur.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille)
{
  vecteur v;
  /* SOLUTION */
  v.donnees = (double *) malloc(sizeof(double)*taille);
  if (v.donnees == NULL)
      v.taille = 0;
  else
      v.taille = taille;
  /* FIN */
  return v;
}

void liberer_vecteur(vecteur v)
{
  /* SOLUTION */
  free(v.donnees);
  /* FIN */
}

int est_vecteur_invalide(vecteur v)
{
  int resultat;
  /* SOLUTION */
  resultat = v.taille == 0;
  /* FIN  */
  return resultat;
}

double *acces_vecteur(vecteur v, int i)
{
  double *resultat;
  /* SOLUTION */
  resultat = v.donnees+i;
  /* FIN */
  return resultat;
}

int taille_vecteur(vecteur v)
{
  int resultat;
  /* SOLUTION */
  resultat = v.taille;
  /* FIN */
  return resultat;
}
