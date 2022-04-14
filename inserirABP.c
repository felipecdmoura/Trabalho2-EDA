#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structABP.h"

No *inserirNums(No *head, int num){
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
        printf("%d\n ", head->Chave);
        imprimir(head->pEsq);
        imprimir(head->pDir);
    }
}
