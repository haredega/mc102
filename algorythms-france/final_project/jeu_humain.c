#include "structures.h"
#include <stdio.h>
#include <string.h>      
                    /*  JEU HUMAIN    */

/*   insertion des lettres a droite et a gauche du chevalet   */

// 1. ajouter des lettres à droite */

extern int _lettres[21];     

//int _lettres[21]={9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2};

int lettresDroite(Chevalet jeu, Chevalet next, Reserve joueur, Mot_Utilise** liste, char reste[], char pieces[], int* octo, char mot2[]) {
      char chevaletLong[100], mot[9];
      int i,n;
      
      printf("Quelle lettre ajoutez-vous ?");
      scanf("%s", &mot );
      n = strlen( mot );
      strcpy(chevaletLong, jeu);
      strncat( chevaletLong, mot, n);
       strcpy(mot2, " ");
      
      for(i =0; i<8;i++){
               next[i]= chevaletLong[i+n];
               }
               next[i]= '\0';
               
     if( recherche_Reserve(joueur, mot) ==-1 ) {
         printf("Vous n'avez pas cettes lettres!\n");
         return -1;
     }
     
     if( rechercheChevalet(next, mot2, 1, 8-n , &(*liste)) == -1) {
         printf("Ce mot n'est pas valide!\n");
         return -1;
     }     
     if( recherche( (*liste), mot2) == -1) {
                printf("Ce mot a deja ete utilise!\n");
                return -1;
     }
     printf("Ok! Le mot %s n'a pas encore ete utilise!\n\n", mot2); 
     if( strlen( mot2 ) == 8 ) *octo = 1;          
     strncpy(reste, chevaletLong, n);
     reste[n]='\0';
     strcpy(pieces, mot);
     return 1;
}

/* 2. ajouter des lettres à gauche */
int lettresGauche(Chevalet jeu, Chevalet next, Reserve joueur, Mot_Utilise** liste, char reste[], char pieces[], int* octo, char mot2[]) {
      char chevaletLong[100], mot[9];
      int i,n;
      
      printf("Quelle lettre ajoutez-vous ?");
      scanf("%s", &mot );
      n = strlen( mot );
      strncpy(chevaletLong, mot, n);
      chevaletLong[n] = '\0';
      strcat( chevaletLong, jeu);
      
      strncpy(next, chevaletLong, 8);
      next[8]='\0';   
      strcpy(mot2, " ");
               
     if( recherche_Reserve(joueur, mot) ==-1 ) {
         printf("Vous n'avez pas cettes lettres!\n");
         return -1;
     }
     
     if( rechercheChevalet(next, mot2, 2, 8-n, &(*liste)) == -1) {
         printf("Ce mot n'est pas valide!\n");
         return -1;
     }     
    if( recherche( (*liste), mot2) == -1) {
                printf("Ce mot a deja ete utilise!\n");
                return -1;
     }
    
    printf("Ok! Le mot %s n'a pas encore ete utilise!\n\n", mot2);            
    if( strlen(mot2) ==8) *octo =1; 
              
     for(i=0;i<n;i++){
               reste[i] = chevaletLong[i+8];
               }
     
     reste[n]='\0';                
     strcpy(pieces, mot);
     return 1;
}

/*   insertion des lettres a droite et a gauche du chevalet   */

/* echanger une lettre */
void echanger(Reserve joueur){
          int i;
          char c[2];
          
          c[1] = '\0';
          printf("Vous échangez une lettre.\n");
          imprimer_Reserve(joueur);
          printf("Quelle lettre voulez-vous jetter?\n");
          do { scanf("%c",&c[0]);} while( c[0]>122 || c[0]<97);
          i = recherche_Reserve(joueur, c); 
          
          while(i !=1){  
              printf("\n Vous n'avez pas cette lettre.\n\n");
              imprimer_Reserve(joueur);
              printf("Quelle lettre voulez-vous jetter?\n");
              do { scanf("%c",&c[0]);} while( c[0]>122 || c[0]<97);
              i = recherche_Reserve(joueur, c);
          }
  
          i = enleverPieces(joueur, c);
          i = (int)(c[0]-'a');
          _lettres[i]++;
          printf("Lettre jette: %c.\n", c[0]);
          i = piocher(joueur);
          c[0]= (char)(i+'a');
          insererPieces(joueur, c);    
          printf("Vous avez pioche la lettre %c\n", c[0]);
          imprimer_Reserve(joueur);
          return;
}


