/*
Implementações das funções para a estrtura de uma pilha.
*/
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
    new->top = NULL;

    return new;
}

int isEmptyStack(Stack *stack){
    return stack->length == 0;
}

int push(Stack* stack, int data) {
    Celula* nova = (Celula *) malloc(sizeof(Celula));

    nova->data = data;
    // printf("PUSH %c\n", data);
    nova->next = stack->top;

    stack->top = nova;
    stack->length += 1;

    return 0;
}

int pop(Stack* stack) {

    if (isEmptyStack(stack)){
        printf("Não é possível retirar um elemento da pilha vazia.\n");
        return 0; // vazia
    }

    int valor = stack->top->data;
    Celula* topCel = stack->top;

    stack->top = topCel->next;
    stack->length -= 1; // um a menos;
    free(topCel); // adeus celula

    // printf("POP %c\n", valor);
    return valor;
}

int deleteStack(Stack *stack){
    Celula *elemento = stack->top;

    for(int i = 1; i <= stack->length; i++){
        stack->top = elemento->next;
        free(elemento);
        elemento = stack->top;
    }

    free(stack);
}