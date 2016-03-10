/* Programa: idade.c        Laborat�rio 01                    */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 17/08/2010                                 */
/* A proposta � um programa que, a partir da entrada de dia, m�s e ano, */
/* tenha como sa�da a idade da pessoa.*/ 

#include <stdio.h>
main(){
    int dia, mes, ano, dia_subm=17, mes_subm=8, ano_subm=2010, d, m, a, b;
/* primeiramente, nomeio as vari�veis que ser�o utilizadas. */
/* "mes" � entrada do m�s, "mes_subm" � o m�s de submiss�o do arquivo e "m" indica */
/* se o m�s inserido j� passou ou n�o. */
/* "dia" � entrada do m�s, "dia_subm" � o dia de submiss�o do arquivo e "d" indica */
/* se o dia inserido j� passou ou n�o. */
/* "ano" � entrada do ano, ano_subm � o ano de submiss�o do arquivo e a indica */
/* a diferen�a entre o ano de submiss�o ("ano_subm") e o ano de entrada */     
/*  ("ano"), ou seja, a idade da pessoa, se j� tiver passado seu anivers�rio */

    scanf("%d", &dia);
    scanf("%d", &mes);
    scanf("%d", &ano);
/* ent�o obtenho as entradas "dia" "mes" e "ano" */
  
    m= mes-mes_subm;
    d=dia-dia_subm;
    a=ano_subm-ano;
    b=a-1;
/* em seguida, subtraio as vari�veis, para poder descobrir se a data referente */
/*  aos dados de entrada j� passou (ou seja, se o anivers�rio j� foi) */
/* e, por fim, j� assumo vari�veis referentes � idade da pessoa, sendo: */
/* a para o caso de o anivers�rio j� ter passado e b caso contr�rio */

/* finalmente, a parte operacional do programa, que descobrir� se o anivers�rio */
/* j� foi. sua l�gica �: */

if(m>0)
    printf("%d anos", b);
 /* se o m�s de entrada n�o passou ainda, com certeza o anivers�rio ainda n�o foi. */
 
else {
    if(m<0)
    printf("%d anos", a);

/* se o m�s de entrada j� passou, o anivers�rio com certeza j� foi. */

    else {
/* nesse "else", s� resta o caso (mes==mes_subm) */        
/* se o m�s de entrada � o corrente, deve-se verificar o dia. */

        if(d>0)
            printf("%d anos", b);
/* se o dia de entrada ainda n�o passou, o anivers�rio ainda n�o foi. */     
       
        else
            printf("%d anos", a);
/* se o dia de entrada � o atual, ou j� passou, o anivers�rio j� foi */           
}
}
}
