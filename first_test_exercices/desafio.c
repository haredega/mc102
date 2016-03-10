#include <stdio.h>
#include <math.h>

main() {
  int pontos, a, b, c;
  printf("Quantos pontos?");
  scanf("%d", &pontos); 
  
  
  for(a=0; a<pontos; a++){
         for(b=pontos-a; b>=0; b--) {
                           printf(" "); }
         for( c=0 ; c<=a; c++ ) {                 
                           printf("*"); }
                                                           
       printf("\n");                 
  
                       
                        }
  
system ("pause"); 
}      
                                       
          
