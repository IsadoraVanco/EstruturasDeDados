/**
 * @file main.c
 * @brief Testando a árvore binária
*/

#include "binaria.h"
#include <stdio.h>

int main(int argc, char const *argv[]){

    Arvore *arvore = criaArvore();

    inserirElemento(arvore, 10);
    inserirElemento(arvore, 15);
    inserirElemento(arvore, 5);
    inserirElemento(arvore, 3);
    inserirElemento(arvore, 1);
    inserirElemento(arvore, 2);
    inserirElemento(arvore, 3);

    printf("\n=> Percorrer em Pre Ordem\n");
    percorrerEmPreordemRecursiva(arvore->raiz);
    printf("\n=> Percorrer em Ordem Simetrica\n");
    percorrerEmOrdemSimetricaRecursiva(arvore->raiz);
    printf("\n=> Percorrer em Pos Ordem\n");
    percorrerEmPosOrdemRecursiva(arvore->raiz);
    
    printf("\nTestando remoção de elementos...\n");

    removeElemento(arvore, 11);
    removeElemento(arvore, 3);
    removeElemento(arvore, 2);
    percorrerEmOrdemSimetricaRecursiva(arvore->raiz);
    printf("\n");
    
    return 0;
}
