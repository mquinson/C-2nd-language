#ifndef MATRICE_H
#define MATRICE_H

typedef struct matrice matrice_t;

/*
   allouer_matrice
   description : alloue une matrice en memoire
   parametres : le nombre de lignes et de colones de la matrice
   valeur de retour : une matrice de la taille demandee si l'allocation s'est
                      bien passee et la matrice invalide si une erreur est survenue
   effets de bord : alloue de la memoire
*/
matrice_t *allouer_matrice(size_t l, size_t c);

/*
   liberer_matrice
   description : libere une matrice precedemment allouee par alloue_matrice
   parametres : la matrice
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void liberer_matrice(matrice_t *m);

/*
   acces_matrice
   description : retourne un pointeur vers l'element d'indice i de la matrice
   parametres : la matrice, les indices de l'element souhaite
   valeur de retour : un pointeur vers double
   effets de bord : aucun
*/
double *acces_matrice(matrice_t *m, unsigned i, unsigned j);

/*
   nb_lignes_matrice
   description : retourne le nombre de lignes d'une matrice
   parametres : la matrice
   valeur de retour : le nombre de lignes
   effets de bord : aucun
*/
size_t nb_lignes_matrice(const matrice_t *m);

/*
   nb_colonnes_matrice
   description : retourne le nombre de colonnes d'une matrice
   parametres : la matrice
   valeur de retour : le nombre de colonnes
   effets de bord : aucun
*/
size_t nb_colonnes_matrice(const matrice_t *m);

/* description: fait en sorte que la matrice devienne dynamique
   (voir la question 3)
 */
void matrice_rend_dynamique(matrice_t* m);

#endif
