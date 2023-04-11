#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// estrutura que representa um nó na lista encadeada
typedef struct Node {
    Item data;            // dados armazenados no nó
    struct Node* next;    // ponteiro para o próximo nó na lista
} Node;

// estrutura que representa uma lista encadeada
typedef struct Lista {
    Node* head;    // ponteiro para o primeiro nó na lista
    int size;      // número de elementos na lista
} Lista;

// estrutura que representa um iterador para percorrer a lista
typedef struct Iterador {
    Node* current;    // ponteiro para o nó atual na iteração
    bool reverse;     // indica se a iteração é em ordem reversa
} Iterador;

// cria um novo iterador para percorrer a lista
Iterador createIterador(Lista lista, bool reverse) {
    Iterador iterador;
    iterador.current = reverse ? NULL : lista.head;
    iterador.reverse = reverse;
    return iterador;
}

// verifica se o iterador já percorreu todos os elementos da lista
bool isEmptyIterator(Lista lista, Iterador iterador) {
    if (iterador.reverse) {
        return iterador.current == NULL;
    } else {
        return iterador.current == NULL || iterador.current->next == NULL;
    }
}

// retorna o próximo elemento da lista de acordo com a posição atual do iterador
Item getNextIterator(Lista lista, Iterador iterador) {
    if (iterador.current == NULL) {
        return NULL;
    }
    Item data = iterador.current->data;
    if (iterador.reverse) {
        iterador.current = iterador.current->prev;
    } else {
        iterador.current = iterador.current->next;
    }
    return data;
}

// libera a memória alocada para o iterador
void killIterator(Lista lista, Iterador iterador) {
    free(iterador);
}
 
// ***************************************************

// Aplica a função "funcao" em cada elemento da lista "lista" e retorna uma nova lista com os resultados
Lista map(Lista lista, Apply funcao) {
    Lista nova_lista = criar_lista();
    NoLista* atual = lista.inicio;
    while (atual != NULL) {
        adicionar_item(nova_lista, funcao(atual->item));
        atual = atual->proximo;
    }
    return nova_lista;
}

// Filtra a lista "lista" mantendo apenas os elementos que atendem à condição especificada pela função "funcao"
Lista filter(Lista lista, Check funcao) {
    Lista nova_lista = criar_lista();
    NoLista* atual = lista.inicio;
    while (atual != NULL) {
        if (funcao(atual->item)) {
            adicionar_item(nova_lista, atual->item);
        }
        atual = atual->proximo;
    }
    return nova_lista;
}

// Aplica a função "funcao" em cada elemento da lista "lista" com a clausura especificada por "clausura"
void fold(Lista lista, ApplyClosure funcao, Clausura clausura) {
    NoLista* atual = lista.inicio;
    while (atual != NULL) {
        funcao(atual->item, clausura);
        atual = atual->proximo;
    }
}