//exemplo de ordenação usando a função quicksort da biblioteca C
#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenação ascendente
int compara(const void* a, const void* b) {
    // Converte os ponteiros para o tipo apropriado
    int* elemento1 = (int*)a;
    int* elemento2 = (int*)b;

    // Realiza a comparação
    if (*elemento1 < *elemento2) {
        return -1; //o elemento é menor
        //o elemento2 virá depois do elemento1
    } else if (*elemento1 > *elemento2) {
        return 1; //o elemento é maior 
        //o elemento1 virá depois do elemento2
    } else {
        return 0; //os elementos são iguais
    }
}

int main() {
    int arr[] = { 9, 2, 5, 1, 7, 4, 8, 6, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //utilizando a função qsort() da stdlib.h
    //array, numero de elementos, tamanho em bytes de um elemento e
    // função de comparação para fazer a ordenação
    qsort(arr, size, sizeof(int), compara);

    printf("Array após a ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

