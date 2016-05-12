/*
# EE641 - 1s2016
#Grupo 6
#Experimento 1
# Leitura do PWM

O esquematico referente a este exercício esta disponível em :
https://s3-sa-east-1.amazonaws.com/haredega-git-imgs/pwm-exp1.png
*/


#include <stdio.h>
#include <wiringPi.h>

#define PWM 2
#define TRUE 1
#define FALSE 0

int main (void)
{ int total=0;
  int high=0;
  int input;
  double duty;

  printf ("Raspberry Pi PWM value\n") ;

  wiringPiSetup () ;
  pinMode (PWM, INPUT) ;

total = 0;
high = 0;
  for (;;)
  {
    total++;
    input = digitalRead (PWM) ;  // On
    if (input == TRUE) {high++;}
    if (high == 0) {duty = 0;}
    else {
printf("\n!\n");
duty = (float)high/(float)total;
printf ("high = %d, total = %d, duty = %f", high, total, duty);
}
    printf("Reading PWM - Input = %d, DC = %f\n High = %d, total = %d", input, duty, high, total);
    delay (100) ;               // mS
  }
  return 0 ;
}
