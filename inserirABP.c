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

No *buscaNode(No *node, CsvNums vet, No *aux, int auxEsq, int auxDir)
{
    for (size_t i = 0; i < vet.qtdNum; i++)
    {
        if(node != NULL){
            if (node->Chave = vet.nums[i]) {
                node = calculaFatBal(node, vet.nums[i], aux, auxEsq, auxDir);
            } else {
                if (vet.nums[i] > node->Chave) {
                    return buscaNode(node->pDir, vet, aux->pDir, auxEsq, auxDir);
                } else {
                    return buscaNode(node->pEsq, vet, aux->pEsq, auxEsq, auxDir);
                }
            }
        }
    }
    return node;
}

No *calculaFatBal(No *node, int num, No *aux, int auxEsq, int auxDir)
{
    auxEsq = fatBalEsq(aux->pEsq, auxEsq);
    auxDir = fatBalEsq(aux->pDir, auxDir);

    node->FatBal = auxEsq + auxDir;
    return node;
}

int fatBalEsq(No *aux, int auxEsq)
{
    // Analisa a esquerda
    if (aux != NULL)
    {
        printf("%d\n", aux->Chave);
        auxEsq = fatBalEsq(aux->pEsq, auxEsq) - 1;
    }
    
    return auxEsq;
}

int fatBalDir(No *aux, int auxDir)
{
    // Analisa a direita
    if (aux != NULL)
    {
        printf("%d\n", aux->Chave);
        auxDir = fatBalDir(aux->pDir, auxDir) + 1;
    }
    
    return auxDir;
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
