/**
 * @brief Funções para criar o arquivo .dot
*/
#ifndef _ARQUIVO_DOT_H_
#define _ARQUIVO_DOT_H_


/************************************************************
 * Definições e typedefs
*************************************************************/

// Possíveis tipos de estruturas que serão representadas
#define TIPO_GRAFO "graph"
#define TIPO_ARVORE "digraph"

// Possíveis formas para as Nodes
#define FORMA_CIRCULO "circle"
#define FORMA_QUADRADO "box"

// Possiveis fontes
#define FONTE_SANS "sans-serif"
#define FONTE_ARIAL "Arial"
#define FONTE_HELVETICA "Helvetica"

// Representa o endereço do arquivo .dot
typedef void *ARQUIVODOT;

/************************************************************
 * Funções básicas
*************************************************************/

/**
 * @brief Cria um arquivo .dot . A partir deste momento, 
 * ele estará aberto na memória.
 * @param nomeArquivo Nome do arquivo que será criado (sem extensão)
 * @return O endereço do arquivo criado
*/
ARQUIVODOT criarNovoArquivoDot(char *nomeArquivo);

/**
 * @brief Inicializa o arquivo com suas propriedades básicas de tipo.
 * Utilizar as definições de tipo.
 * @param arquivo O endereço do arquivo criado
 * @param tipo O tipo da estrutura que será representada
*/
void inicializarDot(ARQUIVODOT arquivo, char *tipo);

/**
 * @brief Finaliza o arquivo e o fecha.
 * @param arquivo O endereço do arquivo criado
*/
void finalizarDot(ARQUIVODOT arquivo);

/************************************************************
 * Funções dos Nodes
*************************************************************/

/**
 * @brief Configura atributos gerais dos Nodes.
 * @param arquivo O endereço do arquivo criado
 * @param forma A forma do Node
 * @param corBorda A cor da borda do Node
 * @param corFundo A cor do fundo do Node
 * @param corFonte A cor da fonte do Node
 * @param nomeFonte A fonte do texto
 * @param tamanhoFonte O tamanho da fonte do texto
*/
void configurarNodes(ARQUIVODOT arquivo, char *forma, char *corBorda, 
    char *corFundo, char *corFonte, char *nomeFonte, int tamanhoFonte);

/**
 * @brief Adiciona um novo Node personalizado
 * @param arquivo O endereço do arquivo criado
 * @param forma A forma do Node
 * @param corBorda A cor da borda do Node
 * @param corFundo A cor do fundo do Node
 * @param corFonte A cor da fonte do Node
 * @param nomeFonte A fonte do texto
 * @param tamanhoFonte O tamanho da fonte do texto
*/
void adicionarNovoNode(ARQUIVODOT arquivo, char *nome, char *texto, 
    char *forma, char *corBorda, char *corFundo, char *corFonte);

/************************************************************
 * Funções dos Edges
*************************************************************/

/**
 * @brief Configura atributos gerais dos Edges.
 * @param arquivo O endereço do arquivo criado
 * @param forma A forma do Node
 * @param corBorda A cor da borda do Node
 * @param corFundo A cor do fundo do Node
 * @param corFonte A cor da fonte do Node
 * @param nomeFonte A fonte do texto
 * @param tamanhoFonte O tamanho da fonte do texto
*/
void configurarEdges(ARQUIVODOT arquivo, char *forma, char *corBorda, 
    char *corFundo, char *corFonte, char *nomeFonte, int tamanhoFonte);

/**
 * @brief Cria uma conexão entre dois Nodes
 * @param arquivo O endereço do arquivo criado
 * @param tipo O tipo da estrutura que será representada
 * @param nodePai O nome do node pai
 * @param nodeFilho O nome do node filho
 * @param texto Texto que nomeia a conexão
*/
void criarConexaoNodes(ARQUIVODOT arquivo, char *tipo, char *nodePai, 
    char *nodeFilho, char *texto);

/************************************************************
 * Funções de automatização
*************************************************************/

/**
 * @brief Cria um arquivo Png a partir do .dot gerado. 
 * OBS: O nome do Png será o mesmo do .dot
 * @param nomeDot Nome do arquivo .dot para conversão
 */
void criarImagem(char *nomeDot);

#endif