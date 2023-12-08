/**
 * @file bubbleSort.c
 * @brief Bubble Sort implementado
*/

#include <stdio.h>
#include "bubbleSort.h"

void bubbleSort(int* v, int n) {
    printf("=> Bubble Sort\n");

    int i, j, aux, contador = 0;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                contador++;
            }
        }
    }

    printf("Trocas realizadas: %d \n", contador);
}

void bubbleSortOtimizado(int* v, int n) {
    printf("=> Bubble Sort (otimizado)\n");

    int i, j, aux, troca;

    for (i = n - 1 ; i > 0; i--) {
        troca = 0;
        for (j = 0; j < n; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca++;
            }
        }
        if (troca == 0) break;
    }

    printf("Trocas realizadas: %d \n", troca);
}