/**
 * @brief Implementação do algoritmo de busca em largura de um grafo
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Ferramentas/Dot/dot.h"
#include "Ferramentas/Diretorios/diretorios.h"
#include "buscaLargura.h"


/*************************************************************
 * Variáveis globais
*************************************************************/

/**
 * Quantidade de imagens do grafo que foram geradas
 * durante a execução do programa
*/
int qtdPrintsBusca = 0;

/************************************************************
 * Funções básicas
*************************************************************/

GrafoBusca *criarGrafoBusca(int numeroVertices){
    GrafoBusca *novo = (GrafoBusca *) malloc(sizeof(GrafoBusca));

    novo->cores = (int *) calloc(numeroVertices, sizeof(int));
    novo->distancias = (int *) calloc(numeroVertices, sizeof(int));
    novo->pais = (int *) calloc(numeroVertices, sizeof(int));
    novo->numeroVertices = numeroVertices;

    return novo;
}

void inicializarGrafoBusca(GrafoBusca* grafo){
    // Todos começam com a cor branca e distancia infinita
    for(int i = 0; i < grafo->numeroVertices; i++){
        grafo->cores[i] = BRANCO;
        grafo->distancias[i] = INT_MAX / 2;
        grafo->pais[i] = NIL;
    }
}

void destruirGrafoBusca(GrafoBusca *grafo){
    free(grafo->cores);
    free(grafo->distancias);
    free(grafo->pais);
    free(grafo);
}

void criarImagemGrafoBusca(GrafoBusca *grafo, bool variasVersoes){

    criaPasta("outputs");

    char nome[50];

    if(variasVersoes){
        sprintf(nome, "./outputs/grafoBusca-%d", qtdPrintsBusca);
    }else{
        sprintf(nome, "./outputs/grafoBusca");
    }

    // Cria o arquivo da árvore.dot
    ArquivoDot *grafoArquivo = criarNovoArquivoDot(nome);
    // Grafo direcionado
    inicializarDot(grafoArquivo, TIPO_ARVORE);
    
    configurarNodes(grafoArquivo, FORMA_CIRCULO, "black", "white", "black", FONTE_SANS, 12);

    // Adiciona as arestas do grafo
    char valor[50], valorPai[50], distancia[50]; // :)

    // Faz as conexões
    for(int i = 0; i < grafo->numeroVertices; i++){
        sprintf(valor, "%d", i);

        if(grafo->cores[i] == BRANCO){
            adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "white", "black");
        }else if(grafo->cores[i] == CINZA){
            adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "gray", "black");
        }else if(grafo->cores[i] == PRETO){
            adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "black", "white");
        }
        
        if(grafo->pais[i] != NIL){
            sprintf(valorPai, "%d", grafo->pais[i]);
            sprintf(distancia, "%d", grafo->distancias[i]);
            criarConexaoNodes(grafoArquivo, TIPO_ARVORE, valorPai, valor, distancia);
        }
    }

    finalizarDot(grafoArquivo);
    criarImagem(nome);

    qtdPrintsBusca++;
}

/************************************************************
 * Funções do algoritmo
*************************************************************/

GrafoBusca *criarSubGrafoMatriz(int verticeOrigem, int numVertices, int matrizAdjacencia[][numVertices]){
    
    GrafoBusca *grafo = criarGrafoBusca(numVertices);

    inicializarGrafoBusca(grafo);

    // Modifica o vértice de origem, marcando que já foi visitado
    grafo->cores[verticeOrigem] = CINZA;
    grafo->distancias[verticeOrigem] = 0;

    // Fila para sequência de análise
    int fila[numVertices];
    int primeiroFila = 0;       // Primeira posição da fila
    int ultimoFila = -1;        // Última posição da fila

    // Enfileira o vértice de origem
    fila[++ultimoFila] = verticeOrigem;

    // Enquanto a fila não estiver vazia
    while(primeiroFila <= ultimoFila){
        // Desenfileira um vértice
        int vertice = fila[primeiroFila++];

        // Percorre os vértices adjacentes ao vertice
        for(int i = 0; i < numVertices; i++){

            // Existe uma aresta entre os vertices
            if(matrizAdjacencia[vertice][i] > 0){

                // Se é branco, não foi descoberto
                if(grafo->cores[i] == BRANCO){
                    grafo->cores[i] = CINZA;
                    grafo->distancias[i] = grafo->distancias[vertice] + 1;
                    grafo->pais[i] = vertice;

                    // Enfileira o nó adjacente
                    fila[++ultimoFila] = i;
                }      
            }
        }

        grafo->cores[vertice] = PRETO;
    }

    return grafo;
}

