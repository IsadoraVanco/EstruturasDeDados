/**
 * @brief Implementação do grafo com lista de adjacência
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Ferramentas/Diretorios/diretorios.h"
#include "grafoLista.h"

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

// ******** INICIALIZAR *************************************

GrafoLista *inicializarGrafoLista(int numeroVertices){
    GrafoLista *novo = malloc(sizeof(GrafoLista));
    
    novo->numeroVertices = numeroVertices;
    novo->arestas = (Aresta **) malloc(sizeof(Aresta *) * numeroVertices);
    novo->quantidadeArestas = 0;

    for(int i = 0; i < numeroVertices; i++){
       novo->arestas[i] = NULL;
    }

    return novo;
}

// ******** IMPRIMIR ****************************************

void imprimirLista(Aresta **lista, int vertice){
    Aresta *aux = *lista;

    while(aux != NULL){
        printf("(%d) v%d -> v%d\n", aux->peso, vertice, aux->vertice);

        aux = aux->proxima;
    }
}

void imprimirGrafoLista(GrafoLista *grafo){
    int numeroVertices = grafo->numeroVertices;

    for(int i = 0; i < numeroVertices; i++){
        imprimirLista(&(grafo->arestas[i]), i);
    }
}

void adicionarArestaArquivo(ArquivoDot *arquivo, Aresta **lista, int vertice){
    char verticeA[50], peso[50], verticeB[50]; // :)
    sprintf(verticeA, "%d", vertice);
    
    Aresta *aux = *lista;

    while(aux != NULL){
        sprintf(peso, "%d", aux->peso);
        sprintf(verticeB, "%d", aux->vertice);
        
        criarConexaoNodes(arquivo, TIPO_ARVORE, verticeA, verticeB, peso);
        adicionarNovoNode(arquivo, verticeB, verticeB, FORMA_CIRCULO, "black", "#01cda4", "black");
        
        aux = aux->proxima;
    }
}

void criarImagemGrafoLista(GrafoLista *grafo, bool variasVersoes){

    criaPasta("outputs");

    char nome[50];

    if(variasVersoes){
        sprintf(nome, "./outputs/grafoLista-%d", qtdPrints);
    }else{
        sprintf(nome, "./outputs/grafoLista");
    }

    // Cria o arquivo da árvore.dot
    ArquivoDot *grafoArquivo = criarNovoArquivoDot(nome);
    // Grafo direcionado
    inicializarDot(grafoArquivo, TIPO_ARVORE);
    
    // Adiciona as arestas do grafo
    char valor[50]; // :)

    configurarNodes(grafoArquivo, FORMA_CIRCULO, "black", "#eed108", "black", FONTE_SANS, 12);

    // Configura os vértices
    for(int i = 0; i < grafo->numeroVertices; i++){
        sprintf(valor, "%d", i);
        adicionarNovoNode(grafoArquivo, valor, valor, FORMA_CIRCULO, "black", "#eed108", "black");
    }

    // Faz as conexões
    for(int i = 0; i < grafo->numeroVertices; i++){
        adicionarArestaArquivo(grafoArquivo, &(grafo->arestas[i]), i);
    }

    finalizarDot(grafoArquivo);
    criarImagem(nome);

    qtdPrints++;
}

// ******** DESTRUIR *****************************************

void destruirLista(Aresta **lista){
    Aresta *aux = *lista;
    Aresta *prox = *lista;

    while(prox != NULL){
        prox = aux->proxima;
        free(aux);
        aux = prox;
    }
}

void destruirGrafoLista(GrafoLista *grafo){
    for(int i = 0; i < grafo->numeroVertices; i++){
        if(&(grafo->arestas[i]) != NULL){
            destruirLista(&(grafo->arestas[i]));
        }
    }

    free(grafo->arestas);
    free(grafo);
    printf("-> Grafo apagado\n");
}

/************************************************************
 * Funções de arestas
*************************************************************/

int retornarNumeroArestasGrafoLista(GrafoLista *grafo){
    printf("-> Total de arestas: %d\n", grafo->quantidadeArestas);
    return grafo->quantidadeArestas;
}

// ******** BUSCAR *****************************************

Aresta *buscarAresta(Aresta **lista, int vertice){
    Aresta *aux = *lista;

    while(aux != NULL && aux->vertice != vertice){
        aux = aux->proxima;
    }

    if(aux != NULL && aux->vertice == vertice){
        return aux;
    }

    return NULL;
}

bool verificarArestaExisteGrafoLista(GrafoLista *grafo, int verticeA, int verticeB){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return false;
    }

    Aresta *aresta = buscarAresta(&(grafo->arestas[verticeA]), verticeB);
    
    // if(aresta != NULL){
    //     printf("-> O vértice [%d] tem conexão com o vértice [%d]\n", verticeA, verticeB);
    // }else{
    //     printf("-> O vértice [%d] NÃO tem conexão com o vértice [%d]\n", verticeA, verticeB);
    // }

    return aresta;
}

