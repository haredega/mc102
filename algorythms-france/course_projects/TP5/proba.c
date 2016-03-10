/*************************************************************

          Tirage aléatoire et tirage aléatoire pondéré

    ------------------------------------------------------

 Auteur: HILAIRE Thibault
 Date: 01/10/2003
 Révisé et porté en C par Didier LIME le 7/05/2009
 Fichier: proba.c
 Compilation: gcc -c proba.c
 But: Fonctions permettant d'effectuer un tirage au sort (compris entre
      0 et un nombre maximum donné en argument)
      et un tirage au sort pondéré, entre 0 et 7 (le tirage n'est pas équiprobable,
      un vecteur de ponderation est fourni en argument)

*************************************************************/


#include <stdlib.h>		// pour rand()
#include <stdio.h>		// pour fprintf()
#include <math.h>		// pour floor()
#include "proba.h"		// pour t_poids

//fonction: nalea
//argument: max : valeur maximum pour le tirage aléatoire
//but: renvoie un entier aléatoire compris entre 0 et max-1 (inclus)
int nalea( int max)
{
	// la fonction rand() renvoit un entier entre 0 et RAND_MAX-1
	return (int)floor( rand()*((float)max)/RAND_MAX );
}


//fonction: nalea_pondere
//argument: poids : vecteur de ponderation
//but: renvoie un nombre tiré au sort (entre 0 et 7). Le tirage n'est pas équiprobable car il est pondéré par le vecteur poids
// principe: on calcule un vecteur des sommes partielles des ponderations, on tire au sort entre 0 et la somme des ponderation - 1, puis on regarde
// à quelle indice ce tirage fait référence
int nalea_pondere( t_poids poids)
{
	t_poids s;
	int rand;
    int i;

	// vérifications sur le vecteur de ponderation
	int somme;
	for(i=0;i<8;i++)
	{
		if (poids[i]<0)
			fprintf(stderr, "Warning (nalea_pondere) : une ponderation ne peut être négative (poids[%d]=%d)\n", i, poids[i]);
		somme = somme + poids[i];
	}
	if (somme==0)  fprintf(stderr, "Warning (nalea_pondere) : toutes les ponderations sont nulles\n");

	// somme partielle
	s[0]=0;
	for(i=1;i<8;i++)
		s[i]=s[i-1]+poids[i-1];

	// tirage au sort
	rand=nalea(s[7]+poids[7]);

	// recherche
	for(i=7;i>=0;i--)
		if (s[i]<=rand) return i;

	return 0;	// ne sert pas
}
