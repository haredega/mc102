/* 
author : A. G. Heitor et L. Alexandre
date : 12-02-2013
file name : ADeboguer.c

ENONCÉ
Vous ne devez retirer aucune instruction de ce programme.
Vous devez ajouter les éléments nécessaires pour que la compilation 
et l'éxécution se déroulent correctement
*/

#include <stdlib.h>
#include <stdio.h>  //on ne peut 

main(void){  /* main ne doit pas etre de type void */
     int nbBug; /* cette variable n'etait pas declare */


	printf("A votre avis, combien est-ce que je contiens de bogues ?\n"); /* on retire l'appel a nbBug et on ajoute un ; */
	scanf("%d", &nbBug);	
	
	while(nbBug < 0) { 
		printf("Le nombre de bogues doit etre positif\n");  //on retire l'appel a nbbug (qui, en plus, n'existe pas)
		scanf("%d", &nbBug); // on ne peut pas changer le types des variables au cour du programme
	}

	printf("Vous avez dit que je contiens ");

	if(nbBug == 0 || nbBug == 1) { // on ne peut pas affecter les variables dans les conditions. donc, on a mis == au lieu de =
		printf("%d bogue\n", nbBug);
	} else {
		printf("%d bogues\n", nbBug);
	}

    system ("pause");     /*apagar depois*/
	return;	
}

