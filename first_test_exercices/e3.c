

main() {
       unsigned ano, n;
       printf("Digite o ano(0 para sair):\n");
       scanf("%u", &ano);
       
      while(ano!=0){      
       
       n= ano/100;
      if(n==0)
                 printf("S�culo %u\n", n);
      else{         
                 n++;
                 printf("S�culo %u\n", n);
                 }
      scanf("%u", &ano);
      }
       
       
       
system ("pause"); 
}      
                                       
          
