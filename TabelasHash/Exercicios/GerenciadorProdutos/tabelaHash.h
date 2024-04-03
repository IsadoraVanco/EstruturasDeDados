/**
 * @brief Tabela Hash com encadeamento Separado 
 * e Duplo Hash
*/

#ifndef _TABELA_HASH_
#define _TABELA_HASH_


#include <stdbool.h>
#include "listaEncadeada.h"

/************************************************************
 * Definições e typedefs
*************************************************************/

#define TIPO_ENCADEADA 0
#define TIPO_DUPLA 1

typedef int TIPO;

typedef struct{
    Node **tabela;
    int tamanho;
    int quantidadeElementos;
    TIPO tipo;
}Hash;

/************************************************************
 * Funções auxiliares
*************************************************************/

/**
 * @brief Calcula se um número é primo
 * @param numero O número a ser analisado
 * @return True se for primo, false, para caso contrário
 */
bool ehPrimo(int numero);

/**
 * @brief Inicializa o sorteador de números aleatórios
 */
void inicializarSorteador();

/**
 * @brief Gera um número decimal entre 0 e 1
 * @return O número sorteado
 */
double sortearNumero();

/************************************************************
 * Funções Hash
*************************************************************/

/**
 * @brief Calcula a quantidade de dígitos de um número
 * @param numero O número a ser verificado
 * @return A quantidade de dígitos
 */
int calcularQuantidadeDigitos(int numero);

/**
 * @brief Calcula a dobra de um número
 * @param chave A chave a ser dobrada
 * @param numeroDigitos O número de dígitos dela
 * @return A nova chave dobrada
 */
int calcularDobra(int chave, int numeroDigitos);

/**
 * @brief Calcula um índice da Hash utilizando o método da Dobra
 * @param hash O endereço da tabela hash
 * @param chave A chave (valor do node) para calcular o índice
 * @return O índice calculado
 */
int metodoDobra(Hash *hash, int chave);

/**
 * @brief Calcula um índice da Hash utilizando o método da Multiplicação
 * @param hash O endereço da tabela hash
 * @param chave A chave (valor do node) para calcular o índice
 * @return O índice calculado
 */
int metodoMultiplicacao(Hash *hash, int chave);

/**
 * @brief Calcula um índice da Hash
 * @param hash O endereço da tabela hash
 * @param chave A chave (valor do node) para calcular o índice
 * @return O índice calculado
 */
int metodoDivisao(Hash *hash, int chave);

/**
 * @brief Calcula o index da hash Encadeada
 * @param hash O endereço da Hash
 * @param chave A chave a ser calculada
 * @return O index calculado
 */
int calcularFuncaoHashEncadeada(Hash *hash, int chave);

/**
 * @brief Calcula o primeiro index para a Hash dupla
 * @param hash O endereço da Hash
 * @param chave A chave a ser calculada
 * @return O index calculado
 */
int calcularPrimeiraFuncaoHashDupla(Hash *hash, int chave);

/**
 * @brief Calcula o segundo index para a Hash dupla
 * @param hash O endereço da Hash
 * @param chave A chave a ser calculada
 * @return O index de incremento
 */
int calcularHashDuplo(Hash *hash, int chave);

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief Aloca um espaço para uma tabela Hash
 * @param tipo O tipo da Hash
 * @param qtdElementosConjunto Quantidade de elementos esperados no conjunto
 * @return O endereço da tabela alocada
 */
Hash *inicializarHash(TIPO tipo, int qtdElementosConjunto);

/**
 * @brief Calcula o valor do fator de carga de uma Hash
 * @param hash O endereço da Hash
 * @return O valor do fator de carga calculado
 */
double calcularFatorCargaHash(Hash *hash);

/**
 * @brief Calcula o tamanho ideal para uma hash, dado um número de elementos 
 * totais que serão armazenados 
 * @param qtdElementosConjunto O número de elementos do conjunto
 * @return O valor para o tamanho ideal
 */
int calcularTamanhoIdealHash(int qtdElementosConjunto);

/**
 * @brief Analisa se uma hash está cheia
 * @param hash O endereço da Hash
 * @return true caso esteja cheia, false para caso contrário
 */
bool estarCheia(Hash *hash);

/************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Insere um novo node na tabela Hash
 * @param hash O endereço da tabela Hash
 * @param novo O endereço do novo elemento
 */
void inserirHash(Hash *hash, Node *novo);

/**
 * @brief Insere um novo node na tabela Hash dupla
 * @param hash O endereço da tabela Hash
 * @param novo O endereço do novo elemento
 */
void inserirHashDupla(Hash *hash, Node *novo);

/**
 * @brief Insere um novo node na tabela Hash encadeada
 * @param hash O endereço da tabela Hash
 * @param novo O endereço do novo elemento
 */
void inserirHashEncadeada(Hash *hash, Node *novo);

/************************************************************
 * Busca
*************************************************************/

/**
 * @brief Busca um valor na tabela Hash
 * @param hash O endereço da tabela Hash
 * @param ID O valor a ser buscado
 */
void buscarHash(Hash *hash, int ID);

/**
 * @brief Busca um valor na tabela Hash encadeada
 * @param hash O endereço da tabela Hash
 * @param valor O valor a ser buscado
 * @return O index do elemento encontrado, ou -1 caso não encontre
 */
int buscarHashDupla(Hash *hash, int valor);

/**
 * @brief Busca um valor na tabela Hash encadeada
 * @param hash O endereço da tabela Hash
 * @param valor O valor a ser buscado
 * @return O endereço do elemento encontrado, ou NULL caso não ache
 */
Node *buscarHashEncadeada(Hash *hash, int valor);

/************************************************************
 * Mostrar
*************************************************************/

/**
 * @brief Mostra os elementos da tabela Hash
 * @param hash O endereço da tabela Hash
 */
void mostrarHash(Hash *hash);

/************************************************************
 * Remoção
*************************************************************/

/**
 * @brief Remove um valor da tabela Hash
 * @param hash O endereço da tabela Hash
 * @param ID O valor a ser retirado
 */
void removerHash(Hash *hash, int ID);

/**
 * @brief Remove um valor da tabela Hash dupla
 * @param hash O endereço da tabela Hash
 * @param valor O valor a ser retirado
 */
void removerHashDupla(Hash *hash, int valor);

/**
 * @brief Remove um valor da tabela Hash encadeada
 * @param hash O endereço da tabela Hash
 * @param valor O valor a ser retirado
 */
void removerHashEncadeada(Hash *hash, int valor);

/************************************************************
 * Destruição
*************************************************************/

/**
 * @brief Apaga todo o conteúdo da Hash
 * @param hash O endereço da tabela Hash
 */
void destruirHash(Hash *hash);

#endif