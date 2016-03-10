/*************************************************************

           Fonctions permettant de gérer l'affichage
              des fourmis et du monde environnant
                 (affichage effectué sous X)

    ------------------------------------------------------

 Auteur: HILAIRE Thibault, BRIDAY MikaÎl
 Date: 01/10/2003
 Révisé et porté en C par Didier LIME le 7/05/2009
 Fichier: affichage.c
 Compilation: gcc -c affichage.c
 Edition de liens: options -lX11 -L/usr/X11R6/lib
                   pour l'utilisation de la librairie de X11
 But: prototypes des fonctions permettant de gérer l'affichage
      de fourmis, du monde dans lequel elles évoluent (nourriture
      et obstacles) et des pheromones

*************************************************************/

#include <X11/Xlib.h>			// pour XLib
#include <X11/keysym.h>			// pour les touches XLib

#include <stdio.h>			// pour l'affichage des erreurs
#include <time.h>			// pour initialiser le générateur aléatoire avec l'heure courante
#include <stdlib.h>         // pour srand et malloc
#include "constantes.h" 		//défini NOURRITURE_MAX

// constantes (pour le graphique)
#define CASE				7
#define FOURMI				2
#define INDICE_COULEUR_PHERO_MAX	100


// type "t_pos" pour stocker une fourmi (sa position et son mode)
typedef struct
{
	int x;
	int y;
	int recherche;
} t_pos;

// Liste chaÓnée de t_pos
typedef struct t_listpos
{
    t_pos pos;
    struct t_listpos * next;
} t_lpos;

// Variables X11
Display* display;
int screen;
GC gc;
Window w;
Colormap cmap;

// Pixmap
Pixmap pix;
Pixmap fond;

// couleurs
unsigned int CoulFourmis[2];
unsigned int CoulObstacle;
unsigned int CoulNourriture;
unsigned int CoulTabNourriture[NOURRITURE_MAX + 1];
unsigned int CoulFourmiliere;
unsigned int CoulPheromones[INDICE_COULEUR_PHERO_MAX+1];
unsigned int CoulFond;


// Variables communes
int init=0;		// permet de savoir si on a lancé InitAffichage

t_lpos* fourmis = NULL;		// liste de position de fourmi
t_monde env;			// copie de l'environnement

//t_pos fourmiliere;	// position de la fourmilière


//fonction: AlloueCouleur
//arguments: red,green,blue : quantité (16bits) de rouge,vert et bleu qui compose la couleur
//but: allocation d'une couleur dans la ColorMap
//principe: fonction XAllocColor - renvoit un entier non signé identifiant la couleur dans la ColorMap
unsigned int AlloueCouleur( int red, int green, int blue)
{
	XColor coul;
	coul.green = green;
	coul.red = red;
	coul.blue = blue;
	XAllocColor( display, cmap, &coul);
	return coul.pixel;
}


//fonction: phero2indice
//arguments: phero : valeur de phéromones
//           x,y : position de la pheromone
//but: permettre la conversion entre la phéromone et la couleur à afficher
//     pour passer d'un indice de pheromones (entre -PHEROMONES_MAX et PHEROMONES_MAX)
//     à un indice de couleur (entre 0 et INDICE_COULEUR_PHERO_MAX-1)
//     permet aussi de faire les vérifications sur le niveau de phéromones
//principe: indice <- phero*INDICE_COULEUR_PHERO_MAX/(PHEROMONES_MAX+1)
//          (fonction très utile quand je testais une phéromone compris entre -PHEROMONES_MAX et +PHEROMONES_MAX)
int phero2indice( int phero, int x, int y)
{
	if ( phero<0 )
	{
		fprintf(stderr, "Warning (AffichePheromones) : l'indice de phéromone ne peut Ítre négatif (x=%d y=%d phero=%d)\n",x,y,phero);
		phero=0;
	}
	if (phero>PHEROMONES_MAX)
	{
		fprintf(stderr, "Warning (AffichePheromones) : l'indice de phéromone ne peut Ítre supérieur à %d (x=%d y=%d phero=%d)\n",PHEROMONES_MAX,x,y,phero); 
		phero=PHEROMONES_MAX;
	}
	return phero*INDICE_COULEUR_PHERO_MAX/(PHEROMONES_MAX+1);
}


