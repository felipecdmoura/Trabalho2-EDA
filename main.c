/*
Trabalho 2 - EDA
Tema: ÁRVORE BINÁRIA DE PESQUISA(ABP);
UnB - Faculdade do Gama;
Professores: Nilton Correia e Fabrício;

Integrantes:
Felipe Candido de Moura: 200030469;
Diógenes Dantas Lélis Júnior: 190150267;
Amanda Fernandes Custodio: 190124989;
Lucas Gomes Caldas: 212005426;
João Pedro Alves Machado: 212008197;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas dos outros arquivos
#include "getNums.h"
#include "structABP.h"
#include "getNums.c"
#include "inserirABP.h"
#include "inserirABP.c"
#include "fatBal.c"
#include "fatBal.h"

// menu de opções
void menu()
{

    printf("--------------------------------\n");
    printf("---------------MENU-------------\n");
    printf("--------------------------------\n");

    printf("Selecione uma das opcoes abaixo: \n");
    printf("1) Gerar ABP\n");
    printf("2) Calcular o Fator de balanceamento para cada nó\n");
    printf("3) Imprimir a ABP\n");
    printf("4) Sair\n");
}

// main
int main()
{
    FILE *arq;
    CsvNums vet;
    int opc = 0;
    char stp, arqName[30];
    No *head = NULL;
    int fatbal = 0;
    int auxEsq = 0;
    int auxDir = 0;

    while (opc != 4)
    {
        menu();
        scanf("%d", &opc);
        system("clear || cls");
        switch (opc)
        {
        case 1:
            system("clear || cls");

            printf("Digite o nome do arquivo a ser usado:\n\n");
            scanf("%s", arqName);

            arq = fopen(arqName, "r");

            if (arq == NULL)
            {
                system("clear || cls");
                printf("Erro ao abrir o arquivo!\n\n");
                system("pause");
                break;
            }

            vet = getNums(arq, head);

            fclose(arq);

            for (size_t i = 0; i < vet.qtdNum; i++)
            {
                head = inserirNums(head, vet.nums[i]);
            }

            system("pause");
            break;
        case 2:

            calculaFatBal(head);

            system("pause");

            break;
        case 3:
            imprimir(head);
            break;
        case 4:

            free(head);
            free(vet.nums);
            break;
        default:
            printf("Opcao invalida!");
        }
    }

    return 0;
}
