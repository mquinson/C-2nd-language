#ifndef MEMORY_OPERATIONS_H
#define MEMORY_OPERATIONS_H

#include <stddef.h>

/*
   description : copie une zone memoire vers un autre emplacement
                 les zones ne doivent pas se recouvrir (cf. man)
   parametres : deux pointeurs respectivement vers la zone destination et source
                ainsi que la taille de la zone
   valeur de retour : la valeur initiale du pointeur vers la zone destination
   effets de bord : modifie le contenu de la memoire
*/
void* my_memcpy(void* dst, const void* src, size_t len);

/*
   description : copie une zone memoire vers un autre emplacement
                 les zones peuvent se recouvrir (cf. man)
   parametres : deux pointeurs respectivement vers la zone destination et source
                ainsi que la taille de la zone
   valeur de retour : la valeur initiale du pointeur vers la zone destination
   effets de bord : modifie le contenu de la memoire
*/
void* my_memmove(void* dst, const void* src, size_t len);

/*
   description : retourne 1 si la machine sur laquelle s'execute la fonction
                 utilise la convention de stockage little endian (poids faible
                 en premier), 0 sinon
   parametres : aucun
   valeur de retour : 1 pour une machine en little endian
                      0 sinon
   effets de bord : aucun
*/
int is_little_endian(void);

/*
   description : transforme une donnee representee en little endian en donnee
                 representee en big endian et inversement
   parametres : un entier a convertir
   valeur de retour : l'entier convertit
   effets de bord : aucun
*/
int reverse_endianess(int value);

#endif
