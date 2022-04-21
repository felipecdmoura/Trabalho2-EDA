#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fatBal.h"

void calculaFatBal(No *node)
{

    if (node == NULL)
    {
        return;
    }
    if (node != NULL)
    {

        int altEsq = calculaAltura(node->pEsq);
        int altDir = calculaAltura(node->pDir);
        int balancoFator = altDir - altEsq;

        node->FatBal = balancoFator;

        calculaFatBal(node->pDir);
        calculaFatBal(node->pEsq);
    }
}

int calculaAltura(No *node)
{

    if (node == NULL)
        return 0;

    int altEsq = calculaAltura(node->pEsq); // endereco do no da esquerda
    int altDir = calculaAltura(node->pDir); // endereco do no da direita

    if (altEsq > altDir)
        return altEsq + 1;
    else
        return altDir + 1;
}