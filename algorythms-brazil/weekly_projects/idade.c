/* Programa: idade.c        Laboratório 01                    */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 17/08/2010                                 */
/* A proposta é um programa que, a partir da entrada de dia, mês e ano, */
/* tenha como saída a idade da pessoa.*/ 

#include <stdio.h>
main(){
    int dia, mes, ano, dia_subm=17, mes_subm=8, ano_subm=2010, d, m, a, b;
/* primeiramente, nomeio as variáveis que serão utilizadas. */
/* "mes" é entrada do mês, "mes_subm" é o mês de submissão do arquivo e "m" indica */
/* se o mês inserido já passou ou não. */
/* "dia" é entrada do mês, "dia_subm" é o dia de submissão do arquivo e "d" indica */
/* se o dia inserido já passou ou não. */
/* "ano" é entrada do ano, ano_subm é o ano de submissão do arquivo e a indica */
/* a diferença entre o ano de submissão ("ano_subm") e o ano de entrada */     
/*  ("ano"), ou seja, a idade da pessoa, se já tiver passado seu aniversário */

    scanf("%d", &dia);
    scanf("%d", &mes);
    scanf("%d", &ano);
/* então obtenho as entradas "dia" "mes" e "ano" */
  
    m= mes-mes_subm;
    d=dia-dia_subm;
    a=ano_subm-ano;
    b=a-1;
/* em seguida, subtraio as variáveis, para poder descobrir se a data referente */
/*  aos dados de entrada já passou (ou seja, se o aniversário já foi) */
/* e, por fim, já assumo variáveis referentes à idade da pessoa, sendo: */
/* a para o caso de o aniversário já ter passado e b caso contrário */

/* finalmente, a parte operacional do programa, que descobrirá se o aniversário */
/* já foi. sua lógica é: */

if(m>0)
    printf("%d anos", b);
 /* se o mês de entrada não passou ainda, com certeza o aniversário ainda não foi. */
 
else {
    if(m<0)
    printf("%d anos", a);

/* se o mês de entrada já passou, o aniversário com certeza já foi. */

    else {
/* nesse "else", só resta o caso (mes==mes_subm) */        
/* se o mês de entrada é o corrente, deve-se verificar o dia. */

        if(d>0)
            printf("%d anos", b);
/* se o dia de entrada ainda não passou, o aniversário ainda não foi. */     
       
        else
            printf("%d anos", a);
/* se o dia de entrada é o atual, ou já passou, o aniversário já foi */           
}
}
}
