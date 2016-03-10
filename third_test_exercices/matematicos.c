/**/
/* lista 5 ex 1*/
#include <stdio.h>
#define TAM

int soma(int vetor[], int tam){
    
    if( tam == 0 )
        return vetor[tam];
        
    else
        return (vetor[tam] + soma(vetor, tam-1));    
    }

int menor(int vetor[], int tam){
    int a;
    if (tam == 0)
       return tam;
       
    else{
        a= menor(vetor, tam-1);
        if ( vetor[tam] < vetor[a])   
           return tam;
        else
            return a;   
        }
    
    }

int maior(int vetor[], int tam){
    int a;
    if (tam == 0)
       return tam;
       
    else{
        a= maior(vetor, tam-1);
        if ( vetor[tam] > vetor[a])   
           return tam;
        else
            return a;   
        }
    
    }
    
int busca(int vetor[],int i, int f, int dado ){
    int meio;
    
    if( i > f)
        return -1;
    
    meio =  (i + f)/2;
    if(vetor[meio]==dado)
         return meio;
    else if(vetor[meio] > dado)
         return ( busca(vetor, i, meio-1, dado ) );       
    else                     
         return ( busca(vetor, meio+1 , f, dado ) );       
    }       
    
int sorted(int vetor[],int tam){
    
    if(tam == 0) return 1;
    
    else if( vetor[tam] > vetor[tam-1]) return sorted(vetor, tam-1);
    else return 0;
    
    }
    
int fatorial(int dado){
    if (dado == 0) return 1;
    else return dado*(fatorial(dado-1)) ;}      
    
int fib(int dado){
    if (dado == 0 ) return 0;
    else if( dado == 1 ) return 1;
    else return ( fib(dado-1)+ fib(dado-2) );
    }
    
int main(){    
    int i, dado;
    int vetor[5];
    
    for(i=0; i<5; i++)
        scanf("%d", &vetor[i]);
    printf("soma = %d\n", soma(vetor, 4));     
    printf("menor = %d\n", (menor(vetor, 4)+1));
    printf("maior = %d\n", (maior(vetor, 4)+1));
    printf("i = %d\n", i);
 
    i = sorted(vetor, 4);
    printf("i = %d\n", i);
    
    if(i==1){    
    scanf("%d", &dado);
    printf("busca = %d\n", (busca(vetor, 0, 4, dado)+1));
    system("pause"); return 0;}
    
    scanf("%d", &i);
    i = fatorial(i);
    printf("fatorial = %d\n",  i);   

    scanf("%d", &i);
    i = fib(i);
    printf("fibonacci = %d\n",  i);


system("pause");
return 0;

}
