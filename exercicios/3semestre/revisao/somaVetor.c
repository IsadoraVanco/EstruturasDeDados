/*
Escreva um programa que declare um vetor de inteiros e um ponteiro
para inteiros. Associe o ponteiro ao vetor. Agora, some mais dez (+10) a
cada posição do vetor usando o ponteiro (use *). (use a aritmética de
ponteiros)
*/
#include <stdio.h>

int main(){
    int vetor[10];
    int *ponteiro;
    ponteiro = &vetor;

    for(int = 0; i < 10; i++){
        vetor[i] = i + 1;
    }

    for(int = 0; i < 10; i++){
        *ponteiro += 10;
        ponteiro++;
    }

    for(int = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}