/* Experimento 3 - Teste do par receptor - emissor
Grupo 8 - Placa 9

Os diagrama de blocos e o esquemático do circuito implementado podem ser vistos em:
https://s3-sa-east-1.amazonaws.com/haredega-git-imgs/esquematico-exp3.png
https://s3-sa-east-1.amazonaws.com/haredega-git-imgs/blocos-exp3.png

*/



#include <stdio.h>
#include <math.h>
#include <wiringPi.h>

#define P1	7
#define P2 	0
#define P3 	2
#define P4 	3

int main (void){

wiringPiSetup();

pinMode(P1, OUTPUT);
pinMode(P2, OUTPUT);
pinMode(P3, OUTPUT);
pinMode(P4, OUTPUT);

digitalWrite(P1, LOW);
digitalWrite(P2, HIGH);
digitalWrite(P3, LOW);
digitalWrite(P4, HIGH);

while(1){

digitalWrite(P1, LOW);
digitalWrite(P2, HIGH);
digitalWrite(P3, LOW);
digitalWrite(P4, HIGH);
delay(1000 );
digitalWrite(P2, LOW);
digitalWrite(P3, HIGH);
digitalWrite(P4, LOW);
digitalWrite(P1, HIGH);
delay(1000);}
}
