/* Experimento 4 - Conversor Digital-Analogico
Grupo 8 - Placa 9

To do - Utilizar pinos 11, 12, 13 e 15 (GPIO0 a GPIO3)

#void digitalWriteByte (int value) ;
#This writes the 8-bit byte supplied to the first 8 GPIO pins. (GPIO0 to GPIO7)
#It’s the fastest way to set all 8 bits at once to a particular value,
#although it still takes two write operations to the Pi’s GPIO hardware.
*/
int flag=0;
char forma_de_onda='d';
int frequencia=0;
int tempo=100;
int tempos_seno1[16];

// Foi necessário escrever uma funcao especifica para lidar com os tempos
// menores que 1 ms
void us_delay(int microseconds)

#Escolha da Frequencia e do Tipo de onda
printf("--------### Conversor D-A. ###--------\n");
while (!flag){
    printf("Escolha a forma de onda desejada (T para Triangular e S para senoidal):");
    scanf("%c", &forma_de_onda)
    if (forma_de_onda == 'T'){ flag = 1; }
    else if (forma_de_onda == 'S') { flag =1; }
printf("Digite um valor válido - T/S\n");
}

flag = 0;
while (!flag){
    printf("Escolha o valor desejado para a frequencia (500 ou 5000 Hz):");
    scanf("%d", &frequencia)
    if (frequencia == 500){
        flag = 1;
        tempo= 67;
        tempos_seno[]={43 21 22 21 19 12 18 15 52 29 34 16 54 29 115};

      }
    else if (frequencia == 5000) {
        flag =1;
        tempo = 7;
        tempos_seno[]={4 2 3 1 2 2 2 1 5 3 4 1 6 3 11};
      }
printf("Digite um valor válido - 500/5000 Hz\n");
}

#Implementacao do gerador de onda
if (forma_de_onda == 'T'){
  // gerador de onda Triangular
      while(1){
        for(int i=0; i<15; i++){
          us_delay(tempo); //us
          digitalWriteByte(i);
        }
        for(int i=15; i>0; i--){
          us_delay(tempo); //us
          digitalWriteByte(i);
        }
      } // end while
} // end if

if (forma_de_onda == 'S'){
  // gerador de onda Triangular
      while(1){
        for(int i=0; i<15; i++){
          us_delay(tempos_seno[i]); //us
          digitalWriteByte(i);
        }
        for(int i=15; i>0; i--){
          us_delay(tempos_seno[i]); //us
          digitalWriteByte(i);
        }
      } // end while
} // end if


void us_delay(int microseconds)
{
    long pause;
    clock_t now,then;

    pause = microseconds*(CLOCKS_PER_SEC/1000000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
