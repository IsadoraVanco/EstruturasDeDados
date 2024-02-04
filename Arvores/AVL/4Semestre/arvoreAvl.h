#ifndef _ARVORE_AVL_H_
#define _ARVORE_AVL_H_


/**********************************
 * Definições e typedefs
***********************************/

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq;
    struct aux *dir;
    int bal;
} NO, *PONT;


/**********************************
 * Funções Auxiliares
***********************************/

/**
 * @brief Calcula o maior valor entre dois inteiros
 * @param a Um valor inteiro
 * @param b Outro valor inteiro
 * @return O maior valor entre a e b
*/
int max(int a, int b);

/**
 * @brief Verifica se a árvore é AVL
 * @param p O endereço do nó
 * @return true caso a árvore seja AVL, 
 * false para caso contrário
*/
bool ehAVL(PONT p);

/**********************************
 * Funções básicas
***********************************/

/**
* @brief Inicializa a árvore, através do ponteiro duplo para a raíz.
* @param raiz O endereço do nó raíz da árvore
*/
void inicializar(PONT *raiz);

/**
 * @brief Insere um novo nó na árvore 
 * @param p É o endereço do nó raíz
 * @param ch O valor a ser inserido
 * @param alterou Inicialmente é false
*/
void inserirAVL(PONT* p, TIPOCHAVE ch, bool* alterou);

/**
 * @brief Cria um novo nó com chave = ch e retorna seu endereço
 * @param ch A chave a ser inserida na árvore
 * @return O endereço do novo nó
*/
PONT criarNovoNo(TIPOCHAVE ch);

/**
 * @brief Calcula a altura de uma sub-árvore
 * @param p O endereço do nó 
 * @return A altura de uma sub-árvore
*/
int altura(PONT p);

/**
 * @brief Atualiza o fator de balanceamento de todos os elementos
 * @param raiz O nó raíz da árvore
 * @return O fator de balanceamento do nó 
*/
int atualizarBalanceamentoTotal(PONT raiz);

/**********************************
 * Funções de exibição
***********************************/

/* 
Exibe arvore Em Ordem 
*/
void exibirArvoreEmOrdem(PONT raiz);

/* 
Exibe arvore Pre Ordem 
*/
void exibirArvorePreOrdem(PONT raiz);

/* 
Exibe arvore Pos Ordem 
*/
void exibirArvorePosOrdem(PONT raiz);

/* 
Exibe arvore Em Ordem 
(com parenteses para os filhos) 
*/
void exibirArvore(PONT raiz);

/* 
Exibe arvore Pre-Ordem indicando pai de cada no 
*/
void exibirArvore2(PONT raiz, TIPOCHAVE chavePai);


/**********************************
 * Rotações
***********************************/

/* 
Rotações à direita (LL e LR)
Retornará o endereço do nó que será a
nova raiz da subárvore originalmente
iniciada por p 
*/
PONT rotacaoL(PONT p);

/* 
Rotações à esquerda (RR e RL)
Retornará o endereço do nó que será a
nova raiz da subárvore originalmente
iniciada por p 
*/
PONT rotacaoR(PONT p);

/**********************************
 * Buscas
***********************************/

/**
 * @brief Proura por um elemento na árvore de maneira recursiva
 * @param ch Chave que será buscada
 * @param raiz Endereço do nó atual/inicial
 * @return O endereço do elemento procurado caso ache, ou NULL, caso contrário
*/
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz);

/* 
Busca binária não recursiva devolvendo o nó pai 
*/
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);

/* 
Auxilir da funcao excluirChave,
procura a maior chave menor que a chave
que serah excluida 
*/
PONT maiorAEsquerda(PONT p, PONT *ant);

/**********************************
 * Exclusões
***********************************/

/* 
Exclui a chave com valor igual a ch
*/
bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou);

/* 
Funcao auxiliar na destruicao
(liberacao da memoria) de uma arvore 
*/
void destruirAux(PONT subRaiz);

/* 
Libera toda memoria de uma arvore e
coloca NULL no valor da raiz 
*/
void destruirArvore(PONT * raiz);

#endif