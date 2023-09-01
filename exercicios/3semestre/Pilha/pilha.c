#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Stack* newStack(){
    Stack* new = (Stack *) malloc(sizeof(Stack));

    if(!new){
        printf("Erro ao alocar espaço para a pilha.\n");
        return NULL;
    }

    new->length = 0;
    new->head = NULL;

    return new;
}

int isEmptyStack(Stack *stack){
    return stack->length == 0;
}

int push(Stack* stack, int data) {
    Celula* nova = (Celula *) malloc(sizeof(Celula));

    nova->data = data;
    nova->next = stack->head;

    stack->head = nova;
    stack->length += 1;

    return 0;
}

int pop(Stack* stack) {

    if (isEmptyStack(stack)){
        printf("Não é possível retirar um elemento da pilha vazia.\n");
        return 0; // vazia
    }

    int valor = stack->head->data;
    Celula* headCel = stack->head;

    stack->head = headCel->next;
    stack->length -= 1; // um a menos;
    free(headCel); // adeus celula

    printf("%d\n", valor);
    return valor;
}

int getLengthStack(Stack *stack){
    return stack->length;
}

int deleteStack(Stack *stack){
    free(stack);
}