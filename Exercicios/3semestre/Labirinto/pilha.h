/*
    Módulos com todas as funções para manipulação de 
    uma Estrutura de Pilha
*/
#ifndef PILHA_H
#define PILHA_H

#include "labirinto.h"

//******************** DEFINIÇÕES ********************

/*
Celula representa cada elemento que está na Pilha.
*/
typedef struct cel{
    Ponto coordenadas; //As coordenadas do ponto no mapa
    struct cel* next;
} Celula;

/*
Pilha representa as informações de uma determinada estrtura de Pilha.
*/
typedef struct{
    Celula* top;
    int length;
} Stack;

//******************** FUNÇÕES ********************

/*
Cria uma estrutura de Pilha e retorna o seu ponteiro.
*/
Stack* newStack();

/*
Retorna 1 se a Pilha estiver vazia, 0 caso contrário.
*/
int isEmptyStack(Stack *Stack);

/*
Adiciona o valor no topo da Pilha, caso tenha espaço.
Retorna 0 se teve sucesso, e 1, caso contrário.
*/
int push(Stack* Stack, Ponto *ponto);

/*
Retira o último elemento da Pilha e o retorna.
*/
int pop(Stack* Stack);

/*
Retorna o tamanho da Pilha.
*/
int getLengthStack(Stack *Stack);

/*
Procura na Pilha uma informação, copia a posição (a 
partir do topo) em 'position' caso a ache na estrutura 
e retorna 0, se não, retorna 1.
*/
int searchInStack(Stack *stack, int tipoCaminho, int *position);

/*
Copia a informação que está na posição indicada da Pilha em 'data'.
Caso não haja a posição indicada (a partir do topo), retorna 1, 
se a operação foi concluída com sucesso, retorna 0.
*/
int getElementInStack(Stack *stack, int position, int *data);

/*
Imprime os elementos da Pilha. Caso a estrutura esteja vazia,
retorna 1, se o processo for concluído com sucesso, retorna 0.
*/
int printStack(Stack *stack);

/*
Apaga a estrutura da Pilha da memória e todas as células.
*/
int deleteStack(Stack *Stack);

#endif