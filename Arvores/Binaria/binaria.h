/**
 * @file binaria.h
 * @brief Árvore Binária
*/

/**********************************************************************
 * MÉTODOS BÁSICOS
***********************************************************************/

/**
 * @brief Cria um espaço para guardar uma árvore.
*/
Arvore* criaArvore();

/**
 * @brief Retorna a altura de uma árvore
 * @param raiz O ponteiro para uma árvore
 * @return A altura da árvore passada
*/
int getAltura(Arvore* raiz);

/**********************************************************************
 * PERCURSOS
***********************************************************************/

/**
 * @brief Percorre a árvore em nível utilizando uma estrutura de fila. 
 * Ou seja, um nível de cada vez, de cima para baixo, da esquerda para a direita.
 * @param raiz O endereço da Arvore
*/
void percorrerEmNivel(Arvore* raiz);

/**
 * @brief Percorre a árvore em pré-ordem utilizando uma estrutura de pilha.
 * Ou seja, percorre sistematicamente a raíz, depois toda a sub-árvore esquerda, 
 * depois a direita.
 * @param raiz O endereço da Arvore
*/
void percorrerEmPreordem(Arvore* raiz);

/**
 * @brief Percorre a árvore em Ordem Simetrica utilizando uma estrutura de pilha.
 * Ou seja, percorre sistematicamente toda a sub-árvore esquerda, depois a raíz, 
 * depois toda a sub-árvore direita.
 * @param raiz O endereço da Arvore
*/
void percorrerEmOrdemSimetrica(Arvore* raiz);

/**
 * @brief Percorre a árvore em Pós-ordem 
 * @param raiz O endereço da Arvore
*/
void percorrerEmPosOrdem(Arvore* raiz);