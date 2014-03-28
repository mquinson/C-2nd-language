#include <stdio.h>
#include <malloc.h>

//char *couleur[6] = {"rouge", "vert", "bleu", "blanc", "noir","jaune"};
char *couleur[6];

int main(){
  int i; 
  char c; char *s;

  couleur[0] = malloc (sizeof("rouge"));
  couleur[0] = "rouge";
  //  couleur[0][0]='r';couleur[0][1]='o';couleur[0][2]='u';
  // couleur[0][3]='g';couleur[0][4]='e';couleur[0][5]='\0';
  
  //free(couleur[0]);

  c= *(*couleur+2);
  s = malloc (10*sizeof(char));
  s = *couleur+2;
  printf("%s %c\n\n",s,c);

  printf("%s \t %c %c\n\n", couleur[0], couleur[0][0], *couleur[0]);


  //c = *(*(couleur+5) + 3);
  //s = *(couleur+5) + 3;
  //printf("%s %c\n\n",s,c);
  
  
  //  printf("couleur = %p *couleur %s\n", couleur,*couleur);

  /*for (i=0;i< 5;i++)
    printf ("couleur[%d] = %p\n",i, couleur[i]);
  */
  
  //printf("couleur + 2 = %p\t *(couleur+2) %s *couleur[2] %s *couleur+2 %s\n", couleur + 2,*(couleur+2), couleur[2], *couleur+2);

  //printf("*(*(couleur+5) + 3) %c\n",*(*(couleur+5) + 3));

  //printf("*couleur+2 %c\n",*couleur+2);

}
