/**
 * @brief Heap Máximo
*/
#ifndef _HEAP_MAXIMO_H_
#define _HEAP_MAXIMO_H_

/************************************************************
 * Definições e typedefs
*************************************************************/

typedef struct {
    int *heap;
    int qtdElementos;
}Heap;

/************************************************************
 * Funções Básicas
*************************************************************/

/**
 * @brief Inicializa o Heap, sem espaço para os nós
 * @return O endereço do Heap
 */
Heap *inicializarHeap();

/**
 * @brief Constrói um vetor em Heap
 * @param heap O endereço do Heap
 */
void construirHeap(Heap *heap);

/**
 * @brief Calcula qual o índice do pai do índice
 * @param indice Índice para calcular
 * @return O índice do pai
 */
int pai(int indice);

/**
 * @brief Calcula qual o índice do filho da esquerda do índice
 * @param indice Índice para calcular
 * @return O índice do filho da esquerda
 */
int esquerda(int indice);

/**
 * @brief Calcula qual o índice do filho da direita do índice
 * @param indice Índice para calcular
 * @return O índice do filho da direita
 */
int direita(int indice);

/************************************************************
 * Imprimir
*************************************************************/

/**
 * @brief Imprime todo o heap
 * @param heap O endereço do Heap
 */
void imprimirHeap(Heap *heap);

/************************************************************
 * Buscar
*************************************************************/

/**
 * @brief Busca um valor no Heap
 * @param heap O endereço do Heap
 * @param valor O valor a ser buscado
 * @return O índice do valor encontrado, ou -1 se não encontrar
 */
int buscarValor(Heap *heap, int valor);

/************************************************************
 * Subir e descer nós
*************************************************************/

/**
 * @brief Sobe o nó para a posição correta
 * @param heap O endereço do Heap
 * @param indice O índice do nó para analisar
 */
void subirNos(Heap *heap, int indice);

/**
 * @brief Desce o nó para a posição correta
 * @param heap O endereço do Heap
 * @param indice O índice do nó para analisar
 */
void descerNos(Heap *heap, int indice);

/************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Insere um novo elemento no Heap
 * @param heap O endereço do Heap
 * @param novoValor O valor a ser adicionado
 */
void inserirNo(Heap *heap, int novoValor);

/************************************************************
 * Remoção
*************************************************************/

/**
 * @brief Remove o elemento do topo
 * @param heap O endereço do Heap
 */
void removerNo(Heap *heap);

/**
 * @brief Apaga todo o espaço alocado para o Heap
 * @param heap O endereço do Heap
 */
void destruirHeap(Heap *heap);

#endif