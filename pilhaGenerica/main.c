#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char const *argv[]){
    Pilha pilhaExemplo; //representa o topo da pilha
    int valor;

    printf("\n ****** INICIANDO TESTE ******\n");

    pilhaExemplo = create_pilha(); //recebe o ponteiro para o primeiro elemento
    valor = pop(&pilhaExemplo); //erro?
    push(&pilhaExemplo, 100);
    push(&pilhaExemplo, 200);
    push(&pilhaExemplo, 300);
    push(&pilhaExemplo, 400);

    valor = pop(&pilhaExemplo);
    printf("item %d ...\n", valor);
    valor = pop(&pilhaExemplo);
    printf("item %d ...\n", valor);
    valor = pop(&pilhaExemplo);
    printf("item %d ...\n", valor);
    valor = pop(&pilhaExemplo);
    printf("item %d ...\n", valor);
    valor = pop(&pilhaExemplo); //erro?
    printf("item %d ...\n", valor);

    free(pilhaExemplo);
    printf("pilha apagada.\n");

    return 0;
}