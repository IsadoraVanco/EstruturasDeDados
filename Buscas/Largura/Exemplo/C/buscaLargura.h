/**
 * @brief Busca em largura
*/
#ifndef _BUSCA_LARGURA_H_
#define _BUSCA_LARGURA_H_

#include <stdbool.h>
#include "grafoLista.h"


/************************************************************
 * Definições e typedefs
*************************************************************/

#define BRANCO 0
#define CINZA 1
#define PRETO 2

#define NIL -1

typedef struct busca{
    int *distancias;
    int *cores;
    int *pais;
    int numeroVertices;
}GrafoBusca;

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief 
 * @param numeroVertices 
 * @return 
 */
GrafoBusca *criarGrafoBusca(int numeroVertices);

/**
 * @brief 
 * @param grafo 
 */
void inicializarGrafoBusca(GrafoBusca* grafo);

/**
 * @brief 
 * @param grafo 
 */
void destruirGrafoBusca(GrafoBusca *grafo);

/**
 * @brief Cria uma imagem .png do grafo
 * @param grafo O endereço do grafo
 * @param variasVersoes Define se serão criadas uma "sequência" de imagens
 */
void criarImagemGrafoBusca(GrafoBusca *grafo, bool variasVersoes);

/************************************************************
 * Funções do algoritmo
*************************************************************/

/**
 * @brief 
 * @param verticeOrigem 
 * @param numVertices 
 * @param matrizAdjacencia 
 * @return 
 */
GrafoBusca *criarSubGrafoMatriz(int verticeOrigem, int numVertices, int matrizAdjacencia[][numVertices]);

/**
 * @brief 
 * @param verticeOrigem 
 * @param numVertices 
 * @param lista 
 * @return 
 */
GrafoBusca *criarSubGrafoLista(int verticeOrigem, int numVertices, Aresta **lista);

/**
 * @brief 
 * @param verticeOrigem 
 * @param verticeChegada 
 * @param numVertices 
 * @param lista 
 * @return 
 */
int contarCaminhoMinimoLista(int verticeOrigem, int verticeChegada, int numVertices, Aresta **lista);
  
#endif