//action: InitAffichage
//arguments: L : largeur du monde à afficher
//           H : hauteur du monde à afficher
//but: préparer l'affichage du monde
//     cette fonction renvoit 0 si l'initialisation n'a pas marché
//     cette fonction doit Ítre utilisée obligatoirement UNE SEULE FOIS, et avant toutes les autres
//principe: création de la fenÍtre X11, initialisation des couleurs, des pixmap, etc...
int InitAffichage( int L, int H)
{
    int i,j;
	// Vérification
	if ( (L>TAILLE_MONDE_MAX) || (H>TAILLE_MONDE_MAX) )
	{
		fprintf(stderr, "Erreur (InitAffichage) : la longueur et la hauteur du 'monde' ne peuvent dépasser %d",TAILLE_MONDE_MAX);
		return 0;
	}
	if ( (L<5) || (H<5) )
	{
		fprintf(stderr, "Erreur (InitAffichage) : la longueur et la hauteur du 'monde' ne peuvent etre inférieur à 5\n");
		return 0;
	}

	// Initialisation X11
	if ( (display=XOpenDisplay(NULL)) == NULL )
	{
		fprintf(stderr, "Erreur (InitAffichage) : connection avec X impossible : X est-il lancé ??\n");
		return 0;
	}

	// crée la fenetre
	screen = DefaultScreen(display);
	gc = DefaultGC (display, screen);
	cmap = DefaultColormap( display, screen);
	w = XCreateSimpleWindow( display, RootWindow(display,screen), 0,0, L*CASE+5,H*CASE+5,2, BlackPixel(display,screen), WhitePixel(display,screen));
	XStoreName( display, w, "FourmiZ");

	// crée la table de couleur
	CoulObstacle = AlloueCouleur( 5000,5000,65535);			// bleu
	CoulNourriture = AlloueCouleur( 5000,65535,5000);		// vert
	for(i=0;i<=NOURRITURE_MAX;i++)
	{
		int j = 30000*i/NOURRITURE_MAX;
		CoulTabNourriture[i] = AlloueCouleur( 65535-2*j,65535-j,65535-2*j);		// du blanc->jaune
	}
	CoulFourmiliere = AlloueCouleur( 65535,5000,65535);		// violet
	CoulFourmis[1] = AlloueCouleur( 65535,5000,5000);		// rouge
	CoulFourmis[0] = AlloueCouleur( 8000,8000,65535);		// bleu clair
	CoulFond = AlloueCouleur( 50000,50000,50000);			// gris
	for(i=0;i<INDICE_COULEUR_PHERO_MAX+1;i++)
	{
		int j = (30000/INDICE_COULEUR_PHERO_MAX)*i;
		CoulPheromones[i] = AlloueCouleur( 65535-2*j,65535-j,65535-j);			// du blanc->grisvert
	}

	// crée le pixmap dans lequel on va tout dessiner
	int prof = XDefaultDepth (display, screen);
	pix = XCreatePixmap (display, RootWindow(display,screen), L*CASE+1,H*CASE+1, prof);

	// crée le pixmap de fond (dans lequel on rajoutera les obstacles )
	fond = XCreatePixmap (display, RootWindow(display,screen), L*CASE+1,H*CASE+1, prof);
	XSetForeground( display, gc, WhitePixel(display,screen) );
	XFillRectangle( display,fond,gc, 0,0, L*CASE+1,H*CASE+1);
	XSetForeground( display, gc, CoulFond);
	for(i=0;i<=H;i++)	XDrawLine( display,fond,gc, 0,i*CASE,L*CASE,i*CASE);
	for(j=0;j<=L;j++)	XDrawLine( display,fond,gc, j*CASE,0,j*CASE,H*CASE);
	XCopyArea( display, fond, pix, gc, 0,0, L*CASE+1,H*CASE+1, 0,0);

	// initialisation de obstacles et cases réservées..
	env.L=L;
	env.H=H;
	env.Fx=env.Fy=0;
	for(i=0;i<=L;i++)
		for(j=0;j<=H;j++)
			env.mat[i][j]=VIDE;

	// sélectionne les évennements que l'on va gérer (renouvellement de l'affichage et gestion des touches)
	XSelectInput (display, w, ExposureMask | KeyPressMask);

	// affiche la fenetre
	XMapWindow(display, w);

	// on en profite pour initialiser le générateur de nb aléatoire, avec la date courante
	srand(time(0));

	// mise à jour d'init (qui indique si on est passé dans InitAffichage)
  	init=1;

	return 1;
}


