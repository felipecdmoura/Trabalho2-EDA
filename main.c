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

int arvore(int valor)
{
    return valor;
}

// menu de opções
void menu()
{

    printf("---Menu---\n\n");
    printf("Selecione uma das opcoes abaixo: \n");
    printf("1) Gerar ABP\n");
    printf("2) Calcula Fator de Balanceamento\n");
    printf("3) Imprime ABP\n");
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

    while(opc != 4)
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

                calcaulaFatBal(head);

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
                printf("opcao invalida");
        }
    }

    return 0;
}