#include "structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
                    /* JEU MACHINE  */
                    
extern int _lettres[21]={9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2};     
                    
/* la machine verifie si chaque mot est possible */
int recursive_Machine(Chevalet jeu,Reserve machine, char mot[], char pieces[], char reste[], Mot_Utilise** utilises){
    int i,n, j,k, l,m, flag1=0;
    n = strlen(mot);
    Chevalet transition;
    char aux[20];
    
    // recherche a gauche
    i = strlen(mot)-3;
    k=0;
    while( i>0 && flag1 == 0 ) {
            for(j=i; j>=0, j<8 ;j--){
                if(jeu[j]!=mot[j+2+k]) {i--; break;}                              
            }
            if(j==-1) flag1=1;
            k++;
    }
    if(flag1==1){     
                      for(j=0; j< k+1 ; j++){pieces[j] = mot[j]; }
                      pieces[k+1] ='\0'; 
                      for(m=0;  m <k+1; m++){ reste[m] = jeu[7-m];}
                      reste[m]='\0';
                      if ( recherche_Reserve( machine, pieces)==1 && recherche( (*utilises), mot)==1 ){ 
                                            strncpy(aux, mot, k+1);
                                            aux[k+1]='\0';
                                            strcat( aux, jeu);
                                            aux[k+8]='\0';
                                            strncpy(jeu, aux, 8);
                                            jeu[8]='\0';
                                            return 1;
                      }
                 }                         
    // recherche droite
    i = 8-n+1;
    k=0;
    flag1=0;
    while( i<8 && flag1 == 0 ) {
           
            for(j=i, l=0; j<=7 ;j++, l++){
                if(jeu[j]!=mot[l]) { i++; break;}                              
            }
            if(j==8) flag1=1;
            else k++;
    }

    if(flag1==1){     
                      for(j=0; j<8-i; j++){pieces[j] = mot[j]; }
                      pieces[j] ='\0';
                      for(j=0; j<i; j++){reste[j] = jeu[j]; }
                      reste[j] ='\0';
                      if (recherche_Reserve( machine, reste)==1 && recherche((*utilises), mot)==1){ 
                                              strcpy(aux, jeu);
                                              aux[8]='\0';
                                              strncat( aux, mot, k+1);
                                              aux[9+k]='\0';
                                              for(i =0; i<8;i++){ jeu[i]= aux[i+k+1];}
                                              jeu[i]= '\0';
                                              return 2;
                      }
                 }                         
    
    
    // avec le chevalet pivoté
         for(i =0; i<8;i++){
               transition[i] = jeu[7-i];               
               }
               transition[i]='\0';
               
    // recherche a gauche
    i = strlen(mot)-3;
    k=0;
    while( i>0 && flag1 == 0 ) {
            for(j=i; j>=0 ;j--){
                if(transition[j]!=mot[j+2+k]) {i--; break;}                              
            }
            if(j==-1) flag1=1;
            k++;
    }
    if(flag1==1){     
                      for(j=0; j< k+1 ; j++){pieces[j] = mot[j]; }
                      pieces[k+1] ='\0'; 
                      for(m=0;  m < k+1; m++){ reste[m] = transition[7-m];}
                      reste[m]='\0';
                      if ( recherche_Reserve( machine, pieces)==1 && recherche((*utilises), mot)==1){ 
                                            strncpy(aux, mot, k+1);
                                            aux[k+1]='\0';
                                            strcat( aux, transition);
                                            aux[k+9]='\0';
                                            strncpy(jeu, aux, 8);
                                            jeu[8]='\0';                                              
                                             return 3;
                      }
                 }                        
    // recherche droite
    i = 8-n+1;
    k=0;
    flag1=0;
    while( i<8 && flag1 == 0 ) {
           
            for(j=i, l=0; j<=7 ;j++, l++){
                if(transition[j]!=mot[l]) { i++; break;}                              
            }
            if(j==8) flag1=1;
            else k++;
    }

    if(flag1==1){     
                      for(j=0; j<8-i; j++){pieces[j] = mot[j]; }
                      pieces[j] ='\0';
                      for(j=0; j<i; j++){reste[j] = transition[j]; }
                      reste[j] ='\0';
                      if (recherche_Reserve( machine, reste)==1 && recherche((*utilises), mot)==1){ 
                                              strcpy(aux, jeu);
                                              aux[8]='\0';
                                              strncat( aux, mot, k+1);
                                              aux[9+k]='\0';
                                              for(i =0; i<8;i++){ jeu[i]= aux[i+k+1];}
                                              jeu[i]= '\0';                                          
                                               return 4;
                      }
                 }              
    
return 0;    
}
/* la machine verifie si ce mot est possible */

