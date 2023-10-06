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
    nova->next = stack->top;

    stack->top = nova;
    stack->length++;

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
    stack->length--;
    free(topCel);

    printf("%d\n", valor);
    return valor;
}

int getLengthStack(Stack *stack){
    return stack->length;
}

int searchInStack(Stack *stack, int data, int *position){
    if(isEmptyStack(stack)){
        printf("Não é possível procurar um elemento em uma Pilha vazia\n");
        return 1;
    }

    Celula *elemento = stack->top;

    for(int i = 0; i < stack->length; i++){
        if(elemento->data == data){
            printf("Elemento %d encontrado na posição [%d] a partir do topo\n", data, i);
            *position = i;
            return 0;
        }
        elemento = elemento->next;
    }

    printf("Elemento %d não encontrado na Pilha\n", data);
    return 1;
}

int getElementInStack(Stack *stack, int position, int *data){
    if(isEmptyStack(stack)){
        printf("Não é possível procurar uma posição de elemento na Pilha vazia\n");
        return 1;
    }else if(position < 0 || position >= stack->length){
        printf("Posição %d não existente\n", position);
        return 1;
    }

    Celula *elemento = stack->top;

    for(int i = 0; i < position; i++){
        elemento = elemento->next;
    }

    *data = elemento->data;
    printf("Elemento %d encontrado na posição [%d] a partir do topo\n", *data, position);

    return 0;
}

int printStack(Stack *stack){
    if(isEmptyStack(stack)){
        printf("Não é possível imprimir uma Pilha vazia\n");
        return 1;
    }

    Celula *elemento = stack->top;

    printf("IMPRIMINDO PILHA:\n");
    for(int i = 0; i < getLengthStack(stack); i++){
        printf("[%d] %d\n", i, elemento->data);
        elemento = elemento->next;
    }

    return 0;
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