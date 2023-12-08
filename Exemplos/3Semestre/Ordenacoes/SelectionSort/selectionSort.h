/**
 * @file selectionSort.h
 * @brief Selection Sort
*/

#ifndef _SELECTION_SORT
#define _SELECTION_SORT

/**
 * @brief Troca os valores de x para y
 * @param xp Endereço de um elemento inteiro
 * @param yp Endereço de um elemento inteiro
*/
void troca(int *xp, int *yp);

/**
 * @brief Ordena um vetor de inteiros utilizando o Selection Sort
 * @param v Endereço de um vetor de inteiros
 * @param n O número de elementos do vetor
*/
void selectionSort(int v[], int n);

#endif