//action: AfficheFourmi
//arguments: x : position en x de la fourmi à afficher
//           y : position en y de la fourmi à afficher
//           mode : indique dans quel mode se trouve la fourmi
//                  0 : la fourmi est en mode "j'ai trouvé de la nourriture, je retourne à la fourmillière"
//                  1 : la fourmi est en mode "je suis en recherche de nourriture"
//but: afficher la fourmi dans le monde
//principe: on stocke les paramètres de la fourmi dans une liste, et on l'affichera dans MiseAJourAffichage
//          (on ne peut l'afficher qu'après avoir affiché la nourriture et la phéromone, et on en profite pour toutes les afficher en meme temps)
void AfficheFourmi( int x, int y, int recherche)
{
	// vérifications
	if (!init) fprintf(stderr, "Warning (AfficheFourmi) : InitAffichage n'a pas encore été exécuté\n");
	if ( (x<0) || (x>env.L) || (y<0) || (y>env.H) )
		fprintf(stderr, "Warning (AfficheFourmi) : coordonnées de fourmi incorrecte (x=%d  y=%d)\n",x,y);
	if (env.mat[x][y]==OBSTACLE)
		fprintf(stderr, "Warning (AfficheFourmi) : une fourmi est sur un obstacle (x=%d  y=%d)\n",x,y);

    // Création et ajout de la fourmi
    t_lpos* nf = (t_lpos*) malloc(sizeof(t_lpos));
    nf->pos.x = x;
    nf->pos.y = y;
    nf->pos.recherche = recherche;
    nf->next = fourmis;
    fourmis = nf;
}


//action: AfficheFourmiliere
//arguments: x : position en x de la fourmiliere à afficher
//           y : position en y de la fourmiliere à afficher
//but: afficher la fourmiliere en (x,y)
//principe: stocke la position de la fourmillière dans une liste
//          celle-si sera en fait affichée pendant MiseAJourAffichage
// (on fait ça, parce que les fourmis déposent de la nourriture sur la fourmillière
// et qu'il est plus simple de la réafficher à chaque fois, que de vérifier qu'on affiche
// pas de la nourriture sur une fourmillière)
/*void AfficheFourmiliere(int x, int y)
{
	// vérifications
	if (!init)
		fprintf(stderr, "Warning (AfficheFourmiliere) : InitAffichage n'a pas encore été exécuté\n");
	if ( (x<0) || (x>env.L) || (y<0) || (y>env.H) )
		fprintf(stderr, "Warning (AfficheFourmiliere) : coordonnees incorrectes (x=%d  y=%d)\n",x,y);
	if (FourmiliereDefinie)
		fprintf(stderr, "Warning (AfficheFourmiliere) : On ne peut appeler qu'une fois AfficheFourmillière\n");
	FourmiliereDefinie = true;
	// stocke dans une liste
	fourmiliere.x=x;
	fourmiliere.y=y;
}*/


