//Testando a Pilha como arranjo
#include <stdio.h>
#include "pilha.h"

int main(int argc, char const *argv[]){
    Pilha *pilha = createStack(3);

    push(pilha, 0);
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);

    pop(pilha);
    pop(pilha);
    pop(pilha);

    pop(pilha);

    deleteStack(pilha);

    return 0;
}