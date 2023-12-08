// Implementação da estrutura de Pilha como Arranjo
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* createStack(int tamanho){
    Pilha* new = (Pilha *) malloc(sizeof(Pilha));

    if(tamanho <= 0){
        printf("Tamanho insuficiente para criar a pilha.\n");
        return NULL;
    }

    if(!new){
        printf("Erro ao alocar espaço para a pilha.\n");
        return NULL;
    }

    new->tamanho = tamanho;
    new->topo = -1;
    new->pilha = (int *) malloc(tamanho * sizeof(int));

    return new;
}

int pop(Pilha *pilha) {

    if (isStackEmpty(pilha)){
        printf("Pilha vazia\n");
        return 0; // vazia
    }

    int valor = pilha->pilha[pilha->topo];
    pilha->topo--;

    printf("%d\n", valor);
    return valor;
}

int push(Pilha *pilha, int valor) {
    if(isStackFull(pilha)){
        printf("Pilha cheia.\n");
        return 1;
    }

    pilha->topo++;
    pilha->pilha[pilha->topo] = valor;

    return 0;
}

int isStackEmpty(Pilha *pilha){
    return pilha->topo < 0;
}

int isStackFull(Pilha *pilha){
    return pilha->topo == (pilha->tamanho - 1);
}

void deleteStack(Pilha *pilha){
    free(pilha->pilha);
    free(pilha);
}