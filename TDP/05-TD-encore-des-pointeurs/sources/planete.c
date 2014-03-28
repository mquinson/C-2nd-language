#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_CAR 20

typedef struct {
  char nomPlanete[MAX_CAR];
  int rayon;
}Planete;

void Saisir(Planete *p);
Planete* Dupliquer(Planete p);

int main (){

  Planete p = {"Jupiter",3245},*ptr_p;
  printf("%s %d \n", p.nomPlanete, p.rayon);
  Saisir(&p);
  ptr_p = Dupliquer(p);
  printf("%s %d \n", ptr_p->nomPlanete, ptr_p->rayon);
  
  return 0;

}

void Saisir(Planete *p){
  
  printf("Donner nom planète : ");
  scanf ("%s",p->nomPlanete);
  printf("Donner son rayon : ");
  scanf ("%d",&p->rayon);
}

Planete* Dupliquer(Planete p){
  
  Planete *p1;
  p1 = (Planete *) malloc (sizeof(Planete));

  strcpy(p1->nomPlanete, p.nomPlanete);
  p1->rayon = p.rayon;

  return (p1);
}
