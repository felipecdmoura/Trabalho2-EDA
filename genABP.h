#ifndef GENABP_H
#define GENABP_H

#include <stdio.h>
#include "structABP.h"

void genABP(FILE *arq, No *head);
No *inserirNums(No *head, int num);
void imprimir(No *head);
void arvore(int num, No *head);


#endif /* GENABP_H */