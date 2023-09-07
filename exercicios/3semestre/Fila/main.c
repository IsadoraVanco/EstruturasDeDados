/*
Teste para a estrutura de Fila.
*/
#include <stdio.h>
#include "fila.h"

int main(int argc, char const *argv[]){
    Queue *fila = newQueue();

    enqueue(fila, 0);
    enqueue(fila, 1);
    enqueue(fila, 2);
    enqueue(fila, 3);

    printf("O tamanho da fila é %d\n", getLengthQueue(fila));

    dequeue(fila);
    dequeue(fila);
    dequeue(fila);
    dequeue(fila);

    enqueue(fila, 4);
    dequeue(fila);

    dequeue(fila);

    deleteQueue(fila);

    return 0;
}