/**
 * @file quickSort.h
 * @brief Quick Sort
*/

#ifndef _QUICK_SORT
#define _QUICK_SORT

/**
 * @brief Particiona o vetor recebido
 * @param v Endereço de um vetor de inteiros
 * @param inicio O índice do inicio que vai analisar
 * @param final O índice do final da parte que está analisando
 * @return O indice do ultimo elemento ordenado
*/
int particiona(int *v, int inicio, int final);

/**
 * @brief Ordena um vetor utilizando o Quick Sort
 * de forma recursiva.
 * @param v Endereço de um vetor de inteiros
 * @param inicio O indice do inicio que vai analisar
 * @param fim O indice do ultimo elemento que está ordenando
*/
void quickSortRecursivo(int *v, int inicio, int fim);

#endif