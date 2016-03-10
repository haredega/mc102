#include "structures.h"
#include <stdio.h>
#include <string.h>         
              /* DEMARRAGE DU JEU */
              
/*  fonctions des action des joueurs  */
int verifierPremierMot(char mot[], Reserve joueur){
     int flag;
     
     if( strlen(mot)!=4) {
         printf("Ce mot n'est pas valide!\n");
         printf("Choisissez un nouveau mot:");
         return -1;
         }
     
     if( recherche_Reserve(joueur, mot) ==-1 ) {
         printf("Vous n'avez pas cettes lettres!\n");
         printf("Choisissez un nouveau mot:");
         return -1;
         }
     if( rechercheDico(mot) == -1) {
         printf("Ce mot n'est pas valide!\n");
         printf("Choisissez un nouveau mot:");
         return -1;
         }
     return 1;
     }

int premierMot(Reserve joueur1, Reserve joueur2, Chevalet jeu, Mot_Utilise** liste){
     char mot[5];
     Chevalet aux;
     int i;
     
     printf("\nChaque joueur doit choisir un mot de 4 lettres pour commencer le jeu.\n\n");
     printf("           JOUEUR 1\n");
     imprimer_Reserve(joueur1);
     printf("Choisissez un mot:");
     i=0;
     do {       
               scanf("%4s", &mot);
               i = verifierPremierMot(mot, joueur1);
     } while( i != 1);
     
     i = enleverPieces(joueur1, mot);
     if ( i ==-1){ printf("Bogue! Reccommencez le jeu.\n"); return -1 ;}  // fonte de problemas
     else {printf("Alors le mot choisi est %s.\n\n", mot); strcpy(aux, mot); }
      *liste = insererMot( &(*liste), mot) ;
     printf("          JOUEUR 2\n");
     imprimer_Reserve(joueur2);
     printf("Choisissez un mot:"); 
     i=0;
     do{ 
         scanf("%4s", &mot); 
         i = verifierPremierMot(mot, joueur2);
     }while( i != 1);
     
     i = enleverPieces(joueur2, mot);
     if ( i ==-1){ printf("Bogue! Reccommencez le jeu.\n"); return -1;} // fonte de problemas
     else {printf("Alors le mot choisi est %s.\n\n", mot);  }
     *liste = insererMot( &(*liste) , mot) ;
     
     if ( strcmp(aux, mot)>0 ) {strcpy(jeu, mot); strcat(jeu, aux); }   
     else { strcpy(jeu, aux); strcat(jeu, mot); }   
     imprimer_Chevalet(jeu);
     return 1;
     }              
   
                   
                    /* DEMARRAGE DU JEU */
