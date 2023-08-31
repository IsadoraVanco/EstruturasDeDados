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