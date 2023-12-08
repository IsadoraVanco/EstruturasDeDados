/**
 * @file quickSort.c
 * @brief Implementação do Quick Sort
*/

#include "quickSort.h"

int particiona(int *v, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio];

    while (esq < dir) {

        while (v[esq] <= pivo) esq++;
        while (v[dir] > pivo) dir--;
        
        if (esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }

    v[inicio] = v[dir];
    v[dir] = pivo;
    
    return dir;
}

void quickSortRecursivo(int *v, int inicio, int fim) {
    int pivo;
    if (fim > inicio) {
        // Encontra o índice do elemento que será o pivô
        pivo = particiona(v, inicio, fim);

        // Ordena os elementos antes e depois do pivô
        quickSortRecursivo(v, inicio, pivo - 1);
        quickSortRecursivo(v, pivo + 1, fim);
    }
}