#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>


//VARIÁVEIS GLOBAIS
int produto_dia[10][7], soma_produto_unidade[10], total_venda_produto_unidade[10], total_venda_de_todos_unidade, entrada_menu;
int escolha_produto, altera_opcao, dia_alterar, dia_exibir,produto_exibir,maior_quantidade_produto_unidade,menor_quantidade_produto_unidade;
float preco_produto[10], soma_produto_valor[10], total_venda_produto_valor[10], total_venda_de_todos_valor;
float maior_quantidade_produto_valor,menor_quantidade_produto_valor;
char produtos_mais_vendidos[100], produtos_mais_vendidos_valor[100];
char nome_produto[10][20]={"FARINHA       : ",
                           "ARROZ         : ",
                           "FEIJÃO        : ",
                           "FRANGO        : ",
                           "CARNE         : ",
                           "SABONETE      : ",
                           "ESCOVA        : ",
                           "PASTA         : ",
                           "SHAMPOO       : ",
                           "CONDICIONADOR : "
                          };
char nome_produto1[10][20]={"FARINHA ",
                           "ARROZ ",
                           "FEIJÃO ",
                           "FRANGO ",
                           "CARNE ",
                           "SABONETE ",
                           "ESCOVA ",
                           "PASTA ",
                           "SHAMPOO ",
                           "CONDICIONADOR : "
                          };
char matriz_dia_semana[8][20] = {"DOMINGO",
                          "SEGUNDA",
                          "TERÇA",
                          "QUARTA",
                          "QUINTA",
                          "SEXTA",
                          "SABADO"
                          };
int i,j = 0, produto = 0, dia = 0, linha_preco =0;


//FUNÇÕES
void dia_semana(FILE *arq1){

printf("                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");
fprintf(arq1,"                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");

}

void menu(FILE *arq1){

    printf("\n\nESCOLHA UMA OPÇÃO :");
    printf("\n1 - EXIBIR A TABELA DE VENDAS");
    printf("\n2- EXIBIR DADOS DOS DIAS");
    printf("\n3- EXIBIR DADOS DOS PRODUTOS");
    printf("\n4- EXIBIR O PREÇO DE CADA ITEM");
    printf("\n5- ALTERAR O DADO DE UM ITEM");
    printf("\n6- GERAR RELATÓRIO");
    printf("\nRESPOSTA :   ");
    scanf("%i", &entrada_menu);

    switch (entrada_menu){
        case 1:
            system("cls");
            exibe_vendas(arq1);
            break;
        case 2:
            system("cls");
            exibe_dados_dia(arq1);
            break;
        case 3:
            system("cls");
            exibe_dados_produto(arq1);
            break;
        case 4:
            system("cls");
            exibe_preco(arq1);
            break;
        case 5:
            system("cls");
            corrije_dado(arq1);
            break;
        case 6:
            system("cls");
            gera_relatorio(arq1);
            break;
}

}

void corrije_dado(){

    system("cls");
    printf("QUAL PRODUTO VOCÊ DESEJA MODIFICAR? ");
    printf("\n1 - FARINHA");
    printf("\n2 - ARROZ");
    printf("\n3 - FEIJAO");
    printf("\n4 - FRANGO");
    printf("\n5 - CARNE");
    printf("\n6 - SABONETE");
    printf("\n7 - ESCOVA");
    printf("\n8 - PASTA");
    printf("\n9 - SHAMPOO");
    printf("\n10 - CONDICIONADOR\n");
    printf("\nRESPOSTA :   ");
    scanf("%i",&escolha_produto);

    system("cls");
    printf("\nVOCÊ DESEJA ALTERAR O VALOR (0) OU QUANTIDADE DO PRODUTO(1)?");
    printf("\nRESPOSTA :   ");
    scanf("%i",&altera_opcao);

    switch (altera_opcao){
        case 0:
            printf("\nQUAL O NOVO PREÇO DO PRODUTO ?  ");
            scanf("%f",&preco_produto[escolha_produto-1]);
            break;
        case 1:
            printf("\nQUAL O DIA QUE DESEJA ALTERAR ?  ");
            printf("\n1 - DOMINGO");
            printf("\n2 - SEGUNDA");
            printf("\n3 - TERÇA");
            printf("\n4 - QUARTA");
            printf("\n5 - QUINTA");
            printf("\n6 - SEXTA");
            printf("\n7 - SÁBADO");
            printf("\nRESPOSTA :   ");
            scanf("%i",&dia_alterar);
            printf("\nQUAL A NOVA QUANTIA DO PRODUTO ?  ");
            scanf("%i",&produto_dia[escolha_produto-1][dia_alterar-1]);
            break;
    }


}

