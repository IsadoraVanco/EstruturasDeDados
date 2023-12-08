/**
 * @file main.c
 * @brief Teste das ordenações
*/

#include <stdio.h>
#include "BubbleSort/bubbleSort.h"
#include "InsertionSort/insertionSort.h"
#include "MergeSort/mergeSort.h"
#include "QuickSort/quickSort.h"
#include "SelectionSort/selectionSort.h"

void mostraVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("[%d] %d ", i, vetor[i]);
    }
    printf("\n");
}

void preencheVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        vetor[i] = n - i;
    }
}

int main(int argc, char const *argv[]){
    int vetorzinho[10];
    
    preencheVetor(vetorzinho, 10);

    printf("Antes da ordenacao:\n");
    mostraVetor(vetorzinho, 10);

    bubbleSort(vetorzinho, 10);
    mostraVetor(vetorzinho, 10);

    preencheVetor(vetorzinho, 10);
    bubbleSortOtimizado(vetorzinho, 10);
    mostraVetor(vetorzinho, 10);

    preencheVetor(vetorzinho, 10);
    insertionSort(vetorzinho, 10);
    mostraVetor(vetorzinho, 10);

    preencheVetor(vetorzinho, 10);
    printf("=> Merge Sort (recursivo)\n");
    mergeSortRecursivo(vetorzinho, 0, 9);
    mostraVetor(vetorzinho, 10);

    preencheVetor(vetorzinho, 10);
    printf("=> Quick Sort (recursivo)\n");
    quickSortRecursivo(vetorzinho, 0, 9);
    mostraVetor(vetorzinho, 10);

    preencheVetor(vetorzinho, 10);
    selectionSort(vetorzinho, 10);
    mostraVetor(vetorzinho, 10);

    return 0;
}