//action: AfficheEnvironnement
//argument: environnement : t_monde contenant l'environnement (obstacles et nourriture)
//but: afficher l'environnement en cours (obstacles en bleu et nourriture en vert : un point vert au milieu, et un rectangle dont l'intensité
//     du vert indique la quantité de nourriture présente)
//principe: recopie de l'environnement dans la variable globale environnement (pour vérifier que les fourmis ne marchent pas sur les obstacles)
//          et affichage des rectangles (couleurs différentes)
void AfficheEnvironnement( t_monde environ)
{
	int i,j;
	// vérifications
	if (!init)
		fprintf(stderr, "Warning (AfficheEnvironnement) : InitAffichage n'a pas encore été exécuté\n");

	if ( (env.H!=environ.H) || (env.L!=environ.L) )
	{
		fprintf(stderr, "Warning (AfficheEnvironnement) : la taille de l'environnement passé en argument d'AfficheEnvironnemnt n'a pas la mÍme taille celle donnée à la fonction InitAffichage\n");
		fprintf(stderr, "\t\t taille donnée à InitAffichage : (%d, %d)\n", env.L, env.H);
		fprintf(stderr, "\t\t taille de cet environnement   : (%d, %d)\n", environ.L, environ.H);
	}
	
	// copie du tableau + affichage
	for(i=0;i<env.H;i++)
		for(j=0;j<env.L;j++)
		{
			if (environ.mat[i][j]==OBSTACLE)
			{
				// copie les obstacles sur pix
				XSetForeground( display, gc, CoulObstacle);
				XFillRectangle( display,pix,gc, i*CASE+1,j*CASE+1, CASE-1, CASE-1);
			}
			else if ( (environ.mat[i][j]<=NOURRITURE_MAX) && (environ.mat[i][j]>VIDE) )
			{
				// copie la nourriture sur pix
				XSetForeground( display, gc, CoulTabNourriture[ environ.mat[i][j] ]);
				XFillRectangle( display,pix,gc, i*CASE+1,j*CASE+1, CASE-1, CASE-1);
				XSetForeground( display,gc, CoulNourriture);
				XFillRectangle( display,pix,gc, i*CASE+3,j*CASE+3, FOURMI, FOURMI);
			}
			else
			{
				if ( (i!=environ.Fx) && (j!=environ.Fy) && (environ.mat[i][j]!=VIDE) )
				fprintf(stderr, "Warning (AfficheEnvironnement) : le tableau environnement contient d'autres valeurs que OBSTACLE, VIDE  ou bien une quantite de nourriture supérieure à %d\n", NOURRITURE_MAX);
			}
			env.mat[i][j] = environ.mat[i][j];
		}

	// copie la fourmilière sur pix
	XSetForeground( display, gc, CoulFourmiliere);
	XFillRectangle( display,pix,gc, environ.Fx*CASE+1,environ.Fy*CASE+1, CASE-1, CASE-1);
	env.Fx=environ.Fx;
	env.Fy=environ.Fy;

}


//action: AffichePheromones
//argument: pheromones : matrice représentant le niveau de phéromones
//but: afficher la quantité de phéromones du monde
//principe: afficher (couleur suivant la quantité de phéromones) un rectangle sur les cases qui sont vides
//          (on n'affiche pas de phéromones ailleurs, ni sur les obstacles, la nourriture ou la fourmillière)
void AffichePheromones( t_matrice phero)
{
	int i,j;
	// vérification
	if (!init)
		fprintf(stderr, "Warning (AffichePheromones) : InitAffichage n'a pas encore été exécuté\n");

	// parcourt du tableau
	for(i=0;i<env.L;i++)
		for (j=0;j<env.H;j++)
		{
			if ( (env.mat[i][j]==VIDE) && ((i!=env.Fx) || (j!=env.Fy)) )
			{
				XSetForeground( display, gc, CoulPheromones[ phero2indice(phero[i][j],i,j) ]);
				XFillRectangle( display,pix,gc, i*CASE+1,j*CASE+1, CASE-1, CASE-1);
			}
		}
}