// ******** INSERIR *****************************************

Aresta *criarAresta(int vertice, int peso){
    Aresta *nova = (Aresta *) malloc(sizeof(Aresta));
    
    nova->peso = peso;
    nova->vertice = vertice;
    nova->proxima = NULL;

    return nova;
}

bool inserirLista(Aresta **lista, int vertice, int peso){

    Aresta *nova = criarAresta(vertice, peso);

    // Primeiro item da lista
    if(*lista == NULL){
        *lista = nova;
        
        // printf("Vértice %d inserido no inicio\n", vertice);
        return true;
    }
    
    Aresta *aux = *lista;

    // Insere no fim da lista
    while(aux->proxima != NULL && aux->vertice != vertice){
        aux = aux->proxima;
    }

    // Vertice duplicado
    if(aux->vertice == vertice){
        free(nova);
        printf("-> A aresta já existe e possui peso %d\n", aux->peso);
        return false;
    }

    aux->proxima = nova;

    // printf("Vertice %d inserido no fim\n", vertice);
    return true;
}

void inserirArestaGrafoLista(GrafoLista *grafo, int verticeA, int verticeB, int peso){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!!\n");
        return;
    }else if(peso <= 0){
        printf("!! Peso inválido!!\n");
        return;
    }

    if(inserirLista(&(grafo->arestas[verticeA]), verticeB, peso)){
        grafo->quantidadeArestas++;
        printf("-> Aresta [%d] v%d -> v%d adicionada\n", peso, verticeA, verticeB);
    }
}

// ******** REMOVER *****************************************

bool removerLista(Aresta **lista, int vertice){
    Aresta *anterior = NULL;
    Aresta *aux = *lista;

    //Primeiro nó
    if(aux->vertice == vertice){
        *lista = aux->proxima;
        free(aux); 
        
        printf("-> Vértice [%d] removido\n", vertice);
        return true;
    }

    while(aux != NULL && aux->vertice != vertice){
        anterior = aux;
        aux = aux->proxima;
    }

    if(aux == NULL || aux->vertice != vertice){
        printf("-> Vértice [%d] não possui a conexão!\n", vertice);
        return false;
    }

    anterior->proxima = aux->proxima;
    free(aux);

    printf("-> Vértice [%d] removido\n", vertice);
    return true;
}

void removerArestaGrafoLista(GrafoLista *grafo, int verticeA, int verticeB){
    if(verticeA >= grafo->numeroVertices || verticeA < 0 || verticeB >= grafo->numeroVertices || verticeB < 0){
        printf("!! O(s) vértice(s) não existe(m)!\n");
        return;
    }

    if(grafo->arestas[verticeA] == NULL){
        printf("-> O vértice [%d] não possui arestas com outros vértices\n", verticeA);
        return;
    }

    if(removerLista(&(grafo->arestas[verticeA]), verticeB)){
        grafo->quantidadeArestas--;
    }
}

/************************************************************
 * Funções de vértices
*************************************************************/

int retornarNumeroVerticesGrafoLista(GrafoLista *grafo){
    return grafo->numeroVertices;
}

bool verificarVerticePossuiVizinho(GrafoLista *grafo, int vertice){
    if(vertice >= grafo->numeroVertices || vertice < 0){
        printf("!!O vértice NÃO existe!!\n");
        return false;
    }

    // Chegadas
    for(int i = 0; i < grafo->numeroVertices; i++){     
        if(i != vertice){
            if(verificarArestaExiste(grafo, i, vertice)){
                printf("-> O vértice [%d] possui arestas com outros vértices\n", vertice);
                return true;
            }
        }
    }

    // Saidas 
    if(grafo->arestas[vertice] != NULL){
        printf("-> O vértice [%d] possui arestas com outros vértices\n", vertice);
        return true;
    }

    printf("-> O vértice [%d] NÃO possui arestas com outros vértices\n", vertice);
    return false;
}

int retornarTamanhoLista(Aresta **lista){
    int quantidade = 0;

    if(*lista != NULL){
        Aresta *aux = *lista;

        while(aux != NULL){
            aux = aux->proxima;
            quantidade++;
        }
    }

    return quantidade;
}

int retornarGrauVerticeGrafoLista(GrafoLista *grafo, int vertice){
    if(vertice >= grafo->numeroVertices || vertice < 0){
        printf("!! O vértice não existe!\n");
        return -1;
    }

    int grau = 0;

    // Chegadas
    for(int i = 0; i < grafo->numeroVertices; i++){     
        if(i != vertice){
            if(verificarArestaExiste(grafo, i, vertice)){
                grau++;
            }
        }
    }

    // Saidas 
    grau += retornarTamanhoLista(&(grafo->arestas[vertice]));

    printf("-> O vértice %d possui grau %d\n", vertice, grau); 
    return grau;
}