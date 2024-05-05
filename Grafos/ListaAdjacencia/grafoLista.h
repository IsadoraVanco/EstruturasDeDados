/**
 * @brief Grafo utilizando lista de adjacência
*/
#ifndef _GRAFO_LISTA_ADJACENCIA_H_
#define _GRAFO_LISTA_ADJACENCIA_H_

#include <stdbool.h>
#include "Ferramentas/Dot/dot.h"


/************************************************************
 * Definições e typedefs
*************************************************************/

typedef struct aresta{
    int vertice;
    int peso;
    struct aresta *proxima;
}Aresta;

typedef struct grafo{
    Aresta **arestas;    
    int numeroVertices;
    int quantidadeArestas;
}GrafoLista;


/************************************************************
 * Funções básicas
*************************************************************/

// ******** INICIALIZAR *************************************

/**
 * @brief Inicializa o grafo
 * @param numeroVertices Número máximo de vértices do grafo
 * @return O endereço do grafo
 */
GrafoLista *inicializarGrafo(int numeroVertices);

// ******** IMPRIMIR ****************************************

/**
 * @brief Mostra a lista de arestas que saem de determinado vértice
 * @param lista O endereço da lista de arestas de um vértice
 * @param vertice O número identificador do vértice
 */
void imprimirLista(Aresta **lista, int vertice);

/**
 * @brief Mostra o grafo no terminal
 * @param grafo O endereço do grafo
 */
void imprimirGrafo(GrafoLista *grafo);

/**
 * @brief Adiciona uma aresta no arquivo .dot
 * @param arquivo O arquivo .dot
 * @param lista O endereço da lista de arestas de um vértice
 * @param vertice O número identificador de um vértice
 */
void adicionarArestaArquivo(ArquivoDot *arquivo, Aresta **lista, int vertice);

/**
 * @brief Cria uma imagem .png do grafo
 * @param grafo O endereço do grafo
 * @param variasVersoes Define se serão criadas uma "sequência" de imagens
 */
void criarImagemGrafo(GrafoLista *grafo, bool variasVersoes);

// ******** DESTRUIR *****************************************

/**
 * @brief Libera da memória o espaço ocupado pelas arestas de um vértice
 * @param lista O endereço da lista de arestas
 */
void destruirLista(Aresta **lista);

/**
 * @brief Libera da memória o espaço ocupado pelo grafo
 * @param grafo O endereço do grafo
 */
void destruirGrafo(GrafoLista *grafo);

/************************************************************
 * Funções de arestas
*************************************************************/

/**
 * @brief Conta quantas arestas existem no grafo
 * @param grafo O endereço do grafo
 * @return O número de arestas
 */
int retornarNumeroArestas(GrafoLista *grafo);

// ******** BUSCAR *****************************************

/**
 * @brief Busca uma aresta em uma lista de arestas de um vértice
 * @param lista O endereço da lista de arestas
 * @param vertice O número identificador do vértice
 * @return O endereço da aresta caso a encontre, ou NULL caso não a encontre.
 */
Aresta *buscarAresta(Aresta **lista, int vertice);

/**
 * @brief Verifica se existe uma aresta entre dois vértices
 * @param grafo O endereço do grafo
 * @param verticeA O endereço fonte
 * @param verticeB O endereço destino
 * @return True caso exista, false para caso contrário
 */
bool verificarArestaExiste(GrafoLista *grafo, int verticeA, int verticeB);

// ******** INSERIR *****************************************

/**
 * @brief Aloca um espaço para uma aresta na memória
 * @param vertice O número do vértice que será ligado
 * @param peso O peso da ligação entre os vértices
 * @return O endereço da nova aresta
 */
Aresta *criarAresta(int vertice, int peso);

/**
 * @brief Insere uma aresta na lista de arestas
 * @param lista O endereço da lista de arestas de um vértice
 * @param vertice O número identificador de um vértice
 * @param peso O peso da lisgação entre os vértices
 * @return True caso tenha ocorrido tudo certo, false para caso contrário.
 */
bool inserirLista(Aresta **lista, int vertice, int peso);

/**
 * @brief Insere uma aresta do verticeA ao verticeB com determinado peso
 * @param grafo O endereço do grafo
 * @param verticeA O vertice fonte
 * @param verticeB O vértice destino
 * @param peso O peso do caminho
 */
void inserirAresta(GrafoLista *grafo, int verticeA, int verticeB, int peso);

// ******** REMOVER *****************************************

/**
 * @brief Remove uma aresta da lista de arestas
 * @param lista O endereço da lista de arestas de um vértice
 * @param vertice O número identificador de um vértice
 * @return True caso tenha ocorrido tudo certo, false para caso contrário.
 */
bool removerLista(Aresta **lista, int vertice);

/**
 * @brief Remove uma aresta do grafo
 * @param grafo O endereço do grafo
 * @param verticeA O vértice fonte
 * @param verticeB O vértice destino
 */
void removerAresta(GrafoLista *grafo, int verticeA, int verticeB);

/************************************************************
 * Funções de vértices
*************************************************************/

/**
 * @brief Conta quantos vértices existem no grafo
 * @param grafo O endereço do grafo
 * @return O número de vértices
 */
int retornarNumeroVertices(GrafoLista *grafo);

/**
 * @brief Verifica se um vértice possui vizinhos
 * @param grafo O endereço do grafo
 * @param vertice O vértice a ser analisado
 * @return True caso exista vizinhos, false para caso contrário
 */
bool verificarVerticePossuiVizinho(GrafoLista *grafo, int vertice);

/**
 * @brief Conta quantas arestas um vértice possui saindo dele
 * @param lista A lista de arestas do vértice
 * @return A quantidade de arestas da lista
 */
int retornarTamanhoLista(Aresta **lista);

/**
 * @brief Conta o grau de um vértice
 * @param grafo O endereço do grafo
 * @param vertice O vértice a ser analisado
 * @return O grau do vértice
 */
int retornarGrauVertice(GrafoLista *grafo, int vertice);

#endif