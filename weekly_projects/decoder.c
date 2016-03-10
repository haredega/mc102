/* Programa: decoder.c        Laboratório 09                    */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 19/11/2010                                 */
/* A proposta é um programa que codifique/decodifique  */
/* textos segundo uma versão simplificada da cifra de César */ 

#include<stdio.h>
#include <string.h>

int main() {
  FILE  *fr, *fw; /* declaro os arquivos */
  char c, comando, entrada[40], saida[40], auxiliar[40];
   /* declaração das variáveis utilizadas */
  
  /* obtenção do comando e do nome do arquivo */
  scanf("%c %[^\n]", &comando, entrada);
  strcpy(auxiliar, entrada);
  
  /* abertura do arquivo de entrada*/
    fr = fopen (entrada, "r");
  
   /* exibição da mensagem de erro, caso o arquivo não exista. */
  if (fr == NULL) {
    printf("ERRO: Arquivo de entrada nao existe!!\n");
    return 0;
  } 
  
   /* codificação*/
  if (comando == 'c'){
      
      /* criação do arquivo de saída */
      strcpy(saida, auxiliar);
      strcat(saida, "_codificado");
      fw = fopen (saida, "w");

      /* aqui, adianto os caracteres em 3, e "pulo" onde houver "\n" */ 
      while (fscanf(fr, "%c", &c) != EOF){
            if (c !='\n')    
                c += 3;
            printf("%c", c);  /* impressão na tela */                 
            fprintf(fw, "%c", c); /* impressão no arquivo */
      }
  }
  /* codificação*/
  
   /* decodificação*/ 
  else if (comando == 'd'){
       
      strcpy(saida, auxiliar);
      strcat(saida, "_decodificado");
      fw = fopen (saida, "w");

      /* aqui, atraso os caracteres em 3, e "pulo" onde houver "\n" */
      while (fscanf(fr, "%c", &c) != EOF){
            if (c !='\n')    
                c -= 3;
            printf("%c", c);   /* impressão na tela */                     
            fprintf(fw, "%c", c);   /* impressão no arquivo */
      }      
       /* decodificação*/ 
       
  }
  
  fclose(fr);
  fclose(fw);

  return 0;
}
