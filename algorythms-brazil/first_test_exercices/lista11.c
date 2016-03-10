

main() {
       int n1, n2, n3, p1, p2, p3, acumulado, media;
       printf("Olá. Por favor, digite as 3 notas:\n");
       scanf("%d %d %d", &n1, &n2, &n3);
       printf("Agora, digite os pesos:\n");
       scanf("%d %d %d", &p1, &p2, &p3);     
       printf("Digite a média:\n");
       scanf("%d", &media);
       
       acumulado= (n1*p1+n2*p2+n3*p3)/(p1+p2+p3);
       
       if(acumulado<media)
                          printf("Sinto Muito. Você foi reprovado./n Até o próximo semestre.\n");
                          
                 
          else{
                          printf("Parabén, você foi aprovado!");
                          }
system ("pause");
  
}      
                                       
          
