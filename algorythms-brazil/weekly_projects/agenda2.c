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
/* quick sort */
int separa (Agenda contato[], int p, int r) {
    Agenda c, t;
    
    /* pivo */
    c.tel = contato[p].tel;
    strcpy(c.id, contato[p].id);
    
    int i = p+1;
    int j = r;
       
   while ( i <= j ) {
    if ( strcmp(contato[i].id, c.id) < 0 ) ++i;
    else if (strcmp(contato[j].id, c.id ) > 0 ) --j; 
    else {
    
    t.tel = contato[i].tel;
    strcpy(t.id, contato[i].id);
    
    contato[i].tel = contato[j].tel;
    strcpy(contato[i].id, contato[j].id);
    
    contato[j].tel = t.tel;
    strcpy(contato[j].id, t.id);
    ++i; --j;
    }
   }
   
   t.tel = contato[p].tel;
   strcpy(t.id, contato[p].id);
    
   contato[p].tel = contato[j].tel;
   strcpy(contato[p].id, contato[j].id);
   
   contato[j].tel = t.tel;
   strcpy(contato[j].id, t.id);
   
   return j; 
}

void quicksort (Agenda contato[], int p, int r) {
  int j;
  if (p < r) {
    j = separa (contato, p, r); 
    quicksort (contato, p, j-1); 
    quicksort (contato, j+1, r);
  }
}
/*quicksort*/
/*insert sort nomes*/



/* busca por telefone*/
/* para buscar os telefones, faço uma busca sequencial */
/* aqui, foi utilizado o modelo mostrado em sala, sendo substituídas */
/* apenas as variáveis. a agenda é dada como parâmetro para localizar o */
/* vetor onde ocorrerá a busca */
int tel_search(int given_tel, Agenda contato[], int numero_contato) {
  int busca=0;
  int encontrado=0; /*Falso*/
  
  while ( (busca <= numero_contato) && (!encontrado) ) {
        if(contato[busca].tel==given_tel) {
            encontrado = 1; /*Verdadeiro*/
        } 
        else {
             busca++;
        }
  }
  
  /* tratamento dos resultados */
  if (encontrado)
    return busca;              

  else  
    return -1;  
}
/* busca por telefone*/


/* busca binária recursiva dos nomes */
/* Retorna o índice no vetor onde está o nome ou -1,
   caso o valor não esteja no vetor */

int busca(Agenda contato[], char given_id[], int i, int f ) {
  int k;

  if (i > f)
      return -1; 
  else {
    k = (i+f)/2;
    
    if ( strcmp( contato[k].id, given_id ) == 0 )
        return k;
    else if (strcmp(contato[k].id, given_id) < 0)
	    return busca(contato, given_id , k+1, f);
    else
	    return busca(contato, given_id ,i,k-1);
  }
}

void id_search(Agenda contato[], char given_id[], int i, int f){
     int encontrado;
     
     encontrado = busca(contato, given_id, i, f);
    
     if (encontrado == -1) {
        printf("Contato nao encontrado!\n\n");                    
     } 
     else {
        printf("%-40s %d\n\n", contato[encontrado].id, contato[encontrado].tel);       
     }
} 
/* busca binária recursiva dos nomes */  
       
/*impressão dos dados*/
/* pela simplicidade desta função, comentários serão dispensados */
void print_all(Agenda contato[], int numero_contato){
     int i;
         
     for (i=0; i<= numero_contato; i++){
         if(i!=0)
            printf("%-40s %d\n", contato[i].id, contato[i].tel );
         
         if(contato[i].id[0]!=contato[i+1].id[0] && i!= numero_contato)
	        printf("----%c----\n", contato[i+1].id[0]);
     }
     printf("\n");
}
/*impressão dos dados*/

/*remoção do contato */
int remocao(Agenda contato[],int numero_contato, int given_tel){
     int aux, i;
         
     aux = tel_search( given_tel, contato, numero_contato );
     if(aux == -1){
            printf("Nao foi possivel remover: Contato inexistente!\n\n");
            return -1;
     }
     else{
          printf("Contato: %-40s %d\nFoi removido com sucesso!\n\n", contato[aux].id, contato[aux].tel);
          for ( i = aux ; i < numero_contato ; i++ ) {
              strcpy(contato[i].id, contato[i+1].id);
              contato[i].tel = contato[i+1].tel;
          }
          return 1;         
     }
}

/*remoção do contato */
      
/* funcionamento da agenda */
/* apesar de auto-explicativo, o funcionamento contará com alguns comentários */
/* para simplificar o entendimento */

int main(){
    /*criação das variáveis */
    char comand, given_id[150]; /* caracteres */
    int given_tel, gambiarra, gambiarra2, numero_contato=0;    /* inteiros e um apontador para numero_contatos */
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
            quicksort(contato , 0, numero_contato); /* ordenação dos contatos */
            /*a ordenação acima é feita para o caso de se precisar  buscar ou */
            /* imprimir os contatos em ordem de nome */
         }

         /* caso receba um 'n', o programa buscará um contato pelo id*/       
         else if(comand=='n'){
            scanf(" %[^\n]", given_id); /* obtenção do id a ser buscado*/
            id_search(contato, given_id , 0, numero_contato); /* busca do contato*/
         }
         
         /* caso receba um 't', o programa buscará um contato pelo tel*/   
         else if(comand=='t'){
            scanf("%d", &given_tel); /* obtenção do telefone a ser buscado*/
            gambiarra = tel_search(given_tel, contato, numero_contato); /*busca do contato*/
            if(gambiarra != -1 )
                         printf("%-40s %d\n\n", contato[gambiarra].id, contato[gambiarra].tel);
            else
                         printf("Contato nao encontrado!\n\n");             
         
         }
         
         /* caso receba um 'p', o programa fará a impressão dos contatos na tela*/
         else if(comand=='p'){
            quicksort(contato , 0, numero_contato);     
            print_all(contato, numero_contato);
         }

         /* caso receba um 'r', o programa removerá um contato a partir do telefone */
         else if(comand=='r'){
              scanf("%d", &given_tel); /* obtenção do telefone a ser apagado*/
              gambiarra2 = remocao(contato, numero_contato, given_tel);
              quicksort(contato , 0, numero_contato); /* re-ordenação dos contatos */
              if(gambiarra2 == 1)
                   numero_contato--;         
         }
         
         
         /*repetição da obtenção de comando para retornar ao início da condição */
         scanf("%c", &comand);    
    } 

    return 0;
}
/* funcionamento da agenda */ 


