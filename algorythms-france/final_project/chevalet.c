#include "structures.h"
#include <stdio.h>
#include <string.h>
                 /* CHEVALET */
  
/* Gestion du Chevalet */
/* Impression du Chevalet */
void imprimer_Chevalet(Chevalet jeu){ 
      printf("Le mot du chevalet est:\n %8s \n\n", jeu); 
  
} 
/* Impression du Chevalet */
  
/* Pivot du Chevalet */
void pivoter(Chevalet jeu){ 
         Chevalet transition; 
         int i;  
         for(i =0; i<8;i++){ 
               transition[i] = jeu[7-i];                
               } 
         for(i =0; i<8;i++){ 
               jeu[i]= transition[i] ;                
               } 
                 
         printf("\nApres pivoter on a:\n %s \n\n", jeu);       
         return;       
} 
/* Pivot du Chevalet */      
  
/* ecrire sur le chevalet */
void ecrireChevalet(Chevalet jeu, char mot[]){ 
     int i=0, j=0; 
     while( i < strlen(mot) && j<8){ 
            if(mot[i] >96 && mot[i]<123) {jeu[j] = mot[i]; j++;} 
            i++; 
            } 
     jeu[8] = '\0';        
     return; 
     } 
/* ecrire sur le chevalet */
  
               /* CHEVALET  */
