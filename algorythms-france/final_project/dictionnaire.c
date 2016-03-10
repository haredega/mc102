#include "structures.h"
#include <stdio.h>
#include <string.h>               
                          /* DICTIONNAIRE */
/*  codes de recherche lexical */

/* recherche sequentielle d'un mot dans le Dictionnaire  */
int rechercheDico(char recherche[]){
    char mot[20];
    FILE *fp;
    fp = fopen ("DICO_FINAL.txt", "r+b");
    if (fp == NULL) {
       printf ("Erreur pour ouvrir le dictionnaire.\n");
       return 0;
    }
   
    while (!feof(fp)) {
    fscanf(fp, "%s", mot);
        if (strcmp(mot, recherche)==0) return 1;
        
    }
    fclose(fp);
return -1;
}
/* recherche d'un mot dans le Dictionnaire */

/* recherche d'un chevalet */
int rechercheRecursive(char cherche[], int nb, char mot[], int dir, int ltch, Mot_Utilise** liste){
    int i, k,j;
    char aux1[nb-1];
    if(nb < 3) {  return -1;}
    if(ltch < 2) {  return -1;}
    
    i = rechercheDico(cherche);
    
    j= recherche(*liste, mot);
    if( i==1 && j==1 ) { strcpy(mot, cherche); return 1;}    

    else if (dir == 1) // on cherche a droite
      {  
          for(k=0; k<nb-1; k++){  aux1[k] = cherche[k+1]; }
          aux1[nb-1]='\0';
          return rechercheRecursive(aux1, nb-1, mot, 1, ltch-1, &(*liste));
      }
     else if (dir == 2) // on cherche a gauche
      {           
          for(k=0; k<nb-1; k++){  aux1[k] = cherche[k]; }
          aux1[nb-1]='\0';
          return rechercheRecursive(aux1, nb-1, mot, 2, ltch-1, &(*liste));         
      }     
      
     
return-1;      
}

int rechercheChevalet(Chevalet jeu, char mot[], int dir, int ltch, Mot_Utilise** liste){
    return rechercheRecursive(jeu, 8, mot, dir, ltch, &(*liste));
}

/* recherche d'un chevalet */

/* fin des codes de recherche lexical */
                          /* DICTIONNAIRE */  
