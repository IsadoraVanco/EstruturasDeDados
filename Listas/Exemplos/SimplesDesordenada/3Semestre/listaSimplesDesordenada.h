/**
 * @file listaSimplesDesordenada.h
 * @brief Lista Encadeada Simples (Desordenada)
*/

#ifndef _LISTA_SIMPLES_DESORDENADA
#define _LISTA_SIMPLES_DESORDENADA

#include <stdbool.h>

/**********************************************************************
 * TYPEDEFS
***********************************************************************/

/*
    Representa cada celula da lista
*/
typedef struct cel{
    int valor;              // Cada célula irá guardar um valor inteiro
    struct cel *proximo;    // O endereço para a próxima célula da lista
} Celula;

/*
    Representa a cabeça da lista e suas informações
*/
typedef struct{
    Celula* inicio; // Guarda a célula que está no inicio da lista
    int tamanho;    // Guarda o tamanho da lista 
} Lista;

/**********************************************************************
 * FUNÇÕES BÁSICAS
***********************************************************************/

/*
    Inicializa uma lista: criando um espaço para
    uma cabeça da lista, sem elementos dentro.
    Retorna o endereço da lista criada.
*/
Lista *inicializarLista();

/*
    Apaga uma lista: percorre todos os elementos e 
    libera o espaço da memória, depois libera o espaço
    alocado para a cabeça da lista. 
*/
void apagarLista(Lista *lista);

/*
    Busca um elemento na lista: Procura pelo conteúdo 
    da célula (um número inteiro) e retorna o endereço
    da célula encontrada.
*/
Celula *buscar(Lista* lista, int valor);


/*
    Função para verificar se a lista está vazia
*/
bool ehListaVazia(Lista *lista);

/*
    Mostra todos os elementos da lista.
*/
void mostraLista(Lista *lista); // Recebe como parâmetro a cabeça da lista

/**********************************************************************
 * INSERÇÕES
***********************************************************************/

/*
    Insere um elemento no inicio da lista
*/
void inserirInicio(Lista *lista, int valor);

/*
    Insere um elemento no meio da lista: 
    Como a lista é desordenada, busca pelo elemento 
    pivo que já está na lista e insere o novo elemento
    depois dele.
*/
void inserirNoMeio(Lista *lista, int valor, int pivo);

/*
    Insere o elemento no fim da lista
*/
void inserirFim(Lista *lista, int valor);

/*
    Insere um elemento na posição desejada, 
    tratando a posição como de um vetor [0, 1, 2, 3,...]
*/
void inserirNaPosicao(Lista *lista, int posicao, int valor);


/**********************************************************************
 * REMOÇÕES
***********************************************************************/

/*
    Remove o primeiro elemento da lista
*/
int removerInicio(Lista *lista);

/*
    Remove um elemento do meio da lista,
    procurando pelo valor que está armazenado nela
*/
void removerMeio(Lista *lista, int valor);

/*
    Remove o último elemento da lista
*/
int removerFim(Lista *Lista);

/*
    Remove um elemento da lista, 
    tratando a posição como um indice, como em
    vetores [0, 1, 2, 3 ...]
*/
void removerPosicao(Lista *lista, int posicao);

#endif