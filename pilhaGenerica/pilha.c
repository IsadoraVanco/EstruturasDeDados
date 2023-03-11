//aqui temos todas as funções que serão usadas para o tipo pilha
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//Novo elemento que será adicionado na pilha
typedef struct {
  Item info; //informação/conteudo do elemento
  NovoItem *proximo; //ponteiro para o proximo elemento
}NovoItem;

Pilha create_pilha(){
    // NovoItem *pointer;
    
    // pointer = (NovoItem*) malloc(sizeof(NovoItem));
    // pointer->proximo = NULL;

    // return pointer; //retorna o ponteiro para a nova pilha

    return NULL; //não preciso do primeiro ponteiro? (coisa do Evandro)
}

void push(Pilha pilha, Item item){ //pq por referencia? (tirei)
    NovoItem *pointer = (NovoItem**) pilha;
    NovoItem *novo;

    novo = (NovoItem *) malloc(sizeof(NovoItem));
    novo->info = item;
    novo->proximo = NULL;

    //percorrer até o ultimo elemento 
    while(pointer->proximo != NULL){
        pointer = pointer->proximo;
    }
    
    //adiciona elemento no final
    pointer->proximo = novo; 

    //coisa do Evandro...
    // sNoItem **tp = (sNoItem **)p;
    // sNoItem *novo;

    // novo = (sNoItem *) malloc(sizeof(sNoItem));
    // novo->info = i;
    // novo->prox = *tp;
    // *tp = novo;
}

Item pop(Pilha pilha){ //pq por referencia? (tirei)
    NovoItem *retirar = (NovoItem*) pilha;

    if(!empty(retirar)){
        NovoItem *pointer;
        Item valor;

        //percorrer até o ultimo elemento 
        while(retirar->proximo != NULL){
            pointer = retirar; 
            retirar = retirar->proximo;
        }

        //retira o ultimo elemento 
        pointer->proximo = NULL; //retira a conexão com o ultimo elemento
        valor = retirar->info;
        free(retirar);
        return valor;
        
    }else{
        printf("pilha vazia.\n");
    }
}

int empty(Pilha pilha){
    NovoItem *pointer = (NovoItem*) pilha;

    return pointer->proximo == NULL; //se não tiver o proximo  
    // return pilha == (Pilha) NULL;  //coisa do Evandro ??
}