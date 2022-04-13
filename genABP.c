#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers\genABP.h"
#include "headers\structABP.h"

void genABP(FILE *arq, struct No *head)
{
    int *nums;
    int cont = 0;
    char buffer[1024], stp;

    while (fgets(buffer, sizeof(buffer), arq))
    {
        char *token;

        token = strtok(buffer, ";");

        nums = (int *)malloc(sizeof(token));

        while (token != NULL)
        {
            nums[cont] = atoi(token);
            cont++;
            token = strtok(NULL, ";");
        }

        for (int i = 0; i < cont; i++)
        {
            head = inserirNums(&head, nums[i]);
        }

        printf("%d\n", head->Chave);
        printf("%d\n", head->pDir->Chave);
        printf("%d\n", head->pDir->pDir->Chave);
        printf("\n%d", cont);
    }

    scanf(" %c", &stp);
}

struct No *inserirNums(struct No *aux, int num)
{
    if (aux == NULL)
    {
        struct No *aux = malloc(sizeof(No));
        aux->Chave = num;
        aux->pEsq = NULL;
        aux->pDir = NULL;
        return aux;
    }
    else
    {
        if (num < aux->Chave)
        {
            aux->pEsq = inserirNums(aux->pEsq, num);
        }
        else
        {
            aux->pDir = inserirNums(aux->pDir, num);
        }
        return aux;
    }
}
