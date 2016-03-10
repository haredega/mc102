#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "entierlong.h"
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"

t_EntierLong add_meme_signe(t_EntierLong n1,t_EntierLong n2){
    int i,retenue;
    t_EntierLong somme;
    
    somme.negatif = n1.negatif;
    
    retenue = 0;    
    for(i = 0 ; i <  MAXCHIFFRES ; i++){   
          somme.chiffres[i] = (retenue + n1.chiffres[i] + n2.chiffres[i])%10;
          retenue = (retenue + n1.chiffres[i] + n2.chiffres[i])/10;    
    }
    
    return somme;    
}

t_EntierLong sous_meme_signe(t_EntierLong n1,t_EntierLong n2){
    int i,j;
    t_EntierLong soustraction;

    if(comparaison(n1,n2)){
      for(i = 0 ; i <  MAXCHIFFRES ; i++) soustraction.chiffres[i] = 0;   //si les numeros sont egaux, le resultat est directement 0
      soustraction.negatif = 0;     
    }

    else{                   
        soustraction.negatif = n1.negatif;        

        for(i = 0 ; i <  MAXCHIFFRES ; i++) {   
           if(n1.chiffres[i] >= n2.chiffres[i]) soustraction.chiffres[i] = n1.chiffres[i] - n2.chiffres[i];

           else {                         
                 soustraction.chiffres[i] = n1.chiffres[i] - n2.chiffres[i] + 10;          
                 j = i + 1;
                 if( j < MAXCHIFFRES) n1.chiffres[j]--;
           }
        }
    }
    
    return soustraction;    
}

t_EntierLong addition_quelconque(t_EntierLong n1,t_EntierLong n2){
    t_EntierLong addition_quelconque;          

    if(n1.negatif == n2.negatif) addition_quelconque = add_meme_signe(n1,n2);

//à finir si on a de temps
             
    return addition_quelconque;         
}