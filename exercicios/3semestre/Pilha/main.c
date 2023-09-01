/*
Implemente uma pilha encadeada com as seguintes funçõ es
básicas:
Criar pilha, verificar se a pilha está vazia, push, pop, retornar tamanho da pilha
*/
#include <stdio.h>
#include "pilha.h"

int main(int argc, char const *argv[]){
    Stack *pilha = newStack();
    push(pilha, 0);
    push(pilha, 1);
    push(pilha, 2);

    printf("O tamanho da pilha é %d\n", getLengthStack(pilha));

    pop(pilha);
    pop(pilha);
    pop(pilha);

    pop(pilha);

    deleteStack(pilha);
    
    return 0;
}
