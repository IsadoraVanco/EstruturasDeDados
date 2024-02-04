/**
 * Baseado nos códigos do "Programe seu Futuro"
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvoreAvl.h"

/***************************************************************
 *  BÁSICAS
 ***************************************************************/

No* criaNo(int valor){
    No* novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->altura = 0;
        novo->direita = NULL;
        novo->esquerda = NULL;
    }else{
        printf("Erro ao alocar um espaço para o novo nó\n");
    }

    return novo;
}

int maior(int a, int b){

    return (a > b)? a : b;
}

int alturaNo(No *no){

    return (no == NULL)? -1 : no->altura; 
}

/***************************************************************
 *  ROTAÇÕES
 ***************************************************************/

No* rotacaoEsquerda(No* p){
    No *u, *filho;

    u = p->esquerda;
    filho = u->direita;

    u->direita = p;
    p->esquerda = filho;

    p->altura = maior(alturaNo(p->esquerda), alturaNo(p->direita)) + 1;
    u->altura = maior(alturaNo(u->esquerda), alturaNo(u->direita)) + 1;
    printf("altura %d : %d ; e %d : %d\n", p->valor, p->altura, u->valor, u->altura);

    return u;
}

No* rotacaoDireita(No* p){
    No *u, *filho;

    printf("valor %d\n", p->valor);
    u = p->direita;
    filho = u->esquerda;

    u->esquerda = p;
    p->direita = filho;

    p->altura = maior(alturaNo(p->esquerda), alturaNo(p->direita)) + 1;
    u->altura = maior(alturaNo(u->esquerda), alturaNo(u->direita)) + 1;
    printf("altura %d : %d ; e %d : %d\n", p->valor, p->altura, u->valor, u->altura);

    return u;
}

No* rotacaoDireitaEsquerda(No* p){
    
    p->direita = rotacaoDireita(p->direita);
    return rotacaoEsquerda(p);
}

No* rotacaoEsquerdaDireita(No* p){
    
    p->esquerda = rotacaoEsquerda(p->esquerda);
    return rotacaoDireita(p);
}

/***************************************************************
 *  BALANCEAMENTO
 ***************************************************************/

int fatorBalanceamento(No *no){

    return (no)? alturaNo(no->direita) - alturaNo(no->esquerda) : 0;
}

No* balancear(No* raiz){
    int fatorRaiz = fatorBalanceamento(raiz);
    int fatorSub;

    if(fatorRaiz < -1){ // Rotações Esquerda
        fatorSub = fatorBalanceamento(raiz->esquerda);

        if(fatorSub <= 0){ // Rotação LL
            raiz = rotacaoEsquerda(raiz);
        }else{  // Rotação LR
            raiz = rotacaoEsquerdaDireita(raiz);
        }

    }else if(fatorRaiz > 1){ // Rotações Direita
        fatorSub = fatorBalanceamento(raiz->direita);

        if(fatorSub >= 0){ // Rotação RR
            raiz = rotacaoDireita(raiz);
        }else{  // Rotação RL
            raiz = rotacaoDireitaEsquerda(raiz);
        }
    }

    return raiz;
}

/***************************************************************
 *  INSERÇÃO
 ***************************************************************/

No* inserir(No* raiz, int valor){

    if(raiz == NULL) // árvore vazia
        return criaNo(valor);
    else{ // inserção será à esquerda ou à direita
        if(valor < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        else if(valor > raiz->valor)
            raiz->direita = inserir(raiz->direita, valor);
        else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", valor);
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}   

/***************************************************************
 *  REMOÇÃO
 ***************************************************************/

No* remover(No *raiz, int valor){
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == valor) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", valor);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    printf("Elemento trocado: %d !\n", valor);
                    raiz->esquerda = remover(raiz->esquerda, valor);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", valor);
                    return aux;
                }
            }
        } else {
            if(valor < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, valor);
            else
                raiz->direita = remover(raiz->direita, valor);
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maior(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

/***************************************************************
 *  IMPRESSÃO
 ***************************************************************/

void imprimir(No *raiz, int nivel){

    if(raiz){
        imprimir(raiz->direita, nivel + 1);
        printf("\n\n");

        for(int i = 0; i < nivel; i++){
            printf("\t");
        }

        printf("%d", raiz->valor);
        
        imprimir(raiz->esquerda, nivel + 1);
    }
}