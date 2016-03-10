#include "structures.h"
#include <stdio.h>
#include <string.h> 

/*       TA ALGPR         OCTO-VERSO                     */
/*       GROUPE I         ELEVES INGENIEURS:             */
/*       AREDE GARCIA HEITOR    DENARDI ALINE            */
/*       GUITTON BARBARA        MUSHAMALIRWA ANNE-MARIE  */


/* Gestion des mots deja utilises */
 /* inserer la biblio string.h !! */

/* type Mot Utilise */
/* chaque noeud contient un mot et l'adresse du prochain mot */

/* création d'un Noeud */
Mot_Utilise *creerNoeud(char mot[], Mot_Utilise *next){
	   
           Mot_Utilise *c;
           /* allocation dynamique */
           c = (Mot_Utilise*) malloc(sizeof(Mot_Utilise));          
	       
           /* on affecte le noeud qu'on vient de créer  */ 
	       strcpy(c->mot, mot );	
	       c->next = next; 
	       /* permet d'ordonner la liste */

           return c;

}	
/* création d'un Noeud */

/* insertion d'un Noeud dans une liste pré-existante */
Mot_Utilise* insererMot(Mot_Utilise **dernier, char mot[]) {
          Mot_Utilise *p, *a;
          p = *dernier;
          a = p; 
          /* pour inserer le nouveau Noeud dans l'ordre, on utilise 2 noeuds auxiliaires */
          
          if(*dernier == NULL)
                { *dernier = creerNoeud(mot, NULL); return *dernier;}
          /* s'il n'y a pas de noeud, on en crée un */
                  
         else{       
                 /* sinon, on le met dans la liste, entre 2 noeuds,  */
                 /* l'anterieur (a) et le prochain (p)*/
                                  
                 while( p != NULL && strcmp(mot, p->mot) > 0 )
                      { a = p; p = p->next; }         

                 if ( a==p )
                     { p = creerNoeud(mot, p); return p; }   
                                        
                 else                 
                 { a->next = creerNoeud(mot, p); return *dernier; } 

         } 
}
/* insertion d'un Noeud */


/* recherche du mot*/
/* sequentielle, noeud par noeud */
int recherche(Mot_Utilise *dernier, char mot[]) {
	Mot_Utilise *q;
	q = dernier;
	
	/* s'il n'y a pas de liste, le mot est bon */
	if(q == NULL)
       { printf("Ok! Ce mot n'a pas encore ete utilise! \n\n"); return 1; }    
    
    /* sinon, on cherche le mot jusqu'a la fin de la liste */    
	while( ( q->next != NULL) && (strcmp( q->mot, mot) != 0) )	
  		q = q->next;
  	
    /* si on trouve le mot, il est pas bon */  	
	if( strcmp(q->mot, mot) == 0) 
		{ printf("Attention!! Le mot %s a deja ete utilise!!\n\n", q->mot); return -1; }
	
	/* sinon, il est bon */
	else 
		{ printf("Ok! Ce mot n'a pas encore ete utilise!\n\n");  return 1; }
}
/* recherche du mot*/

/* impression de la liste sur l'ecran */
void imprimer_Tout(Mot_Utilise *dernier){
      Mot_Utilise *q;
      
      /*  s'il n'y a pas de liste, on l'affiche */
      if ( dernier == NULL)
         { printf("Le jeu vient de commencer!\nIl n'y a pas encore de mot utilise!\n\n"); return; }
         
      /* s'il y a, on l'imprime jusqu'a la fin  */      
      
      else{
         printf("----%c----\n", dernier->mot[0]);
         while (dernier != NULL) {
             printf("%-8s \n", dernier->mot);
             if (dernier->next != NULL){
                 q = dernier->next;
                   if(q->mot[0] != dernier->mot[0])
                     printf("----%c----\n", q->mot[0]);
             }
             dernier = dernier->next;
         }
      }
      printf("\n");
      return;
}
/* impression */       

/* liberarion de la memoire */
void liberer(Mot_Utilise **dernier) {
  Mot_Utilise *f;
  
  while ( *dernier != NULL) {
    f = *dernier;
    *dernier = (*dernier)->next;
    free(f);
  }
}
/* liberarion de la memoire */

/* !!  fin liste des mot utilises  !! */
