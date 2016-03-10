/* Programa: senha.c        Laborat�rio 03                  */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 27/08/2010                                 */
/* A proposta � um programa que, reproduza um jogo de senha, */
/* iniciando com a entrada da mesma.*/ 

#include <stdio.h>
int main(){    
 
 /* primeiro, crio 2 vetores, um para o palpite e um para o chute. */
 /* al�m disso, crio uma vari�vel "a" de pontua��o (quanto esta chegar a 5, */
 /* o jogo termina. ainda crio dois �ndices, i e j, para as posi��es dos vetores. */   
    int senha[5], chute[5], a, i, j;

/* obtenho a senha inicial */
    scanf("%1d%1d%1d%1d%1d", &senha[0], &senha[1], &senha[2], &senha[3], &senha[4]);
   
 /* pulo as 50 linhas pedidas (aproveitando o �ndice j) */  
    for(j = 0; j<50; j++){
        printf("\n");
        }
/*ent�o, come�o o algoritmo do jogo. */
do {   
    /* o primeiro passo � obter o chute. */   
    scanf("%1d%1d%1d%1d%1d", &chute[0], &chute[1], &chute[2], &chute[3], &chute[4]);
   
 /*  ent�o, devo compar�-lo a senha. come�o comparando os �ndices iguais */ 
    for( i=0, a=0; i<=5; i++) {
        if(chute[i]==senha[i]) {
              printf("x");
              
 /* para cada acerto de �ndices iguais, incremento "a" */
        a++;
            }
/* aqui, a compara��o dos �ndices diferentes. */        
        else {
           for(j=0; j<=5; j++){
              if (j!=i && chute[i]==senha[j]) {
            printf("o");
 /* o incremento de 5 para j significa que, se a condi��o for satisfeita */
/* apenas uma vez, a verifica��o para o determinado "i" acaba.*/
            j += 5; }
        }
        }
        }
        printf("\n");
        
 /* isso se repetir� at� que "a" seja incrementado 5 vezes (5 acertos) */     
/* nesse caso, o jogador ganha e o jogo termina. */
        } while(a!=5);
        

        printf("PARABENS!Voce encontrou a senha!");
return 0;

}
