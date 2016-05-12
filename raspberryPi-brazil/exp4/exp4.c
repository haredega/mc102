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
int tempos_seno1[16];
int tempos_seno[16]={43 ,21 ,22, 21 ,19 ,12, 18 ,15 ,52 ,29, 34 ,16, 54 ,29 ,115};
clock_t tic, toc;
int i=0;
int j=0;
int a;
int tempos_senox[16]={4, 2, 3, 1, 2, 2, 2, 1, 5, 3, 4, 1, 6, 3, 11};
// Foi necessário escrever uma funcao especifica para lidar com os tempos
// menores que 1 ms

void usMicroseconds(int microseconds)
{
    long pause;
    clock_t now,then;

    pause = microseconds*(CLOCKS_PER_SEC/1000000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();

}



int main (void){

wiringPiSetup();
pinMode(P1, OUTPUT);
pinMode(P2, OUTPUT);
pinMode(P3, OUTPUT);
pinMode(P4, OUTPUT);
pinMode(P5, OUTPUT);
pinMode(P6, OUTPUT);
pinMode(P7, OUTPUT);
pinMode(P8, OUTPUT);

digitalWrite(P1, HIGH);
digitalWrite(P2, HIGH);
digitalWrite(P3, HIGH);
digitalWrite(P4, HIGH);
digitalWrite(P5, HIGH);
digitalWrite(P6, HIGH);
digitalWrite(P7, HIGH);
digitalWrite(P8, HIGH);
/*
//delay(6000);
      digitalWriteByte(0);
scanf("%d", &i);
//delay(6000);
      digitalWriteByte();
//delay(6000);
scanf("%d", &i);
      digitalWriteByte();
scanf("%d", &i);
*/

/*
for (i=0;i<=15;i++){
      digitalWriteByte(i);
printf("%d\n", i);
scanf("%d", &j);

}*/

     digitalWriteByte(8);


//Escolha da Frequencia e do Tipo de onda
printf("----------Conversor D-A.--------\n");
while (flag != 1){
    printf("Escolha a forma de onda desejada (T para Triangular e S para senoidal):");
    scanf("%c", &forma_de_onda);
    if (forma_de_onda == 'T'){ flag = 1; }
    else if (forma_de_onda == 'S') { flag =1; }
    else printf("Digite um valor válido - T/S\n");
	printf("forma de onda: %c\n", forma_de_onda);
}

flag = 0;
while (flag != 1){
    printf("Escolha o valor desejado para a frequencia (500 ou 5000 Hz):");
    scanf("%d", &frequencia);
    printf("\nfrequencia escolhida: %d\n", frequencia);

    if (frequencia == 500){
        flag = 1;
	printf("1 flag = %d\n", flag);
        tempo= 60;
	frequencia = frequencia*155500/6/500;
     }
    else if (frequencia == 5000) {
        flag =1;
	printf("2 flag = %d\n", flag);
        tempo = 2;
	frequencia = frequencia*155500/6/500;
      }
    else {printf("Digite um valor válido - 500/5000 Hz\n");}

printf("frequencia escolhida: %d\n", frequencia);

}



if (forma_de_onda == 'T'){
//Implementacao do gerador de onda
while(1){
    tic = clock();
    for(i=0; i<=15; i++){
      //printf("%d\n", i);
      if (forma_de_onda == 'T') delayMicroseconds(tempo); //us
      else {

             if (frequencia ==500) delayMicroseconds(tempos_seno[i]); //us
	     else delayMicroseconds(tempos_senox[i]); //us
	}

      digitalWriteByte(i);
      toc = (clock()-tic)/CLOCKS_PER_SEC*1000000;
      //printf("%d s - i = %d\n", toc, i);
    }

    for( i=15; i>=0; i--){
     //printf("%d\n", i);
      if (forma_de_onda == 'T') delayMicroseconds(tempo); //us
      else {
             if (frequencia ==500) delayMicroseconds(tempos_seno[i]); //us
	     else delayMicroseconds(tempos_senox[i]); //us
	}
      digitalWriteByte(i);
      toc = (clock()-tic)/CLOCKS_PER_SEC*1000000;
      //printf("%d s - i = %d\n", toc, i);
    }

  } // end while
}

else{
	i=0;
	j=0;
	flag=0;
	while(1){

		digitalWriteByte(i);
		delayMicroseconds(1);
		j++;
		a = (int)roundf(7*cos(2*3.1415926*frequencia*j)+7);
//printf("a= %d i=%d\n",  a, i );

		while( i<=14){

			delayMicroseconds(1);
			j++;
			a = (int)roundf(7*cos(2*3.1415926*frequencia*j)+7);
//printf("a= %d i=%d\n",  a, i );
			digitalWriteByte(i);


			if(a>=i) {

			i++;
//			printf("i++=   %d\n", i );

			}
		}

		while( i>=0){

			delayMicroseconds(1);
			j++;
			a = (int)roundf(7*cos(2*3.1415926*frequencia*j)+7);
//printf("a= %d i=%d\n",  a, i );
			digitalWriteByte(i);
			if(a<=i) {

			i--;
//			printf("i--=   %d\n", i );
			}
		}
		/*if( a > i && i<14)  {  i++; printf("i++=   %d\n", i ); }
		else if ( i==14){ flag = 1;}
		else if ( flag ==1 && a < i && i>0){  i--;  printf("i--=   %d\n", i );}
		else if (flag ==1 && i==0) {flag=0;}*/

	} //end while

} // end else

}
