//aqui temos a criação da pilha e os métodos que serão usados
#include <stdio.h>
#include <stdlib.h>
#include "pilhaInteiro.h"

int main(int argc, char const *argv[]){
    Pilha pilhaExemplo;
    int valor;
    
    pilhaExemplo = create_pilha(5); //tera o tamanho definido
    push(pilhaExemplo, 100);
    push(pilhaExemplo, 200);
    push(pilhaExemplo, 300);
    push(pilhaExemplo, 400);
    push(pilhaExemplo, 500);
    push(pilhaExemplo, 600); //erro?

    valor = pop(pilhaExemplo);
    printf("item retirado: %d\n", valor);
    valor = pop(pilhaExemplo);
    printf("item retirado: %d\n", valor);
    valor = pop(pilhaExemplo);
    printf("item retirado: %d\n", valor);
    valor = pop(pilhaExemplo);
    printf("item retirado: %d\n", valor);
    valor = pop(pilhaExemplo);
    printf("item retirado: %d\n", valor);
    valor = pop(pilhaExemplo); //erro
    printf("item retirado? %d\n", valor);

    free(pilhaExemplo);
    printf("pilha apagada.");
    return 0;
}