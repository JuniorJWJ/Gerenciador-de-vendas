#include <stdio.h>
#include <stdlib.h>

int main(){
	
		
  FILE *arq, *arq1;
  char Linha[100];
  char *result;
  int i;
  arq = fopen("Entrada.txt", "rt");       // LEITURA
  arq1 = fopen("Relatorio (saida).txt", "wt");  // GRAVA��O
  if (arq == NULL)  // ERRO NA ABERTURA
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  while (!feof(arq)){
	// L� uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' l� at� 99 caracteres ou at� o '\n']
      
      if (result)  // Se foi poss�vel ler
	  printf("Linha %d : %s",i,Linha);
	  result = fprintf(arq1,"Linha %d\n",i);
      i++;
  }
  fclose(arq);

	return 0;
}
