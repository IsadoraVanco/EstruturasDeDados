/**
 * @brief Implementação da lista encadeada para a Tabela Hash
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"


/************************************************************
 * Funções básicas
*************************************************************/

Node *criarNode(int valor){
    Node *novo = (Node *) malloc(sizeof(Node));

    if(novo == NULL){
        perror("Erro ao alocar espaço para o nó da Hash");
        exit(EXIT_FAILURE);
    }

    novo->proximo = NULL;
    novo->valor = valor;

    return novo;
}

/************************************************************
 * Inserção
*************************************************************/

void inserirNodeOrdenado(Node **lista, Node *nova){

    // Primeiro item da lista
    if(*lista == NULL){
        *lista = nova;
        printf("Node %d inserido no inicio\n", nova->valor);

        return;
    }
    
    int chave = nova->valor;
    Node *aux = *lista;

    // Insere no inicio
    if(aux->valor > chave){
        *lista = nova;
        nova->proximo = aux;
        printf("Node %d inserido no inicio\n", nova->valor);

        return;
    }

    // Encontra o node que será o anterior
    while(aux->proximo != NULL && chave > aux->proximo->valor){
        aux = aux->proximo;
    }

    nova->proximo = aux->proximo;
    aux->proximo = nova;

    printf("Node %d inserido no meio\n", nova->valor);
}

/************************************************************
 * Buscar
*************************************************************/

Node *buscarNode(Node **lista, int valor){
    Node *aux = *lista;

    while(aux != NULL && aux->valor < valor){
        aux = aux->proximo;
    }

    if(aux != NULL && aux->valor == valor){
        return aux;
    }

    return NULL;
}

/************************************************************
 * Mostrar
*************************************************************/

void mostrarNodes(Node **lista){
    Node *aux = *lista;
    // printf("%d\n", aux->valor);

    while(aux != NULL){
        printf("%d ", aux->valor);

        aux = aux->proximo;
    }

    printf("\n");
}

/************************************************************
 * Remover
*************************************************************/

void removerNode(Node **lista, int valor){
    Node *anterior = NULL;
    Node *aux = *lista;

    if(*lista == NULL){
        printf("Valor (%d) não encontrado!\n", valor);
        
        return;
    }

    //Primeiro nó
    if(aux->valor == valor) {
        *lista = aux->proximo;
        free(aux); 
        printf("Valor (%d) removido do inicio\n", valor);

        return;
    }

    while(aux != NULL && aux->valor < valor){
        anterior = aux;
        aux = aux->proximo;
    }

    if(aux == NULL || aux->valor != valor){
        printf("Valor (%d) não encontrado!\n", valor);
        
        return;
    }

    anterior->proximo = aux->proximo;
    free(aux);

    printf("Valor (%d) removido\n", valor);
}

/************************************************************
 * Destruição
*************************************************************/

void destruirNodes(Node **lista){
    Node *aux = *lista;
    Node *prox = *lista;

    while(prox != NULL){
        prox = aux->proximo;
        free(aux);
        aux = prox;
    }
}