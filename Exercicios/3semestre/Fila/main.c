/*
Teste para a estrutura de Fila.
*/
#include <stdio.h>
#include "fila.h"

int main(int argc, char const *argv[]){
    int posicao, valor;
    Queue *fila = newQueue();

    enqueue(fila, 0);
    enqueue(fila, 1);
    enqueue(fila, 2);
    enqueue(fila, 3);

    searchInQueue(fila, 3, &posicao);
    searchInQueue(fila, 0, &posicao);
    searchInQueue(fila, 10, &posicao);

    getElementInQueue(fila, 2, &valor);
    getElementInQueue(fila, 10, &valor);
    getElementInQueue(fila, posicao, &valor);

    printf("O tamanho da fila é %d\n", getLengthQueue(fila));

    dequeue(fila);
    dequeue(fila);
    dequeue(fila);
    enqueue(fila, 4);
    dequeue(fila);

    printQueue(fila);

    dequeue(fila);
    dequeue(fila);

    deleteQueue(fila);

    return 0;
}