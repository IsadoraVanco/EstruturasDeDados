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

    if(raiz == NULL){ // Árvore vazia (caso base)
        return criaNo(valor);
    }

    if(valor < raiz->valor){ // Casos recursivos
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }else if(valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }else{
        printf("O valor %d já existe na árvore\n", valor);

        return raiz;
    }

    // Verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    // Recalcula a altura de todos os nós entre a raíz e o novo nó inserido
    raiz->altura = maior(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;

    return raiz;
}   

/***************************************************************
 *  REMOÇÃO
 ***************************************************************/

No* remover(No *raiz, int valor){
    
    //Casos bases
    if(raiz == NULL){ //Valor não encontrado
        printf("Valor %d não encontrado na árvore\n", valor);
        
        return NULL;
    }else if(raiz->valor == valor){ //Valor encontrado

        if(raiz->direita == NULL && raiz->esquerda == NULL){    // Nó folha
            free(raiz);
            printf("Elemento folha (%d) removido da árvore\n", raiz->valor);

            return NULL;
        }else if(raiz->direita != NULL && raiz->esquerda != NULL){ // Nó com 2 filhos
            //Procura o maior da sub-esquerda
            No *auxiliar = raiz->esquerda;

            while(auxiliar->direita != NULL){
                auxiliar = auxiliar->direita;
            }

            //Troca os valores da raíz e valor encontrado
            raiz->valor = auxiliar->valor;

            free(auxiliar);
            //Adiciona o valor a ser removido na posição encontrada
            // auxiliar->valor = valor;

            // raiz->esquerda = remover(raiz->esquerda, valor);
            // raiz->direita = remover(raiz->direita, valor);
            printf("Elemento com dois filhos (%d) removido\n", raiz->valor);
            
            return raiz;
        }else{ // Nó com um filho
            //Procura o lado com filho
            No *auxiliar;
            
            if(raiz->esquerda != NULL){
                auxiliar = raiz->esquerda;
            }else{
                auxiliar = raiz->direita;
            }

            free(raiz);
            printf("Elemento com um filho (%d) retirado\n", raiz->valor);

            return auxiliar;
        }
    }

    //Casos recursivos
    if(raiz->valor > valor){ 
        raiz->esquerda = remover(raiz->esquerda, valor);
    }else if(raiz->valor < valor){
        raiz->direita = remover(raiz->direita, valor);
    }

    // Depois que voltar da recursão
    raiz->altura = maior(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;

    return balancear(raiz);
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