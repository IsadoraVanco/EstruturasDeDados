/**
 * @file insertionSort.c
 * @brief Implementação do Insertion Sort
*/

#include <stdio.h>
#include "insertionSort.h"

void insertionSort(int v[], int n) {
    printf("=> Insertion Sort\n");
    int i, chave, j, contador = 0;

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        // Move os elementos do v[0..i-1] que são maiores que a chave
        // para uma posição à frente de sua posição atual
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;

            contador++;
        }

        v[j + 1] = chave;
    }

    printf("Trocas realizadas: %d \n", contador);
}