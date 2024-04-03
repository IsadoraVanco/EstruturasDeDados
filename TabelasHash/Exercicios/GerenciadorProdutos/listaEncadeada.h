/**
 * @brief Lista Encadeada simples para a tabela Hash
*/

#ifndef _LISTA_ENCADEADA_
#define _LISTA_ENCADEADA_


/************************************************************
 * Definições e typedefs
*************************************************************/

typedef struct no{
    struct no *proximo;     // Proximo elemento da lista
    int id;                 // Valor do elemento 
    char descricao[200];    // Descrição do produto
    double preco;           // Preço do produto
}Node;

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief Cria um node para a lista encadeada
 * @param ID O ID do produto
 * @param descricao A descricao do produto
 * @param preco O preço do produto
 * @return O endereço do novo node
 */
Node *criarNode(int ID, char *descricao, double preco);

/************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Insere um node na lista de forma ordenada
 * @param lista O endereço para o primeiro elemento da lista
 * @param nova O endereço do novo node para inserir
 */
void inserirNodeOrdenado(Node **lista, Node *nova);

/************************************************************
 * Buscar
*************************************************************/

/**
 * @brief Busca um valor na lista encadeada
 * @param lista O endereço para o primeiro elemento da lista
 * @param id O valor a ser buscado
 * @return O endereço do valor encontrado, ou NULL caso não ache
 */
Node *buscarNode(Node **lista, int id);

/************************************************************
 * Mostrar
*************************************************************/

/**
 * @brief Mostra as informações de um Node da tabela
 * @param elemento O endereço do Node
 */
void mostrarNode(Node *elemento);

/**
 * @brief Mostra os valores da lista encadeada
 * @param lista O endereço do primeiro elemento da lista
 */
void mostrarNodes(Node **lista);

/************************************************************
 * Remover
*************************************************************/

/**
 * @brief Remove um node da lista
 * @param lista O endereço do primeiro elemento da lista
 * @param id O valor a ser removido da lista
 */
void removerNode(Node **lista, int id);

/************************************************************
 * Destruição
*************************************************************/

/**
 * @brief Apaga todo o conteúdo da lista da memória
 * @param lista O endereço do primeiro elemento da lista
 */
void destruirNodes(Node **lista);

#endif