/* echanger une lettre */

/* octo-verso */
void octoverso(Reserve joueur){
          int i;
          char c[2];
          
          c[1] = '\0';
          printf("------------------------------ !!!!!!!!! ------------------------------\n\n");

          printf("Vous avez un Octo!\n");
          if(strlen(joueur)==0){ printf("Fin de jeu!\n"); return;  }
          imprimer_Reserve(joueur);
          printf("Quelle lettre voulez-vous jetter?\n");
          do {scanf("%c", &c[0]);} while( c[0]>122 || c[0]<97);
          i = recherche_Reserve(joueur, c); 
          
          while(i !=1){  
              printf("\n Vous n'avez pas cette lettre.\n\n");
              imprimer_Reserve(joueur);
              printf("Quelle lettre voulez-vous jetter?\n");
              do { scanf("%c", &c[0]);} while( c[0]>122 || c[0]<97);
              i = recherche_Reserve(joueur, c);
          }
  
          i = enleverPieces(joueur, c);
          i = (int)(c[0]-'a');
          _lettres[i]++;
          printf("Lettre jettes: %c.\n", c[0]);
          imprimer_Reserve(joueur);
          return;
}
/* octo verso*/

/*  coupe */
int coupe(Chevalet jeu, Reserve joueur, Reserve autre_joueur, Mot_Utilise** utilises){
     int i=0, fintour=0, octo=0;
     Chevalet next;
     char pieces[9], reste[9], mot[9];
     
     printf("\n\nAlors vous coupez.\n");
     while( fintour!=1 ){
       imprimer_Reserve(joueur);
       imprimer_Chevalet(jeu);
       printf("Que faites-vous?\n");
       printf("\n1 pour Pivoter le Chevalet");
       printf("\n2 pour inserer un mot a droite");
       printf("\n3 pour inserer un mot a gauche");
       printf("\n4 pour verifier la liste des mots utilises");
       printf("\n5 pour retourner et annuler le coupe");
       printf("\nChoisissez: ");
       scanf("%d", &i);
    
       while( i != 1  && i!=2 && i!=3 && i!=4 && i!=5) {
           printf("\nChoisissez entre 1 et 4!\n");
           scanf("%d", &i);         
       }
       switch(i){
           case 1: pivoter(jeu); break;
           case 2: fintour = lettresDroite(jeu, next, joueur, &(*utilises), reste, pieces, &octo, mot); break;  //guardo o possivel chevalet em next
           case 3: fintour = lettresGauche(jeu, next, joueur, &(*utilises), reste, pieces, &octo, mot); break;  //e as letras a passar pro outro em reste
           case 4: imprimer_Tout( (*utilises) ); break;
           case 5: return -1;
       }
    }
    
    if(octo ==1){ 
                  *utilises = insererMot( &(*utilises) , mot) ; 
                  octoverso(autre_joueur);
                  return 1;
    } 
    else { printf("Ce n'est pas un coupe valable.\n"); return -1; } 
     
     
}
/*  coupe */