/* machine echange une lettre*/
void echanger_Machine( Reserve joueur ){
     int i;
     char c[2];
          

          c[1] = '\0';
          printf("La MACHINE échange une lettre.\n");
          imprimer_Reserve(joueur);
          i= rand()%(strlen(joueur)-1);
          c[0] = joueur[i];
          i = enleverPieces(joueur, c);
          i = (int)(c[0]-'a');
          _lettres[i]++;
          printf("La machine jette la lettre: %c.\n", c[0]);
          i = piocher(joueur);
          c[0]= (char)(i+'a');
          insererPieces(joueur, c);    
          printf("La machine a pioche la lettre %c.\n", c[0]);
          imprimer_Reserve(joueur);
          return;
}
/* machine echange une lettre*/


/* recherche d'une action par la machine*/
int recherche_Machine(Chevalet jeu, Reserve machine, char pieces[], char reste[], int* octo, char mot[], Mot_Utilise** utilises) {
    int i=0;
    
    FILE *fp;
    FILE *fa;
    
    fp = fopen ("DICO_FINAL.txt", "r+b");
    
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le dictionnaire.\n");
       return -1;
    }

    while (!feof(fp)) {
    fscanf(fp, "%s", mot);
        i = recursive_Machine(jeu, machine, mot, pieces, reste, utilises);
        if ( i>0 && i<5){ if(strlen(mot) == 8) (*octo)=1;  return i;}
    }
    fclose(fp);
    

return 5;    
}
/* recherche d'une action par la machine*/

/* octoverso machine*/

void octoverso_machine( Reserve joueur ){
          int i;
          char c[2];
          
          c[1] = '\0';
          printf("------------------------------ !!!!!!!!! ------------------------------\n\n");
          printf("La MACHINE a un Octo!\n");
          if(strlen(joueur)==0){ printf("Fin de jeu!\n"); return;  }
          imprimer_Reserve(joueur);
          printf("La machine se debarrase d'une lettre.\n");
          i= rand()%(strlen(joueur)-1);
          c[0] = joueur[i];
          i = enleverPieces(joueur, c);
          i = (int)(c[0]-'a');
          _lettres[i]++;
          printf("La machine jette la lettre: %c.\n", c[0]); 
          imprimer_Reserve(joueur);
          return;
}
/* octoverso machine*/
                    
