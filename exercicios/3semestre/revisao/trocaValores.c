/*
Faça um programa que leia 2 valores inteiros e chame uma função
que receba estas 2 variáveis e troque o seu conteúdo, ou seja, esta
função é chamada passando duas variáveis A e B por exemplo e,
após a execução da função, A conterá o valor de B, e B terá o valor
de A.
*/
#include <stdio.h>

void trocaValores(int *num1, int *num2){
    int aux = *num1;

    *num1 = *num2;
    *num2 = aux;
}

int main(int argc, char const *argv[]){
    int num1, num2;

    scanf("%d %d", &num1, &num2);
    printf("Valores %d %d\n", num1, num2);

    trocaValores(num1, num2);
    printf("Novos valores %d %d\n", num1, num2);
    
    return 0;
}
