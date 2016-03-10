/*       TA ALGPR         OCTO-VERSO                     */
/*       GROUPE I         ELEVES INGENIEURS:             */
/*       AREDE GARCIA HEITOR    DENARDI ALINE            */
/*       GUITTON BARBARA        MUSHAMALIRWA ANNE-MARIE  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "jeu_humain.h"
#include "jeu_machine.h"
 
//int _lettres[21]={9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2};           
                    /* MAIN  */
/* fonction principale */
int main(){
    int i;
    
    // début du jeu
    printf("------------------------------------------------------------\n");
    printf("--------------------OCTO-VERSO------------------------------\n");
    printf("------------------------------------------------------------\n\n");
    printf("Choisissez le mode de jeu\n");
    printf("1 - Humain  2 - Machine  :");
    scanf("%d", &i);
    
    while( i != 1  && i!=2 ) {
           printf("\nChoisissez un mode entre 1 e 2.\n");
           scanf("%d", &i);           
           }
    if( i==1 ) jeu_humain();
    else jeu_machine();

    
return 0;    
}
/* fonction principale */