/* tour machine */
int tour_machine(Chevalet jeu, Reserve machine, Reserve autre_joueur, Mot_Utilise** utilises){
    int i=0, j=0, fintour=0, octo=0, coup=0;
    Chevalet next;
    char c, reste[9], pieces[9], mot[9];
    printf("------------------------------------------------------------");
    printf("\n\n         Tour de la MACHINE\n\n");
    imprimer_Reserve(machine);
    imprimer_Chevalet(jeu);
    scanf("%c", &c);
     
     strcpy(next, jeu) ;  
     i = recherche_Machine(next,machine, reste, pieces, &octo, mot, &(*utilises));     
     switch(i){
          case 1: printf("La machine joue les pieces %s a gauche\n", reste);
                  printf("Et forme le mot %s.\n", mot);
                  printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", pieces);
                  break;
          case 2:  printf("La machine joue les pieces %s a droite.\n", reste);
                  printf("Et forme le mot %s.\n", mot);
                   printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", pieces);
                   break;  
           case 3: printf("La machine fait le pivot et joue les pieces %s a gauche.\n", reste);
                  printf("Et forme le mot %s.\n", mot);
                   printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", pieces);
                   break;  
           case 4: printf("La machine fait le pivot et joue les pieces %s a droite.\n", reste);
                  printf("Et forme le mot %s.\n", mot);
                   printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", pieces);
                   break;
           case 5: echanger_Machine( machine );  break;     
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
              if( j==2 ) coup = coupe(jeu, machine, autre_joueur, utilises);
   
            
                       enleverPieces(machine ,reste);
                       ecrireChevalet(jeu, next);
                       *utilises = insererMot( &(*utilises) , mot) ; 
                       insererPieces(autre_joueur, pieces);
                       if(octo ==1) { octoverso_machine( machine );}
    
                       if( strlen(machine) == 0 || strlen(autre_joueur) == 0 ) return 1;     
   }
else return 0;    
}
/* tour machine */

/* tour du joueur contre la machine */
int tour_contremachine(Chevalet jeu,Reserve joueur,Reserve machine,Mot_Utilise** utilises){
    int i=0, j=0, fintour=0, octo=0, coup=0, octom=0;
    Chevalet next, coupe_test;
    char reste[9], reste_test[9], pieces[9], pieces_test[9], mot[9], mot2[9];
    
    printf("------------------------------------------------------------");
    printf("\n\n         Tour du JOUEUR 1\n\n");
    
        
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
           case 1: pivoter(jeu);  imprimer_Reserve(joueur);break;
           case 2: 
                fintour = lettresDroite(jeu, next, joueur, &(*utilises), reste, pieces, &octo, mot); 
                if(fintour != -1){imprimer_Chevalet( next);
                printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", reste);}
                break; 
           case 3:
                 fintour = lettresGauche(jeu, next, joueur, &(*utilises), reste, pieces, &octo, mot); 
                 if(fintour != -1){ imprimer_Chevalet( next);
                 printf("Et les pieces que l'autre joueur recevra sont :\n %8s \n\n", reste);}
                 break;  
           case 4: imprimer_Tout( (*utilises) ); imprimer_Reserve(joueur); imprimer_Chevalet(jeu); break;
           case 5: echanger( joueur );  fintour = 1; break;
       }
    }  

    if(i!=5){ 
             if(octo!=1) {        
                strcpy(coupe_test, jeu);   
                i = recherche_Machine(coupe_test,machine, reste_test, pieces_test, &octom, mot2, &(*utilises) );         
                if(octom==1) {printf("La machine observe un coupe!\n");
                 switch(i){
                 case 1: printf("Si on joue les pieces %s a gauche.\n", pieces);
                         printf("On forme le mot %s et on aurait un OCTO.\n", mot2);
                         break;
                   case 2:  printf("Si on joue les pieces %s a droite.\n", pieces);
                            printf("On forme le mot %s et on aurait un OCTO.\n", mot2);
                            break;
                  case 3: printf("Si on fait le pivot et joue les pieces %s a gauche.\n", pieces);
                          pivoter(jeu);
                          printf("On forme le mot %s et on aurait un OCTO.\n", mot2);
                          break;  
                   case 4: printf("Si on fait le pivot et joue les pieces %s a droite.\n", pieces);
                           pivoter(jeu);
                           printf("On forme le mot %s et on aurait un OCTO.\n", mot2);
                           break;   
                   }
                   *utilises = insererMot( &(*utilises) , mot2);
                   octoverso_machine(machine);
                                   
                }
             }
                       enleverPieces(joueur ,pieces);
                       ecrireChevalet(jeu, next);
                       *utilises = insererMot( &(*utilises) , mot);                         
                       insererPieces(machine, reste);
                       if(octo ==1) { octoverso(joueur); }
                       if( strlen(joueur) == 0 || strlen(machine) == 0 ) return 1;     
} 
else return 0;    
  
