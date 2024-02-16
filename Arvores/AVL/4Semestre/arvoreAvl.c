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

    return (esquerda > direita)? esquerda : direita;
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
    //chavepai deve começar com -1
    if (raiz != NULL) {
        printf("[%d] Balanceamento(%d) Altura(%d)\n", raiz->chave, raiz->bal, altura(raiz));

        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
    }
}

void exibirArvore2(PONT raiz, TIPOCHAVE chavePai){
    //chavepai deve começar com -1
    if (raiz != NULL) {
        if (chavePai == -1) {
            printf("[%d] Balanceamento(%d) Altura(%d) - Raíz\n", raiz->chave, raiz->bal, altura(raiz));
        } else {
            printf("[%d] Balanceamento(%d) Altura(%d) - Pai[%d]\n", raiz->chave, raiz->bal, altura(raiz), chavePai);
        }

        exibirArvore2(raiz->esq, raiz->chave);
        exibirArvore2(raiz->dir, raiz->chave);
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

PONT balancear(PONT *raiz) {
    int fator = (*raiz)->bal;

    if (fator < -1) {
        *raiz = rotacaoL(*raiz);
    } else if (fator > 1) {
        *raiz = rotacaoR(*raiz);
    }

    return *raiz;
}

/**********************************
 * Buscas
***********************************/

PONT buscaBinaria(PONT raiz, TIPOCHAVE ch){

    // Casos bases 
    if(raiz == NULL){ // Não encontrado
        printf("Elemento (%d) não encontrado\n", ch);
        return NULL;
    }else if(raiz->chave == ch){ //Encontrado
        printf("Elemento (%d) encontrado\n", ch);
        return raiz;
    }

    //Casos recursivos
    if(raiz->chave > ch){
        buscaBinaria(raiz->esq, ch);
    }else if(raiz->chave < ch){
        buscaBinaria(raiz->dir, ch);
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
        
    //Caso base
    if(*p == NULL){

        *p = criarNovoNo(ch);
    }else{ 
        if(ch < (*p)->chave){ //Caso recursivo

            inserirAVL(&(*p)->esq, ch, alterou);
        }else if(ch > (*p)->chave){

            inserirAVL(&(*p)->dir, ch, alterou);
        }else{ // Valor já existe na árvore
            printf("Elemento %d já inserido na árvore!\n", ch);
            *alterou = false;

            return;
        }

        // Atualiza o fator de balanceamento do nó raíz
        (*p)->bal = altura((*p)->dir) - altura((*p)->esq);

        // Verifica se não é AVL para balancear
        if(!ehAVL(*p)){
            *p = balancear(p);
            *alterou = true;
        }

        // Não rotacionou
        *alterou = false;
    }
}

/**********************************
 * Exclusões
***********************************/

bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou){
    
    if (*raiz == NULL) {
        printf("Valor %d não encontrado na árvore\n", ch);

        *alterou = false; // Valor não encontrado
        return false;
    }

    if (ch < (*raiz)->chave) {
        if (excluirAVL(&(*raiz)->esq, ch, alterou)) {
            // Subárvore esquerda foi alterada
            (*raiz)->bal = altura((*raiz)->dir) - altura((*raiz)->esq);
            *raiz = balancear(raiz);
            return true;
        }
    } else if (ch > (*raiz)->chave) {
        if (excluirAVL(&(*raiz)->dir, ch, alterou)) {
            // Subárvore direita foi alterada
            (*raiz)->bal = altura((*raiz)->dir) - altura((*raiz)->esq);
            *raiz = balancear(raiz);
            return true;
        }
    } else {
        // Nó a ser removido encontrado
        PONT temp;

        if ((*raiz)->esq == NULL) {
            // Nó com no máximo 1 filho à direita ou sem filhos
            temp = *raiz;
            *raiz = (*raiz)->dir;
            free(temp);
            *alterou = true;
            return true;
        } else if ((*raiz)->dir == NULL) {
            // Nó com no máximo 1 filho à esquerda
            temp = *raiz;
            *raiz = (*raiz)->esq;
            free(temp);
            *alterou = true;
            return true;
        } else {
            // Nó com dois filhos
            PONT suc = (*raiz)->dir;

            while (suc->esq != NULL) {
                suc = suc->esq;
            }

            (*raiz)->chave = suc->chave;
            excluirAVL(&(*raiz)->dir, suc->chave, alterou);
            (*raiz)->bal = altura((*raiz)->dir) - altura((*raiz)->esq);
            *raiz = balancear(raiz);
            return true;
        }
    }

    return false; // Nó não encontrado nesta subárvore
}

void destruirAux(PONT subRaiz){

    //Casos bases
    if(subRaiz == NULL){ // não é nó
        return;
    }else if(subRaiz->esq == NULL && subRaiz->dir == NULL){ // nó folha
        // printf("Elemento follha %d removido\n", subRaiz->chave);
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

    // printf("Elemento %d removido\n", subRaiz->chave);
    free(subRaiz);
}

void destruirArvore(PONT *raiz){

    // Se a árvore foi inicializada
    if(*raiz != NULL){
        destruirAux((*raiz)->esq);
        destruirAux((*raiz)->dir);
        free(*raiz);
        *raiz = NULL;
    }
}
