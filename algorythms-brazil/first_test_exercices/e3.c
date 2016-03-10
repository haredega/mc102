

main() {
       unsigned ano, n;
       printf("Digite o ano(0 para sair):\n");
       scanf("%u", &ano);
       
      while(ano!=0){      
       
       n= ano/100;
      if(n==0)
                 printf("Século %u\n", n);
      else{         
                 n++;
                 printf("Século %u\n", n);
                 }
      scanf("%u", &ano);
      }
       
       
       
system ("pause"); 
}      
                                       
          
