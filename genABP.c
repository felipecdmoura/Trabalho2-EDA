#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genABP.h"
#include "structABP.h"
//#include "inserirABP.h"
//#include "inserirABP.c"

int *genABP(FILE *arq, No *head)
{
    int *nums;
    int cont = 0, valor;
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

    return nums;

}




