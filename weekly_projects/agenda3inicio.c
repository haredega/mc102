#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*criação do 'tipo' agenda */
/* cada "Agenda" contém um 'id'(o nome da pessoa) */
/* e um 'tel'(o númerodo telefone), além de "chamar" o próximo contato. */
typedef struct _contato_ {
  char nome[150];
  int tel;
  struct _contato_ *next;
} Agenda ;
/*criação do 'tipo' agenda */



/* criação do nó*/
Agenda *criaNo(int tel, char nome[], Agenda *next){
	   
           Agenda *c;
           c = (Agenda*) malloc(sizeof(Agenda));          
	
           c->tel = tel;
	       strcpy(c->nome, nome );	
	       c->next = next;
	   
           return c;

}	
/* criação do no*/

/*inserção de contatos*/
Agenda* insereOrdenado(Agenda **contato, char nome[], int tel ) {
          Agenda *q, *s;
          q = *contato;
          s = q; 
          
          if(*contato == NULL)
                { *contato = criaNo(tel, nome, NULL);
                  return *contato;}
                 
          else if( q->next == NULL && strcmp(nome, q->nome) < 0)
                     {*contato = criaNo(tel, nome, *contato);
                      return *contato;}
         else{                    
                 while( q != NULL && strcmp(nome, q->nome) > 0 )
                      { s = q;
                       q = q->next;
                 }         
                 if( s!=q ){                 
                 s->next = criaNo(tel, nome, q);
                 return *contato;} 
                 else
                     { q = criaNo(tel, nome, q); return q;}
         } 
}
/*inserção de contatos*/


/* busca por nome*/
/* para buscar os telefones, faço uma busca sequencial seguindo a lista nó por nó*/
void busca(Agenda *contato, char nome[]) {
	Agenda *q;
	q = contato;
	if(q == NULL){
		printf("Contato nao encontrado!\n\n");
        return;
    }    
        
	while( ( q->next != NULL) && (strcmp( q->nome, nome) != 0) )	
  		q = q->next;
  		
	if( strcmp(q->nome, nome) == 0) 
		printf("%-40s %d\n\n", q->nome, q->tel);
	
	else 
		printf("Contato nao encontrado!\n\n");
}

/*impressão dos dados*/
/* pela simplicidade desta função, comentários serão dispensados */
void imprime(Agenda *contato){
      Agenda *q;
      if ( contato == NULL){ 
         printf("\n");
         return;
      }   
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
          if(q == NULL)
             printf("Nao foi possivel remover: Contato inexistente!\n\n");

          else {
             if( strcmp(nome, q->nome) == 0 ){                  
                     printf("Contato: %-40s %d\nFoi removido com sucesso!\n\n", q->nome, q->tel);
                     f = q;
                     q = q->next;
                     free( f );
                     *contato=q;
             }
             else{
                 while(q != NULL && strcmp(nome, q->nome) != 0 ){
                       s = q;
                       q = q->next;
                 }
                 if(q == NULL)           
                  printf("Nao foi possivel remover: Contato inexistente!\n\n");         
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

         /* caso receba um 'r', o programa removerá um contato a partir do telefone */
         else if(comand=='r'){
              scanf(" %[^\n]", &nome); /* obtenção do telefone a ser apagado*/
              removeNo( &contato, nome);
         } 
    } 
    libera( &contato);
    return 0;
}
/* funcionamento da agenda */ 


