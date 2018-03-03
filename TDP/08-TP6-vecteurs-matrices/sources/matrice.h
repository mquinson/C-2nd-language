#ifndef MATRICE_H
#define MATRICE_H

/* La structure matrix_t est opaque: son implémentation est privée, cachée dans matrice.c */
typedef struct matrix matrix_t;

/*
   description : alloue une matrice en memoire
   parametres : le nombre de lignes et de colones de la matrice
   valeur de retour : une matrice de la taille demandee si l'allocation s'est
                      bien passee et la matrice invalide si une erreur est survenue
   effets de bord : alloue de la memoire
*/
matrix_t* matrix_new(size_t l, size_t c);

/*
   description : libere une matrice precedemment allouee par alloue_matrice
   parametres : la matrice
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void matrix_delete(matrix_t* m);

/*
   description : retourne un pointeur vers l'element d'indice i de la matrice
   parametres : la matrice, les indices de l'element souhaite
   valeur de retour : un pointeur vers double
   effets de bord : aucun
*/
double* matrix_celladdr(matrix_t* m, unsigned int i, unsigned int j);

/*
   description : retourne le nombre de lignes d'une matrice
   parametres : la matrice
   valeur de retour : le nombre de lignes
   effets de bord : aucun
*/
size_t matrix_get_linesamount(const matrix_t* m);

/*
   description : retourne le nombre de colonnes d'une matrice
   parametres : la matrice
   valeur de retour : le nombre de colonnes
   effets de bord : aucun
*/
size_t matrix_get_rowsamount(const matrix_t* m);

/* description: fait en sorte que la matrice devienne dynamique
   (voir la question 3)
*/
void matrix_set_dynamic(matrix_t* m);

#endif
