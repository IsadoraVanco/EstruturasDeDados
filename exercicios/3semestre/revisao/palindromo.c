/*
Números palíndromos são aqueles que escritos da direita para a
esquerda têm o mesmo valor quando escritos da esquerda para a
direita. Exemplo: 545; 789987; 97379; 123454321; etc. Escreva
um programa que verifique se um dado vetor A de 10 elementos
inteiros é um palíndromo, ou seja, se o primeiro elemento do
vetor e igual ao último, se o segundo elemento do vetor é igual ao
penúltimo e assim por diante até verificar todos os elementos ou
chegar à conclusão que o vetor não é um palíndromo.
*/
#include <stdio.h>

int main(){
    int A[10];

    for(int i = 0; i < 10; i++){
        printf("a[%d] = ", i);
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < 5; i++){
        if(A[i] != A[9 - i]){
            printf("Não é palindromo\n");
            return 0;
        }
    }

    printf("É palindromo\n");

    return 0;
}