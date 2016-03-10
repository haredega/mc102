#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*cria��o do 'tipo' agenda */
/* cada "Agenda" cont�m um 'id'(o nome da pessoa) */
/* e um 'tel'(o n�merodo telefone), al�m de "chamar" o pr�ximo contato. */
typedef struct _contato_ {
  char nome[150];
  int tel;
  struct _contato_ *next;
} Agenda ;
/*cria��o do 'tipo' agenda */



/* cria��o do n�*/
Agenda *criaNo(int tel, char nome[], Agenda *next){
	   
           Agenda *c;
           c = (Agenda*) malloc(sizeof(Agenda));          
	
           c->tel = tel;
	       strcpy(c->nome, nome );	
	       c->next = next;
	   
           return c;

}	
/* cria��o do no*/

/*inser��o de contatos*/
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
/*inser��o de contatos*/


/* busca por nome*/
/* para buscar os telefones, fa�o uma busca sequencial seguindo a lista n� por n�*/
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

/*impress�o dos dados*/
/* pela simplicidade desta fun��o, coment�rios ser�o dispensados */
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
/*impress�o dos dados*/       


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

/*remo��o do contato, pelo nome */
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
/*remo��o do contato, pelo nome */     
  

/* funcionamento da agenda */
/* apesar de auto-explicativo, o funcionamento contar� com alguns coment�rios */
/* para simplificar o entendimento */

int main(){
    /*cria��o das vari�veis */
    char comand, nome[150]; /* caracteres */
    int tel;    /* inteiro*/
    Agenda *contato; /*apontador para a agenda*/
    contato = NULL;

	   
	/* se o comando for um 'f', o programa � finalizado, n�o realizando nenhuma opera��o*/
    while(comand!='f'){
                  
  
         scanf("%c", &comand);
	    /*obten��o do comando*/
	
         /* caso receba um 'i', o programa adicionar� um novo contato */
         if(comand=='i'){
            scanf(" %d ", &tel); /*obten��o do telefone do futuro contato*/
	        scanf("%[^\n]", nome); /* obten��o do id do futuro contato */
	        contato = insereOrdenado(&contato, nome, tel);/* adi��o do contato */
           }

         /* caso receba um 'n', o programa buscar� um contato pelo id*/       
         else if(comand=='n'){
            scanf(" %[^\n]", nome); /* obten��o do id a ser buscado*/
           busca(contato, nome); /* busca do contato*/
         }
       
         /* caso receba um 'p', o programa far� a impress�o dos contatos na tela*/
         else if(comand=='p'){
              imprime(contato);
         }

         /* caso receba um 'r', o programa remover� um contato a partir do telefone */
         else if(comand=='r'){
              scanf(" %[^\n]", &nome); /* obten��o do telefone a ser apagado*/
              removeNo( &contato, nome);
         } 
    } 
    libera( &contato);
    return 0;
}
/* funcionamento da agenda */ 


