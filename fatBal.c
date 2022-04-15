#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fatBal.h"

void calcaulaFatBal(No *node) {

    if(node == NULL) {
        return;
    }         
    if(node != NULL){

        int altEsq = calcaulaAltura(node->pEsq);
        int altDir = calcaulaAltura(node->pDir);
        int balancoFator = altDir - altEsq;
        
        node->FatBal = balancoFator;

        calcaulaFatBal(node->pDir);   
        calcaulaFatBal(node->pEsq);
    }
}

int calcaulaAltura(No *node) {

  if(node == NULL)
      return 0;

  int altEsq = calcaulaAltura(node->pEsq); // endereco do no da esquerda
  int altDir = calcaulaAltura(node->pDir); // endereco do no da direita
  
  if(altEsq > altDir) 
      return altEsq + 1;
  else 
      return altDir + 1;
}