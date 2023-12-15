/**
 * @file binaria.h
 * @brief Árvore Binária
*/

#ifndef _ARVORE_BINARIA
#define _ARVORE_BINARIA

/**********************************************************************
 * TYPEDEFS
***********************************************************************/

/**
 * @brief Representa um nó da árvore, armazena uma informação (int),
 * um ponteiro para o nó da esquerda e um ponteiro para o nó da direita.
*/
typedef struct StNode{
    int info;
    struct StNode *esquerda;
    struct StNode *direita;
} Node;

/**
 * @brief Representa a raiz da árvore
*/
typedef struct StRaiz{
    Node* raiz;
    // int altura;
    // int quantidadeElementos;
} Arvore;

/**********************************************************************
 * MÉTODOS BÁSICOS
***********************************************************************/

/**
 * @brief Cria um espaço para guardar uma árvore.
 * @return O endereço para a nova árvore
*/
Arvore* criaArvore();

/**
 * @brief Cria um espaço na memória para um nó.
 * @param valor O valor que será guardado no nó
 * @return O endereço do novo nó
*/
Node* criaNo(int valor);

/**
 * @brief Busca pelo elemento que armazena o valor desejado, de forma recursiva.
 * @param raiz O endereço da árvore
 * @param valor Valor que será buscado
 * @return O endereço do nó com o elemento buscado ou NULL caso não ache
*/
Node* buscarElemento(Node* no, int valor);

/**
 * @brief Insere um elemento de forma recursiva, deixando ela ordenada.
 * @param raiz O endereço da árvore
 * @param valor Valor que será inserido
 * @return O endereço do nó caso seja criado um novo elemento,
 * senão, retorna NULL
*/
Node* inserirElementoRecursivo(Node* no, int valor);

/**
 * @brief Insere um elemento na árvore caso não exista
 * @param raiz O endereço da árvore
 * @param valor O valor a ser inserido
*/
void inserirElemento(Arvore* raiz, int valor);

/**********************************************************************
 * PERCURSOS - MOSTRAR ELEMENTOS
***********************************************************************/

/**
 * @brief Percorre a árvore em nível utilizando uma estrutura de fila. 
 * Ou seja, um nível de cada vez, de cima para baixo, da esquerda para a direita.
 * Por exemplo:
 *           +
 *        *    -
 *      A  B  C  D
 * Saída: + * - A B C D
 * @param raiz O endereço da árvore
*/
void percorrerEmNivel(Arvore* raiz);

/**
 * @brief Percorre a árvore em pré-ordem utilizando uma estrutura de pilha.
 * Ou seja, percorre sistematicamente a raíz, depois toda a sub-árvore esquerda, 
 * por fim, a direita.
 *  * Por exemplo:
 *           +
 *        *    -
 *      A  B  C  D
 * Saída: + * A B - C D
 * @param raiz O endereço da árvore
*/
void percorrerEmPreordem(Arvore* raiz);

/**
 * @brief Também chamada de TreeSort, percorre a árvore em Ordem Simetrica 
 * utilizando uma estrutura de pilha. Ou seja, percorre sistematicamente 
 * toda a sub-árvore esquerda, depois a raíz, por fim, toda a sub-árvore direita.
 *  * Por exemplo:
 *           +
 *        *    -
 *      A  B  C  D
 * Saída: A * B + C - D / E
 * @param raiz O endereço da árvore
*/
void percorrerEmOrdemSimetrica(Arvore* raiz);

/**
 * @brief Percorre a árvore em Pós-ordem utilizando uma estrutura de pilha.
 * Ou seja, percorre sistematicamente toda a sub-árvore esquerda, depois toda a 
 * sub-árvore direita, por fim, a raíz.
 *  * Por exemplo:
 *           +
 *        *    -
 *      A  B  C  D
 * Saída: A B * C D E / - +
 * @param raiz O endereço da árvore
*/
void percorrerEmPosOrdem(Arvore* raiz);

/**********************************************************************
 * PERCURSOS RECURSIVOS
***********************************************************************/

/**
 * @brief Percorre a árvore em pré-ordem utilizando recursão.
 * Ou seja, percorre sistematicamente a raíz, depois toda a sub-árvore esquerda, 
 * por fim, a direita.
 * @param no O endereço de um nó da árvore
*/
void percorrerEmPreordemRecursiva(Node* no);

/**
 * @brief Percorre a árvore em Ordem Simetrica utilizando recursão.
 * Ou seja, percorre sistematicamente toda a sub-árvore esquerda, depois a raíz, 
 * por fim, toda a sub-árvore direita.
 *  * Por exemplo:
 *           +
 *        *    -
 *      A  B  C  D
 * Saída: A * B + C - D / E
 * @param no O endereço de um nó da árvore
*/
void percorrerEmOrdemSimetricaRecursiva(Node* no);

/**
 * @brief Percorre a árvore em Pós-ordem utilizando recursão.
 * Ou seja, percorre sistematicamente toda a sub-árvore esquerda, depois toda a 
 * sub-árvore direita, por fim, a raíz.
 * @param no O endereço de um nó da árvore
*/
void percorrerEmPosOrdemRecursiva(Node* no);

/**********************************************************************
 * REMOÇÃO DE ELEMENTOS
***********************************************************************/

/**
 * @brief Remove o nó folha
 * @param no O endereço do nó que será removido
*/
void removeFolha(Node* no);

/**
 * @brief Remove o nó que contém apenas um filho.
 * @param no O endereço do nó que será removido
*/
Node* removeNoUmFilho(Node* no);

/**
 * @brief Remove o nó que contém o elemento desejado, 
 * reúne as funções de remoção
 * @param no O endereço para procurar o elemento
 * @param valor O valor que será removido
 * @return O endereço do último nó visitado
*/
Node* removeNos(Node* no, int valor);

/**
 * @brief Remove o elemento desejado, utilizando das outras funções
 * @param raiz O endereço da árvore
 * @param valor O valor que será retirado
*/
void removeElemento(Arvore* raiz, int valor);

#endif