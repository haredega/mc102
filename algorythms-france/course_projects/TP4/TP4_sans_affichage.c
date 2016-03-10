/* fichier complet sans edition de liens. */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>			// pour la gestion de la tempo dans affiche

#define MAXALLUMETTES 40
#define NOIR  0
#define BLANC  1
#define ROUGE  2
#define JAUNE  3
#define BLEU  4
#define MAGENTA  5
#define GREEN  6

/*definition du type t Allumette */
typedef struct Allumette {
  int couleur;
  int taille;   
} t_Allumette ;
/* criação do 'tipo' agenda */

typedef  t_Allumette t_VectAllumettes[MAXALLUMETTES];

 /* fonction inserer */
void inserer( t_VectAllumettes A, int dou, int jusquou){
     int couleur, taille, k;
     
     couleur = A[dou-1].couleur;
     taille = A[dou-1].taille;
     
     
     if( dou>jusquou){
         for(k = dou-1; k>jusquou-1; k--){
               A[k].couleur = A[k-1].couleur;
               A[k].taille = A[k-1].taille;
               }
         A[jusquou-1].couleur = couleur;
         A[jusquou-1].taille =  taille;
         
         }
    else if (dou < jusquou){
         for(k = dou-1; k<jusquou-1; k++){
               A[k].couleur = A[k+1].couleur;
               A[k].taille = A[k+1].taille;
               }
         A[jusquou-1].couleur = couleur;
         A[jusquou-1].taille =  taille;
         
         }
return;     
}
 /* fin de la fonction inserer */



/* fonction lecture */
int lecture(t_VectAllumettes transfert){
    int i, couleur, taille, nbvect;
    
    FILE *fp;
    fp = fopen ("allumettes_donnees.txt", "r+b");
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le fichier.\n");
       return;
       }
    
    fscanf(fp, "%d", &nbvect);  
        
        
        
    for(i=0; i<nbvect; i++){
          
          fscanf(fp, "%d", &couleur);
          fscanf(fp, "%d", &taille);
          transfert[i].couleur = couleur;
          transfert[i].taille = taille;  
          }

      fclose (fp);
      printf ("Fin de Lecture!\n");
      return nbvect;
 }
     

void ecrite(t_VectAllumettes transfert, int nbvect){
    int i, couleur, taille;
    
    FILE *fp;
    fp = fopen ("allumettes_sortis.txt", "w+b");
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le fichier.\n");
       return;
       }
    
    fprintf(fp, "%d\r\n", nbvect);
    
    for(i=0; i<nbvect; i++){
          
          fprintf(fp, "%d ", transfert[i].couleur);
          fprintf(fp, "%d\r\n", transfert[i].taille);
          }
          
    printf ("Fin d'Ecrite!\n"); 
    fclose (fp);  
    return;
 }    
 
/* tri pour insertion*/
void tri_insertion(t_VectAllumettes A, int nbvect){
     int i, j, couleuri, couleurj;
     for ( i = 0; i < nbvect ;i++){
         j=0;
         while(j<i && A[j].taille <= A[i].taille) j++; 
        
         /* s'il y a un deplacement, on colore les allumettes deplaces. */
         if(i != j) {
           //   printf("DEPLACEMENT!");
              couleuri = A[i].couleur;
              couleurj = A[j].couleur; 
              A[i].couleur = BLANC; 
              A[j].couleur = BLANC;
            //  affiche(A, nbvect);
            //  ecrite(A, nbvect);
            //  system("pause");
              }
         
         inserer(A, i+1, j+1);
         /* on recolore les allumettes deplaces.*/
         if( i > j){  A[j].couleur = couleuri;
                      A[j+1].couleur = couleurj;
                    //   ecrite(A, nbvect);
                    //   system("pause");  
                   }
         else if (i <j ){  A[j].couleur = couleuri;
                           A[j-1].couleur = couleurj; 
                       //    ecrite(A, nbvect);
                       //    system("pause");                    
                        }
                                      
         // affiche(A, nbvect);
         }
     return;
     }
/* fin tri pour insertion*/ 

/* deplacement bulle */
void bulle(t_VectAllumettes A, int position){
    int couleur, taille;
    couleur = A[position-1].couleur;
    taille = A[position-1].taille;
    A[position-1].couleur= A[position].couleur;
    A[position-1].taille = A[position].taille;  
   A[position].couleur= couleur;
    A[position].taille =taille;
    return;  
}
/* fin deplacement bulle */

/* tri bulle */
void tri_bulle(t_VectAllumettes A, int nbvect){
     int i= nbvect-1, j, couleuri, couleurj;
     while(i >= 0){
        for( j=0; j < i ; j++){
             if(A[j].taille > A[j+1].taille) {  
         //    printf("DEPLACEMENT!");
             couleuri = A[j].couleur;
             couleurj = A[j+1].couleur; 
             A[j].couleur = BLANC;
             A[j+1].couleur = BLANC;
      //       ecrite(A, nbvect);
        //     system("pause"); 
            // affiche(A, nbvect);
             bulle(A, j+1);
             A[j+1].couleur = couleuri;
             A[j].couleur = couleurj;
  //           ecrite(A, nbvect);
    //         system("pause"); 
            //   affiche(A, nbvect);
             }
        }   
        i--;            
     } 
return;     
     }
/* fin tri bulle */

/* tri pour couleur*/
void tri_couleur(t_VectAllumettes A, int nbvect){
     int i, j, couleuri, couleurj;
     for ( i = 0; i < nbvect ;i++){
         j=0;
         while(j<i && A[j].couleur <= A[i].couleur) j++; 
        
         /* s'il y a un deplacement, on colore les allumettes deplaces. */
         if(i != j) {
           //   printf("DEPLACEMENT!");
              couleuri = A[i].couleur;
              couleurj = A[j].couleur; 
              A[i].couleur = BLANC; 
              A[j].couleur = BLANC;
            //  affiche(A, nbvect);
            //  ecrite(A, nbvect);
            //  system("pause");
              }
         
         inserer(A, i+1, j+1);
         /* on recolore les allumettes deplaces.*/
         if( i > j){  A[j].couleur = couleuri;
                      A[j+1].couleur = couleurj;
                    //   ecrite(A, nbvect);
                    //   system("pause");  
                   }
         else if (i <j ){  A[j].couleur = couleuri;
                           A[j-1].couleur = couleurj; 
                       //    ecrite(A, nbvect);
                       //    system("pause");                    
                        }
                                      
         // affiche(A, nbvect);
         }
     return;
     }
/* fin couleur*/ 

int main(){
    t_VectAllumettes nouveau;
    int nbvect;
    
   printf ("Inicio!\n");
   //init();
   nbvect = lecture(nouveau);
// inserer(nouveau, 40, 1);
// inserer(nouveau, 15, 20);
 tri_insertion(nouveau, nbvect);
//   tri_bulle(nouveau, nbvect);   
  // tri_couleur(nouveau, nbvect);
   ecrite(nouveau, nbvect);
   //finish();
   printf ("FIM!\n");
    
    
  system("pause");   
  return 0 ;
    }  
  
  
  
  
  
  
     
