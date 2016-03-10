//monde.c

#include <stdio.h>
#include "constantes.h"
#include "affichage.h"
#include "proba.h"


void LireEnvironnement(t_monde *enviro){
    int i, j;
          
    FILE *fp;
    fp = fopen ("monde1.dat", "r+b");
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le fichier.\n");
       return;
       }
     
     fscanf(fp, "%d", &enviro->L);
     fscanf(fp, "%d", &enviro->H);  
     fscanf(fp, "%d", &enviro->Fx);     
     fscanf(fp, "%d", &enviro->Fy);     

     //lecture matrice mat     
     for(i=0 ;i<enviro->L;i++){
        for(j=0;j<enviro->H;j++){
            fscanf(fp ,"%d", &enviro->mat[i][j]);
        }
     }
    
    fclose (fp);
    printf ("Fin de Lecture!\n");
    //
    
    fp = fopen ("allumettes_sortis.txt", "w+b");
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le fichier.\n");
       return;
       }
    fprintf(fp, "%d", enviro->L);
     fprintf(fp, "%d",enviro->H);  
     fprintf(fp, "%d",enviro->Fx);     
     fprintf(fp, "%d",enviro->Fy);     
      
    for(i=0 ;i<enviro->L;i++){
      for(j=0;j<enviro->H;j++){
         fprintf(fp, "%d", enviro->mat[i][j]);
        } fprintf(fp, "\n\r");
     } 
return;    
}