/* tour d'un joueur */
int tour(Chevalet jeu, Reserve joueur, Reserve autre_joueur, Mot_Utilise** utilises, int nb){
    int i=0, j=0, fintour=0, octo=0, coup=0;
    Chevalet next;
    char reste[9], pieces[9], mot[9];
   printf("------------------------------------------------------------");
    printf("\n\n         Tour du JOUEUR %d\n\n", nb);
    
        
    while( fintour!=1 ){
       imprimer_Reserve(joueur);
       imprimer_Chevalet(jeu);
       printf("Que faites-vous?\n");
       printf("\n1 pour Pivoter le Chevalet");
       printf("\n2 pour inserer un mot a droite");
       printf("\n3 pour inserer un mot a gauche");
       printf("\n4 pour verifier la liste des mots utilises");
       printf("\n5 pour echanger une lettre");
       printf("\nChoisissez: ");
       scanf("%d", &i);
    
       while( i != 1  && i!=2 && i!=3 && i!=4 && i!=5) {
           printf("\nChoisissez entre 1 et 5!\n");
           scanf("%d", &i);         
       }
       switch(i){
           case 1: pivoter(jeu);  break;
           case 2: 
                fintour = lettresDroite(jeu, next, joueur, &(*utilises), reste, pieces, &octo, mot); 
                if(fintour != -1){imprimer_Chevalet( next);
                printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", reste);}
                break;  //guardo o possivel chevalet em next
           case 3:
                 fintour = lettresGauche(jeu, next, joueur, &(*utilises), reste, pieces, &octo, mot); 
                 if(fintour != -1){ imprimer_Chevalet( next);
                 printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", reste);}
                 break;  //e as letras a passar pro outro em reste
           case 4: imprimer_Tout( (*utilises) ); break;
           case 5: echanger( joueur );  fintour = 1; break;
       }
    }  

    if(i!=5){ printf("------------------------------------------------------------\n\n");
             if(octo!=1) {printf("L'autre joueur observe-t-il un COUPE?\n");
                printf("1 - Non  2 - Oui  :");
                scanf("%d", &j);
    
                while( j != 1 && j!=2 ) {
                       printf("\nChoisissez entre 1 e 2.\n");
                       scanf("%d", &j);           
                }
                }      
                if( j==2 ) coup = coupe(jeu, joueur, autre_joueur, utilises);
   
            
                       enleverPieces(joueur ,pieces);
                       ecrireChevalet(jeu, next);
                       *utilises = insererMot( &(*utilises) , mot) ; 
                       insererPieces(autre_joueur, reste);
                       if(octo ==1) { octoverso(joueur);}
    
                       if( strlen(joueur) == 0 || strlen(autre_joueur) == 0 ) return 1;     
   }
else return 0;    
}

/* tour d'un joueur */

/* jeu humain */
void jeu_humain(){

   int i=0, flag, fin=0;
   Reserve joueur[2];
   Chevalet jeu;
   Mot_Utilise *utilises=NULL;
  
   printf("\n------------------------------------------------------------");
   printf("\n--------------------.Mode de jeu Humain.--------------------\n");
   printf("------------------------------------------------------------\n\n");
   printf("Demarrage du jeu: tirage au sort des lettres.\n\n");
  melangeLettres(joueur[0], joueur[1]);
   /*viderReserve(joueur[0]);
   viderReserve(joueur[1]);
   insererPieces(joueur[0], "capmortelleai");
   insererPieces(joueur[1], "chatocpai");   /* code pour tester*/
   
   printf("          JOUEUR 1\n");
   imprimer_Reserve(joueur[0]);
   printf("\n\n");
   printf("           JOUEUR 2\n");
   imprimer_Reserve(joueur[1]);
   flag = premierMot(joueur[0], joueur[1], jeu, &utilises );
   if(flag == -1) {printf("\n"); return;}  
   
   
   while( fin != 1){
          fin = tour(jeu, joueur[0], joueur[1], &utilises, 1);
          if( fin != 1 ) fin = tour(jeu, joueur[1], joueur[0], &utilises, 2);
        }
   
   if( strlen(joueur[0])==0) printf("\nLe joueur 1 a gagne.\n");     
   if( strlen(joueur[1])==0) printf("\nLe joueur 2 a gagne.\n");

return;
}
/* jeu humain */ 
                    
                    /*  JEU HUMAIN    */
                    
