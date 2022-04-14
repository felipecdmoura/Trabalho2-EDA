#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//bibliotecas dos outros arquivos
#include "genABP.h"
#include "structABP.h"
#include "genABP.c"
//#include "inserirABP.h"
//#include "inserirABP.c"

//globais
FILE *arq;
//No *head = NULL;

//menu de opções
void menu()
{

    printf("---Menu---\n\n");
    printf("Selecione uma das opcoes abaixo: \n");
    printf("1) Gerar ABP\n");
    printf("2) Calcula Fator de Balanceamento\n");
    printf("3) Imprime ABP\n");
    printf("4) Sair\n");
}

//main
int main()
{
    int opc;
    int i = 0;
    char stp, arqName[30];
    No *head = NULL;

    while (opc != 4)
    {
        //system("clear || cls");
        menu();
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("clear || cls");

            printf("Digite o nome do arquivo a ser usado:\n\n");
            scanf("%s", arqName);

            arq = fopen(arqName, "r");

            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo! (Digite qualquer coisa para continuar): ");
                scanf(" %c", &stp);
                break;
            }
            genABP(arq, head);
            break;
        case 2:
            break;
        case 3:
            imprimir(head);
            break;
        case 4:
            free(head);
            break;
        default:
            system("clear || cls");

            printf("Opcao invalida! (Digite qualquer tecla para voltar)\n");
            scanf(" %c", &stp);
            break;
        }
    }
    fclose(arq);
    return 0;
}