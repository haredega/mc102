

main() {
       unsigned d1=1, d2=2, d3=3, dv1=2, dv2=2, dv3=2;
       printf("Digite a data de validade(00 00 00 para sair):\n");
       scanf("%u %u %u", &dv1, &dv2, &dv3);
       
       while(dv1!=0&&dv2!=0&&dv3!=0){
         printf("Digite agora a data atual:\n");
         scanf("%u %u %u", &d1, &d2, &d3);
         if(d3>dv3||(d3<=dv3&&d2>dv2)||(d3<=dv3&&d2<=dv2&&d1>dv1))
             printf("Vencido! Cuidado!");
         else 
            printf("Bom para consumo!\n"); 
             
       printf("Digite a data de validade(00 00 00 para sair):\n");
       scanf("%u %u %u", &dv1, &dv2, &dv3);
           }      
       
       
system ("pause"); 
}      
                                       
          