return 0;    
}
/* tour du joueur contre la machine */

/* premier mot machine */
int premierMot_Machine( Reserve joueur, Reserve machine,Chevalet jeu, Mot_Utilise** utilises ){
    char mot[5];
    Chevalet aux;
    int i;
     FILE *fp;
     
     printf("\nChaque joueur doit choisir un mot de 4 lettres pour commencer le jeu.\n\n");
     printf("           JOUEUR 1\n");
     imprimer_Reserve(joueur);
     printf("Choisissez un mot:");
     
     i=0;
     do {       
               scanf("%4s", &mot);
               i = verifierPremierMot(mot, joueur);
     } while( i != 1);
     
     i = enleverPieces(joueur, mot);
     if ( i ==-1){ printf("Bogue! Reccommencez le jeu.\n"); return -1 ;}  // fonte de problemas
     else {printf("Alors le mot choisi est %s.\n\n", mot); strcpy(aux, mot); }
      *utilises = insererMot( &(*utilises), mot) ;
     
     printf("          MACHINE\n");
     imprimer_Reserve(machine);
     printf("La machine choisit un mot."); 
     
     /**/
    
    
    fp = fopen ("DICO_FINAL.txt", "r+b");
    
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le dictionnaire.\n");
       return -1;
    }

    while (!feof(fp)) {
    fscanf(fp, "%s", mot);
        i = recherche_Reserve( machine, mot);
        if (  i==1 && strlen(mot) == 4) break;
    }
    fclose(fp);
     /**/
     
     i = enleverPieces(machine, mot);
     if ( i ==-1){ printf("Bogue! Reccommencez le jeu.\n"); return -1;} // fonte de problemas
     else {printf("Le mot choisi est %s.\n\n", mot);  }
     *utilises = insererMot( &(*utilises) , mot) ;
     
     if ( strcmp(aux, mot)>0 ) {strcpy(jeu, mot); strcat(jeu, aux); }   
     else { strcpy(jeu, aux); strcat(jeu, mot); }   
     imprimer_Chevalet(jeu);
     return 1;
    }
/* premier mot machine */

                    
/* appel*/
void jeu_machine(){
   int i=0, flag, fin=0;
   Reserve joueur, machine;
   Chevalet jeu; 
   Mot_Utilise *utilises=NULL;
  
   printf("\n------------------------------------------------------------");
   printf("\n--------------------Mode de jeu contre la Machine---------------------\n");
   printf("------------------------------------------------------------\n\n");
   printf("Demarrage du jeu: tirage au sort des lettres.\n\n");
 //  melangeLettres(joueur, machine);
   viderReserve(joueur);
   viderReserve(machine);
   insererPieces(joueur, "elleaisfd");
   insererPieces(machine, "mrtchatoib");   /* code pour tester*/
   printf("\n\n");
   printf("          JOUEUR 1\n");
   imprimer_Reserve(joueur);
   printf("\n\n");
   printf("           MACHINE\n");
   imprimer_Reserve(machine);
  
 // flag = premierMot_Machine(joueur,machine, jeu, &utilises );
 // if(flag == -1) {printf("\n"); return;}  
   ecrireChevalet(jeu, "chatmort");
   
   while( fin != 1){
          fin = tour_contremachine(jeu, joueur, machine, &utilises);
          getchar();
          if( fin != 1 ) fin = tour_machine(jeu, machine, joueur, &utilises);
          getchar();
        }
   
   if( strlen(joueur)==0) printf("\nLe joueur 1 a gagne.\n");     
   if( strlen(machine)==0) printf("\nLa MACHINE a gagne.\n");

return;
}
                    
/* appel*/                    
                    
                    /* JEU MACHINE  */                    
                    
            
