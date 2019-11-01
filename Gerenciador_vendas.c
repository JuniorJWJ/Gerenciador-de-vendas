#include <stdio.h>
#include <stdlib.h>

/*int stringToInteger(char string[]){
    int i, digit, j = 1, m =0 ;

    for(  i = strlen(string)-1 ; i>=0 ; i--){
        digit = string[i];
        digit = digit - 48;
        m = m + (digit * j);
        j = j * 10;
    }
    return m;
}*/

int main(){


  FILE *arq, *arq1;
  char Linha[100];
  char *result;
  int produto_dia[10][7];
  int i, produto = 0, dia = 0;
  arq = fopen("Entrada.txt", "rt");       // LEITURA
  arq1 = fopen("Relatorio (saida).txt", "wt");  // GRAVAÇÃO

  if (arq == NULL)  // ERRO NA ABERTURA
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  i = 1;

  while (!feof(arq)){
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n']

      if (result)  // Se foi possível ler
	  printf("Linha %d : %s",i,Linha);
	  result = fprintf(arq1,"Linha %d\n",i);
	  produto_dia[produto][dia] = atoi(Linha);
      i++;
      dia++;
      if(dia>6){
        dia=0;
        produto++;
      }
  }

  for( produto = 0; produto < 10 ; produto++){
    printf("\n");

    for( dia = 0; dia < 7 ; dia++){
        printf("%i  ",produto_dia[produto][dia]); //= stringToInteger(Linha);
    }

  }

  fclose(arq);

	return 0;
}
