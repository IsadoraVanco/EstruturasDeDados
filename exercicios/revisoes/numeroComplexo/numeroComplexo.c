#include <stdio.h>
#include "numeroComplexo.h"

/*
Inicializa os valores reais e complexos do Número Complexo
*/
void inicializa(NumeroComplexo *num, double numReal, double numComplexo){
    num->real = numReal;
    num->complexo = numComplexo;
}

/*
Imprime os valores do número
*/
void imprime(NumeroComplexo *num){
    printf("%.3lf + %.3lfi \n", num->real, num->complexo);
}

/*
Copia os valores do número 2 em número 1
*/
void copia(NumeroComplexo *num1, NumeroComplexo *num2){
    num1->real = num2->real;
    num1->complexo = num2->complexo;
}

/*
Soma os dois números complexos.
*/
void soma(NumeroComplexo *num1, NumeroComplexo *num2){
    printf("Soma: %.3lf + %.3lfi \n", num1->real + num2->real, num1->complexo + num2->complexo);
}

/*
Verifica se o número é Real 
*/
int ehReal(NumeroComplexo *num){
    if(num->complexo == 0){
        printf("O número é Real.\n");
        return 1;
    }

    printf("O número não é Real.\n");
    return 0;
}