void exibe_dados_dia(FILE *arq1){
    calculo_exibe_dados_dia();

    printf("\nQUAL O DIA QUE VOCE DESEJA VER AS VENDAS ?  ");
    printf("\n1 - DOMINGO");
    printf("\n2 - SEGUNDA");
    printf("\n3 - TERÇA");
    printf("\n4 - QUARTA");
    printf("\n5 - QUINTA");
    printf("\n6 - SEXTA");
    printf("\n7 - SÁBADO");
    printf("\n8 - TODA SEMANA");
    printf("\nRESPOSTA :   ");
    scanf("%i",&dia_exibir);

    if(dia_exibir>0 || dia_exibir<8){
       printf("\nTOTAL DE VENDAS POR DIA (EM UNIDADE) :%i", soma_produto_unidade[dia_exibir-1]);
       printf("\nTOTAL DE VENDAS POR DIA (EM REAIS) :%.2f", soma_produto_valor[dia_exibir-1]);
    }
    if(dia_exibir==8){
        //UNIDADE
        printf("\n\n\nTOTAL DE VENDAS POR DIA (EM UNIDADE)\n\n");
        printf("DOMINGO  SEGUNDA  TERCA  QUARTA  QUINTA  SEXTA  SABADO\n");
        for(i = 0; i<7; i++){
            printf("  %i    ",soma_produto_unidade[i]);
        }

        //VALOR
        printf("\n\n\nTOTAL DE VENDAS POR DIA (EM REAIS))\n\n");
        printf("DOMINGO   SEGUNDA    TERCA     QUARTA     QUINTA      SEXTA     SABADO\n");
        for(i = 0; i<7; i++){
            printf("%.2f     ",soma_produto_valor[i]);
        }
    }
}

void calculo_exibe_dados_produto(){
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
}

void calculo_exibe_dados_dia(){
    //UNIDADE
    for(i = 0; i<7; i++){
            for(j=0; j<10; j++){
                soma_produto_unidade[i]+=produto_dia[j][i];
            }
    }

    //VALOR
    for(i = 0; i<7; i++){
        for(j=0; j<10; j++){
            soma_produto_valor[i]=soma_produto_valor[i]+(produto_dia[j][i]*preco_produto[j]);
        }
    }
}

