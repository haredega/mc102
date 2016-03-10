#include <stdio.h>

main(){
    char tabuleiro[8][8], tabuleiro2[8][8];
        int i, j,k,a;
        a=0;
   
    for(i=0 ;i<8;i++){
        for(j=0;j<=8;j++){
            scanf("%c", &tabuleiro[i][j]);
           /* tabuleiro2[i][j]=tabuleiro[i][j];  */
           tabuleiro2[i][j]='.'; }
        }
/* testes!*/
        printf("\n\n");

    for(i=0 ;i<8;i++){
        for(j=0;j<8;j++){
            printf("%c", tabuleiro[i][j]); }
        printf("\n");
        }   
        
        printf("\n\n");
/*TESTES */

    for(i=0 ;i<8;i++){
        for(j=0;j<8;j++){
           
            switch(tabuleiro[i][j]){
            
            case 't':
            for(k=0; k<8;k++){
              tabuleiro2[i][k]='*' ;
              tabuleiro2[k][j]='*';    }
            tabuleiro2[i][j]=tabuleiro[i][j];
            break;
            
           
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
              
              tabuleiro2[i][j]=tabuleiro[i][j];
              break;
                  
          
           case 'r':
            for(k=0; k<8;k++){
              tabuleiro2[i][k]='*' ;
              tabuleiro2[k][j]='*';    }
                   
            for(k=1;k<8;k++){
               if( i+k>=0 && j+k>=0 && i+k<8 && j+k<8){
        
              tabuleiro2[i+k][j+k]='*';  }
              
              if( i-k>=0 && j-k>=0 && i-k<8 && i-k<8 ){   
              tabuleiro2[i-k][j-k]='*';   }
              
              if( j+k>=0 && i-k>=0 && j+k<8 && i-k<8 ){
              tabuleiro2[i-k][j+k]='*';  }
              
              if( i+k>=0 && j-k>=0 && i+k<8 && j-k<8 ){
              tabuleiro2[i+k][j-k]='*'; }} 
              
              tabuleiro2[i][j]=tabuleiro[i][j];
             
              break;
                  
          
              case 'R':
                if(tabuleiro2[i][j]=='*')
                    a++;
            tabuleiro2[i][j]=tabuleiro[i][j];
            
            break;  /*ver isso dpois! tem q ficar fora do switch, pro caso de
            a peça vir dpois! 
            */
            }}}
            /*finzinho*/
            for(i=0 ;i<8;i++){
                for(j=0;j<=8;j++){
                   if(tabuleiro[i][j]=='R' && tabuleiro2[i][j]=='*'){                      
                          a++;  } } }  
   
    for(i=0 ;i<8;i++){
        for(j=0;j<8;j++){
            printf("%c", tabuleiro2[i][j]); }
        printf("\n");
        }   
   
    if(a!=0)
      printf("O Rei esta em check!\n");
   
    else
      printf("O Rei nao esta em check!\n");
 
 system("pause");      
}
