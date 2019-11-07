#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void dia_semana(){
	printf(" PRODUTO          DOM  SEG  TER  QUA  QUI  SEX  SAB\n");
}
int main(){
	
	FILE *arq, *arq1;
	char Linha[100];
	char *result;
	int produto_dia[10][7];
	float preco_produto[10];
	char nome_produto[10][20] = {"Farinha       : ",
	                           "Arroz         : ",
	                           "Feijao        : ",
	                           "Frango        : ",
	                           "Carne         : ",
	                           "Sabonete      : ",
	                           "Escova        : ",
	                           "Pasta         : ",
	                           "Shampoo       : ",
	                           "Condicionador : "
	                          };
	int i,j = 0, produto = 0, dia = 0, linha_preco =0 ;
	arq = fopen("Entrada.txt", "rt");             // LEITURA
	arq1 = fopen("Relatorio (saida).txt", "wt");  // GRAVAÇÃO
	
	if (arq == NULL){
		  // ERRO NA ABERTURA
	    printf("Problemas na abertura do arquivo\n");
	    return;
	}
	
	i = 1;
	
	
	while (!feof(arq)){
	  	// LÊ UMA LINHA (INCLUSIVE COM O '\N')
	    // O 'FGETS' LÊ ATÉ 99 CARACTÉRES OU ATÉ O '\N']
	
	  	if (result){  // SE FOI POSSÍVEL LER
	  		result = fgets(Linha, 100, arq);  
	      	printf("Linha %d : %s",i,Linha);
	      	result = fprintf(arq1,"Linha %d\n",i);
	      	produto_dia[produto][dia] = atoi(Linha); //Str pra Int
	
	      	i++;
	      	dia++;
	
	      	if(dia>6){
	        	dia=0;
	        	produto++;
	      	}
	      	if(i>70){
	      		fscanf(arq,"%s",&Linha);
	      		char *p;
	      		if(p=strchr(Linha, '\n')){//Testa se existe uma nova linha
                *p = 0;
                printf("Existe caractere de nova linha");
            	}
	        	preco_produto[linha_preco]=atof(Linha); //Str pra Float
	        	linha_preco++;
	      	}
	    }
	}
	
	dia_semana();
	for( produto = 0; produto < 10 ; produto++){
		printf("     \n %s", nome_produto[produto]);
		for( dia = 0; dia < 7 ; dia++){
	    	printf("  %i  ",produto_dia[produto][dia]);
		}
	}
	
	printf("\n\n");
	for(j=0; j<10; j++){
	    printf("\n%s  %.2f", nome_produto[j],preco_produto[j]);
	}
	
	fclose(arq);
	
	return 0;
}