void exibe_dados_produto(FILE *arq1){
    calculo_exibe_dados_produto();


    printf("\nQUAL O PRODUTO QUE VOCE DESEJA VER AS VENDAS ?  ");
    printf("\n1 - FARINHA");
    printf("\n2 - ARROZ");
    printf("\n3 - FEIJAO");
    printf("\n4 - FRANGO");
    printf("\n5 - CARNE");
    printf("\n6 - SABONETE");
    printf("\n7 - ESCOVA");
    printf("\n8 - PASTA");
    printf("\n9 - SHAMPOO");
    printf("\n10 - CONDICIONADOR\n");
    printf("\n11 - TODOS OS PRODUTOS");
    printf("\nRESPOSTA :   ");
    scanf("%i",&produto_exibir);

    if(produto_exibir>0 || produto_exibir<11){

        //printf("\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
        printf("\n%s %i UNIDADES",nome_produto[produto_exibir-1],total_venda_produto_unidade[produto_exibir-1]);
        //printf("\nTOTAL DE VENDAS POR PRODUTO (EM REAIS)\n");
        printf("\n%s %.2f REAIS",nome_produto[produto_exibir-1],total_venda_produto_valor[produto_exibir-1]);

    }
    if(produto_exibir==11){
        //UNIDADE
        printf("\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
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
}

void exibe_produto_semana(FILE *arq1){
    printf("\nTOTAL DAS VENDAS (EM UNIDADE): %i",total_venda_de_todos_unidade);
    printf("\nTOTAL DAS VENDAS (EM UNIDADE): %.2f",total_venda_de_todos_valor);
}

void calcular_mais_vendido(){
    //MAIS VENDIDO UNIDADE
    maior_quantidade_produto_unidade=total_venda_produto_unidade[0];
    for(i = 0; i<10; i++){
        if(total_venda_produto_unidade[i]>maior_quantidade_produto_unidade){
            maior_quantidade_produto_unidade=total_venda_produto_unidade[i];
        }
    }

    //MAIS VENDIDO VALOR
    maior_quantidade_produto_valor=total_venda_produto_valor[0];
    for(i = 0; i<10; i++){
        if(total_venda_produto_valor[i]>maior_quantidade_produto_valor){
            maior_quantidade_produto_valor=total_venda_produto_valor[i];
        }
    }

}

void calcular_menor_vendido(){
    //MAIS VENDIDO UNIDADE
    menor_quantidade_produto_unidade=total_venda_produto_unidade[0];
    for(i = 0; i<10; i++){
        if(total_venda_produto_unidade[i]<menor_quantidade_produto_unidade){
            menor_quantidade_produto_unidade=total_venda_produto_unidade[i];
        }
    }

    //MAIS VENDIDO VALOR
    menor_quantidade_produto_valor=total_venda_produto_valor[0];
    for(i = 0; i<10; i++){
        if(total_venda_produto_valor[i]<menor_quantidade_produto_valor){
            menor_quantidade_produto_valor=total_venda_produto_valor[i];
        }
    }

}

void exibe_comparacao_maior_unidade(FILE *arq1){
    //MAIOR UNIDADE
    for(i = 0; i<10; i++){
        if(total_venda_produto_unidade[i]==maior_quantidade_produto_unidade){
            fprintf(arq1,"  %s - ",nome_produto1[i]);
            fprintf(arq1,"%i",maior_quantidade_produto_unidade);
        }
    }

}

void exibe_comparacao_maior_valor(FILE *arq1){
    //MAIOR VALOR
    for(i = 0; i<10; i++){
        if(total_venda_produto_valor[i]==maior_quantidade_produto_valor){
            fprintf(arq1,"  %s  ",nome_produto1[i]);
            fprintf(arq1,"%.2f",maior_quantidade_produto_valor);
        }
    }
}

void exibe_comparacao_menor_unidade(FILE *arq1){
    //MAIOR UNIDADE
    for(i = 0; i<10; i++){
        if(total_venda_produto_unidade[i]==menor_quantidade_produto_unidade){
                printf("%i",menor_quantidade_produto_unidade);
            fprintf(arq1,"  %s - ",nome_produto1[i]);
            fprintf(arq1,"%i",menor_quantidade_produto_unidade);
        }
    }

}

void exibe_comparacao_menor_valor(FILE *arq1){
    //MAIOR VALOR
    for(i = 0; i<10; i++){
        if(total_venda_produto_valor[i]==menor_quantidade_produto_valor){
            fprintf(arq1,"  %s  ",nome_produto1[i]);
            fprintf(arq1,"%.2f",menor_quantidade_produto_valor);
        }
    }
}

void gera_relatorio(FILE *arq1){
    printf("....RELATÓRIO CRIADO");
    fprintf(arq1,"TABELA DE VENDAS\n");
    fprintf(arq1,"                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");
    //EXIBE VENDAS
    for( produto = 0; produto < 10 ; produto++){
        fprintf(arq1,"     \n %s", nome_produto[produto]);
        for( dia = 0; dia < 7 ; dia++){
            fprintf(arq1,"  %i  ",produto_dia[produto][dia]);
        }
    }
    //EXIBIR DADOS DIAS
    calculo_exibe_dados_dia();
    //UNIDADE
    fprintf(arq1,"\n\n\nTOTAL DE VENDAS POR DIA (EM UNIDADE)\n\n");
    fprintf(arq1,"DOMINGO  SEGUNDA  TERCA  QUARTA  QUINTA  SEXTA  SABADO\n");
    for(i = 0; i<7; i++){
        fprintf(arq1,"  %i    ",soma_produto_unidade[i]);
    }
    //VALOR
    fprintf(arq1,"\n\n\nTOTAL DE VENDAS POR DIA (EM REAIS))\n\n");
    fprintf(arq1,"DOMINGO   SEGUNDA    TERCA     QUARTA     QUINTA      SEXTA     SABADO\n");
    for(i = 0; i<7; i++){
        fprintf(arq1,"%.2f     ",soma_produto_valor[i]);
    }

    //EXIBIR DADOS PRODUTOS
    calculo_exibe_dados_produto();
    //UNIDADE
    fprintf(arq1,"\n\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
    for(i = 0; i<10; i++){
        fprintf(arq1,"\n%s %i",nome_produto[i],total_venda_produto_unidade[i]);
    }
    //VALOR
    fprintf(arq1,"\n\nTOTAL DE VENDAS POR PRODUTO (EM REAIS)\n");
    for(i = 0; i<10; i++){
        fprintf(arq1,"\n%s %.2f",nome_produto[i],total_venda_produto_valor[i]);
    }

    //INFORMAÇÕES SEMANA
    fprintf(arq1,"\n\nTOTAL DAS VENDAS (EM UNIDADE): %i",total_venda_de_todos_unidade);
    fprintf(arq1,"\nTOTAL DAS VENDAS (EM REAIS): %.2f",total_venda_de_todos_valor);

    calcular_mais_vendido();
    fprintf(arq1,"\nPRODUTO QUE MAIS VENDEU (EM UNIDADE): ");
    exibe_comparacao_maior_unidade(arq1);
    fprintf(arq1,"\nPRODUTO QUE MAIS VENDEU (EM REAIS): ");
    exibe_comparacao_maior_valor(arq1);

    calcular_menor_vendido();
    fprintf(arq1,"\nPRODUTO QUE MENOS VENDEU (EM UNIDADE): ");
    exibe_comparacao_menor_unidade(arq1);
    fprintf(arq1,"\nPRODUTO QUE MENOS VENDEU (EM REAIS): ");
    exibe_comparacao_menor_valor(arq1);
}



void exibe_vendas(FILE *arq1){
    dia_semana(arq1);
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

    setlocale(LC_ALL, "Portuguese");
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
     	//result = fprintf(arq1,"Linha %d\n",i);
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

    while(entrada_menu!=6){
        menu(arq1);

    }

fclose(arq);

return 0;
}
