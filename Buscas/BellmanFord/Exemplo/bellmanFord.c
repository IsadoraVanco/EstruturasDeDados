/**
 * @brief Implementação do algoritmo de busca de caminho mínimo
 * com Bellman ford
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Ferramentas/Dot/dot.h"
#include "Ferramentas/Diretorios/diretorios.h"
#include "bellmanFord.h"


/*************************************************************
 * Variáveis globais
*************************************************************/

/**
 * Quantidade de imagens do grafo que foram geradas
 * durante a execução do programa
*/
int qtdPrintsBellmanFord = 0;

/************************************************************
 * Funções básicas
*************************************************************/

GrafoBellmanFord *criarGrafoBellmanFord(int numeroVertices){
    GrafoBellmanFord *novo = (GrafoBellmanFord *) malloc(sizeof(GrafoBellmanFord));

    novo->distancias = (int *) calloc(numeroVertices, sizeof(int));
    novo->pais = (int *) calloc(numeroVertices, sizeof(int));
    novo->numeroVertices = numeroVertices;

    return novo;
}

void inicializarGrafoBellmanFord(GrafoBellmanFord* grafo, int origem){
    // Todos começam com a distancia infinita
    for(int i = 0; i < grafo->numeroVertices; i++){
        grafo->distancias[i] = INT_MAX / 2;
        grafo->pais[i] = NIL;
    }

    grafo->distancias[origem] = 0;
}

void destruirGrafoBellmanFord(GrafoBellmanFord *grafo){
    free(grafo->distancias);
    free(grafo->pais);
    free(grafo);
}

void criarImagemBellmanFord(GrafoBellmanFord *grafo, bool variasVersoes){

    criaPasta("outputs");

    char nome[50];

    if(variasVersoes){
        sprintf(nome, "./outputs/grafoBellmanFord-%d", qtdPrintsBellmanFord);
    }else{
        sprintf(nome, "./outputs/grafoBellmanFord");
    }

    // Cria o arquivo da árvore.dot
    ArquivoDot *grafoArquivo = criarNovoArquivoDot(nome);

    // Grafo direcionado
    inicializarDot(grafoArquivo, TIPO_ARVORE);
    configurarNodes(grafoArquivo, FORMA_CIRCULO, "black", "#e6fa35", "black", FONTE_SANS, 12);

    // Adiciona as arestas do grafo
    char valor[50], valorPai[50], distancia[50]; // :)

    // Adiciona os vértices
    for(int i = 0; i < grafo->numeroVertices; i++){
        sprintf(valor, "%d", i);
        adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "#eed108", "black");
    }

    // Faz as conexões
    for(int i = 0; i < grafo->numeroVertices; i++){
        sprintf(valor, "%d", i);

        if(grafo->pais[i] != NIL){
            sprintf(valorPai, "%d", grafo->pais[i]);
            sprintf(distancia, "%d", grafo->distancias[i]);

            adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "#ffa30d", "black");
            adicionarNovoNode(grafoArquivo, valorPai, valorPai, FORMA_CIRCULO, "black", "#ffa30d", "black");
            criarConexaoNodes(grafoArquivo, TIPO_ARVORE, valorPai, valor, distancia);
        }
    }

    finalizarDot(grafoArquivo);
    criarImagem(nome);

    qtdPrintsBellmanFord++;
}

/************************************************************
 * Funções do algoritmo
*************************************************************/

void relaxarVertice(GrafoBellmanFord *grafoBellman, GrafoLista *grafoLista, int verticePai, int verticeFilho){
    Aresta *vizinho = grafoLista->arestas[verticePai];

    // Procura pelo vertice filho
    while(vizinho && vizinho->vertice != verticeFilho){
        vizinho = vizinho->proxima;
    }

    if(vizinho){
        if(grafoBellman->distancias[verticeFilho] > grafoBellman->distancias[verticePai] + vizinho->peso){
            grafoBellman->distancias[verticeFilho] = grafoBellman->distancias[verticePai] + vizinho->peso;
            grafoBellman->pais[verticeFilho] = verticePai;
        }
    }
}

GrafoBellmanFord *criarBellmanLista(GrafoLista *grafoLista, int verticeOrigem){
    
    GrafoBellmanFord *grafoBellman = criarGrafoBellmanFord(grafoLista->numeroVertices);

    inicializarGrafoBellmanFord(grafoBellman, verticeOrigem);

    // Faz o relaxamento das arestas ( n - 1)
    for(int i = 1; i <= grafoLista->numeroVertices - 1; i++){
        // Passa por todos os vértices
        for(int u = 0; u < grafoLista->numeroVertices; u++){
            Aresta *vertice = grafoLista->arestas[u];

            while(vertice){
                relaxarVertice(grafoBellman, grafoLista, u, vertice->vertice);
                vertice = vertice->proxima;
            }
        }
    }

    // Analisa ciclos com pesos negativos
    for(int u = 0; u < grafoLista->numeroVertices; u++) {
        Aresta *vertice = grafoLista->arestas[u];

        while(vertice){
            int distanciaVertice = grafoBellman->distancias[vertice->vertice];
            int distanciaPai = grafoBellman->distancias[u];

            if(distanciaVertice > distanciaPai + vertice->peso){
                printf("-> Ciclo de custo negativo a partir de v%d\n", verticeOrigem);
                destruirGrafoBellmanFord(grafoBellman);
                return NULL;
            }
            vertice = vertice->proxima;
        }
    }

    return grafoBellman;
}
