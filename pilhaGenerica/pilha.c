//aqui temos todas as funções que serão usadas para o tipo pilha
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//Representa uma pilha com suas informações
typedef struct {
    int topo; //primeira posição livre
    int tamanho; //indica o tamanho da pilha
    Item* itens; //armazena os itens da pilha
}PilhaGenerica;

//Novo elemento que será adicionado na pilha
typedef struct {
  Item info; //informação/conteudo do elemento
  NovoItem *proximo; //ponteiro para o proximo elemento
}NovoItem;

Pilha create_pilha(int capacidade){ //segundo o exemplo do Evandro...
    PilhaGenerica *pointer;
    
    pointer = (PilhaGenerica*) malloc(sizeof(PilhaGenerica));
    pointer->tamanho = capacidade;
    pointer->itens = malloc(capacidade * sizeof(Item));
    pointer->topo = 0; //a primeira posição livre da pilha

    return pointer; //retorna o ponteiro para a nova pilha
    // return NULL;
}

// void push(Pilha *pilha, Item iitem){ 
//   sNoItem **tp = (sNoItem **)pilha;
//   sNoItem *novo;

//   novo = (sNoItem *) malloc(sizeof(sNoItem));
//   novo->info = i;
//   novo->prox = *tp;
//   *tp = novo;
// }

void push(Pilha *pilha, Item item){ //pq por referencia?
    PilhaGenerica *pointer = (PilhaGenerica*) pilha;

    if(!full(pointer)){
        pointer->itens[pointer->topo] = item; //adiciona o item na pilha
        pointer->topo++;
    }else{
        printf("pilha cheia.\n");
    }

   
}

Item pop(Pilha *pilha){ //pq por referencia?
    PilhaGenerica *pointer = (PilhaGenerica*) pilha;

    if(!empty(pointer)){
        pointer->topo--;
        return pointer->itens[pointer->topo];
    }else{
        printf("pilha vazia.\n");
    }

     // nao esquecer de desalocar (free)
}

int empty(Pilha pilha){
    PilhaGenerica *pointer = (PilhaGenerica*) pilha;
 
    if(pointer->topo == 0){
        return 1;
    }

    return 0;

    // return p == (Pilha)NULL;
}