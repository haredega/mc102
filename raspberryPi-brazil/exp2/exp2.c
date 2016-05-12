/* Experimento 2 - Implementação do termostato
Grupo 8 - Placa 9

Os diagramas referentes a este experimento podem ser vistos em:
https://s3-sa-east-1.amazonaws.com/haredega-git-imgs/Relay-exp22.jpg
https://s3-sa-east-1.amazonaws.com/haredega-git-imgs/condicionador-exp2.JPG
// Atenção! Houve modificações no esquemático de condicionamento durante a realização do projeto.

*/

#include <stdio.h>
#include <math.h>
#include <wiringPi.h>

#define PWM 2
#define TRUE 1
#define FALSE 0
#define RELAY 1

int main (void){

    int total, high, input; // parametros do PWM
    double duty;
    double G = 2.875;  // transcondutancia  do INA122
    double Vpp = 5;    // tensão de pico a pico na entrada inversora do comparador
    int Vcc = 5;
    int R1 = 9900;
    int cnt=0;
    double Vin_neg = 0.480;    // definir tensao inversora do INA122 (em cima do trimpot)
    double Vin_pos;    // tensao nao-inversora do INA122
    double Vo;  // tensao na entrada nao-inversora
    double Rt;  // resistencia do termistor
    double k1 = -29.29; // coeficientes obtidos no ajuste logaritmico
    double k2 = 255.44;
    double T;   // Temperatura medida pelo termistor


    wiringPiSetup();
    pinMode(PWM, INPUT);
    pinMode(RELAY,OUTPUT);
    digitalWrite(RELAY,LOW);

	delay(2000);


    while(1){
            total = 0;
            high = 0;
            duty = 0;
            cnt=0;

            for(cnt; cnt<=200; cnt++){
                total++;
                input = digitalRead (PWM) ;  // On
//printf("PWM: %d\n", input);

                if (input == TRUE) high++;
                delay (5);  // mS
            }

printf("Duty: %d / %d; count: %d \n", high, total, cnt);

            duty = (double)high/(double)total;





printf("Duty: %f \n", duty);
            Vo = duty * Vpp;
printf("Vo: %f, Vpp = %f \n", Vo, Vpp);
            Vin_pos = (Vo/G) + Vin_neg;
	    printf("Vin_pos = %f \n", Vin_pos);
printf("Vo+: %f \n", Vin_pos);
            Rt = (R1 * Vin_pos)/(Vcc - Vin_pos);

            T = k1 * log(Rt) + k2;
printf("Rt: %f \n", Rt);
            printf("Temperatura: %f \n", T);
            delay(100);

/* Se a temperatura estiver abaixo de 40ºC, a lâmpada conectada a um relé externo deverá ser ativada com o sinal
disponível na saída 'RELAY' */
	if(T <= 40)
	{
		digitalWrite(RELAY,HIGH);
	}
	else{
		digitalWrite(RELAY,LOW);
		}
       };



  }
