/* Programa: decoder.c        Laborat�rio 09                    */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 19/11/2010                                 */
/* A proposta � um programa que codifique/decodifique  */
/* textos segundo uma vers�o simplificada da cifra de C�sar */ 

#include<stdio.h>
#include <string.h>

int main() {
  FILE  *fr, *fw; /* declaro os arquivos */
  char c, comando, entrada[40], saida[40], auxiliar[40];
   /* declara��o das vari�veis utilizadas */
  
  /* obten��o do comando e do nome do arquivo */
  scanf("%c %[^\n]", &comando, entrada);
  strcpy(auxiliar, entrada);
  
  /* abertura do arquivo de entrada*/
    fr = fopen (entrada, "r");
  
   /* exibi��o da mensagem de erro, caso o arquivo n�o exista. */
  if (fr == NULL) {
    printf("ERRO: Arquivo de entrada nao existe!!\n");
    return 0;
  } 
  
   /* codifica��o*/
  if (comando == 'c'){
      
      /* cria��o do arquivo de sa�da */
      strcpy(saida, auxiliar);
      strcat(saida, "_codificado");
      fw = fopen (saida, "w");

      /* aqui, adianto os caracteres em 3, e "pulo" onde houver "\n" */ 
      while (fscanf(fr, "%c", &c) != EOF){
            if (c !='\n')    
                c += 3;
            printf("%c", c);  /* impress�o na tela */                 
            fprintf(fw, "%c", c); /* impress�o no arquivo */
      }
  }
  /* codifica��o*/
  
   /* decodifica��o*/ 
  else if (comando == 'd'){
       
      strcpy(saida, auxiliar);
      strcat(saida, "_decodificado");
      fw = fopen (saida, "w");

      /* aqui, atraso os caracteres em 3, e "pulo" onde houver "\n" */
      while (fscanf(fr, "%c", &c) != EOF){
            if (c !='\n')    
                c -= 3;
            printf("%c", c);   /* impress�o na tela */                     
            fprintf(fw, "%c", c);   /* impress�o no arquivo */
      }      
       /* decodifica��o*/ 
       
  }
  
  fclose(fr);
  fclose(fw);

  return 0;
}
