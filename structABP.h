#ifndef STRUCTABP_H
#define STRUCTABP_H

typedef struct TNo
{
    int Chave;
    struct TNo *pEsq, *pDir;
    int FatBal;
} No;

typedef struct CsvNums
{
    int *nums;
    size_t qtdNum;
} CsvNums;

#endif /* STRUCTABP_H */