GrafoBusca *criarSubGrafoLista(int verticeOrigem, int numVertices, Aresta **lista){
    
    GrafoBusca *grafo = criarGrafoBusca(numVertices);

    inicializarGrafoBusca(grafo);

    // Modifica o vértice de origem, marcando que já foi visitado
    grafo->cores[verticeOrigem] = CINZA;
    grafo->distancias[verticeOrigem] = 0;

    // Fila para sequência de análise
    int fila[numVertices];
    int primeiroFila = 0;       // Primeira posição da fila
    int ultimoFila = -1;        // Última posição da fila

    // Enfileira o vértice de origem
    fila[++ultimoFila] = verticeOrigem;

    // Enquanto a fila não estiver vazia
    while(primeiroFila <= ultimoFila){
        // Desenfileira um vértice
        int vertice = fila[primeiroFila++];
        Aresta *adjacente = lista[vertice];

        // Percorre os vértices adjacentes ao vertice
        while(adjacente){

            // Se é branco, não foi descoberto
            if(grafo->cores[adjacente->vertice] == BRANCO){
                grafo->cores[adjacente->vertice] = CINZA;
                grafo->distancias[adjacente->vertice] = grafo->distancias[vertice] + 1;
                grafo->pais[adjacente->vertice] = vertice;

                // Enfileira o nó adjacente
                fila[++ultimoFila] = adjacente->vertice;
            } 

            adjacente = adjacente->proxima;
        }

        grafo->cores[vertice] = PRETO;
    }

    return grafo;
}

int contarCaminhoMinimoLista(int verticeOrigem, int verticeChegada, int numVertices, Aresta **lista){
    
    int distancia = -1;

    GrafoBusca *grafo = criarGrafoBusca(numVertices);
    inicializarGrafoBusca(grafo);

    // Modifica o vértice de origem, marcando que já foi visitado
    grafo->cores[verticeOrigem] = CINZA;
    grafo->distancias[verticeOrigem] = 0;

    // Fila para sequência de análise
    int fila[numVertices];
    int primeiroFila = 0;       // Primeira posição da fila
    int ultimoFila = -1;        // Última posição da fila

    // Enfileira o vértice de origem
    fila[++ultimoFila] = verticeOrigem;

    // Enquanto a fila não estiver vazia
    while(primeiroFila <= ultimoFila){
        // Desenfileira um vértice
        int vertice = fila[primeiroFila++];
        Aresta *adjacente = lista[vertice];

        // Percorre os vértices adjacentes ao vertice
        while(adjacente){

            // Encontrou o ponto de chegada
            if(adjacente->vertice == verticeChegada){
                distancia = grafo->distancias[vertice] + 1;
                break;
            }

            // Se é branco, não foi descoberto
            if(grafo->cores[adjacente->vertice] == BRANCO){
                grafo->cores[adjacente->vertice] = CINZA;
                grafo->distancias[adjacente->vertice] = grafo->distancias[vertice] + 1;
                grafo->pais[adjacente->vertice] = vertice;

                // Enfileira o nó adjacente
                fila[++ultimoFila] = adjacente->vertice;
            } 

            adjacente = adjacente->proxima;
        }

        grafo->cores[vertice] = PRETO;
    }

    destruirGrafoBusca(grafo);

    if(distancia >= 0){
        printf("-> Caminho mínimo entre v%d -> v%d é %d\n", verticeOrigem, verticeChegada, distancia);
    }else{
        printf("-> Não existe caminho disponível entre os vértice v%d -> v%d\n", verticeOrigem, verticeChegada);
    }

    return distancia;
}