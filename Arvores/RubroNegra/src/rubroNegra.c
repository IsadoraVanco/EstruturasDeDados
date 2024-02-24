/**
 * @brief Implementação da Árvore Rubro Negra
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Ferramentas/Diretorios/diretorios.h"
#include "../../Ferramentas/Dot/dot.h"
#include "rubroNegra.h"


/*************************************************************
 * Variáveis globais
*************************************************************/

/*
    Conta quantas imagens da árvore foram geradas 
    durante a execução do programa
*/
int qtdPrints = 0;

/*************************************************************
 * Auxiliares
*************************************************************/

int max(int a, int b){

    return (a > b)? a : b;
}

/************************************************************
 * Funções básicas
*************************************************************/

ArvoreRubroNegra *inicializarArvore(){
    ArvoreRubroNegra *nova = malloc(sizeof(ArvoreRubroNegra));

    nova->raiz = NULL;
    nova->quantidadeElementos = 0;

    return nova;
}

int altura(Node *no){

    if(no == NULL){ // Caso base
        return 0;
    }

    // Encontra a altura das outras sub-árvores
    int esquerda = altura(no->esquerda) + 1;
    int direita = altura(no->direita) + 1;

    return max(esquerda, direita);
}

/**********************************
 * Exibição
***********************************/

void exibirArvore(Node *no){
    char cor[10];

    if (no != NULL) {
        if(no->cor == vermelho){
            sprintf(cor, "Vermelho");
        }else{
            sprintf(cor, "Preto");
        }

        if(no->pai == NULL){
            printf("[%d] Cor(%s) Altura(%d) - Raíz\n", no->chave, cor, altura(no));
        } else {
            printf("[%d] Cor(%s) Altura(%d) - Pai[%d]\n", no->chave, cor, altura(no), no->pai->chave);
        }

        exibirArvore(no->esquerda);
        exibirArvore(no->direita);
    }
}

void criarImagemArvore(ArvoreRubroNegra *arvore){

    if(criaPasta("outputs")){
        printf("Ou pasta já criada\n");
    }

    char nome[50];
    sprintf(nome, "./outputs/arvoreRubro-%d", qtdPrints);

    // Cria o arquivo da árvore.dot
    ARQUIVODOT *arvoreArquivo = criarNovoArquivo(nome);
    inicializar(arvoreArquivo, TIPO_ARVORE);

    configurarNodes(arvoreArquivo, FORMA_CIRCULO, "red", "red", "black", FONTE_SANS, 12);

    // Adiciona a raíz
    char valor[50]; // :)
    sprintf(valor, "%d", arvore->raiz->chave);
    
    if(arvore->raiz->cor == vermelho){
        adicionarNovoNode(arvoreArquivo, valor, valor, "", "#b81e1e", "#d02222", "black");
    }else{
        adicionarNovoNode(arvoreArquivo, valor, valor, "", "#333232", "#3f3f3f", "white");
    }

    // Adiciona recursivamente os outros nós
    adicionarNodeArquivo(arvoreArquivo, arvore->raiz->esquerda);
    adicionarNodeArquivo(arvoreArquivo, arvore->raiz->direita);

    finalizar(arvoreArquivo);
    criarImagem(nome);

    qtdPrints++;
}

void adicionarNodeArquivo(ARQUIVODOT *arquivo, Node *no){
    
    if (no != NULL) {
        char valorPai[50], valorFilho[50]; // :)
        sprintf(valorPai, "%d", no->pai->chave);
        sprintf(valorFilho, "%d", no->chave);

        if(no->cor == vermelho){
            adicionarNovoNode(arquivo, valorFilho, valorFilho, "", "#b81e1e", "#d02222", "black");
        }else{
            adicionarNovoNode(arquivo, valorFilho, valorFilho, "", "#333232", "#3f3f3f", "white");
        }

        criarConexaoNodes(arquivo, TIPO_ARVORE, valorPai, valorFilho, "");

        adicionarNodeArquivo(arquivo, no->esquerda);
        adicionarNodeArquivo(arquivo, no->direita);
    }
}

/**********************************
 * Buscas
***********************************/

Node *buscaBinaria(Node *raiz, TIPO_CHAVE chave){

    // Casos bases 
    if(raiz == NULL){ // Não encontrado
        printf("Elemento (%d) não encontrado\n", chave);
        return NULL;
    }else if(raiz->chave == chave){ //Encontrado
        printf("Elemento (%d) encontrado\n", chave);
        return raiz;
    }

    //Casos recursivos
    if(raiz->chave > chave){
        buscaBinaria(raiz->esquerda, chave);
    }else if(raiz->chave < chave){
        buscaBinaria(raiz->direita, chave);
    }

}

