#ifndef VECTEUR_H
#define VECTEUR_H

#include <stddef.h>

typedef struct vector {
  size_t size;
  double* data;
  int dynamic; /* Ignoré jusqu'à la question 3 */
} vector_t;

/* description : alloue un vecteur en memoire
   parametres : la taille du vecteur
   valeur de retour : un vecteur de la taille demandee si l'allocation s'est
                      bien passee et le vecteur invalide si une erreur est survenue
   effets de bord : alloue de la memoire
*/
vector_t* vector_new(size_t size);

/* description : libere un vecteur precedemment alloue par alloue_vecteur
   parametres : le vecteur
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void vector_delete(vector_t* v);

/* description : retourne un pointeur vers l'element d'indice i du vecteur
   parametres : le vecteur, l'indice de l'element souhaite
   valeur de retour : un pointeur vers double
   effets de bord : aucun
*/
double* vector_celladdr(vector_t* v, unsigned int i);

/* description : retourne le nombre de cases d'un vecteur
   parametres : le vecteur
   valeur de retour : la taille du vecteur
   effets de bord : aucun
*/
size_t vector_size(const vector_t* v);

/* description: fait en sorte que le vecteur devienne dynamique
   (voir la question 3)
 */
void vector_set_dynamic(vector_t* v);

#endif
