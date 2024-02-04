#include <stdio.h>
#include <stdlib.h>
#include "arvoreAvl.h"

/**********************************
 * Funções básicas
***********************************/

void inicializar(PONT *raiz){
    *raiz = malloc(sizeof(NO));

    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
    (*raiz)->bal = 0;
    (*raiz)->chave = 0;
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

PONT criarNovoNo(TIPOCHAVE ch){
    PONT novoNo = malloc(sizeof(NO));
    
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->bal = 0; // ?

    return novoNo;
}

int altura(PONT p){

}

bool ehAVL(PONT p){
}

void inserirAVL(PONT* pp, TIPOCHAVE ch, bool* alterou){

}

// Atualiza o balancemento total
int atualizarBalanceamentoTotal(PONT raiz){
}

/**********************************
 * Funções de exibição
***********************************/

void exibirArvoreEmOrdem(PONT raiz){
    if(raiz != NULL){ // Se for um nó válido
        exibirArvorePreOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        exibirArvorePreOrdem(raiz->dir);
    }
}

void exibirArvorePreOrdem(PONT raiz){

    if(raiz != NULL){ // Se for um nó válido
        printf("%d ", raiz->chave);
        exibirArvorePreOrdem(raiz->esq);
        exibirArvorePreOrdem(raiz->dir);
    }
}

void exibirArvorePosOrdem(PONT raiz){

    if(raiz != NULL){ // Se for um nó válido
        exibirArvorePreOrdem(raiz->esq);
        exibirArvorePreOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

void exibirArvore(PONT raiz){
    if(raiz != NULL){ // Se for um nó válido
        exibirArvorePreOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        exibirArvorePreOrdem(raiz->dir);
    }
}

void exibirArvore2(PONT raiz, TIPOCHAVE chavePai){
}

/**********************************
 * Rotações
***********************************/

PONT rotacaoL(PONT p);

PONT rotacaoR(PONT p);

/**********************************
 * Buscas
***********************************/

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){

}

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){

}

PONT maiorAEsquerda(PONT p, PONT *ant){
}

/**********************************
 * Exclusões
***********************************/

bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou){
}

void destruirAux(PONT subRaiz){
}

void destruirArvore(PONT * raiz){
}
