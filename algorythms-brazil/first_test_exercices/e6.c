#include <stdio.h>
#include <math.h>

main() {
       float peso, altura, IMC;
       printf("Digite o peso(0 para sair):\n");
       scanf("%f", &peso);
       while(peso<0){
                    printf("Peso inv�lido, digite novamente.\n");
                    scanf("%f", &peso); }
       
       while(peso!=0){
           printf("Digite a altura:\n");
           
           scanf("%f", &altura);
           while(altura<=0){
                    printf("Altura inv�lida, digite novamente.\n");
                    scanf("%f", &altura);}
           
           
           IMC= peso/(altura*altura);
           printf("Seu IMC � %.1f .", IMC);
           
           if(IMC<=19)
              printf("IMC at� 19 indica sinais de desnutri��o.\n");
              
           else if(IMC>19&&IMC<=23)
              printf("Entre 19 e 23, IMC t�pico de pessoas saud�veis. Parab�ns!\n");
              
           else if(IMC>23&&IMC<=25)
              printf("IMC entre 23 e 27 indica pr�-obesidade.\n");
              
           else if(IMC>25&&IMC<30)
              printf("A faixa entre 23 e 27 de IMC engloba os obesos.Cuidado.\n");
              
           else
              printf("Acima de 30, seu IMC indica obesidade m�rbida.\n Consulte um m�dico especialista.\n");                         
           
           printf("Digite o peso(0 para sair):\n");
       scanf("%f", &peso);
       while(peso<0){
                    printf("Peso inv�lido, digite novamente.\n");
                    scanf("%f", &peso);}
           }
system ("pause"); 
}      
                                       
          
