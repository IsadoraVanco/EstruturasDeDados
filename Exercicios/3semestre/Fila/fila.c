/*
Implementações da estrutura de Fila.
*/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Queue *newQueue(){
    Queue *new = (Queue *) malloc(sizeof(Queue));
    
    new->head = NULL;
    new->tail = NULL;
    new->length = 0;

    return new;
}

int isEmptyQueue(Queue *queue){
    return queue->length == 0;
}

int dequeue(Queue *queue){
    if(isEmptyQueue(queue)){
        printf("Não é possível retirar um elemento da fila vazia\n");
        return 0;
    }

    int data = queue->head->data;
    Celula *newHead = queue->head->next;

    free(queue->head);
    queue->head = newHead;
    queue->length--;

    printf("%d\n", data);
    return data;
}

int enqueue(Queue *queue, int data){
    Celula *new = (Celula *) malloc(sizeof(Celula));

    if(!new){
        return 1;
    }

    if(isEmptyQueue(queue)){ //se for o primeiro elemento da fila
        queue->head = new;
    }else{
        Celula *auxiliar = queue->head;

        for(int i = getLengthQueue(queue); i > 1; i--){
            auxiliar = auxiliar->next;
        }

        auxiliar->next = new;
    }

    new->next = NULL;
    new->data = data;

    queue->tail = new;
    queue->length++;

    return 0;
}

int getLengthQueue(Queue *queue){
    return queue->length;
}

int printQueue(Queue *queue){
    if(isEmptyQueue(queue)){
        printf("Fila vazia\n");
        return 1;
    }

    Celula *elemento = queue->head;

    printf("IMPRIMINDO FILA:\n");

    for(int i = 0; i < getLengthQueue(queue); i++){
        printf("[%d] %d \n", i, elemento->data);
    }

    return 0;
}

int searchInQueue(Queue *queue, int data, int *position){
    if(isEmptyQueue(queue)){
        printf("Não é possível procurar um elemento em uma Fila vazia\n");
        return 1;
    }

    Celula *elemento = queue->head;

    for(int i = 0; i < queue->length; i++){
        if(elemento->data == data){
            printf("Elemento %d encontrado na posição [%d]\n", data, i);
            *position = i;
            return 0;
        }
        elemento = elemento->next;
    }

    printf("Elemento %d não encontrado na Fila\n", data);
    return 1;
}

int getElementInQueue(Queue *queue, int position, int *data){
    if(isEmptyQueue(queue)){
        printf("Não é possível procurar uma posição de elemento na Fila vazia\n");
        return 1;
    }else if(position < 0 || position >= queue->length){
        printf("Posição %d não existente\n", position);
        return 1;
    }

    Celula *elemento = queue->head;

    for(int i = 0; i < position; i++){
        elemento = elemento->next;
    }

    *data = elemento->data;
    printf("Elemento %d encontrado na posição [%d]\n", elemento->data, position);

    return 0;
}

void deleteQueue(Queue *queue){
    free(queue);
}