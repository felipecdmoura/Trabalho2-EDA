#ifndef INSERIRABP_H
#define INSERIRABP_H

#include <stdio.h>
#include "structABP.h"

No *inserirNums(No *head, int num);
No *buscaNode(No *node, int num);
No *calculaFatBal(No *node, CsvNums vet, No *aux, int auxEsq, int auxDir);
int fatBalEsq(No *aux, int auxEsq);
int fatBalDir(No *aux, int auxDir);
void imprimir(No *head);

#endif /* INSERIRABP_H */