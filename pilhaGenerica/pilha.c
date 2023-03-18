//aqui temos todas as funções que serão usadas para o tipo pilha
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//Estrutura da pilha
typedef struct {
    int size; //indica o tamanho da pilha   
    Item info; //informação/conteudo do elemento
    Stack *data; //ponteiro para o data elemento
} Stack; //a palavra Stack é usada para se referir a uma pilha 

Pilha create_pilha(){
    printf("pilha criada.\n");
    return NULL; 
    //o primeiro elemento representa o topo da pilha, 
    // como ainda não há elementos, então é NULL
}

void push(Pilha *pilha, Item item){ //pq por referencia?
    Stack **pointer = (Stack**) pilha;
    Stack *novo;

    novo = (Stack *) malloc(sizeof(Stack));
    novo->info = item;
    printf("item adicionado\n");
    novo->data = *pointer; //agora o novo aponta para o elemento que estava no topo
    *pointer = novo; //e o topo agora aponta para o novo elemento adicionado
}

Item pop(Pilha *pilha){ //pq por referencia?
    Stack **pointer = (Stack**) pilha;

    if(!empty(*pointer)){
        Item valor;
        Stack *retirar = *pointer;

        valor = (*pointer)->info;
        *pointer = (*pointer)->data; //o topo agora apontara para o elemento que estava antes do ultimo
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