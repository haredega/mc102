

main() {
       float n1, n2, n3, p1, p2, p3, acumulado, media;
       printf("Ol�. Por favor, digite as 3 notas:\n");
       scanf("%f %f %f", &n1, &n2, &n3);
       printf("Agora, digite os pesos:\n");
       scanf("%f %f %f", &p1, &p2, &p3);     
       printf("Digite a m�dia:\n");
       scanf("%f", &media);
       
       if(n3==-1){
                 acumulado=(n1*p1+n2*p2)/(p1+p2+p3);
                 n3= media*(p1+p2+p3)-(n1*p1+n2*p2);
                 if(n3>10)
                          printf("Sinto Muito. Voc� j� foi reprovado.\n At� o pr�ximo semestre.\n");
                 
                 else
                     printf("Voc� precisa tirar %f na �ltima prova.", n3);
                 
                 
                 }                 
        else {         
                 
       acumulado= (n1*p1+n2*p2+n3*p3)/(p1+p2+p3);
       
       if(acumulado<media)
                          printf("Sinto Muito. Voc� foi reprovado.\n At� o pr�ximo semestre.\n");
                          
                 
          else
                          printf("Parab�ns, voc� foi aprovado!");
              
              }
system ("pause");
  
}      
                                       
          
