#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
FILE *fr;
char arquivo[150], aux[150], aux2[1500], c;
int i;
i=0;

scanf("%s", arquivo);
strcpy(aux, arquivo);
strcat(arquivo, ".txt");
fr = fopen(arquivo, "r+");
 
if(fr == NULL) { printf("FAIl!"); system("pause"); return 0;}

while( fscanf(fr, "%c", &c) != EOF) 
      { if( c == '\n')  i++; }

printf("i = %d\n", i);
fprintf(fr, "%d", i);


fclose(fr);
system ("pause");
return 0;
} 

    
