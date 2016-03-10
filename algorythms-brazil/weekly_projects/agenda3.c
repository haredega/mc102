/* Programa: agenda3.c        Laboratório 08                    */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 10/11/2010                                 */
/* A proposta é adicionar à agenda anterior o conceito de  */
/* lista ligada e alocação dinâmica de memória */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*criação do 'tipo' agenda */
/* cada "Agenda" contém um 'nome'(o nome da pessoa) */
/* e um 'tel'(o númerodo telefone), além de "chamar" o próximo contato. */
typedef struct _contato_ {
  char nome[150];
  int tel;
  struct _contato_ *next;   /* esta linha define a lista ligada*/
} Agenda ;
/*criação do 'tipo' agenda */



/* criação do nó*/
Agenda *criaNo(int tel, char nome[], Agenda *next){
	   
           Agenda *c;
           /* alocação da memória */
           c = (Agenda*) malloc(sizeof(Agenda));          
	       
           /* aqui copiamos para o novo nó os dados inseridos*/ 
           c->tel = tel;
	       strcpy(c->nome, nome );	
	       c->next = next;
	       /* esta última linha faz com que o contato novo aponte para*/
	       /* o contato certo (será necessário para organizar alfabeticamente)*/
           return c;

}	
/* criação do no*/

/*inserção de contatos*/
/* como alteraremos a Agenda contato, ela deve ser passada por referencia.  */    
Agenda* insereOrdenado(Agenda **contato, char nome[], int tel ) {
          Agenda *p, *a;
          p = *contato;
          a = p; 
          /*utilizaremos 2 agendas auxiliares, para colocar o novo nó entre*/
          /* os demais em ordem alfabetica*/
          
          if(*contato == NULL)
                { *contato = criaNo(tel, nome, NULL); return *contato;}
          /*se não há nenhum nó, criamos o primeiro*/
                  
         else{       
                 /* caso contrário, procuramos a posicao correta, indicada sempre por 2 nós,*/
                 /* o anterior (a) e o proximo (p)*/
                                  
                 /* aqui, procuramos a posição correta, sempre atualizando a e p*/
                 while( p != NULL && strcmp(nome, p->nome) > 0 )
                      { a = p; p = p->next; }         

                 /* se a e p forem o mesmo número, o que só acontece na */
                 /* primeira posição, devemos fazer com que o contato que estava  */
                 /* na primeira posição seja apontado pelo novo  */                 
                 if ( a==p )
                     { p = criaNo(tel, nome, p); return p; }   
                                        
                 /* caso contrário, colocamos o novo contato entre o */
                 /* anterior e o próximo (é apontado por a e aponta para p) */
                 else                 
                 { a->next = criaNo(tel, nome, p); return *contato; } 

         } 
}
/*inserção de contatos*/


/* busca por nome*/
/* para buscar os telefones, faço uma busca sequencial seguindo a lista nó por nó*/
void busca(Agenda *contato, char nome[]) {
	Agenda *q;
	q = contato;
	
	/* se a lista estiver vazia, o contato não existe */
	if(q == NULL)
       { printf("Contato nao encontrado!\n\n"); return; }    
    
    /* caso contrário, sigo a lista até o fim procurando o nome correto  */    
	while( ( q->next != NULL) && (strcmp( q->nome, nome) != 0) )	
  		q = q->next;
  	
    /* se  ele for encontrado, imprimo-o*/  	
	if( strcmp(q->nome, nome) == 0) 
		printf("%-40s %d\n\n", q->nome, q->tel);
	
	/* caso contrário, ele não existe  */
	else 
		printf("Contato nao encontrado!\n\n");
    return;
}

/*impressão dos dados*/
void imprime(Agenda *contato){
      Agenda *q;
      
      /* se a lista estiver vazia, apenas pulo uma linha */
      if ( contato == NULL)
         { printf("\n"); return; }
         
      /* caso contrário, imprimo a lista, nó a nó, até o fim  */      
      
      else{
         printf("----%c----\n", contato->nome[0]);
         while (contato != NULL) {
             printf("%-40s %d\n", contato->nome, contato->tel);
             if (contato->next != NULL){
                 q = contato->next;
                 if(q->nome[0] != contato->nome[0])
                     printf("----%c----\n", q->nome[0]);
                     }
             contato = contato->next;
         }
      }
      printf("\n");
      return;
}
/*impressão dos dados*/       


