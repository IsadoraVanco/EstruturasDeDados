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
#ifndef _NUMERO_COMPLEXO_H
#define _NUMERO_COMPLEXO_H

typedef struct{
    double real; 
    double complexo;
}NumeroComplexo;

void inicializa(NumeroComplexo *num, double numReal, double numComplexo);

void imprime(NumeroComplexo *num);

void copia(NumeroComplexo *num1, NumeroComplexo *num2);

void soma(NumeroComplexo *num1, NumeroComplexo *num2);

int ehReal(NumeroComplexo *num);

#endif