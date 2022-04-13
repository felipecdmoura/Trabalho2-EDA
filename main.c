#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genABP.h"
#include "structABP.h"
#include "genABP.c"
#include "inserirABP.h"
#include "inserirABP.c"

FILE *arq;
//No *head = NULL;

/*No *inserirNums(No *head, int num){
    if(head == NULL){
        No *aux = malloc(sizeof(No));
        aux->Chave = num;
        aux->pEsq = NULL;
        aux->pDir = NULL;
        return aux;
    }
    else{
        if(num < head->Chave)
            inserirNums(head->pEsq, num);
        else
            inserirNums(head->pDir, num);
    }
    return head;
}

void imprimir(No *head){
    if(head){
        printf("%d ", head->Chave);
        imprimir(head->pEsq);
        imprimir(head->pDir);
    }
}*/

void menu()
{

    printf("---Menu---\n\n");
    printf("Selecione uma das opcoes abaixo: \n");
    printf("1) Gerar ABP\n");
    printf("2) Calcula Fator de Balanceamento\n");
    printf("3) Imprime ABP\n");
    printf("4) Sair\n");
}

int main()
{
    int opc;
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
            //system("clear || cls");

            printf("Digite o nome do arquivo a ser usado:\n\n");
            scanf("%s", arqName);

            arq = fopen(arqName, "r");

            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo! (Digite qualquer coisa para continuar): ");
                scanf(" %c", &stp);
                break;
            }

            head = inserirNums(head, 5);
            imprimir(head);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            system("clear || cls");

            printf("Opcao invalida! (Digite qualquer tecla para voltar)\n");
            scanf(" %c", &stp);
            break;
        }
    }

    return 0;
}