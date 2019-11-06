#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){


  FILE *arq, *arq1;
  char Linha[100];
  char *result;
  int produto_dia[10][7];
  char nome_produto[11][20] = {"Farinha",
                               "Arroz",
                               "Feijao",
                               "Frango",
                               "Carne",
                               "Sabonete",
                               "Escova",
                               "Pasta",
                               "Shampoo",
                               "Condicionador"
                              };
  float preco_produto[10];
  int i,j = 0, produto = 0, dia = 0, linha_preco =0 ;
  arq = fopen("Entrada.txt", "rt");             // LEITURA
  arq1 = fopen("Relatorio (saida).txt", "wt");  // GRAVAÇÃO

  if (arq == NULL){  // ERRO NA ABERTURA
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  i = 1;

  printf("\n%s", nome_produto[0]);
  while (!feof(arq)){
  printf("\n%s", nome_produto[0]);
      // LÊ UMA LINHA (INCLUSIVE COM O '\N')
      result = fgets(Linha, 100, arq);  // O 'FGETS' LÊ ATÉ 99 CARACTÉRES OU ATÉ O '\N']

      if (result){  // SE FOI POSSÍVEL LER
          printf("Linha %d : %s",i,Linha);
          result = fprintf(arq1,"Linha %d\n",i);
          produto_dia[produto][dia] = atoi(Linha);

          i++;
          dia++;

          if(dia>6){
            dia=0;
            produto++;
          }
          if(i>70){
            preco_produto[linha_preco]=atoi(Linha);
            linha_preco++;
          }
      }
  }

  printf("\n%s", nome_produto[0]);
  for( produto = 0; produto < 10 ; produto++){
    printf("\n");
    for( dia = 0; dia < 7 ; dia++){
        printf("%i  ",produto_dia[produto][dia]);
    }
  }

  for(j=0; j<11; j++){
        printf("\n%s", nome_produto[j]);
  }



  printf("\n%s", nome_produto[0]);
  fclose(arq);

    getchar();
	return 0;
}
