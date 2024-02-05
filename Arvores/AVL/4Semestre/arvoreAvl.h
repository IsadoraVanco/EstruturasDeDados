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

/**********************************
 * Funções básicas
***********************************/

/**
* @brief Inicializa a árvore, através do ponteiro duplo para a raíz.
* @param raiz O endereço do nó raíz da árvore
*/
void inicializar(PONT *raiz);

/**
 * @brief Calcula a altura de uma sub-árvore
 * @param p O endereço do nó 
 * @return A altura de uma sub-árvore
*/
int altura(PONT p);

/**
 * @brief Verifica se a árvore é AVL
 * @param p O endereço do nó
 * @return true caso a árvore seja AVL, 
 * false para caso contrário
*/
bool ehAVL(PONT p);

/**********************************
 * Exibição
***********************************/

/**
 * @brief Exibe a árvore em Ordem Simétrica utilizando recursão, ou seja, 
 * sub-árvore esquerda, raíz e sub-árvore direita
 * @param raiz O endereço do nó a ser imprimido
*/
void exibirArvoreEmOrdem(PONT raiz);

/**
 * @brief Exibe a árvore em Pré-Ordem utilizando recursão, ou seja, 
 * raíz, sub-árvore esquerda e sub-árvore direita
 * @param raiz O endereço do nó a ser imprimido
*/
void exibirArvorePreOrdem(PONT raiz);

/**
 * @brief Exibe a árvore em Pós-Ordem utilizando recursão, ou seja, 
 * sub-árvore esquerda, sub-árvore direita e raíz
 * @param raiz O endereço do nó a ser imprimido
*/
void exibirArvorePosOrdem(PONT raiz);

/**
 * @brief Exibe a árvore em Ordem Simétrica utilizando recursão, ou seja, 
 * sub-árvore esquerda, raíz e sub-árvore direita. Mostra a relação dos nós com parêntesis
 * @param raiz O endereço do nó a ser imprimido
*/
void exibirArvore(PONT raiz);

/* 
Exibe arvore Pre-Ordem indicando pai de cada no 
*/
void exibirArvore2(PONT raiz, TIPOCHAVE chavePai);

/**********************************
 * Rotações
***********************************/

/**
 * @brief Faz a rotação de nós desbalanceados à esquerda da árvore
 * @param p O endereço do nó onde será feita a rotação
 * @return O endereço da nova raíz
*/
PONT rotacaoL(PONT p);

/**
 * @brief Faz a rotação de nós desbalanceados à direita da árvore
 * @param p O endereço do nó onde será feita a rotação
 * @return O endereço da nova raíz
*/
PONT rotacaoR(PONT p);

/**********************************
 * Balanceamento
***********************************/

/**
 * @brief Atualiza o fator de balanceamento de todos os elementos
 * @param raiz O nó raíz da árvore
 * @return O fator de balanceamento do nó 
*/
int atualizarBalanceamentoTotal(PONT raiz);

/**********************************
 * Buscas
***********************************/

/**
 * @brief Proura por um elemento na árvore de maneira recursiva, utilizando busca binária
 * @param raiz Endereço do nó atual/inicial
 * @param ch Chave que será buscada
 * @return O endereço do elemento procurado caso ache, ou NULL, caso contrário
*/
PONT buscaBinaria(PONT raiz, TIPOCHAVE ch);

/**
 * @brief Procura por um elemento na árvore de maneira iterativa, utilizando busca binária
 * @param raiz O nó raíz da árvore
 * @param ch Chave a ser procurada
 * @param pai Endereço do nó que é pai do nó a ser procurado
 * @return O endereço do nó pai do elemento a ser encontrado
*/
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);

/**
 * @brief Procura o maior elemento dentro da sub-árvore, de forma recursiva.
 * OBS: Auxiliar a função de exclusão
 * @param p Endereço do nó raíz
 * @param ant Endereço do nó anterior
 * @return O endereço do maior elemento da sub-árvore
*/
PONT maiorAEsquerda(PONT p, PONT *ant);

/**********************************
 * Inserção
***********************************/

/**
 * @brief Cria um novo nó com chave = ch e retorna seu endereço
 * @param ch A chave a ser inserida na árvore
 * @return O endereço do novo nó
*/
PONT criarNovoNo(TIPOCHAVE ch);

/**
 * @brief Insere um novo nó na árvore 
 * @param p É o endereço do nó raíz
 * @param ch O valor a ser inserido
 * @param alterou Inicialmente é false
*/
void inserirAVL(PONT* p, TIPOCHAVE ch, bool* alterou);

/**********************************
 * Exclusões
***********************************/

/**
 * @brief Exclui o elemento que possui a chave ch
 * @param raiz O endereço do nó raíz
 * @param ch Valor do elemento a ser procurado
 * @param alterou Recebe false caso a árvore não seja rotacionada, 
 * e true, caso contrário
 * @return True caso encontre o elemento na árvore, false, 
 * para caso contrário
*/
bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou);

/**
 * @brief Apaga toda a estrutura da sub-árvore.
 * OBS: Auxilia a função de limpeza da árvore
 * @param subRaiz O endereço da raíz da sub-árvore
*/
void destruirAux(PONT subRaiz);

/**
 * @brief Libera todo o espaço ocupado na memória pela árvore e atribui NULL à raíz
 * @param raiz O endereço do nó raíz
*/
void destruirArvore(PONT *raiz);

#endif