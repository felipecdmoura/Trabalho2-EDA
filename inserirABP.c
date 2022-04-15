#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structABP.h"
#include "inserirABP.h"

No *inserirNums(No *node, int num)
{
    if (node == NULL)
    {
        No *aux = malloc(sizeof(No));
        aux->Chave = num;
        aux->pEsq = NULL;
        aux->pDir = NULL;
        return aux;
    }
    else
    {
        if (num < node->Chave) 
            node->pEsq = inserirNums(node->pEsq, num);
        else 
            node->pDir = inserirNums(node->pDir, num);
    }
    return node;
}

void imprimir(No *head)
{
    if (head)
    {
        printf("%d\n ", head->Chave);
        imprimir(head->pEsq);
        imprimir(head->pDir);
    }
}
