/*author : A. G. Heitor et L. Alexandre
date : 12-02-2013
file name : mon1erprog.c

ce que fait le programme : calcul des n premiers termes u(n) 
de la suite de Fibonacci (telle que u(n+1) = u(n) + u(n-1))
définie par u(0) = 1 et u(1) = (1-racine(5))/2
*/

#include <stdlib.h> // pour la librairie standard 
#include <stdio.h> // pour lecture/écriture 
#include <math.h> // pour la racine carre sqrt et la puissance pow

int main(void)
{
	// déclaration des constantes et variables
	const float r = (1-sqrt(5))/2;
	double dbl = 1/5.0;
	int i,n;
	float uprec, ucour, usuiv; // pour u(n-1), u(n), u(n+1)
	
	// initialisations
	printf("calcul des n premiers termes de la suite de Fibonacci\n");
	printf("avec u0=1 et u1=(1-racine(5))/2\n");
	printf("n = ? "); 
    scanf("%d",&n);
	uprec = 1;
	ucour = r;
	
	// calcul de u(2), ..., u(n)
	for (i=2;i<=n;i=i+1)
	{
		usuiv = ucour + uprec;
		uprec = ucour;
		ucour = usuiv;
		printf("u( %d ) = %f ", i, ucour);
		printf(" i-eme puissance de r: r^( %d ) = %f \n", i, pow(r,i));
		printf("\n"); // pour passer à la ligne
	}
	
	
    system ("pause");     /*apagar depois*/
	return (EXIT_SUCCESS);
}