//action: MiseAJourAffichage
//but: permet de faire une pause en fin d'affichage
//     nécessaire pour gérer les évènement graphiques (déplacement de fenÍtre, touche pressée au clavier, etc...)
//     renvoit 0 si l'utilisateur a pressé la touche ESC (et 1 sinon)
//principe: on affiche les fourmis sur le pix, puis on affiche le pix à l'écran (les fourmis, les obstacles, la nourriture sont donc affichés
//          tous ensembles, et en une seule fois)
//          une boucle d'attente (delai fixé par argument) permet de gérer les évènements/signaux qui peuvent intervenir : fenÍtre cachée ou
//          réaffichée, touche pressée, etc...
int MiseAJourAffichage()
{
	int fin_attente = 0;
	static int nb_iter = 1;
	static int tempoAffichage = 100; //en us.

	// vérifications
	if (!init)
		fprintf(stderr, "Warning (MiseAJourAffichage) : InitAffichage n'a pas encore été exécuté\n");

	// affiche les fourmis en parcourant la liste des fourmis
    t_lpos* it;
    t_lpos* its;
    it = fourmis; 
    while (it != NULL)
	{
        // Affiche la fourmi
		XSetForeground( display, gc, CoulFourmis[it->pos.recherche]);
		XFillRectangle( display,pix,gc, it->pos.x*CASE+3,it->pos.y*CASE+3, FOURMI,FOURMI);
        
        // et la retire de la liste
        its = it;
        it = it->next;
        free(its);
	}
    fourmis = NULL;

	// affiche tout à l'écran
	XCopyArea( display, pix, w, gc, 0,0, env.L*CASE+1,env.H*CASE+1, 2,2);

	// copie du fond (grille) sur pix pour le tour suivant
	XCopyArea( display, fond, pix, gc, 0,0, env.L*CASE+1,env.H*CASE+1, 0,0);

	// attente et gestion des évenements
	time_t time=clock();
	while(!fin_attente)
	{
		XEvent e;
		if (XPending(display))		// y'a-t-il un event qui nous attent
		{
			XNextEvent(display,&e);
			switch (e.type)
			{
				case Expose :				// réaffichage demandé
					XCopyArea( display, pix, w, gc, 0,0, env.L*CASE+1,env.H*CASE+1, 2,2);
					break;
				case KeyPress:			// touche pressée
					if (XLookupKeysym(&e.xkey, 0) == XK_space)	fin_attente=1;
					else if (XLookupKeysym(&e.xkey, 0) == XK_KP_Add)	// ('+') plus vite
					{
						if(tempoAffichage > 10) tempoAffichage -= 10;
						else if(tempoAffichage > 1) tempoAffichage--;
					}
					else if (XLookupKeysym(&e.xkey, 0) == XK_KP_Subtract)	// ('-') plus vite
					{
						if(tempoAffichage < 10) tempoAffichage++;
						else tempoAffichage += 10;
					}
					else if (XLookupKeysym(&e.xkey, 0) == XK_Escape)
					{
						XCloseDisplay( display);

						// teste si la fourmilière est correctement placée
						if ( (env.Fx<0) || (env.Fx>env.L) || (env.Fy<0) || (env.Fy>env.H) )
						{
							fprintf(stderr, "Warning (MiseAJourAffichage) : la fourmilière est placée en (%d, %d)\n", env.Fx, env.Fy);
						}
						else
						{
							// affiche les conclusions : nourriture par fourmillière
							printf("Simulation en %d itérations\n", nb_iter); 
							printf("Nourriture rapportée à la fourmillière = %d\n", env.mat[env.Fx][env.Fy]);
						}
						return 0;
					}
					break;
			}
		}
		// vérification si on a attendu suffisamment longtemps
		// (façon de faire absolument horrible, j'ai honte; mais faire "propre" me demanderait trop de temps)
		if ( ((clock()-time)*1000/CLOCKS_PER_SEC) > tempoAffichage) fin_attente=1;
 	}

	nb_iter++;	// compte le nombre d'itérations
	return 1;
}

