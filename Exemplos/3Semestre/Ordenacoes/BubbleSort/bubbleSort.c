/*
    Bubble Sort
*/
#include <stdio.h>

/*
Recebe o endereço de um vetor de inteiros, 
e sua quantidade n. Ordena o vetor de forma 
crescente utilizando o algoritmo do 
Bubble Sort.
*/
void bubbleSort(int* v, int n) {
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

/*
Recebe o endereço de um vetor de inteiros, 
e sua quantidade n. Ordena o vetor de forma 
crescente utilizando o algoritmo do 
Bubble Sort de forma otimizada.
*/
void bubbleSortOtimizado(int* v, int n) {
    int i, j, aux, troca;

    for (i = n - 1 ; i > 0; i--) {
        troca = 0;
        for (j = 0; j < fim; j++) {
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