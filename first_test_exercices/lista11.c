

main() {
       int n1, n2, n3, p1, p2, p3, acumulado, media;
       printf("Ol�. Por favor, digite as 3 notas:\n");
       scanf("%d %d %d", &n1, &n2, &n3);
       printf("Agora, digite os pesos:\n");
       scanf("%d %d %d", &p1, &p2, &p3);     
       printf("Digite a m�dia:\n");
       scanf("%d", &media);
       
       acumulado= (n1*p1+n2*p2+n3*p3)/(p1+p2+p3);
       
       if(acumulado<media)
                          printf("Sinto Muito. Voc� foi reprovado./n At� o pr�ximo semestre.\n");
                          
                 
          else{
                          printf("Parab�n, voc� foi aprovado!");
                          }
system ("pause");
  
}      
                                       
          
