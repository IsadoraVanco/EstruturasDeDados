/**
 * @brief Implementação da árvore Rubro-Negra
*/
#ifndef _ARVORE_RUBRO_NEGRA_H_
#define _ARVORE_RUBRO_NEGRA_H_

#include "Ferramentas/Dot/dot.h"

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
 * @brief Troca a posição de dois nós
 * @param arvore O endereço da árvore
 * @param pai O endereço do nó mais acima
 * @param filho O endereço do nó mais abaixo
 */
void trocar(ArvoreRubroNegra *arvore, Node *pai, Node *filho);

/**
 * @brief Calcula a altura de uma sub-árvore
 * @param arvore O endereço da árvore
 * @param no O endereço do nó corrente
 * @return A altura de uma sub-árvore
*/
int altura(ArvoreRubroNegra *arvore, Node *no);

/**
 * @brief Calcula a altura negra de uma sub-árvore
 * @param arvore O endereço da árvore
 * @param no O endereço do nó corrente
 * @return A altura negra de uma sub-árvore
 */
int alturaNegra(ArvoreRubroNegra *arvore, Node *no);

/**
 * @brief Conta a quantidade de nós pretos e vermelhos da árvore
 * @param arvore O endereço da árvore
 * @param no O endereço do nó
 * @param noPreto O endereço para retornar a quantidade de nós pretos
 * @param noVermelho O endereço para retornar a quantidade de nós veremlhos
 */
void contarNos(ArvoreRubroNegra *arvore, Node *no, int *noPreto, int *noVermelho);

/**
 * @brief Calcula a porcentagem de nós pretos e vermelhos da árvore
 * @param arvore O endereço da árvore
 */
void obterPorcentagemCores(ArvoreRubroNegra *arvore);

/*************************************************************
 * Exibição
*************************************************************/

/**
 * @brief Exibe a árvore em Pré Ordem utilizando recursão, ou seja, 
 * raíz, sub-árvore esquerda e sub-árvore direita. Mostra a relação dos 
 * nós e seus pais
 * @param arvore O endereço da árvore
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
 * @param arvore O endereço da árvore
 * @param no Nó que será registrado no .dot
 */
void adicionarNodeArquivo(ARQUIVODOT *arquivo, ArvoreRubroNegra *arvore, Node *no);

/*************************************************************
 * Buscas
*************************************************************/

/**
 * @brief Calcula o custo médio de uma busca na árvore
 * @param arvore O endereço de uma árvore
 * @param valor O valor a ser buscado
 * @return O número de comparaçoes feitas para encontrar o valor
 */
int calcularCustosBusca(ArvoreRubroNegra *arvore, int valor);

/**
 * @brief Proura por um elemento na árvore de maneira recursiva, utilizando busca binária
 * @param arvore O endereço de uma árvore
 * @param raiz Endereço do nó atual/inicial
 * @param chave Chave que será buscada
 * @return O endereço do elemento procurado caso ache, ou NULL, caso contrário
*/
Node *buscaBinaria(ArvoreRubroNegra *arvore, Node *raiz, TIPO_CHAVE chave);

/**
 * @brief Encontra o menor valor dentro de uma sub-árvore
 * @param arvore O endereço da árvore
 * @param no O endereço do nó corrente 
 * @param ant O endereço do nó anterior
 * @return O endereço do menor valor
 */
Node *encontrarMenor(ArvoreRubroNegra *arvore, Node *no, Node *ant);

/*************************************************************
 * Rotações
*************************************************************/

/**
 * @brief Faz a rotação de nós desbalanceados à esquerda da árvore
 * @param arvore O endereço da árvore
 * @param pai O nó a ser rotacionado
*/
void rotacaoEsquerda(ArvoreRubroNegra *arvore, Node *pai);

/**
 * @brief Faz a rotação de nós desbalanceados à direita da árvore
 * @param arvore O endereço da árvore
 * @param pai O nó a ser rotacionado
*/
void rotacaoDireita(ArvoreRubroNegra *arvore, Node *pai);

/*************************************************************
 * Correções
*************************************************************/

/**
 * @brief Modifica a árvore para que os nós satisfaçam as regras
 * @param arvore O endereço da árvore
 * @param novo O endereço do novo nó inserido e o que está sendo 
 * analisado
 */
void corrigirInsercao(ArvoreRubroNegra *arvore, Node *novo);

/**
 * @brief Corrige a árvore do lado esquerdo
 * @param arvore O endereço da árvore
 * @param no O endereço do nó
 * @param pai O endereço do pai do nó
 * @param avo O endereço do avô do nó
 */
void corrigirInsercaoEsquerda(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo);

/**
 * @brief Corrige a árvore do lado direito
 * @param arvore O endereço da árvore
 * @param no O endereço do nó
 * @param pai O endereço do pai do nó
 * @param avo O endereço do avô do nó
 */
void corrigirInsercaoDireita(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo);

/*************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Cria um novo nó com o valor da chave e retorna seu endereço
 * @param arvore É o endereço da árvore
 * @param chave A chave a ser inserida na árvore
 * @return O endereço do novo nó
*/
Node *criarNovoNo(ArvoreRubroNegra *arvore, TIPO_CHAVE chave);

/**
 * @brief Insere um novo nó na árvore 
 * @param arvore É o endereço da árvore
 * @param chave O valor a ser inserido
*/
void inserir(ArvoreRubroNegra *arvore, TIPO_CHAVE chave);

/*************************************************************
 * Correções de exclusões
*************************************************************/

/**
 * @brief Corrige a exclusão de um elemento da árvore
 * @param arvore O endereço da árvore
 * @param no O endereço do nó a ser analisado
 */
void corrigeApagar(ArvoreRubroNegra *arvore, Node *no);

/**
 * @brief Corrige o nó da árvore que caiu no caso da esquerda
 * @param arvore O endereço da árvore
 * @param no O endereço do nó a ser analisado
 */
void corrigirApagarEsquerda(ArvoreRubroNegra *arvore, Node **no);

/**
 * @brief Corrige o nó da árvore que caiu no caso da direita
 * @param arvore O endereço da árvore
 * @param no O endereço do nó a ser analisado
 */
void corrigirApagarDireita(ArvoreRubroNegra *arvore, Node **no);

/*************************************************************
 * Exclusões
*************************************************************/

/**
 * @brief Remove um elemento da árvore
 * @param arvore O endereço da árvore
 * @param chave O valor a ser removido
 */
void apagar(ArvoreRubroNegra *arvore, TIPO_CHAVE chave);

/**
 * @brief Apaga toos os nós de uma subárvore
 * @param arvore O endereço das informações da árvore
 * @param subRaiz O endereço da raíz da sub-árvore
*/
void destruirNos(ArvoreRubroNegra *arvore, Node *subRaiz);

/**
 * @brief Libera todo o espaço ocupado na memória pela árvore e atribui NULL à raíz
 * @param arvore O endereço das informações da árvore
*/
void destruirArvore(ArvoreRubroNegra *arvore);

#endif