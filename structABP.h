#ifndef STRUCTABP_H
#define STRUCTABP_H

typedef struct TNo
{
    int Chave;
    struct TNo *pEsq, *pDir;
    int FatBal;
} No;

#endif /* STRUCTABP_H */