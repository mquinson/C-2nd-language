#include <stdio.h>

int main(int argc, char **argv) {
   int a=0,e=0,i=0,o=0,u=0,y=0;
   
   if (argc>1) { 
      char *p;
      
      for (p = argv[1]; *p; p++) {
	 switch (*p) {
	  case 'a': case 'A':
	    a++; break;
	  case 'e': case 'E':
	    e++; break;
	  case 'i': case 'I':
	    i++; break;
	  case 'o': case 'O':
	    o++; break;
	  case 'u': case 'U':
	    u++; break;
	  case 'y': case 'Y': 
	    y++; break;
	 }	 
      }
   }
   
   printf("Nombre de a: %d\n",a);
   printf("Nombre de e: %d\n",e);
   printf("Nombre de i: %d\n",i);
   printf("Nombre de o: %d\n",o);
   printf("Nombre de u: %d\n",u);
   printf("Nombre de y: %d\n",y);
}
