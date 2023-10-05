/*
Implementações das funções para a estrtura de uma pilha.
*/
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* criaPilha(){
    Pilha* nova = (Pilha *) malloc(sizeof(Pilha));

    if(!nova){
        printf("Erro ao alocar espaço para a pilha.\n");
        return NULL;
    }

    nova->tamanho = 0;
    nova->topo = NULL;

    return nova;
}

int ehPilhaVazia(Pilha *pilha){
    return pilha->tamanho == 0;
}

int obtemTamanhoPilha(Pilha *pilha){
    return pilha->tamanho;
}

int adicionaPilha(Pilha* pilha, Ponto *ponto) {
    Celula* nova = (Celula *) malloc(sizeof(Celula));

    nova->coordenadas.x = ponto->x;
    nova->coordenadas.y = ponto->y;
    nova->proxima = pilha->topo;

    pilha->topo = nova;
    pilha->tamanho++;

    return 0;
}

Ponto* retiraPilha(Pilha* pilha) {

    if(ehPilhaVazia(pilha)){
        printf("Não é possível retirar um elemento da pilha vazia.\n");
        return 0;
    }

    Celula* celulaTopo = pilha->topo;

    Ponto *ponto = (Ponto *) malloc(sizeof(Ponto));
    ponto->x = celulaTopo->coordenadas.x;
    ponto->y = celulaTopo->coordenadas.y;

    pilha->topo = celulaTopo->proxima;
    pilha->tamanho--;
    free(celulaTopo); 

    return ponto;
}

int imprimePilha(Pilha *pilha){
    if(ehPilhaVazia(pilha)){
        printf("\n=>Sem solução\n");
        return 1;
    }

    Celula *elemento = pilha->topo;

    printf("\n=>Caminho completo:\n");
    for(int i = 0; i < obtemTamanhoPilha(pilha); i++){
        printf("(%d, %d) ", elemento->coordenadas.x, elemento->coordenadas.y);
        elemento = elemento->proxima;
    }
    printf("\n");

    return 0;
}

int apagaPilha(Pilha *pilha){
    Celula *elemento = pilha->topo;

    for(int i = 1; i <= pilha->tamanho; i++){
        pilha->topo = elemento->proxima;
        free(elemento);
        elemento = pilha->topo;
    }

    free(pilha);
}

//******************** CAMINHO ********************

void mostraCaminho(Pilha *pilha){
    Pilha *nova = criaPilha();

    //Desempilha em uma outra pilha
    for(int i = 1; i <= obtemTamanhoPilha(pilha); i++){
        Ponto *ponto;
        ponto = retiraPilha(pilha);
        adicionaPilha(nova, ponto);
        free(ponto);
    }

    //Imprime a pilha
    imprimePilha(nova);

    apagaPilha(nova);
}