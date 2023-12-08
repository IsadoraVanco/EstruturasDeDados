/*
    Exemplo de implementação de uma Pilha em C.
    Fonte: ChatGPT
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da pilha genérica
typedef struct {
    void** data; // Array de ponteiros para os elementos da pilha
    int size;    // Tamanho atual da pilha
    int capacity; // Capacidade total da pilha
} Stack;

// Função que inicializa a pilha com capacidade inicial
Stack* stack_init(int capacity) {
    Stack* stack = malloc(sizeof(Stack)); // Aloca memória para a pilha
    stack->data = malloc(capacity * sizeof(void*)); // Aloca memória para os elementos
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

// Função que empilha um elemento na pilha
void stack_push(Stack* stack, void* element) {
    if (stack->size == stack->capacity) { // Verifica se a pilha está cheia
        stack->capacity *= 2; // Dobra a capacidade da pilha
        stack->data = realloc(stack->data, stack->capacity * sizeof(void*)); // Realoca memória para a pilha
    }
    stack->data[stack->size++] = element; // Adiciona o elemento na pilha
}

// Função que desempilha um elemento da pilha
void* stack_pop(Stack* stack) {
    if (stack->size == 0) { // Verifica se a pilha está vazia
        return NULL;
    }
    void* element = stack->data[--stack->size]; // Remove o último elemento da pilha
    if (stack->size <= stack->capacity / 4) { // Verifica se a pilha está menos de 1/4 cheia
        stack->capacity /= 2; // Reduz a capacidade da pilha pela metade
        stack->data = realloc(stack->data, stack->capacity * sizeof(void*)); // Realoca memória para a pilha
    }
    return element;
}

// Função que retorna o elemento no topo da pilha
void* stack_top(Stack* stack) {
    if (stack->size == 0) { // Verifica se a pilha está vazia
        return NULL;
    }
    return stack->data[stack->size - 1]; // Retorna o último elemento da pilha
}

// Função que verifica se a pilha está vazia
int stack_is_empty(Stack* stack) {
    return stack->size == 0;
}

// Função que desaloca a memória utilizada pela pilha
void stack_free(Stack* stack) {
    free(stack->data);
    free(stack);
}

// Exemplo de uso da pilha genérica
int main() {
    Stack* stack = stack_init(10); // Inicializa a pilha com capacidade inicial de 10

    int a = 10;
    float b = 3.14;
    char c = 'c';

    stack_push(stack, &a); // Empilha um inteiro
    stack_push(stack, &b); // Empilha um float
    stack_push(stack, &c); // Empilha um char

    printf("%c\n", *(char*)stack_pop(stack)); // Desempilha e imprime o último elemento (char)
    printf("%f\n", *(float*)stack_pop(stack)); // Desempilha e imprime o último elemento (float)
    printf("%d\n", *(int*)stack_pop(stack));

    stack_push(stack, &a); // Empilha um inteiro novamente

    while (!stack_is_empty(stack)) { // Desempilha e imprime todos os elementos da pilha
        printf("%d ", *(int*)stack_pop(stack));
    }
    printf("\n");

    stack_free(stack); // Desaloca a memória utilizada pela pilha

    return 0;
}