/**********************************
 * Rotações
***********************************/

// Utilizando o algoritmo do livro do Thomas Cormen
void rotacaoEsquerda(ArvoreRubroNegra *arvore, Node *x){
    Node *y = x->direita;   // Define y

    x->direita = y->esquerda;   // Transforma a subárvore à esquerda

    if(y->esquerda != NULL){    // Se y possui um filho à esquerda
        y->esquerda->pai = x;
    }

    y->pai = x->pai;            // Liga o pai de x a y

    if(x->pai == NULL){
        arvore->raiz = y;
    }else if(x == x->pai->esquerda){
        x->pai->esquerda = y;
    }else{
        x->pai->direita = y;
    }

    y->esquerda = x;        // Coloca x à esquerda de y
    x->pai = y;
}

// Utilizando o algoritmo do livro do Thomas Cormen
void rotacaoDireita(ArvoreRubroNegra *arvore, Node *x){
    Node *y = x->esquerda;   // Define y

    x->esquerda = y->direita;   // Transforma a subárvore à esquerda

    if(y->direita != NULL){    // Se y possui um filho à esquerda
        y->direita->pai = x;
    }

    y->pai = x->pai;            // Liga o pai de x a y

    if(x->pai == NULL){
        arvore->raiz = y;
    }else if(x == x->pai->direita){
        x->pai->direita = y;
    }else{
        x->pai->esquerda = y;
    }

    y->direita = x;        // Coloca x à esquerda de y
    x->pai = y;
}

/*************************************************************
 * Correções
*************************************************************/

void arrumaInsercao(ArvoreRubroNegra *arvore, Node *novo){
    Node *pai, *avo;

    // Enquanto o pai do nó a ser modificado (não é a raíz) e é vermelho
    while(novo != arvore->raiz && novo->pai->cor == vermelho){
        printf("Arruma nó %d...\n", novo->chave);
        pai = novo->pai;
        // printf("Pai %d\n", pai->chave);
        avo = novo->pai->pai;
        // printf("Avo %d\n", avo->chave);

        // se o pai do nó é filho da esquerda
        if(avo->esquerda == pai){   
            correcaoEsquerda(arvore, &novo, pai, avo);
        }else{  // se o pai do nó é filho da direita
            correcaoDireita(arvore, &novo, pai, avo);
        }

        printf("Proximo verificar: %d\n", novo->chave);
    }

    arvore->raiz->cor = preto;  // Caso 0
}

void correcaoEsquerda(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo){
    // O tio à direita do nó
    Node *tio = avo->direita;

    // Se o tio é folha nula
    if(tio == NULL){
        if(pai->direita == *no){   // Caso 2 
            printf("=> Caso 2 (esquerda):\n");
            printf("\t1.Nó é da direita\n");
            printf("\t2.Seu pai é rubro da esquerda\n");
            printf("\t3.O tio é negro\n");

            rotacaoEsquerda(arvore, pai);
            // rotacaoDireita(arvore, pai);

            (*no) = (*no)->esquerda;          // Desce a verificação em 1 nível e cai no caso 3
        }else{                          // Caso 3 
            printf("=> Caso 3 (esquerda):\n");
            printf("\t1.Nó é da esquerda\n");
            printf("\t2.Seu pai é rubro da esquerda\n");
            printf("\t3.O tio é negro\n");

            pai->cor = preto;
            avo->cor = vermelho;

            rotacaoDireita(arvore, avo);
            // rotacaoEsquerda(arvore, pai);
        }
    }else if(tio->cor == vermelho){       // Caso 1
        printf("=> Caso 1 (esquerda):\n");
        printf("\t1.Nó é da esquerda ou direita\n");
        printf("\t2.Seu pai é rubro da esquerda\n");
        printf("\t3.O tio é rubro\n");

        pai->cor = preto;
        avo->cor = vermelho;
        tio->cor = preto;

        *no = (*no)->pai->pai;
        printf("av %d\n", (*no)->chave);                   // Sobe a verificação em 2 níveis
        printf("avv %d\n", avo->chave);                   // Sobe a verificação em 2 níveis
    }
}

