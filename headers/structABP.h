#ifndef STRUCTABP_H
#define STRUCTABP_H

#include <stdio.h>

struct No
{
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
} No;

#endif /* STRUCTABP_H */