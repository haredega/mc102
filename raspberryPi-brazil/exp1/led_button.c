/*
# EE641 - 1s2016
#Grupo 6
#Experimento 1
# Blink com LED
*/

#include <stdio.h>
#include <wiringPi.h>


// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
//BUTTON PIN - wiringPi pin 3 is BCM_GPIO 22
#define	LED	0
#define BUTTON 3

int main (void)
{ int i=0;
  printf ("Raspberry Pi blink\n") ;
  printf("t2\n");

  wiringPiSetup();
  printf("t2\n");
  pinMode (LED, OUTPUT);
  printf("t2\n");
  pinMode (BUTTON, INPUT);
  printf("t2\n");
  pullUpDnControl(BUTTON, PUD_UP);
  printf("t2\n");

  for (;;)
    {   printf("%d\n", i);

    printf("%d\n", digitalRead(BUTTON) );
    if ( digitalRead(BUTTON)==1 ) {
        digitalWrite (LED, LOW) ;	// On
        delay (500) ;		// mS
        }
    else{
        digitalWrite (LED, HIGH) ;	// Off
        delay (500) ;
        }
    i++;
    }  
  return 0 ;
}

