#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//VARIÁVEIS GLOBAIS
int produto_dia[10][7], soma_produto_unidade[10], total_venda_produto_unidade[10], total_venda_de_todos_unidade, entrada_menu;
float preco_produto[10], soma_produto_valor[10], total_venda_produto_valor[10], total_venda_de_todos_valor;
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
int i,j = 0, produto = 0, dia = 0, linha_preco =0;


//FUNÇÕES
void dia_semana(void){

	printf("                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");

}

void menu(){
    printf("ESCOLHA UMA OPÇÃO :");
    printf("\n1 - EXIBIR A TABELA DE VENDAS");
    printf("\n2- EXIBIR DADOS DOS DIAS");
    printf("\n3- EXIBIR DADOS DOS PRODUTOS");
    printf("\n4- EXIBIR O PREÇO DE CADA ITEM");
    printf("\n5- GERAR RELATÓRIO");
    scanf("%i", &entrada_menu);
    switch (entrada_menu){
    case 1:
        exibe_vendas();
        break;
    case 2:
        exibe_dados_dia();
        break;
    case 3:
        exibe_dados_produto();
        break;
    case 4:
        exibe_preco();
        break;

}

}

void corrije_dado(){

}

void exibe_dados_dia(){
    //UNIDADE
    for(i = 0; i<7; i++){
            for(j=0; j<10; j++){
                soma_produto_unidade[i]+=produto_dia[j][i];
            }
    }

    printf("\n\n\nTOTAL DE VENDAS POR DIA (EM UNIDADE)\n\n");
    printf("DOMINGO  SEGUNDA  TERCA  QUARTA  QUINTA  SEXTA  SABADO\n");
    for(i = 0; i<7; i++){
        printf("  %i    ",soma_produto_unidade[i]);
	}

	//VALOR
	for(i = 0; i<7; i++){
        for(j=0; j<10; j++){
            soma_produto_valor[i]=soma_produto_valor[i]+(produto_dia[j][i]*preco_produto[j]);
        }
    }
    printf("\n\n\nTOTAL DE VENDAS POR DIA (EM REAIS))\n\n");
    printf("DOMINGO   SEGUNDA    TERCA     QUARTA     QUINTA      SEXTA     SABADO\n");
    for(i = 0; i<7; i++){
        printf("%.2f     ",soma_produto_valor[i]);
	}
}

void exibe_dados_produto(void){
    //UNIDADE
    for(i = 0; i<10; i++){
        for(j = 0; j<7; j++){
            total_venda_de_todos_unidade+=produto_dia[i][j];
            total_venda_produto_unidade[i]+=produto_dia[i][j];
        }
    }
    //VALOR
    for(i = 0; i<10; i++){
        total_venda_produto_valor[i]=total_venda_produto_unidade[i]*preco_produto[i];
        total_venda_de_todos_valor+=total_venda_produto_valor[i];

    }

    //UNIDADE
    printf("\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
    for(i = 0; i<10; i++){
        printf("\n%s %i",nome_produto[i],total_venda_produto_unidade[i]);
    }

    //VALOR
    printf("\nTOTAL DE VENDAS POR PRODUTO (EM REAIS)\n");
    for(i = 0; i<10; i++){
        printf("\n%s %.2f",nome_produto[i],total_venda_produto_valor[i]);
    }



}
void exibe_produto_semana(){
    printf("\nTOTAL DAS VENDAS (EM UNIDADE): %i",total_venda_de_todos_unidade);
    printf("\nTOTAL DAS VENDAS (EM UNIDADE): %.2f",total_venda_de_todos_valor);

}

void gera_relatorio(){
}

void exibe_vendas(void){
    dia_semana();
	for( produto = 0; produto < 10 ; produto++){
		printf("     \n %s", nome_produto[produto]);
		for( dia = 0; dia < 7 ; dia++){
	    	printf("  %i  ",produto_dia[produto][dia]);
		}
	}
}

void exibe_preco(void){
	printf("\n\n");
	for(j=0; j<10; j++){
	    printf("\n%s  %.2f", nome_produto[j],preco_produto[j]);
	}

}

int main(){

	FILE *arq, *arq1;
	char Linha[100];
	char *result;
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
	      	//printf("Linha %d : %s",i,Linha);
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
	        	preco_produto[linha_preco]=atof(Linha); //Str pra Float
	        	linha_preco++;
	      	}
	    }
	}


	//exibe_vendas();
	//exibe_dados_dia();
	//exibe_dados_produto();
	//exibe_produto_semana();

    while(entrada_menu!=6){
        menu();

    }

	fclose(arq);

	return 0;
}
