//arquivo do Evandro :/ (resumido/modificado)
//aqui fica as descrições das funções 

//Pilha é uma coleção de itens, os primeiros itens 
//acrescentados serão os ultimos a serem retirados.
//Neste módulo, uma pilha com elementos do tipo inteiro
#ifndef _PILHA_INT__
#define _PILHA_INT__

typedef int Item; //cria um tipo inteiro Item
typedef void *Pilha; //cria um tipo void pointer Pilha = o tipo pilha

 /**
   Cria uma pilha vazia com uma certa capacidade de armazenamento.
   Retorna o ponteiro para a pilha criada.
  */
Pilha create_pilha(int capacidade);

/**
  Empilha o item na pilha.
  A pilha nao pode estar cheia.
 */
void push(Pilha pilha, Item item);

/**
  Retira o item que está no topo da pilha e retorna o seu valor.
  A pilha nao pode estar vazia.
 */
Item pop(Pilha pilha);

/**
  Retorna verdadeiro(1) se a pilha está vazia ou 
  falso(0), caso contrario.
 */
int empty(Pilha pilha);

/**
  Retorna verdadeiro(1) se a pilha está cheia ou 
  falso(0), caso contrario.
 */
int full(Pilha pilha);

#endif