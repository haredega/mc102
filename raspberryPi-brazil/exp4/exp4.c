/* Experimento 4 - Conversor Digital-Analogico
Grupo 8 - Placa 9

O esquemático do circuito a ser implementado está disponível em:
https://s3-sa-east-1.amazonaws.com/haredega-git-imgs/esquematico-exp4.JPG

To do - Utilizar pinos 11, 12, 13 e 15 (GPIO0 a GPIO3) da RaspberryPi

Funções úteis ao projeto:

void digitalWriteByte (int value) ;
This writes the 8-bit byte supplied to the first 8 GPIO pins. (GPIO0 to GPIO7)
It's the fastest way to set all 8 bits at once to a particular value,
although it still takes two write operations to the Pi's GPIO hardware.

void delayMicroseconds (unsigned int howLong)
This causes program execution to pause for at least howLong microseconds.
Due to the multi-tasking nature of Linux it could be longer. Note that the maximum
delay is an unsigned 32-bit integer microseconds or approximately 71 minutes.
Delays under 100 microseconds are timed using a hard-coded loop continually polling
the system time, Delays over 100 microseconds are done using the system nanosleep()
function – You may need to consider the implications of very short delays on the overall
performance of the system, especially if using threads.
*/

#include <time.h>
#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

//Definição dos pinos GPIO com os headers WiringPi
#define P1	0
#define P2 	1
#define P3 	2
#define P4 	3
#define P5 	4
#define P6 	5
#define P7 	6
#define P8 	7

int flag=0;
char forma_de_onda='d';
int frequencia=0;
int tempo=100;
clock_t tic, toc;
int i=0;
int j=0;
int a;
// Foi necessário escrever uma funcao especifica para lidar com os tempos
// menores que 1 ms

int main (void){
      // Configuração das 8 portas iniciais do GPIO, utilizadas pela função digitalWriteByte
      wiringPiSetup();
      pinMode(P1, OUTPUT);
      pinMode(P2, OUTPUT);
      pinMode(P3, OUTPUT);
      pinMode(P4, OUTPUT);
      pinMode(P5, OUTPUT);
      pinMode(P6, OUTPUT);
      pinMode(P7, OUTPUT);
      pinMode(P8, OUTPUT);

      //Teste do GPIO e da função digitalWriteByte
      //Removido do programa para focar no fluxo solicitado para o projeto.
      /*
      digitalWrite(P1, HIGH);
      digitalWrite(P2, HIGH);
      digitalWrite(P3, HIGH);
      digitalWrite(P4, HIGH);
      digitalWrite(P5, HIGH);
      digitalWrite(P6, HIGH);
      digitalWrite(P7, HIGH);
      digitalWrite(P8, HIGH);

      delay(6000);
      digitalWriteByte(0);
      scanf("%d", &i);
      digitalWriteByte();
      scanf("%d", &i);
      digitalWriteByte();
      scanf("%d", &i);

      for (i=0;i<=15;i++){
            digitalWriteByte(i);
            printf("%d\n", i);
            scanf("%d", &j);
      }
      digitalWriteByte(i);

      // Fim da zona de testes  GPIO
      */

      digitalWriteByte(8);


      //Escolha da Frequencia e do Tipo de onda
      printf("----------Conversor D-A.--------\n");

      //Escolha da forma da onda - T ou S apenas
      while (flag != 1){
          printf("Escolha a forma de onda desejada (T para Triangular e S para senoidal):");
          scanf("%c", &forma_de_onda);
          if (forma_de_onda == 'T'){ flag = 1; }
          else if (forma_de_onda == 'S') { flag =1; }
          else printf("Digite um valor válido - T/S\n");
      	  printf("forma de onda: %c\n", forma_de_onda);
       }

      flag = 0;

      //Escolha da frequencia, entre 500 e 5000Hz.
      while (flag != 1){
          printf("Escolha o valor desejado para a frequencia (500 ou 5000 Hz):");
          scanf("%d", &frequencia);
          printf("\nfrequencia escolhida: %d\n", frequencia);
          if (frequencia == 500){
              flag = 1;
              tempo= 60;
      	      frequencia = frequencia*155500/6/500;
           }
          else if (frequencia == 5000) {
              flag =1;
              tempo = 2;
      	      frequencia = frequencia*155500/6/500;
            }
          else { printf("Digite um valor válido - 500/5000 Hz\n"); }
          printf("frequencia escolhida: %d\n", frequencia);
      }

      //Implementacao do gerador de onda
      //Onda triangular
      if (forma_de_onda == 'T'){
            while(1){
                for(i=0; i<=15; i++){
                  if (forma_de_onda == 'T') delayMicroseconds(tempo); //us
                  digitalWriteByte(i);
                } //onda descendente
                for( i=15; i>=0; i--){
                  if (forma_de_onda == 'T') delayMicroseconds(tempo); //us
                  digitalWriteByte(i);
                } // onda ascendente
            } // end while
      } // end geração de onda triangular

      //Onda senoidal
      else{
        //reinicamos todas as variáveis
      	i=0;
      	j=0;
      	flag=0;

      	while(1){
      		digitalWriteByte(i);
      		delayMicroseconds(1);
      		j++;
      		a = (int)roundf(7*cos(2*3.1415926*frequencia*j)+7);
      		while( i<=14){
          			delayMicroseconds(1);
          			j++;
          			a = (int)roundf(7*cos(2*3.1415926*frequencia*j)+7);
          			digitalWriteByte(i);
          			if(a>=i) {		i++;  }
      		} // onda descendente
      		while( i>=0){
          			delayMicroseconds(1);
          			j++;
          			a = (int)roundf(7*cos(2*3.1415926*frequencia*j)+7);
          			digitalWriteByte(i);
          			if(a<=i) {  i--; }
          		} // onda descendente
      	} //end while
      } // end onda senoidal
} // end main
