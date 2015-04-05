//
// Annuaire

//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Avec Typedef on evite de repeter struct 
/*typedef struct  {
char nom[32];
char telephone[16];
} Personne;

typedef struct {
 Personne annuaire[20];
 int cnt;
} Carnet;
Carnet unCarnet;

*/


struct Personne {
char nom[32];
char telephone[16];
};

struct Carnet {
 struct Personne annuaire[20];
 int cnt;
} unCarnet;




// Renvoie une structure remplie avec le nom et le telephone
struct Personne GetPersonne (char *nom, char *tel)
{
struct Personne u;

strcpy ( u.nom, nom);
strcpy ( u.telephone, tel);

return (u);
}


// Ajouter personne dans un carnet
// Passage par référence car sinon compteur pas modifie
AddPersonne (struct Carnet *c,  char *nom, char *tel)
{
int i;
struct Personne u;
// recherche place libre
for (i=0; i < c->cnt; i++);


u = GetPersonne (nom, tel);
//printf (" AddPersonne i = %d \n", i);
//printf (" AddPersonne nom = %s \n", u.nom );
//printf (" AddPersonne tel = %s \n", u. telephone );

// afectation structure = copie 
c->annuaire[i] = u;

//printf (" AddPersonne nom annuaire = %s \n", c->annuaire[i].nom );
//printf (" AddPersonne tel annnuaire = %s \n", c->annuaire[i].telephone );
c->cnt++;
}



// Aficher infomation Personne
AffPersonne (struct Personne unePersonne)
{
printf (" %s ",unePersonne.nom);
printf (" %s \n",unePersonne.telephone);
}



// Afficher un carnet
AffCarnet(struct Carnet c)
{
int i;

printf (" AffCarnet  c->cnt = %d \n", c.cnt);

for (i=0; i < c.cnt; i++) {
AffPersonne (c.annuaire[i]);
}
}




int main ()
{
char nom[32];
char telephone[16];
int choice;

while (1) {

printf (" Entrer votre choix : \n");
printf ("       1 ---- Ajouter personne \n");
printf ("       2 ---- Afficher carnet \n");
printf ("       3 ---- Quitter \n");

scanf ("%d", & choice);

switch (choice) {

	case 1:
		printf (" Entrer nom \n");
		scanf ("%s", nom);

		printf (" Entrer telephone \n");
		scanf ("%s", telephone);

		AddPersonne (&unCarnet, nom, telephone);
		break;
 	case 2 : 
		AffCarnet(unCarnet);
		break ;
 	case 3 :
		exit(0);
   	default:
		printf ("erreur saisie \n");

}
}
}