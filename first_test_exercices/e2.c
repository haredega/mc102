

main() {
       float n1, n2, n3, p1, p2, p3, acumulado, media;
       printf("Olá. Por favor, digite as 3 notas:\n");
       scanf("%f %f %f", &n1, &n2, &n3);
       printf("Agora, digite os pesos:\n");
       scanf("%f %f %f", &p1, &p2, &p3);     
       printf("Digite a média:\n");
       scanf("%f", &media);
       
       if(n3==-1){
                 acumulado=(n1*p1+n2*p2)/(p1+p2+p3);
                 n3= media*(p1+p2+p3)-(n1*p1+n2*p2);
                 if(n3>10)
                          printf("Sinto Muito. Você já foi reprovado.\n Até o próximo semestre.\n");
                 
                 else
                     printf("Você precisa tirar %f na última prova.", n3);
                 
                 
                 }                 
        else {         
                 
       acumulado= (n1*p1+n2*p2+n3*p3)/(p1+p2+p3);
       
       if(acumulado<media)
                          printf("Sinto Muito. Você foi reprovado.\n Até o próximo semestre.\n");
                          
                 
          else
                          printf("Parabéns, você foi aprovado!");
              
              }
system ("pause");
  
}      
                                       
          
