/*
Créditos ao profº Gilberto, autor do exercício.

1. Implemente um TAD “Número Complexo” e implemente as seguintes operações:
    * Inicializa: atribui valores para os campos
    * Imprime: imprime o número da forma “R + Ci”
    * Copia: Copia o valor de um número para outro
    * Soma: Soma dois números complexos
    * EhReal: testa se um número é real

    Por fim, faça um pequeno programa para testar o seu TAD. Lembre-se que em números complexos, 
    cada número possui os campos real e imaginário
*/
#include <stdio.h>
#include "numeroComplexo.h"

int main(){
    NumeroComplexo numero;
    NumeroComplexo outroNumero;

    printf("Numero1: ");
    inicializa(&numero, 10.5, 5);
    imprime(&numero);

    printf("Numero2: ");
    inicializa(&outroNumero, 3, 1.43);
    imprime(&outroNumero);

    printf("Numero1: ");
    copia(&numero, &outroNumero);
    imprime(&numero);

    soma(&numero, &outroNumero);

    printf("Numero1: ");
    ehReal(&numero);

    return 0;
}