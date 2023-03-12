#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char const *argv[]){
    Pilha pilhaExemplo; //representa o topo da pilha
    int valor;

    pilhaExemplo = create_pilha(); //recebe o ponteiro para o primeiro elemento
    push(pilhaExemplo, 100);
    push(pilhaExemplo, 200);
    push(pilhaExemplo, 300);
    push(pilhaExemplo, 400);

    valor = pop(pilhaExemplo);
    valor = pop(pilhaExemplo);
    valor = pop(pilhaExemplo);
    valor = pop(pilhaExemplo);
    valor = pop(pilhaExemplo); //erro?

    free(pilhaExemplo);
    printf("pilha apagada.\n");

    return 0;
}