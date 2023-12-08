//ok, vamos lá...
//aqui temos todas as funções que serão usadas para o tipo pilha
#include <stdio.h>
#include <stdlib.h>
#include "pilhaInteiro.h"

//#define MAX_TAMANHO 50 => num modelo de tamanho ja fixo

//Representa uma pilha com suas informações
typedef struct {
    int topo; //primeira posição livre
    int tamanho; //tamanho maximo da pilha
    Item* itens; //armazena os itens da pilha
}PilhaInt;

Pilha create_pilha(int capacidade){ //segundo o exemplo do Evandro...
    PilhaInt *pointer;
    
    pointer = (PilhaInt*) malloc(sizeof(PilhaInt));
    pointer->tamanho = capacidade;
    pointer->itens = malloc(capacidade * sizeof(Item));
    pointer->topo = 0; //a primeira posição livre da pilha

    return pointer; //retorna o ponteiro para a nova pilha
}

void push(Pilha pilha, Item item){ 
    PilhaInt *pointer = (PilhaInt*) pilha;

    if(!full(pointer)){
        pointer->itens[pointer->topo] = item; //adiciona o item na pilha
        pointer->topo++;
    }else{
        printf("pilha cheia.\n");
    }
}

Item pop(Pilha pilha){
    PilhaInt *pointer = (PilhaInt*) pilha;

    if(!empty(pointer)){
        pointer->topo--;
        return pointer->itens[pointer->topo];
    }else{
        printf("pilha vazia.\n");
    }
}

int empty(Pilha pilha){
    PilhaInt *pointer = (PilhaInt*) pilha;
 
    if(pointer->topo == 0){
        return 1;
    }

    return 0;
}

int full(Pilha pilha){
    PilhaInt *pointer = (PilhaInt*) pilha;

    if(pointer->topo >= pointer->tamanho){
        return 1;
    }

    return 0;
}