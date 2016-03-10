#include "fourmi.h"
#include "constantes.h"

void LireEnvironnement(int *L, int *H, t_fourmi *f1, t_monde *mondeA){
	int i,j;
	FILE *finput;
	finput = fopen("monde1.dat","r");
	
	fscanf(finput,"%d %d %d %d",L,H, f1->x, f1->y);       //les premiers nombres sont les tailles du monde et les coordonées de la fourmillière.

	for(i = 0;i<*H; i++){
		for (j=0; j<*L; j++){
		    fscanf(finput,"%d",mondeA->mat[i][j]);    //lit, ligne par ligne, colomne par colomne, les cases de la carte du monde
		}

	}
	
	fclose(finput);
	return;
}