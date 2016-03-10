#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "entierlong.h"
#include "lit_ecrit.h"
#include "utilitaires.h"


t_EntierLong conversion_std_en_long(int std){
       int i;      
       t_EntierLong n_long;
       
       if(std > 0){
          n_long.negatif = 0;
	  }

       else{
          n_long.negatif = 1;  
       }   
       
       i = 0;
       while(std != 0){            
            if (std>0) n_long.chiffres[i] = std%10;
	    else n_long.chiffres[i] = -std%10;
	    i++;
            std=std/10;   //apres avoir affecte le numero des unites dans le vecteur on reduit l'entier de facon a ce que les dizaines deviennent les unites         
       }
       for(;i < MAXCHIFFRES ;i++){    //on n'initialise pas la variable i dans for pour qu'elle ait sa valeur en fin de boucle while
	    n_long.chiffres[i] = 0;
	}
             
       return n_long;
}

int comparaison(t_EntierLong n1,t_EntierLong n2){
    int i=0;
    if(n1.negatif != n2.negatif) return 0;   //s'ils n'ont pas la même signe la fonction le signale immediatement
    
    for(i=0 ; i<MAXCHIFFRES ;i++){
        if(n1.chiffres[i] != n2.chiffres[i]) return 0;  //si un des chiffres differe, la fonction le signale immediatement
    }  
    return 1;  //si aucun des cas precedent arrive, la fonction return 1, c'est-a-dire, les numeros sont les memes
}

int comp_valeur_abs(t_EntierLong n1,t_EntierLong n2){
    int i;
    
    i = MAXCHIFFRES - 1;
    while (i >= 0 && n1.chiffres[i] == n2.chiffres[i]) i--;   //On compare les chiffres des deux entiers en partant des poids les plus forts
    
    if(i < 0 ) return 1;   //il retourne 1 parce que les nombres sont egaux en valeur absolue
    
    if(n1.chiffres[i] < n2.chiffres[i]) return 1;    //il retourne 1 parce que le premier est le plus petit
    else return 0;   
}       