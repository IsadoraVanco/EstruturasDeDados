/**
 * @brief Implementação da lista encadeada para a Tabela Hash
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeada.h"


/************************************************************
 * Funções básicas
*************************************************************/

Node *criarNode(int ID, char *descricao, double preco){
    Node *novo = (Node *) malloc(sizeof(Node));

    if(novo == NULL){
        perror("Erro ao alocar espaço para o nó da Hash");
        exit(EXIT_FAILURE);
    }

    novo->proximo = NULL;
    novo->id = ID;
    strcpy(novo->descricao, descricao);
    novo->preco = preco;

    return novo;
}

/************************************************************
 * Inserção
*************************************************************/

void inserirNodeOrdenado(Node **lista, Node *nova){

    // Primeiro item da lista
    if(*lista == NULL){
        *lista = nova;
        // printf("Node %d inserido no inicio\n", nova->id);

        return;
    }
    
    int chave = nova->id;
    Node *aux = *lista;

    // Insere no inicio
    if(aux->id > chave){
        *lista = nova;
        nova->proximo = aux;
        // printf("Node %d inserido no inicio\n", nova->id);

        return;
    }

    // Encontra o node que será o anterior
    while(aux->proximo != NULL && chave > aux->proximo->id){
        aux = aux->proximo;
    }

    nova->proximo = aux->proximo;
    aux->proximo = nova;

    // printf("Node %d inserido no meio\n", nova->id);
}

/************************************************************
 * Buscar
*************************************************************/

Node *buscarNode(Node **lista, int id){
    Node *aux = *lista;

    while(aux != NULL && aux->id < id){
        aux = aux->proximo;
    }

    if(aux != NULL && aux->id == id){
        return aux;
    }

    return NULL;
}

/************************************************************
 * Mostrar
*************************************************************/

void mostrarNode(Node *elemento){
    printf("\tID: %d\n", elemento->id);
    printf("\tDescrição: %s\n", elemento->descricao);
    printf("\tPreço: %.2lf\n", elemento->preco);
}

void mostrarNodes(Node **lista){
    Node *aux = *lista;

    while(aux != NULL){
        mostrarNode(aux);
        aux = aux->proximo;
    }
}

/************************************************************
 * Remover
*************************************************************/

void removerNode(Node **lista, int id){
    Node *anterior = NULL;
    Node *aux = *lista;

    if(*lista == NULL){
        printf("-> ID (%d) não encontrado!\n", id);
        
        return;
    }

    //Primeiro nó
    if(aux->id == id) {
        *lista = aux->proximo;
        free(aux); 
        printf("-> ID (%d) removido\n", id);

        return;
    }

    while(aux != NULL && aux->id < id){
        anterior = aux;
        aux = aux->proximo;
    }

    if(aux == NULL || aux->id != id){
        printf("-> ID (%d) não encontrado!\n", id);
        
        return;
    }

    anterior->proximo = aux->proximo;
    free(aux);

    printf("-> ID (%d) removido\n", id);
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