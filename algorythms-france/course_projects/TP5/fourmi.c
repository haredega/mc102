#include "proba.h"
#include "fourmi.h"

void DeplaceFourmi ( t_fourmi *fourmi1){

      int tirage;

      tirage = nalea(8);
      
      switch ( tirage )
      {
	  case 0: (*fourmi1).y++;   //on definit la direction 0 vers le haut et ensuite on prend les cas suivants dans le sens horaire.
		  break;

	  case 1: (*fourmi1).x++;
		  (*fourmi1).y++;
		  break;
	  
	  case 2: (*fourmi1).x++;
		  break;
	  
	  case 3: (*fourmi1).x++;
		  (*fourmi1).y--;
		  break;

	  case 4: (*fourmi1).y--;
		  break;

	  case 5: (*fourmi1).x--;
		  (*fourmi1).y--;
		  break;

	  case 6: (*fourmi1).x--;
		  break;

	  case 7: (*fourmi1).x--;
		  (*fourmi1).y++;
		  break;

      }
}

		  