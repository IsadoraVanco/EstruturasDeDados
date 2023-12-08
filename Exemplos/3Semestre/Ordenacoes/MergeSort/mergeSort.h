/**
 * @file mergeSort.h
 * @brief Merge Sort
*/

#ifndef _MERGE_SORT
#define _MERGE_SORT

/**
 * @brief Ordena um vetor de inteiros utilizando o Merge Sort de forma recursiva
 * @param arr Endereço de um vetor de inteiros
 * @param left O indice do sub-array da esquerda
 * @param right O indice do sub-array da direita
*/
void mergeSortRecursivo(int arr[], int left, int right);

/**
 * @brief Ordena um vetor de inteiros utilizando o Merge Sort de forma recursiva
 * @param arr Endereço de um vetor de inteiros
 * @param esq O indice do sub-array da esquerda
 * @param meio O indice do sub-array do meio
 * @param dir O indice do sub-array da direita
*/
void merge(int arr[], int esq, int meio, int dir);

#endif