#include "tris_def.h"

void lecture_fichier(int *nb_All, t_VectAllumettes Allumettes){
	int i;
	FILE *finput;
	finput = fopen("allumettes_donnees.txt","r");
	
	fscanf(finput,"%d",nb_All);       //le premier nombre du fichier represent le nombre d'allumettes
	for(i = 0;i < *nb_All; i++){
		fscanf(finput,"%d %d",&Allumettes[i].couleur,&Allumettes[i].taille);    //lit, ligne par ligne, les proprietes de chaque allumette
	}
	
	fclose(finput);
	return;
}

void ecriture_fichier(int nb_All, t_VectAllumettes Allumettes){
    int i;
	FILE *foutput;
	foutput = fopen("sortie_allumettes.txt","w");
	
	fprintf(foutput,"%d\n",nb_All);		//affiche à la premiere ligne le nombre d'allumettes
	for(i = 0;i < nb_All; i++){
		fprintf(foutput,"%d %d\n",Allumettes[i].couleur,Allumettes[i].taille);		//affiche en chaque ligne les proprietes de chaque allumette
	}
	
	fclose(foutput);
	return;
}