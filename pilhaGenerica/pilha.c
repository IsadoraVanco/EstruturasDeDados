//aqui temos todas as funções que serão usadas para o tipo pilha
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//Novo elemento que será adicionado na pilha
typedef struct item{
  Item info; //informação/conteudo do elemento
  struct item *proximo; //ponteiro para o proximo elemento
}NovoItem;

Pilha create_pilha(){
    printf("pilha criada.\n");
    return NULL; 
    //o primeiro elemento representa o topo da pilha, como ainda não há elementos, então é NULL
}

void push(Pilha *pilha, Item item){ //pq por referencia?
    NovoItem **pointer = (NovoItem**) pilha;
    NovoItem *novo;

    novo = (NovoItem *) malloc(sizeof(NovoItem));
    novo->info = item;
    printf("item adicionado\n");
    novo->proximo = *pointer; //agora o novo aponta para o elemento que estava no topo
    *pointer = novo; //e o topo agora aponta para o novo elemento adicionado
}

Item pop(Pilha *pilha){ //pq por referencia?
    NovoItem **pointer = (NovoItem**) pilha;

    if(!empty(*pointer)){
        Item valor;
        NovoItem *retirar = *pointer;

        valor = (*pointer)->info;
        *pointer = (*pointer)->proximo; //o topo agora apontara para o elemento que estava antes do ultimo
        free(retirar);
        
        printf("item removido\n");
        return valor;
    }else{
        printf("metodo pop() invalido: lista vazia.\n");
    }
}

int empty(Pilha pilha){
    printf("verificando se a pilha esta vazia.\n");
    return pilha == (Pilha) NULL;  //se o topo apontar pra NULL, então a pilha está vazia
}