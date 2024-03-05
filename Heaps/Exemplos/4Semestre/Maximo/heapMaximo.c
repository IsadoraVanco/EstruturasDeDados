/**
 * @brief Implementação do Heap Máximo
*/

#include <stdio.h>
#include <stdlib.h>
#include "heapMaximo.h"


/************************************************************
 * Funções Básicas
*************************************************************/

Heap *inicializarHeap(){
    Heap *novo = malloc(sizeof(Heap));
    novo->qtdElementos = 0;
    // Inicializa com um elemento nulo
    novo->heap = (int *) calloc(1, sizeof(int));

    return novo;
}

void construirHeap(Heap *heap){ 
    int quantidade = heap->qtdElementos;
    
    // Verifica apenas os nós de dentro
    for(int i = quantidade / 2; i >= 1; i--){
        descerNos(heap, i);
    }
}

int pai(int indice){
    return indice / 2;
}

int esquerda(int indice){
    return indice * 2;
}

int direita(int indice){
    return (indice * 2) + 1;
}

/************************************************************
 * Imprimir
*************************************************************/

void imprimirHeap(Heap *heap){
    
    // Saída bonitinha :)
    if(heap->qtdElementos <= 0){
        printf("=> Não há elementos no Heap!\n");
        return;
    }

    for(int i = 1; i <= heap->qtdElementos; i++){
        printf("[%d]: %d\n", i, heap->heap[i]);
    }
}

/************************************************************
 * Buscar
*************************************************************/

int buscarValor(Heap *heap, int valor){
    for(int i = 1; i <= heap->qtdElementos; i++){
        if(heap->heap[i] == valor){
            printf("-> Valor (%d) encontrado no índice %d\n", valor, i);
            return i;
        }
    }
    
    printf("-> Valor (%d) não encontrado!\n", valor);
    return -1;
}

/************************************************************
 * Subir e descer nós
*************************************************************/

void subirNos(Heap *heap, int indice){ 
    int noPai = pai(indice);

    if(noPai < indice && noPai > 0){
        if(heap->heap[indice] > heap->heap[noPai]){
            // Troca os nós
            printf("-> Nó (%d) sobe e pai (%d) desce\n", heap->heap[indice], heap->heap[noPai]);
            int temp = heap->heap[indice];
            heap->heap[indice] = heap->heap[noPai];
            heap->heap[noPai] = temp;

            subirNos(heap, noPai);
        }
    }

}

void descerNos(Heap *heap, int indice){
    int quantidade = heap->qtdElementos;
    int esq = esquerda(indice);
    int dir = direita(indice);
    int maior = indice;

    // Verifica qual o maior
    if(esq <= quantidade && esq > 0 && heap->heap[esq] > heap->heap[indice]){
        maior = esq;
    }
    if(dir <= quantidade && esq > 0 && heap->heap[dir] > heap->heap[maior]){
        maior = dir;
    }

    // Se achou um maior na esquerda ou direita
    if(maior != indice){
        // Troca os nós
        printf("-> Nó (%d) desce e pai (%d) sobe\n", heap->heap[indice], heap->heap[maior]);
        int temp = heap->heap[indice];
        heap->heap[indice] = heap->heap[maior];
        heap->heap[maior] = temp;

        descerNos(heap, maior);
    }
}

/************************************************************
 * Inserção
*************************************************************/

void inserirNo(Heap *heap, int novoValor){
    // Procura se o elemento já está no Heap
    if(buscarValor(heap, novoValor) > 0){
        printf("-> O valor (%d) já está no Heap\n", novoValor);
        return;
    }

    int quantidade = heap->qtdElementos;

    // Aumenta o tamanho do vetor
    heap->heap = (int *) realloc(heap->heap, sizeof(int) * (quantidade + 2));

    // Insere
    quantidade++;
    heap->heap[quantidade] = novoValor;
    heap->qtdElementos++;

    // Verifica se precisa subir o valor
    subirNos(heap, quantidade);
    printf("-> Valor (%d) adicionado no Heap\n", novoValor);
}

/************************************************************
 * Remoção
*************************************************************/

void removerNo(Heap *heap){
    
    if(heap->qtdElementos <= 0){
        printf("-> Não há elementos no Heap\n");

        return;
    }

    int quantidade = heap->qtdElementos;
    int valor = heap->heap[1];
    
    // Coloca o último elemento no topo
    heap->heap[1] = heap->heap[quantidade];

    // Diminui a quantidade de elementos do total
    heap->heap = (int *) realloc(heap->heap, sizeof(int) * (quantidade + 1));
    heap->qtdElementos--;

    // Desce o valor do topo
    descerNos(heap, 1);
    printf("->Valor (%d) removido do Heap\n", valor);
}

void destruirHeap(Heap *heap){

    free(heap->heap);
    free(heap);
}