#include <stdio.h>
#include "proba.h"
#include "fourmi.h"
#include "constantes.h"
#include "affichage.h"
#include "lireenvir.h"

int main()
{
      int i,j;
      int L, H;
      int affiche;
      t_monde mondeA;
      t_fourmi f1;

      /*L = 50;
      H = 50;
      
      mondeA.L = L;
      mondeA.H = H;
      
      for (i=0; i<=mondeA.L; i++){
	    for (j=0; j<=mondeA.H; j++){
			  mondeA.mat[i][j]=0;
	    }
      }
	    
      mondeA.Fx = 25;
      mondeA.Fy = 25;
      f1.x=25;
      f1.y=26;*/
      f1.mode=1;
      
      LireEnvironnement(&L, &H, &f1, &mondeA);
      affiche = InitAffichage( L, H);
      while (affiche == 1){
	  AfficheEnvironnement (mondeA);
	  AfficheFourmi (f1.x, f1.y, f1.mode);
	  //DeplaceFourmi ( &f1 );
	  affiche=MiseAJourAffichage();
      }

      return 0;
}
      

      

      