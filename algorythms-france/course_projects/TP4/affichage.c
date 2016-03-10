/*************************************************************
                     TP TRI DES ALLUMETTES
                     
        fichier source de affichage.c

    ------------------------------------------------------

 Auteurs: Equipe pÈdagogique ALGPR
 Date: 21/04/2009
 Fichier: affichage.c
 But: ensemble de fonctions permettant d'afficher pseudo-
 	  graphiquement des allumettes que l'on souhaite trier

*************************************************************/

#include <curses.h>			// pour le pseudo-affichage graphique
#include <time.h>			// pour la gestion de la tempo dans affiche

#include "tris_def.h"
#include "affichage.h"

// Macros internes (Ne pas toucher)
#define gotoxy(x,y) move(y, x)
#define textcolor(color) attrset(COLOR_PAIR(color))


// fonction init
// but : initialise l'affichage pseudo graphique
void finish()
{
	textcolor(9);
	gotoxy(1,22);
	printw("\nFin : appuyer sur une touche pour terminer\n");
	refresh();
	
	getchar();
    endwin();
}


// function finish
// but : Quitte proprement le mode pseudo graphique
void init()
{
	initscr();      			/* initialize the curses library */
	keypad(stdscr, TRUE);  		/* enable keyboard mapping */
	nonl();         			/* tell curses not to do NL->CR/NL on output */
	cbreak();       			/* take input chars one at a time, no wait for \n */
	noecho();       			/* don't echo input */
	nodelay(stdscr, TRUE);		/* getch() don't wait for an input */	
	if (has_colors())
	{
	    start_color();

		// Initialise les couleurs
		// Seul le fond change, pour afficher des " " de diffÈrentes couleurs
	    init_pair(0, COLOR_BLACK, COLOR_BLACK);
	    init_pair(1, COLOR_BLACK, COLOR_WHITE);
	    init_pair(2, COLOR_BLACK, COLOR_RED);
	    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
		init_pair(4, COLOR_BLACK, COLOR_BLUE);
		init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
		init_pair(6, COLOR_BLACK, COLOR_GREEN);
		
		// Une couleur pour l'Ècriture : blanc sur fond noir
		init_pair(9, COLOR_WHITE, COLOR_BLACK);
	} 
	else
	{
		printw("Le terminal ne supporte pas les couleurs!\n");
		finish();
	}
}


// function affiche
// Affiche un vecteur d'allumettes fourni en paramËtre
void affiche(t_VectAllumettes A, int nbAllumettes)
{
	int i,j;
	int fin_attente=0;
	static int tempoAffichage = 500; 	// delai initial, en us.

	//if((nbAllumettes > 0) && (nbAllumettes < 41)) 
	//{
		for (i = 0; i < nbAllumettes; i++)
		{
			// VÈrifie la taille
			if ( (A[i].taille>20) || (A[i].taille<1) )
			{
				gotoxy(1,21);
				printw("L'allumette no %u a une taille invalide : %u\n",i,A[i].taille);
			}
		
			// VÈrifie la couleur, et la change pour celle de l'allumette
			if ( (A[i].couleur<BLANC) || (A[i].couleur>GREEN) )
			{
				gotoxy(1,22);
				printw("L'allumette no %u a une couleur invalide : %u\n",i,A[i].taille);
			}
			else		
				textcolor(A[i].couleur);
		
			// Affiche l'allumette
			for (j = 0; j < A[i].taille; j++)
			{
				// Positionnement
				gotoxy((i*2),20-j);

				// Affiche un espace (la couleur de fond fait que Áa affiche un
				// carrÈ
				printw(" ");
			}
		
			// Change la couleur pour celle du fond
			textcolor(0);
		
			// Efface l'allumette prÈcÈdente (en affichant des carrÈs de la couleur du fond)		
			for(j=A[i].taille;j<20;j++)
			{
				// Positionnement
				gotoxy((i*2),20-j);
				
				// Affiche un espace de la couleur du fond
				printw(" ");
			}
		}

		printw("\n");

		// Met ‡ jour ‡ l'affichage
		refresh();
	
	
		// attente et gestion des Èvenements
		time_t time=clock();
		while (!fin_attente)
		{
			// gestion des touches
			int key = getch();
			if (key==KEY_UP)
			{
				if (tempoAffichage > 100)
					tempoAffichage -= 100;
				else if (tempoAffichage > 10)
					tempoAffichage--;
			}
			if (key==KEY_DOWN)
			{
				if (tempoAffichage < 100)
					tempoAffichage++;
				else if (tempoAffichage < 5000)
					tempoAffichage += 100;
			}
		
			// vÈrification si on a attendu suffisamment longtemps
			fin_attente = ( (clock()-time)*1000/CLOCKS_PER_SEC ) > tempoAffichage;
		}
	//} else {
	//	gotoxy(1,21);
	//	printw("Erreur sur le nombre d'allumettes ! %u\n");
	//}
	
}
