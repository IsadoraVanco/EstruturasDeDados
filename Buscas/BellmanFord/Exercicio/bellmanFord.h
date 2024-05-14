/**
 * @brief Caminho mínimo com Bellman Ford
*/
#ifndef _BELLMAN_FORD_H_
#define _BELLMAN_FORD_H_

#include <stdbool.h>
#include "grafoLista.h"


/************************************************************
 * Definições e typedefs
*************************************************************/

#define NIL -1

typedef struct bellman{
    int *distancias;
    int *pais;
    int numeroVertices;
}GrafoBellmanFord;

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief 
 * @param numeroVertices 
 * @return 
 */
GrafoBellmanFord *criarGrafoBellmanFord(int numeroVertices);

/**
 * @brief 
 * @param grafo 
 * @param origem
 */
void inicializarGrafoBellmanFord(GrafoBellmanFord* grafo, int origem);

/**
 * @brief 
 * @param grafo 
 */
void destruirGrafoBellmanFord(GrafoBellmanFord *grafo);

/**
 * @brief Cria uma imagem .png do grafo
 * @param grafo O endereço do grafo
 * @param variasVersoes Define se serão criadas uma "sequência" de imagens
 */
void criarImagemBellmanFord(GrafoBellmanFord *grafo, bool variasVersoes);

/************************************************************
 * Funções do algoritmo
*************************************************************/

/**
 * @brief 
 * @param grafoLista 
 * @param verticeOrigem 
 * @return 
 */
GrafoBellmanFord *criarBellmanLista(GrafoLista *grafoLista, int verticeOrigem);

#endif