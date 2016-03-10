#include <stdio.h>
#include <string.h>
#define MAXIMUM 70

/*cria��o do 'tipo' agenda */
/* cada "Agenda" cont�m um 'id'(o nome da pessoa) */
/* e um 'tel'(o n�merodo telefone) */
typedef struct _contato_ {
  char id[150];
  int tel;
} Agenda ;
/*cria��o do 'tipo' agenda */


/*inser��o de contatos*/
/* para inserir novos contatos, ap�s aumentar n�mero de contatos*/
/* (no corpo do programa), copio o id dado para o id do contato */
/* e fa�o o mesmo para o telefone*/
void insert(Agenda contato[], char given_id[], int given_tel, int numero_contato) {
    strcpy(contato[numero_contato].id, given_id);
    contato[numero_contato].tel=given_tel;       
} 
/*inser��o de contatos*/


/*insert sort nomes*/
/* coloco em ordem os contatos utilizando o insert sort, de acordo com os id's*/
void perform_id_sort(Agenda contato[], int numero_contato){

    int i, j;
    Agenda aux;
   
    for(i = 1; i < numero_contato+1; i++) {
        strcpy(aux.id, contato[i].id);
        aux.tel=contato[i].tel;
        /*nesse passo, fa�o "aux = vetor[i];" */
       
        for(j = i - 1 ; (j >= 0) && (strcmp(aux.id,contato[j].id)<0); j--){
           strcpy(contato[j+1].id, contato[j].id);
           contato[j+1].tel = contato[j].tel;
           /* aqui, fa�o "vetor[j+1]= vetor[j];" */
        }
                    
        strcpy(contato[j+1].id, aux.id);
        contato[j+1].tel=aux.tel; 
        /* e ent�o,  "vetor[j+1] = aux;" */  
    }
}  
/*insert sort nomes*/

/* busca por telefone*/
/* para buscar os telefones, fa�o uma busca sequencial */
/* aqui, foi utilizado o modelo mostrado em sala, sendo substitu�das */
/* apenas as vari�veis. a agenda � dada como par�metro para localizar o */
/* vetor onde ocorrer� a busca */
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
/* nesse caso, utilizo, para buscar os id's, uma busca bin�ria. */
/* aqui, foi utilizado o modelo mostrado em sala, sendo substitu�das */
/* apenas as vari�veis. e trocada a compara��o de inteiros pela compara��o */
/* de strings com o comando 'strcmp()'. � importante incluir a "Agenda" */ 
/* para localizar o vetor onde ocorrer� a busca */  
void id_search(Agenda contato[], char given_id[], int numero_contato) {
  
  int encontrado;
  int direita, esquerda, meio;
  encontrado = 0; /*Falso*/
  esquerda = 0;
  direita = numero_contato+1; /*por uma quest�o do uso de vetores de caracteres*/
  /* � necess�rio alterar alguns par�metros para manter o funcionamento*/

  while (esquerda <= direita && !encontrado) {
    meio = (direita + esquerda) / 2;
    if ( strcmp(contato[meio].id, given_id)==0)  /* aqui, fa�o "if(vetor[meio] == valor)"*/
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
       
/*impress�o dos dados*/
/* pela simplicidade desta fun��o, coment�rios ser�o dispensados */
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
/*impress�o dos dados*/


      
/* funcionamento da agenda */
/* apesar de auto-explicativo, o funcionamento contar� com alguns coment�rios */
/* para simplificar o entendimento */

int main(){
    /*cria��o das vari�veis */
    char comand, given_id[150]; /* caracteres */
    int given_tel, numero_contato=0;    /* inteiros */
    Agenda contato[MAXIMUM];           /* a "Agenda" em si, limitada a "MAXIMUM" contatos*/
    
	scanf("%c", &comand);
	/*obten��o do comando*/
	   
	/* se o comando for um 'f', o programa � finalizado, n�o realizando nenhuma opera��o*/
    while(comand!='f'){
          
         /* caso receba um 'i', o programa adicionar� um novo contato */
         if(comand=='i'){
	        numero_contato++;
            scanf(" %d ", &given_tel); /*obten��o do telefone do futuro contato*/
	        scanf("%[^\n]", given_id); /* obten��o do id do futuro contato */
	        insert(contato, given_id, given_tel, numero_contato); /* adi��o do contato */
            perform_id_sort(contato ,numero_contato); /* ordena��o dos contatos */
            /*a ordena��o acima � feita para o caso de se precisar  buscar ou */
            /* imprimir os contatos em ordem de nome */
         }

         /* caso receba um 'n', o programa buscar� um contato pelo id*/       
         else if(comand=='n'){
            scanf(" %[^\n]", given_id); /* obten��o do id a ser buscado*/
            id_search(contato, given_id , numero_contato); /* busca do contato*/
         }
         
         /* caso receba um 't', o programa buscar� um contato pelo tel*/   
         else if(comand=='t'){
            scanf("%d", &given_tel); /* obten��o do telefone a ser buscado*/
            tel_search(given_tel, contato, numero_contato); /*busca do contato*/
         }
         
         /* caso receba um 'p', o programa far� a impress�o dos contatos na tela*/
         else if(comand=='p'){
            perform_id_sort(contato ,numero_contato);     
            print_all(contato, numero_contato);
         }

         /*repeti��o da obten��o de comando para retornar ao in�cio da condi��o */
         scanf("%c", &comand);    
    } 

    return 0;
}
/* funcionamento da agenda */ 


