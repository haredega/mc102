#include "tris_def.h"
#include "lectecr.h"
#include "inserer.h"
#include "tri_insertion.h"
#include "affichage.h"

int main(){
	int nb_All;
	t_VectAllumettes Allumettes;
	
	init();

	lecture_fichier(&nb_All, Allumettes);
	tri_insertion(nb_All, Allumettes);
	ecriture_fichier(nb_All,Allumettes);
      
	affiche(Allumettes,nb_All);

	finish();

	return 0;
}