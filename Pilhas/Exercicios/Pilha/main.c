/*
Um teste para a estrutura de pilha.
*/
#include <stdio.h>
#include "pilha.h"

int main(int argc, char const *argv[]){
    int posicao, valor = 0;
    Stack *pilha = newStack();
    
    push(pilha, 0);
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);

    printf("O tamanho da pilha é %d\n", getLengthStack(pilha));
    
    searchInStack(pilha, 1, &posicao);
    searchInStack(pilha, 3, &posicao);
    searchInStack(pilha, 0, &posicao);
    searchInStack(pilha, 10, &posicao);

    getElementInStack(pilha, posicao, &valor);
    getElementInStack(pilha, 10, &valor);
    
    printStack(pilha);

    pop(pilha);
    pop(pilha);
    pop(pilha);
    pop(pilha);

    pop(pilha);

    deleteStack(pilha);
    
    return 0;
}
