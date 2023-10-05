/*
    Módulos com todas as funções para manipulação de 
    uma Estrutura de Pilha
*/
#ifndef PILHA_H
#define PILHA_H

//******************** DEFINIÇÕES ********************

/*
Representa um ponto no mapa
*/
typedef struct {
    int x, y;
} Ponto;

/*
Celula representa cada elemento que está na Pilha.
*/
typedef struct cel{
    Ponto coordenadas; //As coordenadas do ponto no mapa
    struct cel* proxima;
} Celula;

/*
Pilha representa as informações de uma determinada estrtura de Pilha.
*/
typedef struct{
    Celula* topo;
    int tamanho;
} Pilha;

//******************** FUNÇÕES ********************

/*
Cria uma estrutura de Pilha e retorna o seu ponteiro.
*/
Pilha* criaPilha();

/*
Retorna 1 se a Pilha estiver vazia, 0 caso contrário.
*/
int ehPilhaVazia(Pilha *pilha);

/*
Adiciona o valor no topo da Pilha, caso tenha espaço.
Retorna 0 se teve sucesso, e 1, caso contrário.
*/
int adicionaPilha(Pilha* pilha, Ponto *ponto);

/*
Retira o último elemento da Pilha e o retorna.
*/
Ponto *retiraPilha(Pilha* pilha);

/*
Retorna o tamanho da Pilha.
*/
int obtemTamanhoPilha(Pilha *pilha);

/*
Procura na Pilha uma informação, copia a posição (a 
partir do topo) em 'position' caso a ache na estrutura 
e retorna 0, se não, retorna 1.
*/
int searchInPilha(Pilha *Pilha, int tipoCaminho, int *position);

/*
Copia a informação que está na posição indicada da Pilha em 'data'.
Caso não haja a posição indicada (a partir do topo), retorna 1, 
se a operação foi concluída com sucesso, retorna 0.
*/
int getElementInPilha(Pilha *Pilha, int position, int *data);

/*
Imprime os elementos da Pilha. Caso a estrutura esteja vazia,
retorna 1, se o processo for concluído com sucesso, retorna 0.
*/
int imprimePilha(Pilha *pilha);

/*
Apaga a estrutura da Pilha da memória e todas as células.
*/
int apagaPilha(Pilha *pilha);

//******************** CAMINHO ********************

void mostraCaminho(Pilha *pilha);

#endif