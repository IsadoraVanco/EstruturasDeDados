#include <stdio.h>
#include <stdlib.h>
#include "arvoreAvl.h"


/**********************************
 * Auxiliares
***********************************/

int max(int a, int b){

    return (a > b)? a : b;
}

bool ehAVL(PONT p){
    //percorre a árvore e verifica cada nó
}

/**********************************
 * Funções básicas
***********************************/

void inicializar(PONT *raiz){ // é so isso?
    *raiz = NULL;
}

void inserirAVL(PONT* p, TIPOCHAVE ch, bool* alterou){
    *alterou = false;

    NO *novo = malloc(sizeof(NO));

    if(novo){
        novo->bal = 0;
        novo->chave = ch;
        novo->esq = NULL;
        novo->dir = NULL;
    }else{
        printf("Erro ao alocar espaço para o novo nó\n");
    }

    //busca uma posição e insere
    //verifica se é avl
    // se não, modifica alterou 
    // calcula todos os fatores e balanceia
}

PONT criarNovoNo(TIPOCHAVE ch){
    PONT novo = malloc(sizeof(NO));
    
    if(novo){
        novo->bal = 0;
        novo->chave = ch;
        novo->esq = NULL;
        novo->dir = NULL;
    }else{
        printf("Erro ao alocar espaço para o novo nó\n");
    }

    return novo;
}

int altura(PONT p){

    if(p == NULL){ // Caso base
        return 0;
    }

    // Encontra a altura das outras sub-árvores
    int esquerda = altura(p->esq) + 1;
    int direita = altura(p->dir) + 1;

    return (esq > dir)? esq : dir;
}

int atualizarBalanceamentoTotal(PONT raiz){

    if(raiz == NULL){ // Caso base
        return 0;
    }

    raiz->bal = altura(raiz->dir) - altura(raiz->esq);

    return raiz->bal;
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
        printf("(%d) ", raiz->chave);
        exibirArvorePreOrdem(raiz->dir);
    }
}

void exibirArvore2(PONT raiz, TIPOCHAVE chavePai){
}

/**********************************
 * Rotações
***********************************/

PONT rotacaoL(PONT p){
    PONT u, v;

    u = p->esq;

    if(u->bal == -1){ //Rotação LL
        v = u->esq;

        // Atribui o filho direito de u na esquerda de p
        p->esq = u->dir;
        // Atribui p na direita de u
        u->dir = p;

        // Atualiza fatores de balanceamento
        p->bal = 0;
        u->bal = 0;

        return u;
    }else if(u->bal == 1){  //Rotação LR
        v = u->dir;

        u->dir = v->esq;
        v->esq = u;

        p->esq = v->dir;
        v->dir = p;

        // ???
        if(v->bal == -1){
            p->bal = -1;
        }else{
            p->bal = 0;
        }

        if(v->bal == -1){
            u->bal = -1;
        }else{
            u->bal = 0;
            v->bal = 0;
        }

        return v;
    }
}

PONT rotacaoR(PONT p){
    PONT u, v;

    u = p->dir;

    if(u->bal == 1){ // Rotação RR
        v = u->esq;
        u->esq = p;
        p->dir = v;

        u->bal = 0;
        p->bal = 0;

    }else if(u->bal == -1){ //Rotação RL

    }

    return u;
}

/**********************************
 * Buscas
***********************************/

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){

    // Casos bases 
    if(raiz == NULL){ // Não encontrado
        printf("Elemento (%d) não encontrado\n", ch);
    }else if(raiz->chave == ch){ //Encontrado
        return raiz;
    }

    //Casos recursivos
    if(raiz->chave > ch){
        buscaBinaria(ch, raiz->esq);
    }else if(raiz->chave < ch){
        buscaBinaria(ch, raiz->dir);
    }

}

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){ //retornar o pai?
    PONT auxiliar = raiz;

    while(auxiliar->chave != ch && auxiliar != NULL){
        *pai = auxiliar;

        if(auxiliar->chave > ch){
            auxiliar = auxiliar->esq;
        }else{
            auxiliar = auxiliar->dir;
        }
    }

    return *pai;
}

PONT maiorAEsquerda(PONT p, PONT *ant){ //oq retornar?

}

/**********************************
 * Exclusões
***********************************/

bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou){
}

void destruirAux(PONT subRaiz){
}

void destruirArvore(PONT *raiz){
}
