//a ideia é fazer uma lista ligada, com indices, conteudo, 
// ponteiros para proximo e anterior.
// uma lista é um conjunto de elementos ordenados. 
// O ultimo a entrar é o ultimo a sair.

// novamente, copiando do Evandro ...
#ifndef _LISTA_LIGADA__
#define _LISTA_LIGADA__

#include <stdbool.h>

typedef void* Lista;
typedef void* Item;
typedef void* Posicao; //tipo para a posição de um elemento

typedef void* Iterador; //tipo para iteradores
typedef void* Clausura; //??

#define NIL NULL; //valor inválido = não se refere a nenhum item
#define CAPAC_ILIMITADA -1 //valor definido para comparar se a lista vai ter tamanho ilimitado

// ********************** MÉTODOS DA LISTA ************************

/** Retorna uma lista vazia. A capacidade de elementos na lista será definida. 
 * Caso a capacidade seja < 0, o tamanho da lista é ilimitado */
Lista createList(int capacidade);

/** Retorna o numero de elementos da lista. */
int lengthList(Lista lista);

/** Retorna a capacidade da lista. Retorna -1, se a capacidade é ilimitada */
int maxLengthList(Lista lista);

/** Retorna verdadeiro se a lista estiver vazia */
bool isEmptyList(Lista lista);

/** Retorna verdadeiro se a lista estiver cheia. Ou seja, se a lista
   tiver sido criada com uma capacidade máxima e lenght == maxLength. */
bool isFullList(Lista lista);

/**  Insere o item info no final da lista. Retorna um indicador para o 
 * elemento acrescentado; ou NIL, se a lista estiver cheia */
Posicao insertList(Lista lista, Item info);

/** Insere o item info na posicao imediatamente anterior ao
item indicado pela posicao. Retorna um indicador para o elemento acrescentado.*/
Posicao insertBefore(Lista lista,Posicao posicao, Item info);
 
/** Insere o item info na posicao imediatamente posterior ao
item indicado pela posicao. Retorna um indicador para o elemento acrescentado. */
Posicao insertAfter(Lista lista,Posicao posicao, Item info); 

// Remove o elemento da lista indicado pela posicao. 
void remove(Lista lista, Posicao posicao);

/** Remove e retorna o primeiro elemento da lista. 
    A lista nao pode estar vazia */
Item pop(Lista lista);

// Retorna o valor do item da lista indicado pela posicao.
Item get(Lista lista, Posicao posicao);

/** Retorna o indicador do primeiro elemento da lista.
 * Se length(L)=0, retorna NIL. */
Posicao getFirst(Lista lista);

/** Retorna o indicador do elemento seguinte ao elemento
indicado pela posicao. Se posicao for o ultimo elemento da lista, retorna NIL.*/
Posicao getNext(Lista lista,Posicao posicao);

/** Retorna o indicador do ultimo elemento da lista.
 * Se length(L)=0, retorna NIL.*/
Posicao getLast(Lista lista);

/** Retorna o indicador do elemento anterior ao elemento
indicado pela posicao. Se posicao for o primeiro elemento da lista, retorna NIL.*/
Posicao getPrevious(Lista lista, Posicao posicao);

/** Libera toda memoria alocada pela lista. */
void kill(Lista lista);


// ********************** ITERADORES ************************
// permite navegar pelos elementos da lista
/** (nota: existe uma certa redundancia com getFirst, getLast, 
 **  getNext e getPrevious). **/

/** Retorna um iterador sobre a lista. 
   O iterador "anda" do inicio -> fim se reverso for falso;
   fim -> inicio, se reverso for verdadeiro. */
Iterador createIterador(Lista lista, bool reverso);

/**Retorna verdadeiro caso o iterador esteja cheio,
   i.e., todos os item ja' tenham sido retornados; falso, caso contrario. */
bool isEmptyIterator(Lista lista, Iterador iterador);

/** Retorna o proximo item. O iterador nao deve estar esgotado.
   Caso o item retornado seja o ultima, subsequentes invocacoes
   a isIteratorEmpty retornam verdadeiro.*/
