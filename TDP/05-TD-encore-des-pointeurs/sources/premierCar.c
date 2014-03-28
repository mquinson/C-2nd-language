#include <stdio.h>


char *PremierCar(char c, char *ptrCar){
  
  do
    if (*ptrCar == c)
      return (ptrCar);
  while (*ptrCar++);

  return (NULL);
}

int main(int argc, char * argv[]){

  char c, *str, *adrPremCar;

  c = argv[1][0]; //argv[1] étant un pointeur vers une chaine de car.
                  // argv[1][0] est le premier car de cette chaine

  str = argv[2];

  if ( (adrPremCar = PremierCar(c,str)) == NULL) 
    printf ("'%c' n'est pas dans %s.\n",c,str);
  else
    printf ("La premiere occurence de '%c' dans %s est en position %d.\n",c,str,adrPremCar - str);

}
