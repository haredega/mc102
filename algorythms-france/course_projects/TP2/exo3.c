/* 
author : A. G. Heitor et L. Alexandre
date : 22-02-2013
file name : lancerDes.c

ENONCE:
jeu de l'oie   
*/

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>       /* time */

int lancer(int mode){
   int lancerActuel, i;
   if (mode ==1) {
      printf("Saisissez la some obtenue (0 pour sortir):");
      scanf("%d",&lancerActuel);
      printf("\n");         
      if(lancerActuel > 0 && lancerActuel < 13){ return lancerActuel;}
      else {printf("Lancer Impossible. Essayez a nouveau\n");  return lancer(1);}     
   }
   else if(mode == 2) {
        i = rand()%6+1;
        printf("Des 1: %d\n", i);
        lancerActuel = i;
        i = rand()%6+1;
        printf("Des 2: %d\n", i);
        lancerActuel += i;
        printf("Somme des des: %d\n", lancerActuel);
        return lancerActuel;
        }
}

int tour ( int positions[], int enjeu, int mode ){
    int i, plus, aux, dep;
    for( i=0; i < enjeu; i++){
         if( positions[i]!=-1){
             printf("C'est le tour de JOUEUR %d\n", i+1);
             plus = lancer(mode);
             aux = positions[i]+plus;
             
             switch (aux){
                    case 9:
                    case 18:
                    case 27:
                    case 36:
                    case 45:
                    case 54:
                         printf("Le joueur est tombe sur l'oie!\n");
                         aux += plus; 
                         break;
                    case 63:
                         printf("Le joueur %d a gagné\n", i+1); 
                         return 1;    
                    case 52:
                         printf("Perdu! Le joueur %d est dans la prison!\n", i+1);
                         positions[i] = -1;              
                         break;
             } // end switch
             
             if( aux > 63) {  dep = aux-63; aux = 63-dep; 
                 if( aux == 54) aux -= dep;}
             } //end if
             positions[i] = aux;
             if( positions[i]!=-1) {printf("Le joueur %d est tombe sur la case %d\n", i+1, aux);}
         } //end if       
    } //end for

    return 0;   
}


int main(void)
{   int enjeu, fin, i, mode;
    srand (time(NULL));
    
    printf("Combien de personnes jouent?");
    scanf("%d", &enjeu);
    
    do{ printf("\nQuel est le mode de jeu?\n");
    printf("1 pour manuel et 2 pour automatique:");             
    scanf("%d", &mode);
    if( mode !=1 && mode !=2) printf("\nMode non-disponible. Essayez a nouveau.\n");
    }while (mode !=1 && mode !=2); 
        
    int positions[enjeu];
    for (i=0; i < enjeu ; i++){ positions[enjeu-1] = 0;}
    
    while ( fin !=1){
          fin = tour( positions, enjeu, mode);
          }
    
    printf("\n");    
    system ("pause");     /*apagar depois*/
	return (EXIT_SUCCESS);
}
