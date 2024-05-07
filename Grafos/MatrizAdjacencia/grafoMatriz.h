/**
 * @brief GrafoMatriz utilizando matriz de adjacência
*/
#ifndef _GRAFO_MATRIZ_ADJACENCIA_H_
#define _GRAFO_MATRIZ_ADJACENCIA_H_

#include <stdbool.h>


/************************************************************
 * Definições e typedefs
*************************************************************/

typedef struct grafo{
    int **matriz;    // Matriz de adjacência
    int numeroVertices;
}GrafoMatriz;

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief Inicializa o grafo
 * @param numeroVertices Número máximo de vértices do grafo
 * @return O endereço do grafo
 */
GrafoMatriz *inicializarGrafoMatriz(int numeroVertices);

/**
 * @brief Mostra o grafo no terminal
 * @param grafo O endereço do grafo
 */
void imprimirGrafoMatriz(GrafoMatriz *grafo);

/**
 * @brief Cria uma imagem .png do grafo
 * @param grafo O endereço do grafo
 * @param variasVersoes Define se serão criadas uma "sequência" de imagens
 */
void criarImagemGrafoMatriz(GrafoMatriz *grafo, bool variasVersoes);

/**
 * @brief Libera da memória o espaço ocupado pelo grafo
 * @param grafo O endereço do grafo
 */
void destruirGrafoMatriz(GrafoMatriz *grafo);

/************************************************************
 * Funções de arestas
*************************************************************/

/**
 * @brief Insere uma aresta do verticeA ao verticeB com determinado peso
 * @param grafo O endereço do grafo
 * @param verticeA O vertice fonte
 * @param verticeB O vértice destino
 * @param peso O peso do caminho
 */
void inserirArestaMatriz(GrafoMatriz *grafo, int verticeA, int verticeB, int peso);

/**
 * @brief Remove uma aresta do grafo
 * @param grafo O endereço do grafo
 * @param verticeA O vértice fonte
 * @param verticeB O vértice destino
 */
void removerArestaMatriz(GrafoMatriz *grafo, int verticeA, int verticeB);

/**
 * @brief Verifica se existe uma aresta entre dois vértices
 * @param grafo O endereço do grafo
 * @param verticeA O endereço fonte
 * @param verticeB O endereço destino
 * @return True caso exista, false para caso contrário
 */
bool verificarArestaMatrizExiste(GrafoMatriz *grafo, int verticeA, int verticeB);

/**
 * @brief Conta quantas arestas existem no grafo
 * @param grafo O endereço do grafo
 * @return O número de arestas
 */
int retornarNumeroArestasMatriz(GrafoMatriz *grafo);

/************************************************************
 * Funções de vértices
*************************************************************/

/**
 * @brief Conta quantos vértices existem no grafo
 * @param grafo O endereço do grafo
 * @return O número de vértices
 */
int retornarNumeroVerticesMatriz(GrafoMatriz *grafo);

/**
 * @brief Verifica se um vértice possui vizinhos
 * @param grafo O endereço do grafo
 * @param vertice O vértice a ser analisado
 * @return True caso exista vizinhos, false para caso contrário
 */
bool verificarVerticePossuiVizinhoMatriz(GrafoMatriz *grafo, int vertice);

/**
 * @brief Conta o grau de um vértice
 * @param grafo O endereço do grafo
 * @param vertice O vértice a ser analisado
 * @return O grau do vértice
 */
int retornarGrauVerticeMatriz(GrafoMatriz *grafo, int vertice);

#endif