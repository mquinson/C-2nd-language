#ifndef VECTEUR_H
#define VECTEUR_H

#include <stddef.h>

typedef struct vector {
  size_t taille;
  double* donnees;
  int dynamique; /* Ignoré jusqu'à la question 3 */
} vecteur_t;

/* description : alloue un vecteur en memoire
   parametres : la taille du vecteur
   valeur de retour : un vecteur de la taille demandee si l'allocation s'est
                      bien passee et le vecteur invalide si une erreur est survenue
   effets de bord : alloue de la memoire
*/
vecteur_t* allouer_vecteur(size_t taille);

/* description : libere un vecteur precedemment alloue par alloue_vecteur
   parametres : le vecteur
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void liberer_vecteur(vecteur_t* v);

/* description : retourne un pointeur vers l'element d'indice i du vecteur
   parametres : le vecteur, l'indice de l'element souhaite
   valeur de retour : un pointeur vers double
   effets de bord : aucun
*/
double* acces_vecteur(vecteur_t* v, unsigned i);

/* description : retourne le nombre de cases d'un vecteur
   parametres : le vecteur
   valeur de retour : la taille du vecteur
   effets de bord : aucun
*/
size_t taille_vecteur(const vecteur_t* v);

/* description: fait en sorte que le vecteur devienne dynamique
   (voir la question 3)
 */
void vecteur_rend_dynamique(vecteur_t* v);

#endif
