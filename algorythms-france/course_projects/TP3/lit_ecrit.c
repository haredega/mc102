#include <stdio.h> //pour printf
#include <string.h> // pour strlen
#include <ctype.h> // pour toascii et isdigit

#include "entierlong.h" //pour le type t_EntierLong
#include "lit_ecrit.h" //pour vÈrifier les prototypes des fonctions

//fonction ecrireEntierLong
//but: afficher ‡ l'ecran un entier long 

void ecrireEntierLong(t_EntierLong a)
{
//variables
int i,j;
// debut
// signe
if (a.negatif)
{
    printf("-");
}
// chiffres
/* on recherche le 1er chiffre non nul (ou le chiffre des unites dans le cas
d'un entier nul*/
i=MAXCHIFFRES-1;
while ((a.chiffres[i]==0)&&(i>0))
{
    i=i-1;
}
/*on ecrit les chiffres "utiles"*/
for(j=i;j>=0;j=j-1)
{
    printf("%d",a.chiffres[j]);
}
printf("\n");   
// fin
}

//fonction lireEntierLong
//but: lire au clavier un entier long
t_EntierLong lireEntierLong()
{
char Nb[MAXCHIFFRES+1];
t_EntierLong a;
int i,l;
int test; //en cas de pb
char c;
// debut
do
{
scanf("%s",Nb);
a.negatif = (Nb[0]=='-');
l=strlen(Nb);
test = 1;
if ((a.negatif)||(Nb[0]=='+')) 
{
    //on decale le caractere de fin de chaine d'un indice a gauche
    for(i=0;i<l;i=i+1)
    {
        Nb[i]=Nb[i+1];
    }
    l=strlen(Nb);
}
i=0;
while ((test)&&(i<l))
{
    c=Nb[l-1-i];
    test=isdigit(c);
    if (test)
    { 
        a.chiffres[i] = toascii(c)-toascii('0');
        i=i+1;
    }
}
// on complete par des 0
if (test)
{
    for (i=l;i<MAXCHIFFRES;i=i+1)
    {
        a.chiffres[i]=0;
    }
}
else
{
    printf("erreur, rentrez un entier : \n");
}
}while (!(test));
return a;
// fin
}
