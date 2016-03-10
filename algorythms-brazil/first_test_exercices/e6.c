#include <stdio.h>
#include <math.h>

main() {
       float peso, altura, IMC;
       printf("Digite o peso(0 para sair):\n");
       scanf("%f", &peso);
       while(peso<0){
                    printf("Peso inválido, digite novamente.\n");
                    scanf("%f", &peso); }
       
       while(peso!=0){
           printf("Digite a altura:\n");
           
           scanf("%f", &altura);
           while(altura<=0){
                    printf("Altura inválida, digite novamente.\n");
                    scanf("%f", &altura);}
           
           
           IMC= peso/(altura*altura);
           printf("Seu IMC é %.1f .", IMC);
           
           if(IMC<=19)
              printf("IMC até 19 indica sinais de desnutrição.\n");
              
           else if(IMC>19&&IMC<=23)
              printf("Entre 19 e 23, IMC típico de pessoas saudáveis. Parabéns!\n");
              
           else if(IMC>23&&IMC<=25)
              printf("IMC entre 23 e 27 indica pré-obesidade.\n");
              
           else if(IMC>25&&IMC<30)
              printf("A faixa entre 23 e 27 de IMC engloba os obesos.Cuidado.\n");
              
           else
              printf("Acima de 30, seu IMC indica obesidade mórbida.\n Consulte um médico especialista.\n");                         
           
           printf("Digite o peso(0 para sair):\n");
       scanf("%f", &peso);
       while(peso<0){
                    printf("Peso inválido, digite novamente.\n");
                    scanf("%f", &peso);}
           }
system ("pause"); 
}      
                                       
          
