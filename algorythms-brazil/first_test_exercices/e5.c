#include <stdio.h>
#include <math.h>

main() {
       float a, b, c, delta, x1, x2;
       printf("Digite a, b e c(0 0 0 para sair):\n");
       scanf("%f %f %f", &a, &b, &c);
       
       while(a!=0||b!=0||c!=0){
           if(a!=0){                    
              delta= b*b- 4*a*c;
              printf("O delta é %.1f\n", delta);
              if(delta>0){
                    printf("Isso quer dizer que há 2 raízes para a equação.") ;
                    x1=(-b+ sqrt(delta))/2*a;
                    x2=(-b- sqrt(delta))/2*a;
                    printf("As quais são: %.1f e %.1f", x1, x2); }
              else if(delta=0){  
                    printf("Isso quer dizer que há 1 raiz para a equação.");
                    x1=(-b/2*a);
                    printf("Que é %.1f", x1); }
              else {
                    printf("Então não há raízes para a equação.\n"); }
                    }
             else {
                  x1=-c/b;
                  printf("A sua equação é de primeiro grau. A raiz é %.1f\n", x1);       
                         } 
                         
       printf("Digite a, b e c(0 0 0 para sair):\n");
       scanf("%f %f %f", &a, &b, &c);
           }      
       
       
system ("pause"); 
}      
                                       
          
