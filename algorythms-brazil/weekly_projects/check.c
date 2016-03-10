/* Programa: check.c        Laborat�rio 04                  */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 04/09/2010                                 */
/* Proposta: reproduzir um jogo "check the check"*/

#include <stdio.h>

int main(){
  
    char tabuleiro[8][8], tabuleiro2[8][8]; /* ser�o utilizados um tabuleiro  */
/* para a entrada e um para a sa�da.*/
    int i, j, k, a=0; /* i, j e k ser�o �ndices, a � um contador  */
    
   /* entrada: */
    for(i=0 ;i<8;i++){
        for(j=0;j<=8;j++){
            scanf("%c", &tabuleiro[i][j]);
            tabuleiro2[i][j]='.'; }}

   /* verifica��o :*/
   /* aqui, marcarei com * no tabuleiro 2 as casas sob ataque, e colocarei */
   /* as pe�as nas respectivas casas, exceto o rei. */
    for(i=0 ;i<8;i++){
        for(j=0;j<8;j++){
           switch(tabuleiro[i][j]){
            
           /* se houver uma torre, dever�o ser marcadas a linha e coluna*/
           /* (ou seja, todas as casas da forma (i,k) e (k,j)*/ 
             case 't':
                for(k=0; k<8;k++){
                  tabuleiro2[i][k]='*' ;
                  tabuleiro2[k][j]='*';    }
             /* colocando a torre na casa certa:*/     
             tabuleiro2[i][j]=tabuleiro[i][j];
             break;
            
           /*se houver um bispo, dever�o ser marcadas as diagonais referentes */
           /*(ou seja, as casas (i+k, j+k),(i-k,i-j)- diagonal principal */
           /* e (i-k, j+k),(i+k, j-k) - diagonal oposta */
             case 'b':
                for(k=1;k<8;k++){
                    if( i+k>=0 && j+k>=0 && i+k<8 && j+k<8){
                        tabuleiro2[i+k][j+k]='*';  }
                    if( i-k>=0 && j-k>=0 && i-k<8 && i-k<8 ){   
                        tabuleiro2[i-k][j-k]='*';   }
                    if( j+k>=0 && i-k>=0 && j+k<8 && i-k<8 ){
                        tabuleiro2[i-k][j+k]='*';  }
                    if( i+k>=0 && j-k>=0 && i+k<8 && j-k<8 ){
                        tabuleiro2[i+k][j-k]='*'; }} 
             /* colocando o bispo na casa certa:*/ 
             tabuleiro2[i][j]=tabuleiro[i][j];
             break;
                  
           /* no caso da rainha, tanto as casas marcadas para a torre como as */
           /* marcadas para o bispo dever�o ser marcadas */
             case 'r':
                /*casas marcadas para torre*/                
                for(k=0; k<8;k++){
                   tabuleiro2[i][k]='*' ;
                   tabuleiro2[k][j]='*';    }
                /*casa marcadas para o bispo*/
                for(k=1;k<8;k++){
                    if( i+k>=0 && j+k>=0 && i+k<8 && j+k<8){
                        tabuleiro2[i+k][j+k]='*';  }
                    if( i-k>=0 && j-k>=0 && i-k<8 && i-k<8 ){   
                        tabuleiro2[i-k][j-k]='*';   }
                    if( j+k>=0 && i-k>=0 && j+k<8 && i-k<8 ){
                        tabuleiro2[i-k][j+k]='*';  }
                    if( i+k>=0 && j-k>=0 && i+k<8 && j-k<8 ){
                        tabuleiro2[i+k][j-k]='*'; }}   
                /* colocando a rainha na casa certa:*/        
                tabuleiro2[i][j]=tabuleiro[i][j];
                break;                          
                }}}                         
                    
             /*abaixo, fa�o a verifica��o do cheque: */                                                   
             for(i=0 ;i<8;i++){
                for(j=0;j<=8;j++){
                    if(tabuleiro[i][j]=='R'){                      
                        if(tabuleiro2[i][j]=='*'){
                        /*se a casa onde o Rei est� estiver sob ataque, */
                        /*somo um ao contador "a", que indica cheque. */                          
                           a++;  }
                         /* colocando o Rei na casa certa:*/  
                        tabuleiro2[i][j]=tabuleiro[i][j];  } } }  
   
             for(i=0 ;i<8;i++){
                for(j=0;j<8;j++){
                    printf("%c", tabuleiro2[i][j]); }
                printf("\n");  }   
   
    if(a!=0)
    /*se o contador a for incrementado, h� cheque.*/
        printf("O Rei esta em check!\n");
   
    else
        printf("O Rei nao esta em check!\n");
    
return 0;  
}
