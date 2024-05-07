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

GrafoMatriz *inicializarGrafoMatriz(int numeroVertices){
    GrafoMatriz *novo = malloc(sizeof(GrafoMatriz));
    novo->numeroVertices = numeroVertices;
    novo->matriz = malloc(sizeof(int *) * numeroVertices);

    for(int i = 0; i < numeroVertices; i++){
        novo->matriz[i] = calloc(numeroVertices, sizeof(int));
    }

    return novo;
}

void imprimirGrafoMatriz(GrafoMatriz *grafo){
    int numeroVertices = grafo->numeroVertices;

    for(int i = 0; i < numeroVertices; i++){
        for(int j = 0; j < numeroVertices; j++){
            if(grafo->matriz[i][j] != 0){
                printf("(%d) v%d -> v%d\n", grafo->matriz[i][j], i, j); 
            }
        }
    }
}

void criarImagemGrafoMatriz(GrafoMatriz *grafo, bool variasVersoes){

    criaPasta("outputs");

    char nome[50];

    if(variasVersoes){
        sprintf(nome, "./outputs/grafoMatriz-%d", qtdPrints);
    }else{
        sprintf(nome, "./outputs/grafoMatriz");
    }

    // Cria o arquivo da árvore.dot
    ArquivoDot *grafoArquivo = criarNovoArquivoDot(nome);
    // GrafoMatriz direcionado
    inicializarDot(grafoArquivo, TIPO_ARVORE);
    
    configurarNodes(grafoArquivo, FORMA_CIRCULO, "black", "#eed108", "black", FONTE_SANS, 12);

    // Adiciona as arestas do grafo
    char valor[50]; // :)

    // Configura os vértices
    for(int i = 0; i < grafo->numeroVertices; i++){
        sprintf(valor, "%d", i);
        adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "#eed108", "black");
    }

    // Faz as conexões
    for(int i = 0; i < grafo->numeroVertices; i++){
        char a[50], b[50]; // :)
        for(int j = 0; j < grafo->numeroVertices; j++){
            if(grafo->matriz[i][j] != 0){
                sprintf(valor, "%d", grafo->matriz[i][j]);
                sprintf(a, "%d", i);
                sprintf(b, "%d", j);
                criarConexaoNodes(grafoArquivo, TIPO_ARVORE, a, b, valor);
                adicionarNovoNode(grafoArquivo, b, b, FORMA_CIRCULO, "black", "#01cda4", "black");
            }
        }
    }

    finalizarDot(grafoArquivo);
    criarImagem(nome);

    qtdPrints++;
}

void destruirGrafoMatriz(GrafoMatriz *grafo){
    for(int i = 0; i < grafo->numeroVertices; i++){
        free(grafo->matriz[i]);
    }
    free(grafo->matriz);
    free(grafo);
}

/************************************************************
 * Funções de arestas
*************************************************************/

void inserirArestaMatriz(GrafoMatriz *grafo, int verticeA, int verticeB, int peso){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return;
    }else if(peso <= 0){
        printf("!! Peso inválido\n");
        return;
    }

    grafo->matriz[verticeA][verticeB] = peso;

    printf("-> Aresta [%d] v%d -> v%d adicionada\n", peso, verticeA, verticeB);
}

void removerArestaMatriz(GrafoMatriz *grafo, int verticeA, int verticeB){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return;
    }

    grafo->matriz[verticeA][verticeB] = 0;

    printf("-> Aresta de v%d -> v%d removida\n", verticeA, verticeB);
}

bool verificarArestaMatrizExiste(GrafoMatriz *grafo, int verticeA, int verticeB){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return false;
    }

    return grafo->matriz[verticeA][verticeB] == 0;
}

int retornarNumeroArestasMatriz(GrafoMatriz *grafo){
    int numeroArestas = 0;

    for(int i = 0; i < grafo->numeroVertices; i++){
        for(int j = 0; j < grafo->numeroVertices; j++){
            if(grafo->matriz[i][j] != 0){
                numeroArestas++;
            }
        }
    }

    printf("-> O número de arestas é %d\n", numeroArestas);
    return numeroArestas;
}

/************************************************************
 * Funções de vértices
*************************************************************/

int retornarNumeroVerticesMatriz(GrafoMatriz *grafo){
    return grafo->numeroVertices;
}

bool verificarVerticePossuiVizinhoMatriz(GrafoMatriz *grafo, int vertice){
    if(vertice >= grafo->numeroVertices || vertice < 0){
        printf("!! O vértice não existe!\n");
        return false;
    }

    int vizinhos = 0;

    for(int i = 0; i < grafo->numeroVertices; i++){        
        // Chegadas
        if(grafo->matriz[i][vertice] != 0){
            vizinhos++;
            printf("[%d] v%d -> v%d\n", grafo->matriz[i][vertice], i, vertice);
        }else if(grafo->matriz[vertice][i] != 0){
            // Saídas
            vizinhos++;
            printf("[%d] v%d -> v%d\n", grafo->matriz[vertice][i], vertice, i);
        }
    }

    printf("-> O vértice %d possui %d vizinhos\n", vertice, vizinhos); 

    return vizinhos > 0;
}

int retornarGrauVerticeMatriz(GrafoMatriz *grafo, int vertice){
    if(vertice >= grafo->numeroVertices || vertice < 0){
        printf("!! O vértice não existe!\n");
        return -1;
    }

    int grau = 0;

    for(int i = 0; i < grafo->numeroVertices; i++){        
        // Chegadas
        if(grafo->matriz[i][vertice] != 0){
            grau++;
        }
        // Saídas
        if(grafo->matriz[vertice][i] != 0){
            grau++;
        }
    }

    printf("-> O vértice %d possui grau %d\n", vertice, grau); 
    return grau;
}