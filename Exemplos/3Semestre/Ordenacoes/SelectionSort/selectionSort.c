/*
    Selection Sort
*/
#include <stdio.h>

void troca(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
Recebe o endereço de um vetor de inteiros, 
e sua quantidade n. Ordena o vetor de forma 
crescente utilizando o algoritmo do 
Selection Sort.
*/
void selectionSort(int v[], int n) {
    int i, j, min, contador = 0;

    for (i = 0; i < n-1; i++) {
        // Acha índice do menor elemento na parte não ordenada
        min = i;
        for (j = i+1; j < n; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }

        // Troca o elemento mínimo com o primeiro elemento não ordenado
        troca(&v[min], &v[i]);
        contador++;
    }

    printf("Trocas realizadas: %d \n", contador);
}