//Exemplo de Pilha do profº Gilberto
#include <stdio.h>
#include "pilha.h"

int main(int argc, char const *argv[]){
    Pilha *pilha = NEW_PILHA();
    PUSH(0, pilha);
    PUSH(1, pilha);
    PUSH(2, pilha);

    POP(pilha);
    POP(pilha);
    POP(pilha);

    POP(pilha);

    DELETE_PILHA(pilha);
    
    return 0;
}
