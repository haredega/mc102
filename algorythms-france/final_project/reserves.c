#include "structures.h"
#include <stdio.h>
#include <string.h>  
#include "jeu_humain.h"                    
              /*   RESERVES    */
extern int _lettres[21];  
              
void viderReserve(Reserve joueur){
        int i, nb;
        nb = strlen (joueur);
        for (i=0;i<nb;i++) joueur[i]=00;
        }

/* insertion d'une string dans une reserve pré-existante */
void insererPieces(Reserve joueur, char mot[]) {
          int i,j, nb, espaces;
          char aux;
          Reserve remplissage;
          /* pour inserer les caracteres dans l'ordre, on utilise une chaine auxiliaire */
          strcpy(remplissage, joueur);
          strcat(remplissage, mot);          
          nb = strlen(remplissage);
      
          for(i = 0; i < nb; i++){
                 j = i;
               while((j != 0) && (remplissage[j] < remplissage[j - 1])) {
                        if( remplissage[j]!=' '){
                        aux = remplissage[j];
                        remplissage[j] = remplissage[j - 1];
                        remplissage[j - 1] = aux;
                        j--;
                            }
                        else{ 
                          j--;  
                            }     
                }               
          }
          
          i=0;
          while(remplissage[i]!=' ') i++;
          if(remplissage[i]==' ') remplissage[i]='\0';
            
strcpy(joueur, remplissage);        
return;        
}
/* insertion des caracteres dans une reserve */


/* recherche d'un mot*/
/* sequentielle */
int recherche_Reserve(Reserve joueur, char mot[]) {
	int i, nb, j, nb2;
	char aux[strlen(joueur)], c[2]=" ", *pch;
    nb = strlen(mot);
    nb2 = strlen(joueur);
	strcpy(aux, joueur);
	
    i=0;
    while( i< nb ){
              pch=strchr(aux, mot[i]);
              if (pch==NULL) return -1;
              pch[0]=' ';
              i++;}
    return 1;
	
}
/* recherche du mot*/

/* impression de la réserve */
void imprimer_Reserve(Reserve joueur){
     int j=0;
      /* on imprime jusqu'a la fin la reserve du joueur  */   
       
    if( strlen(joueur)==0 ){ printf("La reserve est vide.\n");return;}
    
    printf("La reserve est: ");
    for(j=0;j<strlen(joueur);j++) printf("%c ", joueur[j]);
      printf("\n");
      return;
}
/* impression */       


/* enlever des pieces d'une reserve */
int enleverPieces(Reserve joueur, char mot[]) {
          int i,j, nb,nb2,espaces, aux = 0;
          Reserve remplissage;
          char teste[50], *pch;
          strcpy(remplissage, joueur);
          nb = strlen(mot);
          nb2 = strlen(remplissage);
          
          i=0;
          while( i< nb){
             j=0;
             while( remplissage[j] != mot[i] && j<nb2 ){ j++; }
             if( remplissage[j] == mot[i]) { remplissage[j]=' '; aux++; i++; }
             else {  return -1;  }  //l'enlevement est impossible.
          }
          pch=strchr(remplissage,' ');
          while (pch!=NULL){
              for( j= pch-remplissage ;j< strlen(remplissage);j++) remplissage[j]=remplissage[j+1];
              pch=strchr(pch,' ');
              }
strcpy(joueur, remplissage);    
return 1;

} 
/* enlever des pieces d'une reserve */

/* gestion du melange */
/* piocher une lettre (et mettre a jour le "sac de lettres" */
int piocher(Reserve joueur){
     int i, j, k,  restent=0;
     for(i=0; i<21; i++) restent += _lettres[i];
     
     i =rand()%restent+1;
     
     j=0;
     while(i>=0){        
        k=0;
        while( _lettres[j]-k > 0) k++;
        if( i-k >0) { j++; }
        i -=k;           
     }
    _lettres[j]--;
    if(j>=10) j++;
    
return j;     
}
/* piocher une lettre*/


/* mélange et distribution des lettres   */
/* avec création des réserves initiales */
 void melangeLettres(Reserve joueur1, Reserve joueur2){
       int i, j;
       // lettres c'est le vecteur de ponderation des lettres disponibles.
       char c[3]="  ";
       
       viderReserve(joueur1);
       viderReserve(joueur2);
       srand (time(NULL));
             
       for(j=0;j<11;j++){
       i = piocher(joueur1);
       c[0] = 'a'+i;
       insererPieces(joueur1, c);     
       i = piocher(joueur2);
       c[0] = 'a'+i;
       insererPieces(joueur2, c);
       }
     
return;
}
/* mélange et distribution des lettres   */
/*   fin des fonctions de la reserve  */
              
              /*    RESERVES   */
              
