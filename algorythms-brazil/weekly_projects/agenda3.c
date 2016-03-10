/* Programa: agenda3.c        Laborat�rio 08                    */
/* Autor: Heitor Arede Garcia                   RA102566     */
/* Disciplina: MC102                      Turma C     */
/* Data: 10/11/2010                                 */
/* A proposta � adicionar � agenda anterior o conceito de  */
/* lista ligada e aloca��o din�mica de mem�ria */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*cria��o do 'tipo' agenda */
/* cada "Agenda" cont�m um 'nome'(o nome da pessoa) */
/* e um 'tel'(o n�merodo telefone), al�m de "chamar" o pr�ximo contato. */
typedef struct _contato_ {
  char nome[150];
  int tel;
  struct _contato_ *next;   /* esta linha define a lista ligada*/
} Agenda ;
/*cria��o do 'tipo' agenda */



/* cria��o do n�*/
Agenda *criaNo(int tel, char nome[], Agenda *next){
	   
           Agenda *c;
           /* aloca��o da mem�ria */
           c = (Agenda*) malloc(sizeof(Agenda));          
	       
           /* aqui copiamos para o novo n� os dados inseridos*/ 
           c->tel = tel;
	       strcpy(c->nome, nome );	
	       c->next = next;
	       /* esta �ltima linha faz com que o contato novo aponte para*/
	       /* o contato certo (ser� necess�rio para organizar alfabeticamente)*/
           return c;

}	
/* cria��o do no*/

/*inser��o de contatos*/
/* como alteraremos a Agenda contato, ela deve ser passada por referencia.  */    
Agenda* insereOrdenado(Agenda **contato, char nome[], int tel ) {
          Agenda *p, *a;
          p = *contato;
          a = p; 
          /*utilizaremos 2 agendas auxiliares, para colocar o novo n� entre*/
          /* os demais em ordem alfabetica*/
          
          if(*contato == NULL)
                { *contato = criaNo(tel, nome, NULL); return *contato;}
          /*se n�o h� nenhum n�, criamos o primeiro*/
                  
         else{       
                 /* caso contr�rio, procuramos a posicao correta, indicada sempre por 2 n�s,*/
                 /* o anterior (a) e o proximo (p)*/
                                  
                 /* aqui, procuramos a posi��o correta, sempre atualizando a e p*/
                 while( p != NULL && strcmp(nome, p->nome) > 0 )
                      { a = p; p = p->next; }         

                 /* se a e p forem o mesmo n�mero, o que s� acontece na */
                 /* primeira posi��o, devemos fazer com que o contato que estava  */
                 /* na primeira posi��o seja apontado pelo novo  */                 
                 if ( a==p )
                     { p = criaNo(tel, nome, p); return p; }   
                                        
                 /* caso contr�rio, colocamos o novo contato entre o */
                 /* anterior e o pr�ximo (� apontado por a e aponta para p) */
                 else                 
                 { a->next = criaNo(tel, nome, p); return *contato; } 

         } 
}
/*inser��o de contatos*/


/* busca por nome*/
/* para buscar os telefones, fa�o uma busca sequencial seguindo a lista n� por n�*/
void busca(Agenda *contato, char nome[]) {
	Agenda *q;
	q = contato;
	
	/* se a lista estiver vazia, o contato n�o existe */
	if(q == NULL)
       { printf("Contato nao encontrado!\n\n"); return; }    
    
    /* caso contr�rio, sigo a lista at� o fim procurando o nome correto  */    
	while( ( q->next != NULL) && (strcmp( q->nome, nome) != 0) )	
  		q = q->next;
  	
    /* se  ele for encontrado, imprimo-o*/  	
	if( strcmp(q->nome, nome) == 0) 
		printf("%-40s %d\n\n", q->nome, q->tel);
	
	/* caso contr�rio, ele n�o existe  */
	else 
		printf("Contato nao encontrado!\n\n");
    return;
}

/*impress�o dos dados*/
void imprime(Agenda *contato){
      Agenda *q;
      
      /* se a lista estiver vazia, apenas pulo uma linha */
      if ( contato == NULL)
         { printf("\n"); return; }
         
      /* caso contr�rio, imprimo a lista, n� a n�, at� o fim  */      
      
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
/* conforme arquivo no site da disciplina, */
/* com apenas as vari�veis modificadas  */
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
          
          /* se  a lista estiver vazia, n�o posso remover contato algum*/ 
          if(q == NULL)
             printf("Nao foi possivel remover: Contato inexistente!\n\n");

          /* caso contr�rio, procuro o contato at� o fim da lista */
          else {
             /* se  for o primeiro contato, apenas o removo */
             /* e fa�o o apontador inicial ser o seguinte  */
             if( strcmp(nome, q->nome) == 0 ){                  
                     printf("Contato: %-40s %d\nFoi removido com sucesso!\n\n", q->nome, q->tel);
                     f = q;
                     q = q->next;
                     free( f );
                     *contato=q;
             }
             
             /* se n�o, percorro a lista at�  fim procurando pelo nome  */
             else{
                 while(q != NULL && strcmp(nome, q->nome) != 0 ){
                       s = q;
                       q = q->next;
                 }
                 
                 /* se chegar ao fim da lista, n�o encontramos */
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

         /* caso receba um 'r', o programa remover� um contato a partir do nome*/
         else if(comand=='r'){
              scanf(" %[^\n]", nome); /* obten��o do nome a ser apagado*/
              removeNo( &contato, nome);  /* remo��o do nome  */

              
         } 
    } 
    
    /* desaloca��o da mem�ria */
    libera( &contato);
    return 0;
}
/* funcionamento da agenda */ 


