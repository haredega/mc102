#include <stdio.h>
#include <string.h>
#define MAXIMUM 70

/*criação do 'tipo' agenda */
/* cada "Agenda" contém um 'id'(o nome da pessoa) */
/* e um 'tel'(o númerodo telefone) */
typedef struct _contato_ {
  char id[150];
  int tel;
} Agenda ;
/*criação do 'tipo' agenda */


/*inserção de contatos*/
/* para inserir novos contatos, após aumentar número de contatos*/
/* (no corpo do programa), copio o id dado para o id do contato */
/* e faço o mesmo para o telefone*/
void insert(Agenda contato[], char given_id[], int given_tel, int numero_contato) {
    strcpy(contato[numero_contato].id, given_id);
    contato[numero_contato].tel=given_tel;       
} 
/*inserção de contatos*/


/*insert sort nomes*/
/* coloco em ordem os contatos utilizando o insert sort, de acordo com os id's*/
void perform_id_sort(Agenda contato[], int numero_contato){

    int i, j;
    Agenda aux;
   
    for(i = 1; i < numero_contato+1; i++) {
        strcpy(aux.id, contato[i].id);
        aux.tel=contato[i].tel;
        /*nesse passo, faço "aux = vetor[i];" */
       
        for(j = i - 1 ; (j >= 0) && (strcmp(aux.id,contato[j].id)<0); j--){
           strcpy(contato[j+1].id, contato[j].id);
           contato[j+1].tel = contato[j].tel;
           /* aqui, faço "vetor[j+1]= vetor[j];" */
        }
                    
        strcpy(contato[j+1].id, aux.id);
        contato[j+1].tel=aux.tel; 
        /* e então,  "vetor[j+1] = aux;" */  
    }
}  
/*insert sort nomes*/

/* busca por telefone*/
/* para buscar os telefones, faço uma busca sequencial */
/* aqui, foi utilizado o modelo mostrado em sala, sendo substituídas */
/* apenas as variáveis. a agenda é dada como parâmetro para localizar o */
/* vetor onde ocorrerá a busca */
void tel_search(int given_tel, Agenda contato[], int numero_contato) {
  int busca=0;
  int encontrado=0; /*Falso*/
  
  while ( (busca < numero_contato+1) && (!encontrado) ) {
        if(contato[busca].tel==given_tel) {
            encontrado = 1; /*Verdadeiro*/
        } 
        else {
             busca++;
        }
  }
  
  /* tratamento dos resultados */
  if (encontrado) {
    printf("%-40s %d\n\n", contato[busca].id, contato[busca].tel);              
  } 
  else if(!encontrado) {
    printf("Contato nao encontrado!\n\n");     
  }  
}
/* busca por telefone*/

/* busca por nome*/
/* nesse caso, utilizo, para buscar os id's, uma busca binária. */
/* aqui, foi utilizado o modelo mostrado em sala, sendo substituídas */
/* apenas as variáveis. e trocada a comparação de inteiros pela comparação */
/* de strings com o comando 'strcmp()'. é importante incluir a "Agenda" */ 
/* para localizar o vetor onde ocorrerá a busca */  
void id_search(Agenda contato[], char given_id[], int numero_contato) {
  
  int encontrado;
  int direita, esquerda, meio;
  encontrado = 0; /*Falso*/
  esquerda = 0;
  direita = numero_contato+1; /*por uma questão do uso de vetores de caracteres*/
  /* é necessário alterar alguns parâmetros para manter o funcionamento*/

  while (esquerda <= direita && !encontrado) {
    meio = (direita + esquerda) / 2;
    if ( strcmp(contato[meio].id, given_id)==0)  /* aqui, faço "if(vetor[meio] == valor)"*/
      encontrado = 1; /*Verdadeiro*/
    else if ( strcmp(given_id, contato[meio].id )<0 )     /*e aqui, "else if(valor < vetor[meio])" */
      direita = meio - 1;
    else 
      esquerda = meio + 1;
  }
  
  /* tratamento dos resultados */
  if (encontrado) {
    printf("%-40s %d\n\n", contato[meio].id, contato[meio].tel);              
  } 
  else {
    printf("Contato nao encontrado!\n\n");       
  }
}
/* busca por nome*/   
       
/*impressão dos dados*/
/* pela simplicidade desta função, comentários serão dispensados */
void print_all(Agenda contato[], int numero_contato){
     int i;
         
     for (i=0; i<numero_contato+1; i++){
         if(i!=0)
            printf("%-40s %d\n", contato[i].id, contato[i].tel );
         
         if(contato[i].id[0]!=contato[i+1].id[0] && i!=numero_contato)
	        printf("----%c----\n", contato[i+1].id[0]);
     }
     printf("\n");
}
/*impressão dos dados*/


      
/* funcionamento da agenda */
/* apesar de auto-explicativo, o funcionamento contará com alguns comentários */
/* para simplificar o entendimento */

int main(){
    /*criação das variáveis */
    char comand, given_id[150]; /* caracteres */
    int given_tel, numero_contato=0;    /* inteiros */
    Agenda contato[MAXIMUM];           /* a "Agenda" em si, limitada a "MAXIMUM" contatos*/
    
	scanf("%c", &comand);
	/*obtenção do comando*/
	   
	/* se o comando for um 'f', o programa é finalizado, não realizando nenhuma operação*/
    while(comand!='f'){
          
         /* caso receba um 'i', o programa adicionará um novo contato */
         if(comand=='i'){
	        numero_contato++;
            scanf(" %d ", &given_tel); /*obtenção do telefone do futuro contato*/
	        scanf("%[^\n]", given_id); /* obtenção do id do futuro contato */
	        insert(contato, given_id, given_tel, numero_contato); /* adição do contato */
            perform_id_sort(contato ,numero_contato); /* ordenação dos contatos */
            /*a ordenação acima é feita para o caso de se precisar  buscar ou */
            /* imprimir os contatos em ordem de nome */
         }

         /* caso receba um 'n', o programa buscará um contato pelo id*/       
         else if(comand=='n'){
            scanf(" %[^\n]", given_id); /* obtenção do id a ser buscado*/
            id_search(contato, given_id , numero_contato); /* busca do contato*/
         }
         
         /* caso receba um 't', o programa buscará um contato pelo tel*/   
         else if(comand=='t'){
            scanf("%d", &given_tel); /* obtenção do telefone a ser buscado*/
            tel_search(given_tel, contato, numero_contato); /*busca do contato*/
         }
         
         /* caso receba um 'p', o programa fará a impressão dos contatos na tela*/
         else if(comand=='p'){
            perform_id_sort(contato ,numero_contato);     
            print_all(contato, numero_contato);
         }

         /*repetição da obtenção de comando para retornar ao início da condição */
         scanf("%c", &comand);    
    } 

    return 0;
}
/* funcionamento da agenda */ 


