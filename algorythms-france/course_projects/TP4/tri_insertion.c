#include "tris_def.h"
#include "inserer.h"
#include "tri_insertion.h"
#include "affichage.h"

void tri_insertion(int nb_All, t_VectAllumettes Allumettes){
	int i,j;
	int aux_couleur_i, aux_couleur_j;
	
	for(i = 0 ; i < nb_All ; i++){
		j = 0;
		while(j < i && Allumettes[j].taille <= Allumettes[i].taille){
			j++;
		}

		aux_couleur_i = Allumettes[i].couleur;
		aux_couleur_j = Allumettes[j].couleur;

		Allumettes[i].couleur = BLANC;
		Allumettes[j].couleur = BLANC;
		affiche(Allumettes,nb_All);

     
		Allumettes[i].couleur = aux_couleur_i;
		Allumettes[j].couleur = aux_couleur_j;
		
  
		inserer(Allumettes,i,j);
	}
	return;
}

