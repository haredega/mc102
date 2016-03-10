/* 
author : A. G. Heitor et L. Alexandre
date : 22-02-2013
file name : lancerDes.c

ENONCE:
Calculer les fréquences por une suite de lancers de dés.       
*/

#include <stdlib.h>
#include <stdio.h> 

int main(void)
{
    float nbLancers=0, nb[6]={0,0,0,0,0,0}, d;
    int lancerActuel, i;
    do {
    printf("Saisissez le numero obtenu ( <0 ou >6 pour sortir):");
    scanf("%d",&lancerActuel);
    printf("\n");
    if(lancerActuel > 0 && lancerActuel < 7){    
        nbLancers++;
        nb[lancerActuel-1]++;
        }
    }  while (lancerActuel>0 && lancerActuel<7); 
    
    if( nbLancers==0) printf("Aucune valeur entre 1 et 6");
    else {
         printf("%d ", nbLancers);
         for(i=0; i<6; i++) {
                  d= nb[i]*100/nbLancers;
                  printf("Frequence de %d : %f\n", i+1 , d );}
    }
    
    printf("\n");    
    system ("pause");     /*apagar depois*/
	return (EXIT_SUCCESS);
}
