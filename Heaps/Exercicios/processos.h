/**
 * @brief Processos do gerenciador
*/
#ifndef _PROCESSOS_H_
#define _PROCESSOS_H_


/************************************************************
 * Definições e typedefs
*************************************************************/

#define MINIMO 0
#define MAXIMO 1

typedef int TIPO_HEAP;

typedef struct {
    int pid; // Identificador único
    int prioridade; // Prioridade de execução
    int tempoEspera; // O tempo corrido esperando
}Processo;

typedef struct {
    Processo *heap;
    int qtdElementos;
    int totalElementos;
    TIPO_HEAP tipo;
}Heap;


/************************************************************
 * Funções Básicas
*************************************************************/

/**
 * @brief Inicializa o Heap, sem espaço para os nós
 * @param tipo O tipo do Heap
 * @return O endereço do Heap
 */
Heap *inicializarHeap(TIPO_HEAP tipo);

/**
 * @brief Constrói um vetor em Heap
 * @param heap O endereço do Heap
 */
void construirHeap(Heap *heap);

/**
 * @brief Calcula qual o índice do pai do índice
 * @param indice Índice para calcular
 * @return O índice do pai
 */
int pai(int indice);

/**
 * @brief Calcula qual o índice do filho da esquerda do índice
 * @param indice Índice para calcular
 * @return O índice do filho da esquerda
 */
int esquerda(int indice);

/**
 * @brief Calcula qual o índice do filho da direita do índice
 * @param indice Índice para calcular
 * @return O índice do filho da direita
 */
int direita(int indice);

/**
 * @brief Verifica se o Heap está vazio
 * @param heap O endereço do Heap
 * @return Caso esteja vazio, retorna 1, se não, retorna 0
 */
int heapVazio(Heap *heap);

/**
 * @brief Transforma o vetor em Heap
 * @param heap O endereço do Heap
 */
void construirHeap(Heap *heap);

/************************************************************
 * Imprimir
*************************************************************/

/**
 * @brief Imprime os processos do Heap
 * @param heap O endereço do Heap
 */
void imprimirProcessos(Heap *heap);

/************************************************************
 * Buscar
*************************************************************/

/**
 * @brief Busca um processo pelo seu ID no Heap 
 * @param heap O endereço do Heap
 * @param id O ID do processo
 * @return O índice do processo encontrado no Heap, ou -1 caso 
 * não encontre
 */
int buscarProcesso(Heap *heap, int id);

/************************************************************
 * Subir e descer nós => Heap Máximo (Prioridade)
*************************************************************/

/**
 * @brief Sobe um Processo no Heap de Prioridades
 * @param heap O endereço de Heap
 * @param indice O índice do Processo corrente a ser analisado
 */
void subirPrioridade(Heap *heap, int indice);

/**
 * @brief Desce um Processo no Heap de Prioridades
 * @param heap O endereço de Heap
 * @param indice O índice do Processo corrente a ser analisado
 */
void descerPrioridade(Heap *heap, int indice);

/************************************************************
 * Subir e descer nós => Heap Mínimo (Tempo)
*************************************************************/

/**
 * @brief Sobe um Processo no Heap de Tempo de espera
 * @param heap O endereço de Heap
 * @param indice O índice do Processo corrente a ser analisado
 */
void subirTempo(Heap *heap, int indice);

/**
 * @brief Desce um Processo no Heap de Tempo de espera
 * @param heap O endereço de Heap
 * @param indice O índice do Processo corrente a ser analisado
 */
void descerTempo(Heap *heap, int indice);

/************************************************************
 * Inserção
*************************************************************/

/**
 * @brief Insere um processo no Heap
 * @param heap O endereço do Heap
 * @param prioridade A prioridade do processo
 * @param tempo O tempo de espera do processo
 */
void inserirProcesso(Heap *heap, int prioridade, int tempo);

/************************************************************
 * Remoção
*************************************************************/

/**
 * @brief Remove o processo do topo do Heap
 * @param heap O endereço do Heap
 * @return O PID do processo removido
 */
int removerProcessoTopo(Heap *heap);

/**
 * @brief Remove o mesmo processo de ambos os Heaps
 * @param prioridades O Heap de prioridades
 * @param tempos O Heap de tempos
 */
void removerProcessoTopoAmbos(Heap *prioridades, Heap *tempos);

/**
 * @brief Apaga da memória o Heap de processos
 * @param heap O endereço do Heap
 */
void destruirProcessos(Heap *heap);

#endif