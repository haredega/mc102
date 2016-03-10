#include "tris_def.h"
#include "inserer.h"

void inserer(t_VectAllumettes Allumettes, int i, int j){
	int k;
	t_Allumette aux;
	
	aux = Allumettes[i];
	
	for(k = i ; k > j ; k--){
		Allumettes[k] = Allumettes[k-1];
	}
	
	Allumettes[j] = aux;
	return;
}