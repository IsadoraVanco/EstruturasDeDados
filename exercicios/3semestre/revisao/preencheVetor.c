/*
Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo
tipo do vetor. A função deverá preencher os elementos de vetor com esse
valor. Não utilize índices para percorrer o vetor, apenas aritmética de
ponteiros.
*/
#include <stdio.h>

void preencheVetor(int *vetor, int valor){
    for(int = 0; i < 10; i++){
        *vetor = valor;
        vetor++;
    }
}

int main(){
    int vetor[10];
    int valor = 7;

    preencheVetor(&vetor, valor);

    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}