#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getNums.h"
#include "structABP.h"

CsvNums getNums(FILE *arq, No *head)
{
    CsvNums vet;
    vet.qtdNum = 0;
    int valor;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), arq))
    {
        char *token;

        token = strtok(buffer, ";");

        vet.nums = (int *)malloc(sizeof(token));

        while (token != NULL)
        {
            vet.nums[vet.qtdNum] = atoi(token);
            vet.qtdNum++;
            token = strtok(NULL, ";");
        }
    }

    return vet;
}
