/**
 * @brief Tabela Hash com encadeamento separado 
*/
#ifndef _HASH_ENCADEAMENTO_SEPARADO_
#define _HASH_ENCADEMENTO_SEPARADO_

#include <stdbool.h>
#include "listaEncadeada.h"

/************************************************************
 * Definições e typedefs
*************************************************************/

typedef struct{
    Node **tabela;
    int tamanho;
    int quantidadeElementos;
}HashEncadeada;

/************************************************************
 * Funções auxiliares
*************************************************************/

/**
 * @brief Calcula se um número é primo
 * @param numero O número a ser analisado
 * @return True se for primo, false, para caso contrário
 */
bool ehPrimo(int numero);

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief Aloca um espaço para uma tabela Hash
 * @param qtdElementosConjunto Quantidade de elementos esperados no conjunto
 * @return O endereço da tabela alocada
 */
HashEncadeada *inicializaHash(int qtdElementosConjunto);

/**
 * @brief Calcula um índice da Hash
 * @param hash O endereço da tabela hash
 * @param chave A chave (valor do node) para calcular o índice
 * @return O índice calculado
 */
int funcaoHash(HashEncadeada *hash, int chave);

/**
 * @brief Calcula o valor do fator de carga de uma Hash
 * @param hash O endereço da Hash
 * @return O valor do fator de carga calculado
 */
double calcularFatorCargaHash(HashEncadeada *hash);

/**
 * @brief Calcula o tamanho ideal para uma hash, dado um número de elementos 
 * totais que serão armazenados 
 * @param qtdElementosConjunto O número de elementos do conjunto
 * @return O valor para o tamanho ideal
 */
int calcularTamanhoIdealHash(int qtdElementosConjunto);

/************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Insere um novo node na tabela Hash
 * @param hash O endereço da tabela Hash
 * @param novo O endereço do novo elemento
 */
void inserirHash(HashEncadeada *hash, Node *novo);

/************************************************************
 * Busca
*************************************************************/

/**
 * @brief Busca um valor na tabela Hash
 * @param hash O endereço da tabela Hash
 * @param valor O valor a ser buscado
 * @return O endereço do elemento encontrado, ou NULL caso não ache
 */
Node *buscarValorHash(HashEncadeada *hash, int valor);

/************************************************************
 * Mostrar
*************************************************************/

/**
 * @brief Mostra os elementos da tabela Hash
 * @param hash O endereço da tabela Hash
 */
void mostrarHash(HashEncadeada *hash);

/************************************************************
 * Remoção
*************************************************************/

/**
 * @brief Remove um valor da tabela Hash
 * @param hash O endereço da tabela Hash
 * @param valor O valor a ser retirado
 */
void removerValorHash(HashEncadeada *hash, int valor);

/************************************************************
 * Destruição
*************************************************************/

/**
 * @brief Apaga todo o conteúdo da Hash
 * @param hash O endereço da tabela Hash
 */
void destruirHash(HashEncadeada *hash);

#endif