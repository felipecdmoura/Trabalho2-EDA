#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genABP.h"
#include "structABP.h"
//#include "inserirABP.h"
//#include "inserirABP.c"

void genABP(FILE *arq, No *head)
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
    }

    for (int i = 0; i < cont; i++)
    {
        printf("%d", nums[i]);
        arvore(nums[i], head);
    }
        //scanf(" %c", &stp);
}

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

/*void imprimir(No *head){
    if(head){
        imprimir(head->pEsq);
        printf("%d ", head->Chave);
        imprimir(head->pDir);
    }
}*/
void imprimir(No *head)
{
  if(head==0)
    return;
  imprimir(head->pDir);
  printf(" %d ",head->Chave);
  imprimir(head->pEsq);
}

void arvore(int num, No *head){
    head = inserirNums(head, num);
    imprimir(head);
}



