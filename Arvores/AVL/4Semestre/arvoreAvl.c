#include <stdio.h>
#include <stdlib.h>
#include "arvoreAvl.h"


/**********************************
 * Auxiliares
***********************************/

int max(int a, int b){

    return (a > b)? a : b;
}

/**********************************
 * Funções básicas
***********************************/

void inicializar(PONT *raiz){
    *raiz = NULL;
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

bool ehAVL(PONT p){

    if(p->bal > 1 || p->bal < -1){
        return false;
    }else{
        return true;
    }
}

/**********************************
 * Exibição
***********************************/

void exibirArvoreEmOrdem(PONT raiz){

    if(raiz != NULL){
        exibirArvorePreOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        exibirArvorePreOrdem(raiz->dir);
    }
}

void exibirArvorePreOrdem(PONT raiz){

    if(raiz != NULL){ 
        printf("%d ", raiz->chave);
        exibirArvorePreOrdem(raiz->esq);
        exibirArvorePreOrdem(raiz->dir);
    }
}

void exibirArvorePosOrdem(PONT raiz){

    if(raiz != NULL){ 
        exibirArvorePreOrdem(raiz->esq);
        exibirArvorePreOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

void exibirArvore(PONT raiz){

    if(raiz != NULL){
        printf("(");
        exibirArvorePreOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        exibirArvorePreOrdem(raiz->dir);
        printf(")");
    }
}

void exibirArvore2(PONT raiz, TIPOCHAVE chavePai){
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

/**********************************
 * Rotações
***********************************/

PONT rotacaoL(PONT p){
    PONT u = p->esq;

    if(u->bal == -1){ //Rotação LL

        // Atribui o filho direito de u na esquerda de p
        p->esq = u->dir;
        // Atribui p na direita de u
        u->dir = p;

        // Atualiza fatores de balanceamento
        p->bal = 0;
        u->bal = 0;

        return u;
    }
    
    if(u->bal == 1){  //Rotação LR
        PONT v = u->dir;

        // Atribui os filhos menores de v nos maiores de u
        u->dir = v->esq;
        // Atribui u nos menores de v
        v->esq = u;
        // Os maiores de v agora são os menores de p
        p->esq = v->dir;
        // Atribui p nos maiores de v
        v->dir = p;

        //Atualiza os balanceamentos
        if(v->bal == -1){
            p->bal = -1;
        }else{
            p->bal = 0;
        }

        if(v->bal == 1){
            u->bal = -1;
        }else{
            u->bal = 0;
        }

        v->bal = 0;
        
        return v;
    }
}

PONT rotacaoR(PONT p){
    PONT u = p->dir;

    if(u->bal == 1){ //Rotação RR

        // Atribui o filho esquerdo de u na direita de p
        p->dir = u->esq;
        // Atribui p na esquerda de u
        u->esq = p;

        // Atualiza fatores de balanceamento
        p->bal = 0;
        u->bal = 0;

        return u;
    }
    
    if(u->bal == -1){  //Rotação RL
        PONT v = u->esq;

        // Atribui os filhos maiores de v nos menores de u
        u->esq = v->dir;
        // Atribui u nos maiores de v
        v->dir = u;
        // Os menores de v agora são os maiores de p
        p->dir = v->esq;
        // Atribui p nos menores de v
        v->esq = p;

        //Atualiza os balanceamentos
        if(v->bal == 1){
            p->bal = 1;
        }else{
            p->bal = 0;
        }

        if(v->bal == -1){
            u->bal = 1;
        }else{
            u->bal = 0;
        }

        v->bal = 0;
        
        return v;
    }
}

/**********************************
 * Balanceamento
***********************************/

int atualizarBalanceamentoTotal(PONT raiz){

    if(raiz->esq == NULL && raiz->dir == NULL){ // Caso base (nó folha)
        raiz->bal = 0;
        return 0;
    }

    // Calcula a altura das sub-árvores 
    int subEsq = altura(raiz->esq);
    int subDir = altura(raiz->dir);

    raiz->bal = subDir - subEsq;

    //Caso recursivo
    atualizarBalanceamentoTotal(raiz->esq);
    atualizarBalanceamentoTotal(raiz->dir);

    return raiz->bal;
}

/**********************************
 * Buscas
***********************************/

PONT buscaBinaria(PONT raiz, TIPOCHAVE ch){

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

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
    PONT auxiliar = raiz;
    *pai = NULL;

    while(auxiliar->chave != ch && auxiliar != NULL){
        *pai = auxiliar;

        //Busca pela chave
        if(auxiliar->chave > ch){
            auxiliar = auxiliar->esq;
        }else{
            auxiliar = auxiliar->dir;
        }
    }

    if(auxiliar->chave == ch){
        return *pai;
    }

    printf("Valor (%d) não encontrado na árvore", ch);

    return NULL;
}

PONT maiorAEsquerda(PONT p, PONT *ant){

    if(p->dir != NULL){
        *ant = p;

        return maiorAEsquerda(p->dir, ant);
    }

    return p;
}

/**********************************
 * Inserção
***********************************/

PONT criarNovoNo(TIPOCHAVE ch){
    PONT novo = malloc(sizeof(NO));
    
    if(novo){
        novo->bal = 0;
        novo->chave = ch;
        novo->esq = NULL;
        novo->dir = NULL;
    }else{
        printf("Erro ao alocar espaço para o novo nó\n");
        exit(EXIT_FAILURE); // Tratamento de erro 
    }

    return novo;
}

void inserirAVL(PONT* p, TIPOCHAVE ch, bool* alterou){
    *alterou = false;

    PONT atual;

    //Verifica se há um nó com o valor de inserção
    if(buscaNo(*p, ch, &atual) != NULL){
        printf("Elemento %d já inserido na árvore\n", ch);
        return;
    }

    // Se não, cria um novo nó
    PONT novo = criarNovoNo(ch);

    // Busca uma posição para inserir
    while(atual != NULL && atual->chave){

        if(atual->chave > ch){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }

    //atualiza o fator de balanceamento dos itens
    //verifica se é avl
    // se não, modifica alterou => rotacionou a arvore
}

/**********************************
 * Exclusões
***********************************/

bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou){


    // utilizar o maioresquerda para procurar o elemento

    //atualiza o fator de balanceamento dos itens
    //verifica se é avl
    // se não, modifica alterou => rotacionou a arvore
}

void destruirAux(PONT subRaiz){

    if(subRaiz->esq == NULL && subRaiz->dir == NULL){ //Caso base (nó folha)
        free(subRaiz);
        return;
    }
    
    // Casos recursivos
    if(subRaiz->esq != NULL && subRaiz->dir != NULL){ //Nó com 2 filhos 
        destruirAux(subRaiz->esq);
        destruirAux(subRaiz->dir);
    }else{  // Nó com um filho
        if(subRaiz->esq != NULL){
            destruirAux(subRaiz->esq);
        }else{
            destruirAux(subRaiz->dir);
        }
    }

    free(subRaiz);
}

void destruirArvore(PONT *raiz){

    destruirAux((*raiz)->esq);
    destruirAux((*raiz)->dir);

    *raiz = NULL;
}