void correcaoDireita(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo){
    // O tio à esquerda do nó
    Node *tio = avo->esquerda;

    // Se o tio é folha nula
    if(tio == NULL || tio->cor == preto){
        if(pai->esquerda == *no){  // Caso 2
            printf("=> Caso 2 (direita):\n");
            printf("\t1.Nó é da esquerda\n");
            printf("\t2.Seu pai é rubro da direita\n");
            printf("\t3.O tio é negro\n");

            rotacaoDireita(arvore, pai);
            // rotacaoEsquerda(arvore, pai);

            (*no) = (*no)->direita;           // Desce a verificação em 1 nível e cai no caso 3
        }else{                          // Caso 3
            printf("=> Caso 3 (direita):\n");
            printf("\t1.Nó é da direita\n");
            printf("\t2.Seu pai é rubro da direita\n");
            printf("\t3.O tio é negro\n");

            pai->cor = preto;
            avo->cor = vermelho;

            rotacaoEsquerda(arvore, avo);
            // rotacaoDireita(arvore, pai);
        }
    }else if(tio->cor == vermelho){       // Caso 1
        printf("=> Caso 1 (direita):\n");
        printf("\t1.Nó é da esquerda ou direita\n");
        printf("\t2.Seu pai é rubro da direita\n");
        printf("\t3.O tio é rubro\n");

        pai->cor = preto;
        avo->cor = vermelho;
        tio->cor = preto;

        *no = (*no)->pai->pai;                   // Sobe a verificação em 2 níveis
    
        printf("av %d\n", (*no)->chave);                   // Sobe a verificação em 2 níveis
        printf("avv %d\n", avo->chave);
    }
}

/**********************************
 * Inserção
***********************************/

Node *criarNovoNo(TIPO_CHAVE chave){
    Node *novo = calloc(1, sizeof(Node));
    
    if(novo){
        novo->chave = chave;
        novo->cor = vermelho;       // Todo novo nó deve ser vermelho (regra)
    }else{
        printf("Erro ao alocar espaço para o novo nó\n");
        exit(EXIT_FAILURE);         // Tratamento de erro 
    }

    return novo;
}

void inserir(ArvoreRubroNegra *arvore, TIPO_CHAVE chave){

    // Se o novo nó é raíz
    if(arvore->raiz == NULL){
        Node *novo = criarNovoNo(chave);
        novo->cor = preto;
        arvore->raiz = novo;
        arvore->quantidadeElementos++;

        printf("\n::Elemento (%d) adicionado na raíz\n", chave);
        return;
    }

    Node *pai = NULL;
    Node *aux = arvore->raiz;

    // Procura o melhor lugar para o novo
    while(aux != NULL){
        pai = aux;

        if(aux->chave > chave){
            aux = aux->esquerda;
        }else if(aux->chave < chave){
            aux = aux->direita;
        }else{
            printf("\n::Elemento (%d) já inserido na árvore\n", chave);
            return;
        }
    }

    Node *novo = criarNovoNo(chave);

    novo->pai = pai;

    // Faz as ligações de pai e filho
    if(pai->chave > chave){
        pai->esquerda = novo;
    }else{
        pai->direita = novo;
    }

    arvore->quantidadeElementos++;
    printf("\n::Elemento (%d) adicionado na árvore\n", chave);

    arrumaInsercao(arvore, novo);
}

/**********************************
 * Exclusões
***********************************/

void destruirAux(Node *subRaiz){

    //Casos bases
    if(subRaiz == NULL){ // Não é nó
        return;
    }else if(subRaiz->esquerda == NULL && subRaiz->direita == NULL){ // Nó folha
        printf("Elemento follha %d removido\n", subRaiz->chave);
        free(subRaiz);
        return;
    }
    
    // Casos recursivos
    if(subRaiz->esquerda != NULL && subRaiz->direita != NULL){ //Nó com 2 filhos 
        destruirAux(subRaiz->esquerda);
        destruirAux(subRaiz->direita);
    }else{  // Nó com um filho
        if(subRaiz->esquerda != NULL){
            destruirAux(subRaiz->esquerda);
        }else{
            destruirAux(subRaiz->direita);
        }
    }

    // printf("Elemento %d removido\n", subRaiz->chave);
    free(subRaiz);
}

void destruirArvore(ArvoreRubroNegra *arvore){

    // Se a árvore foi inicializada
    if(arvore->quantidadeElementos > 0){
        destruirAux(arvore->raiz->esquerda);
        destruirAux(arvore->raiz->direita);

        free(arvore->raiz);
    }

    free(arvore);
    // printf("Árvore apagada\n");
}
