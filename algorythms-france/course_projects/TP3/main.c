#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "entierlong.h"
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"

int main()
{
      int i, standard;
      t_EntierLong n_converti, long1, long2, n, u0, u1, aux;
      
      //Test des fonctions lireEntierLong et ecrireEntierLong
   /* printf("Ecrire un numero tres long: ");
      n = lireEntierLong();
      printf("Le numero est: ");
      ecrireEntierLong(n);  */

      //Test de la fonction de conversion de standard en long
   /* printf("Ecrire un entier pas trop long: ");
      scanf("%d",&standard);
      n_converti = conversion_std_en_long(standard);
      ecrireEntierLong(n_converti);   */

      //Test de la fonction de comparaison
   /* printf("Ecrire un premier numero tres long: ");
      long1 = lireEntierLong();
      printf("Ecrire un deuxieme numero tres long: ");
      long2 = lireEntierLong();
      if (comparaison(long1,long2)) printf("Ils sont égaux\n");
      else printf("Ils sont differents\n");  */

      //Test de la fonction de comparaison en valeur absolue
   /* printf("Ecrire un premier numero tres long: ");
      long1 = lireEntierLong();
      printf("Ecrire un deuxieme numero tres long: ");
      long2 = lireEntierLong();
      if (comp_valeur_abs(long1,long2)) printf("Premier <= Deuxieme en valeur absolue\n");
      else printf("Premier > Deuxieme en valeur absolue\n");    */

      //Test des operations
  /*  printf("Ecrire un premier numero tres long: ");
      long1 = lireEntierLong();
      printf("Ecrire un deuxieme numero tres long de meme signe et plus petit en absolue: ");
      long2 = lireEntierLong();
      printf("La soustraction est: ");
      ecrireEntierLong(sous_meme_signe(long1, long2));   */

      i=2;
      printf("Donner les valeurs de u0, soit 0: ");
      u0 = lireEntierLong();
      printf("Donner les valeurs de u1, soit 1: ");
      u1 = lireEntierLong();
      while (i < 20000){
	      aux=add_meme_signe (u0,u1);
	      u0=u1;
	      u1=aux;
	      printf("u%d = ", i);
	      ecrireEntierLong(u1);
	      i++;
	    }	      

      return 0;
}