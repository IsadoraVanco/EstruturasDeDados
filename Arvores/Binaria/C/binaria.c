/**
 * @file binaria.c
 * @brief Implementação da Árvore Binária
 * Baseado nos códigos do prof° Gilberto
 * 
*/

#include "binaria.h"
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 * MÉTODOS BÁSICOS
***********************************************************************/

Arvore* criaArvore(){
    Arvore *nova = (Arvore *) malloc(sizeof(Arvore));

    nova->raiz = NULL;
    // nova->quantidadeElementos = 0;
    // nova->altura = 1;

    return nova;
}

Node* criaNo(int valor){
    Node *nova = (Node *) malloc(sizeof(Node));

    nova->info = valor;
    nova->direita = NULL;
    nova->esquerda = NULL;

    return nova;
}

Node* buscarElemento(Node* no, int valor){

    if(no == NULL){
        printf("Valor não encontrado\n");
        return no;
    }else if(no->info == valor){
        return no;
    }

    if(no->info > valor){ 
        return buscarElemento(no->esquerda, valor);
    }else{
        return buscarElemento(no->direita, valor);
    }

}

// Inserção recursiva
Node* inserirElementoRecursivo(Node* no, int valor){

    if(no == NULL){ // Se não achou um nó com o valor que será inserido
        Node* nova = criaNo(valor);

        // printf("elemento criado\n");
        return nova;
    }

    if(no->info > valor){   // Percorre a árvore
        no->esquerda = inserirElementoRecursivo(no->esquerda, valor);
        // printf("esquerda\n");
    }else if(no->info < valor){
        no->direita = inserirElementoRecursivo(no->direita, valor);
        // printf("direita\n");
    }else{
        printf("O valor %d já existe na árvore\n", no->info);
    }

    // printf("%d inserido\n", valor);
    return no;
}

// Inserção utilizando da função recursiva
void inserirElemento(Arvore* raiz, int valor){
    
    raiz->raiz = inserirElementoRecursivo(raiz->raiz, valor);
}

/**********************************************************************
 * PERCURSOS - MOSTRAR ELEMENTOS
***********************************************************************/

void percorrerEmNivel(Arvore* raiz){
/*
Percurso_nivel ( T ) // T é o nó raiz

Esvazia(Fila);
Enfila (T);
Enquanto (Fila não estiver Vazia):

Desenfila (p);
Visita (p);
Enfila (p−>esq);
Enfila (p−>dir);

Fim enquanto;

Fim;
*/
}

void percorrerEmPreordem(Arvore* raiz){
/*
Pre-Ordem ( T )

Esvazia (Pilha);
PUSH (T);
Enquanto(topo != NULO) //pilha não vazia

POP (p); Visita (p);
PUSH (p−>dir);
PUSH (p−>esq);

Fim enquanto;

Fim;
*/
}

void percorrerEmOrdemSimetrica(Arvore* raiz){
/*
Ordem Simétrica ( T )

Esvazia (Pilha); p = T;
Enquanto ((p != NULO) || (topo != NULO))

Enquanto (p != Nulo):

PUSH (p); p = p−>esq;

Fim enquanto;
POP (p); Visita (p);
p = p−>dir;
Fim enquanto;

Fim;
*/
}

void percorrerEmPosOrdem(Arvore* raiz){
/*
Pos−Ordem ( T )

Esvazia Pilha; p = T;
Enquanto ((p != NULO) || (topo != NULO)):

Enquanto (p != Nulo):

PUSH (p, 1); p = p−>esq;

Fim enquanto;
Enquanto ((p == NULO) && (topo != NULO)):

POP (p, vez);
Se ((vez = 1) && (p−>dir != Nulo)) Então

PUSH(p, 2); p = p−>dir;

Senão

Visita (p); p != Nulo;

Fim enquanto;

Fim enquanto;

Fim;
*/
}

/**********************************************************************
 * PERCURSOS RECURSIVOS
***********************************************************************/

void percorrerEmPreordemRecursiva(Node* no){

    if(no != NULL){ // Se for um nó válido
        printf("%d ", no->info);
        percorrerEmPreordemRecursiva(no->esquerda);
        percorrerEmPreordemRecursiva(no->direita);
    }
}

void percorrerEmOrdemSimetricaRecursiva(Node* no){

    if(no != NULL){ // Se for um nó válido
        percorrerEmOrdemSimetricaRecursiva(no->esquerda);
        printf("%d ", no->info);
        percorrerEmOrdemSimetricaRecursiva(no->direita);
    }
}

void percorrerEmPosOrdemRecursiva(Node* no){
    
    if(no != NULL){ // Se for um nó válido
        percorrerEmPosOrdemRecursiva(no->esquerda);
        percorrerEmPosOrdemRecursiva(no->direita);
        printf("%d ", no->info);
    }
}

/**********************************************************************
 * REMOÇÃO DE ELEMENTOS
***********************************************************************/

void removeFolha(Node* no){
    free(no);
}

Node* removeNoUmFilho(Node* no){
    Node* auxiliar;

    if(no->esquerda != NULL){
        auxiliar = no->esquerda;
    }else{
        auxiliar = no->direita;
    }

    free(no);
    return auxiliar;
}

Node* removeNos(Node* no, int valor){

    if(no == NULL){
        printf("O valor %d não foi encontrado na árvore\n", valor);

        return NULL;
    }

    // Se achou o valor desejado
    if(no->info == valor){
        // Nenhum filho
        if(no->esquerda == NULL && no->direita == NULL){
            removeFolha(no);

            return NULL;
        }

        // Dois filhos ou mais
        if(no->esquerda != NULL && no->direita != NULL){
            Node* auxiliar = no->esquerda;

            // Encontra o maior elemento da esquerda
            while(auxiliar->direita != NULL){   
                auxiliar = auxiliar->direita;
            }

            no->info = auxiliar->info;
            auxiliar->info = valor;

            no->esquerda = removeNos(no->esquerda, valor);

            return no;
        }

        // Um filho
        return removeNoUmFilho(no);
    }
    
    // Procura pelo elemento
    if(no->info > valor){
        no->esquerda = removeNos(no->esquerda, valor);
        // printf("vai para esquerda\n");
    }else{
        no->direita = removeNos(no->direita, valor);
        // printf("vai para direita\n");
    }

    return no;
}

void removeElemento(Arvore* raiz, int valor){
    raiz->raiz = removeNos(raiz->raiz, valor);

    if(raiz->raiz != NULL){
        // raiz->quantidadeElementos--;
    }
}

void apagaArvore(Arvore* raiz){

    while(raiz->raiz != NULL){
        raiz->raiz = removeNos(raiz->raiz, raiz->raiz->info);
    }

    free(raiz);
    printf("Árvore apagada\n");
}