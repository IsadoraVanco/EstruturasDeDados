/**
 * @brief Implementação do grafo com matriz de adjacência
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Ferramentas/Dot/dot.h"
#include "Ferramentas/Diretorios/diretorios.h"
#include "grafoMatriz.h"

/*************************************************************
 * Variáveis globais
*************************************************************/

/**
 * Quantidade de imagens do grafo que foram geradas
 * durante a execução do programa
*/
int qtdPrints = 0;

/************************************************************
 * Funções básicas
*************************************************************/

Grafo *inicializarGrafo(int numeroVertices){
    Grafo *novo = malloc(sizeof(Grafo));
    novo->numeroVertices = numeroVertices;
    novo->matriz = malloc(sizeof(int) * numeroVertices * numeroVertices);

    int *relacao = novo->matriz;
    for(int i = 0; i < numeroVertices; i++){
        for(int j = 0; j < numeroVertices; j++){
            *relacao = 0;
            relacao++;
        }
    }

    return novo;
}

void imprimirGrafo(Grafo *grafo){
    int numeroVertices = grafo->numeroVertices;
    int *relacao = grafo->matriz;

    for(int i = 0; i < numeroVertices; i++){
        for(int j = 0; j < numeroVertices; j++){
            if(*relacao != 0){
                printf("(%d) v%d -> v%d\n", *relacao, i, j);
            }
            relacao++;
        }
    }
}

void criarImagemGrafo(Grafo *grafo, bool variasVersoes){

    criaPasta("outputs");

    char nome[50];

    if(variasVersoes){
        sprintf(nome, "./outputs/grafo-%d", qtdPrints);
    }else{
        sprintf(nome, "./outputs/grafo");
    }

    // Cria o arquivo da árvore.dot
    ARQUIVODOT *grafoArquivo = criarNovoArquivoDot(nome);
    // Grafo direcionado
    inicializarDot(grafoArquivo, TIPO_ARVORE);
    
    // Adiciona as arestas do grafo
    char valor[50]; // :)
    int *relacao = grafo->matriz;

    configurarNodes(grafoArquivo, FORMA_CIRCULO, "black", "#eed108", "black", FONTE_SANS, 12);

    // Configura os vértices
    for(int i = 0; i < grafo->numeroVertices; i++){
        sprintf(valor, "%d", i);
        adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "#eed108", "black");
        relacao++;
    }

    relacao = grafo->matriz;

    // Faz as conexões
    for(int i = 0; i < grafo->numeroVertices; i++){
        char a[50], b[50]; // :)
        for(int j = 0; j < grafo->numeroVertices; j++){
            if(*relacao != 0){
                sprintf(valor, "%d", *relacao);
                sprintf(a, "%d", i);
                sprintf(b, "%d", j);
                criarConexaoNodes(grafoArquivo, TIPO_ARVORE, a, b, valor);
                adicionarNovoNode(grafoArquivo, b, b, FORMA_CIRCULO, "black", "#01cda4", "black");
            }
            relacao++;
        }
    }

    finalizarDot(grafoArquivo);
    criarImagem(nome);

    qtdPrints++;
}

void destruirGrafo(Grafo *grafo){
    free(grafo->matriz);
    free(grafo);
}

/************************************************************
 * Funções de arestas
*************************************************************/

void inserirAresta(Grafo *grafo, int verticeA, int verticeB, int peso){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return;
    }else if(peso <= 0){
        printf("!! Peso inválido\n");
        return;
    }

    int *relacao = grafo->matriz + (grafo->numeroVertices * verticeA) + verticeB;
    *relacao = peso;

    printf("-> Aresta [%d] v%d -> v%d adicionada\n", peso, verticeA, verticeB);
}

void removerAresta(Grafo *grafo, int verticeA, int verticeB){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return;
    }

    int *relacao = grafo->matriz + (grafo->numeroVertices * verticeA) + verticeB;
    *relacao = 0;
    printf("-> Aresta de v%d -> v%d removida\n", verticeA, verticeB);
}

bool verificarArestaExiste(Grafo *grafo, int verticeA, int verticeB){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return false;
    }

    int *relacao = grafo->matriz + (grafo->numeroVertices * verticeA) + verticeB;
    
    return *relacao == 0;
}

int retornarNumeroArestas(Grafo *grafo){
    int *relacao = grafo->matriz;
    int numeroArestas = 0;

    for(int i = 0; i < grafo->numeroVertices; i++){
        for(int j = 0; j < grafo->numeroVertices; j++){
            if(*relacao != 0){
                numeroArestas++;
            }
            relacao++;
        }
    }

    printf("-> O número de arestas é %d\n", numeroArestas);
    return numeroArestas;
}

/************************************************************
 * Funções de vértices
*************************************************************/

int retornarNumeroVertices(Grafo *grafo){
    return grafo->numeroVertices;
}

bool verificarVerticePossuiVizinho(Grafo *grafo, int vertice){
    if(vertice >= grafo->numeroVertices || vertice < 0){
        printf("!! O vértice não existe!\n");
        return false;
    }

    int *relacao = grafo->matriz;
    int vizinhos = 0;

    // Chegadas
    for(int i = 0; i < grafo->numeroVertices; i++){
        relacao += vertice;
        
        if(*relacao != 0){
            vizinhos++;
            printf("[%d] v%d -> v%d\n", *relacao, i, vertice);
        }
    }

    relacao = grafo->matriz + (grafo->numeroVertices * vertice);

    // Saidas 
    for(int i = 0; i < grafo->numeroVertices; i++){
        if(*relacao != 0 && i != vertice){
            vizinhos++;
            printf("[%d] v%d -> v%d\n", *relacao, vertice, i);
        }

        relacao++;
    }

    printf("-> O vértice %d possui %d vizinhos\n", vertice, vizinhos); 

    return vizinhos != 0;
}

int retornarGrauVertice(Grafo *grafo, int vertice){
    if(vertice >= grafo->numeroVertices || vertice < 0){
        printf("!! O vértice não existe!\n");
        return -1;
    }

    int *relacao = grafo->matriz;
    int grau = 0;

    // Chegadas
    for(int i = 0; i < grafo->numeroVertices; i++){
        relacao += vertice;
        
        if(*relacao != 0){
            grau++;
        }
    }

    relacao = grafo->matriz + (grafo->numeroVertices * vertice);

    // Saidas 
    for(int i = 0; i < grafo->numeroVertices; i++){
        if(*relacao != 0 && i != vertice){
            grau++;
        }

        relacao++;
    }

    printf("-> O vértice %d possui grau %d\n", vertice, grau); 
    return grau;
}