/* 
author : A. G. Heitor et L. Alexandre
date : 22-02-2013
file name : nombreCache.c

ENONCE:
Jeu du nombre Cach�
*/

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>       /* time */

 
int main(void)
{     int but, i=0, actuel;
      srand (time(NULL));
      but = 22364;//rand()%99999;
     printf("D�but du Jeu! Le nombre est entre 0 et 99999.\n");
     
     do { printf("A toi de jouer:");
          scanf("%d", &actuel);
          printf("\n");
          if( actuel < but ) printf("Le numero est plus grand que %d \n", actuel);
          else if (actuel > but) printf("Le numero est plus petit que %d \n", actuel);    
          i++;
     }while ( actuel != but);
     printf("Bien Joue! Le numero cache etait bien %d\n", but);  
     if(i ==2 || i == 1) printf("Tu as r�ussi en %d proposition.\n", i);
     else printf("Tu as r�ussi en %d propositions.\n", i);      
 
 
    printf("\n");
	return (EXIT_SUCCESS);
}
