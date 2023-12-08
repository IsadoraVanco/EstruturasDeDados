// Implementação da estrutura de Pilha
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* NEW_PILHA(){
    Pilha* new = (Pilha *) malloc(sizeof(Pilha));

    if(!new){
        printf("Erro ao alocar espaço para a pilha.\n");
        return NULL;
    }

    new->tamanho = 0;
    new->topo = NULL;

    return new;
}

int POP(Pilha* pilha) {

    if (pilha->tamanho < 1){
        printf("Pilha vazia\n");
        return 0; // vazia
    }

    int valor = pilha->topo->valor;
    Celula* cel_topo = pilha->topo;

    pilha->topo = cel_topo->proximo;
    pilha->tamanho -= 1; // um a menos;
    free(cel_topo); // adeus celula

    printf("%d\n", valor);
    return valor;
}

int PUSH(int v, Pilha* pilha) {
    Celula* nova = (Celula *) malloc(sizeof(Celula));

    nova->valor = v;
    nova->proximo = pilha->topo;

    pilha->topo = nova;
    pilha->tamanho += 1;

    return 0;
}

int DELETE_PILHA(Pilha *pilha){
    free(pilha);
}