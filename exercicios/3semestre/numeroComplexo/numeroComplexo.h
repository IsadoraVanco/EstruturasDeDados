#ifndef __NUMERO_COMPLEXO_
#define __NUMERO_COMPLEXO_

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