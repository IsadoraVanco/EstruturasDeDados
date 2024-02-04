#ifndef _ARVORE_AVL_H_
#define _ARVORE_AVL_H_

typedef struct no{
    int valor;
    int altura;
    struct no *esquerda;
    struct no *direita;
} No;

/***************************************************************
 *  BÁSICAS
 ***************************************************************/

/**
 * @brief Cria um novo nó
 * @return O endereço do novo nó
*/
No* criaNo(int valor);

/**
 * @brief Compara qual o maior valor entre dois parâmetros
 * @return O maior valor
*/
int maior(int a, int b);


/**
 * @brief Pega a altura de um nó
 * @return A altura de um nó
*/
int alturaNo(No *no);

/***************************************************************
 *  ROTAÇÕES
 ***************************************************************/

/**
 * @brief Rotação à esquerda
 * @return O endereço do nó u em p->u->v
*/
No* rotacaoEsquerda(No* p);

/**
 * @brief Rotação à direita
 * @return O endereço do nó u em p->u->v
*/
No* rotacaoDireita(No* p);

/**
 * @brief Rotação à direita e esquerda
 * @return O endereço do nó v em p->u->v
*/
No* rotacaoDireitaEsquerda(No* p);

/**
 * @brief Rotação à esquerda e direita
 * @return O endereço do nó v em p->u->v
*/
No* rotacaoEsquerdaDireita(No* p);

/***************************************************************
 *  BALANCEAMENTO
 ***************************************************************/

/**
 * @brief Calcula o fator de balanceamento de um nó 
 * (FB = Hd - He)
 * @return O fator calculado
*/
int fatorBalanceamento(No *no);

/**
 * @brief Faz o balanceamento da árvore
 * @return A nova raíz da árvore depois do balanceamento
*/
No* balancear(No* raiz);

/***************************************************************
 *  INSERÇÃO
 ***************************************************************/

/**
 * @brief Insere um nó na árvore
 * @return O endereço da nova raíz balanceada
*/
No* inserir(No* raiz, int valor);

/***************************************************************
 *  REMOÇÃO
 ***************************************************************/

/**
 * @brief Remove um nó da árvore
 * @return A árvore balanceada
*/
No* remover(No *raiz, int valor);

/***************************************************************
 *  IMPRESSÃO
 ***************************************************************/

/**
 * @brief Imprime toda a árvore em esquema de nível
*/
void imprimir(No *raiz, int nivel);

#endif