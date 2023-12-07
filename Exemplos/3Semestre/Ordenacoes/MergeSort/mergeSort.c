/*
    Merge Sort
*/

/*
Recebe o endereço de um vetor de inteiros, 
e sua quantidade n. Ordena o vetor de forma 
crescente utilizando o algoritmo do 
Merge Sort.
*/
void mergeSortRecursivo(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Mesclar/intercalar as metades ordenadas
        merge(arr, left, middle, right);
    }
}

void merge(int v[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    
    // Criação de sub-listas temporárias
    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[esq + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[meio + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}