/* liberacao de memoria */
/* conforme arquivo no site da disciplina, */
/* com apenas as variáveis modificadas  */
void libera(Agenda **contato) {
  Agenda *f;
  
  while ( *contato != NULL) {
    f = *contato;
    *contato = (*contato)->next;
    free(f);
  }
}
/* liberacao de memoria */

/*remoção do contato, pelo nome */
void removeNo(Agenda **contato, char nome[]) {
          Agenda *q, *s, *f;
          q = *contato;
          s = q;
          
          /* se  a lista estiver vazia, não posso remover contato algum*/ 
          if(q == NULL)
             printf("Nao foi possivel remover: Contato inexistente!\n\n");

          /* caso contrário, procuro o contato até o fim da lista */
          else {
             /* se  for o primeiro contato, apenas o removo */
             /* e faço o apontador inicial ser o seguinte  */
             if( strcmp(nome, q->nome) == 0 ){                  
                     printf("Contato: %-40s %d\nFoi removido com sucesso!\n\n", q->nome, q->tel);
                     f = q;
                     q = q->next;
                     free( f );
                     *contato=q;
             }
             
             /* se não, percorro a lista até  fim procurando pelo nome  */
             else{
                 while(q != NULL && strcmp(nome, q->nome) != 0 ){
                       s = q;
                       q = q->next;
                 }
                 
                 /* se chegar ao fim da lista, não encontramos */
                 if(q == NULL)           
                  printf("Nao foi possivel remover: Contato inexistente!\n\n");         
                 
                 /* se encontrarmos antes, imprimimos o contato */
                 else if( strcmp(nome, q->nome) == 0){                  
                     printf("Contato: %-40s %d\nFoi removido com sucesso!\n\n", q->nome, q->tel);
                     f = q;
                     q = q->next;
                     free( f );
                     s->next = q;
                 }    
                 else            
                  printf("Nao foi possivel remover: Contato inexistente!\n\n"); }
             } 
}
/*remoção do contato, pelo nome */     
  

/* funcionamento da agenda */
/* apesar de auto-explicativo, o funcionamento contará com alguns comentários */
/* para simplificar o entendimento */

int main(){
    /*criação das variáveis */
    char comand, nome[150]; /* caracteres */
    int tel;    /* inteiro*/
    Agenda *contato; /*apontador para a agenda*/
    contato = NULL;

	   
	/* se o comando for um 'f', o programa é finalizado, não realizando nenhuma operação*/
    while(comand!='f'){
                  
  
         scanf("%c", &comand);
	    /*obtenção do comando*/
	
         /* caso receba um 'i', o programa adicionará um novo contato */
         if(comand=='i'){
            scanf(" %d ", &tel); /*obtenção do telefone do futuro contato*/
	        scanf("%[^\n]", nome); /* obtenção do id do futuro contato */
	        contato = insereOrdenado(&contato, nome, tel);/* adição do contato */
           }

         /* caso receba um 'n', o programa buscará um contato pelo id*/       
         else if(comand=='n'){
            scanf(" %[^\n]", nome); /* obtenção do id a ser buscado*/
           busca(contato, nome); /* busca do contato*/
         }
       
         /* caso receba um 'p', o programa fará a impressão dos contatos na tela*/
         else if(comand=='p'){
              imprime(contato);
         }

         /* caso receba um 'r', o programa removerá um contato a partir do nome*/
         else if(comand=='r'){
              scanf(" %[^\n]", nome); /* obtenção do nome a ser apagado*/
              removeNo( &contato, nome);  /* remoção do nome  */

              
         } 
    } 
    
    /* desalocação da memória */
    libera( &contato);
    return 0;
}
/* funcionamento da agenda */ 


