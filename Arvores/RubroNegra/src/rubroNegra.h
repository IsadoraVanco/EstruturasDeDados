/**
 * @brief Implementação da árvore Rubro-Negra
*/
#ifndef _ARVORE_RUBRO_NEGRA_H_
#define _ARVORE_RUBRO_NEGRA_H_

#include "../../Ferramentas/Dot/dot.h"

/************************************************************
 * Definições e typedefs
*************************************************************/

// Cores da árvore Vermelho-Preto :P
#define preto 0
#define vermelho 1

typedef int COR;
typedef int TIPO_CHAVE;

typedef struct no {
    TIPO_CHAVE chave;
    COR cor;
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
}Node;

typedef struct arvore {
    Node *raiz;
    Node *folhasNulas;
    int quantidadeElementos;
}ArvoreRubroNegra;

/*************************************************************
 * Funções Auxiliares
*************************************************************/

/**
 * @brief Calcula o maior valor entre dois inteiros
 * @param a Um valor inteiro
 * @param b Outro valor inteiro
 * @return O maior valor entre a e b
*/
int max(int a, int b);

/************************************************************
 * Funções básicas
*************************************************************/

/**
* @brief Inicializa a árvore, criando um espaço na memória 
* para as informações
* @return O endereço do nó raíz da árvore
*/
ArvoreRubroNegra *inicializarArvore();

/**
 * @brief Calcula a altura de uma sub-árvore
 * @param no O endereço do nó 
 * @return A altura de uma sub-árvore
*/
int altura(ArvoreRubroNegra *arvore, Node *no);

/*************************************************************
 * Exibição
*************************************************************/

/**
 * @brief Exibe a árvore em Pré Ordem utilizando recursão, ou seja, 
 * raíz, sub-árvore esquerda e sub-árvore direita. Mostra a relação dos 
 * nós e seus pais
 * @param no O endereço do nó a ser imprimido
*/
void exibirArvore(ArvoreRubroNegra *arvore, Node *no);

/**
 * @brief Cria um arquivo Png a partir de um .dot com todos os elementos 
 * da árvore
 * @param arvore O endereço da árvore
 */
void criarImagemArvore(ArvoreRubroNegra *arvore);

/**
 * @brief Adiciona os nós da árvore no arquivo .dot
 * @param arquivo Endereço do arquivo .dot
 * @param no Nó que será registrado no .dot
 */
void adicionarNodeArquivo(ARQUIVODOT *arquivo, ArvoreRubroNegra *arvore, Node *no);

/*************************************************************
 * Buscas
*************************************************************/

/**
 * @brief Proura por um elemento na árvore de maneira recursiva, utilizando busca binária
 * @param raiz Endereço do nó atual/inicial
 * @param chave Chave que será buscada
 * @return O endereço do elemento procurado caso ache, ou NULL, caso contrário
*/
Node *buscaBinaria(ArvoreRubroNegra *arvore, Node *raiz, TIPO_CHAVE chave);

Node *encontraMenor(ArvoreRubroNegra *arvore, Node *p, Node *ant);

/*************************************************************
 * Rotações
*************************************************************/

/**
 * @brief Faz a rotação de nós desbalanceados à esquerda da árvore
 * @param arvore O endereço da árvore
 * @param x O nó a ser rotacionado
*/
void rotacaoEsquerda(ArvoreRubroNegra *arvore, Node *x);

/**
 * @brief Faz a rotação de nós desbalanceados à direita da árvore
 * @param arvore O endereço da árvore
 * @param x O nó a ser rotacionado
*/
void rotacaoDireita(ArvoreRubroNegra *arvore, Node *x);

/*************************************************************
 * Correções
*************************************************************/

/**
 * @brief Modifica a árvore para que os nós satisfaçam as regras
 * @param arvore O endereço da árvore
 * @param novo O endereço do novo nó inserido e o que está sendo 
 * analisado
 */
void arrumaInsercao(ArvoreRubroNegra *arvore, Node *novo);

/**
 * @brief Corrige a árvore do lado esquerdo
 * @param arvore O endereço da árvore
 * @param no O endereço do nó
 * @param pai O endereço do pai do nó
 * @param avo O endereço do avô do nó
 */
void correcaoEsquerda(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo);

/**
 * @brief Corrige a árvore do lado direito
 * @param arvore O endereço da árvore
 * @param no O endereço do nó
 * @param pai O endereço do pai do nó
 * @param avo O endereço do avô do nó
 */
void correcaoDireita(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo);

/*************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Cria um novo nó com chave = ch e retorna seu endereço
 * @param chave A chave a ser inserida na árvore
 * @return O endereço do novo nó
*/
Node *criarNovoNo(ArvoreRubroNegra *arvore, TIPO_CHAVE chave);

/**
 * @brief Insere um novo nó na árvore 
 * @param arvore É o endereço das informações da árvore
 * @param chave O valor a ser inserido
*/
void inserir(ArvoreRubroNegra *arvore, TIPO_CHAVE chave);

/*************************************************************
 * Exclusões
*************************************************************/

void troca(ArvoreRubroNegra *arvore, Node *u, Node *v);

void apagar(ArvoreRubroNegra *arvore, TIPO_CHAVE chave);

void corrigeApagar(ArvoreRubroNegra *arvore, Node *x);

/**
 * @brief Apaga toda a estrutura da sub-árvore.
 * OBS: Auxilia a função de limpeza da árvore
 * @param subRaiz O endereço da raíz da sub-árvore
*/
void destruirAux(Node *subRaiz);

/**
 * @brief Libera todo o espaço ocupado na memória pela árvore e atribui NULL à raíz
 * @param arvore O endereço das informações da árvore
*/
void destruirArvore(ArvoreRubroNegra *arvore);

#endif