Item getNextIterator(Lista lista, Iterador iterador);

// Libera os recursos usados pelo iterador.
void killIterator(Lista lista, Iterador iterador);


// ********************** HIGH ORDER FUNCTIONS ************************

// Programação de alta ordem: Programação de alta ordem é um estilo de programação 
// em que as funções são tratadas como valores e podem ser passadas como argumentos para 
// outras funções ou retornadas como resultados de outras funções. 
// Isso permite que os programas sejam mais modulares e flexíveis.

// ponteiros de função:
typedef Item (*Apply)(Item item);
// define o tipo "Apply" como um ponteiro para uma função 
// que recebe um argumento do tipo "Item" e retorna um valor do mesmo tipo "Item".

typedef bool (*Check)(Item item);
//  define o tipo "Check" como um ponteiro para uma função que recebe um 
//  argumento do tipo "Item" e retorna um valor booleano.

typedef void (*ApplyClosure)(Item item, Clausura clausura);
// define o tipo "ApplyClosure" como um ponteiro para uma função que recebe dois argumentos: 
// um do tipo "Item" e outro do tipo "Clausura", e não retorna valor.

// Esse trecho de código em C define um tipo de ponteiro de função 
// chamado "ApplyClosure" que recebe dois argumentos: um do tipo "Item" 
// e outro do tipo "Clausura". A função apontada por esse ponteiro deve retornar 
// "void", ou seja, não retornar valor. A definição desse tipo de ponteiro de função
// pode ser usada para criar funções que apliquem uma determinada operação em cada 
// item de uma coleção (por exemplo, uma lista ou uma árvore) utilizando uma clausura 
// (também conhecida como contexto ou estado compartilhado). O uso de uma clausura 
// permite que a função que aplica a operação possa acessar e modificar informações 
// compartilhadas entre todas as chamadas para essa função.

/** Cria uma nova lista. Aplica a funcao a cada item da lista
    e insere o resultado na nova lista. */
Lista map(Lista lista, Apply funcao);
// recebe uma lista e uma função "funcao" do tipo "Apply". Ela aplica a função "funcao" 
// a cada elemento da lista e retorna uma nova lista com os resultados.

/** Cria uma nova lista contendo os itens da lista para os quais a
   invocacao da funcao retornar verdeira. */
Lista filter(Lista lista, Check funcao);
// recebe uma lista e uma função "funcao" do tipo "Check". Ela filtra a lista, 
// mantendo apenas os elementos que satisfazem a condição definida pela função 
// "funcao", e retorna uma nova lista com esses elementos.

/** Aplica a funcao a cada elemento da lista, possivelmente, 
 * atualizando o conteudo da clausura. */
void fold(Lista lista, ApplyClosure funcao, Clausura clausura);
//  recebe uma lista, uma função "funcao" do tipo "ApplyClosure" e uma clausura "clausura". 
//  Ela aplica a função "funcao" a cada elemento da lista, passando o elemento e a clausura 
//  como argumentos, e atualiza a clausura de acordo com o resultado da função. 
//  Essa função é comumente utilizada para implementar operações como somatórios e produtos 
//  sobre uma lista de valores.

// CLAUSURA 
// Em programação, uma clausura (também conhecida como closure em inglês) é uma função que 
// contém referências a variáveis locais que foram definidas em um escopo externo. Essas variáveis 
// locais são capturadas pela clausura e podem ser acessadas pela função interna, mesmo que o escopo 
// externo não esteja mais ativo.
// Uma clausura é usada para manter o estado de uma função entre chamadas sucessivas, permitindo que 
// a função acesse e modifique variáveis que persistem entre as chamadas. Isso é útil quando uma 
// função precisa ser chamada várias vezes com diferentes valores de entrada e precisa manter algum 
// estado interno entre essas chamadas.
// No exemplo dado, a clausura é um parâmetro passado para a função "fold", junto com uma função 
// "funcao" do tipo "ApplyClosure". A clausura é atualizada a cada chamada da função "funcao", 
// permitindo que ela armazene informações sobre o estado da operação realizada até aquele ponto.

#endif