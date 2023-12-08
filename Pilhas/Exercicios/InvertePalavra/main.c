/*
Créditos ao profº Gilberto, autor do exercício.

Faça uma programa que use uma pilha para inverter a ordem das
letras de cada palavra de uma string, preservando a ordem das
palavras.

O texto de entrada:
“EXERCICIO MUITO COMPLICADO”

deve produzir uma saı́da como:
“OICICREXE OTIUM ODACILPMOC”.
*/

#include <stdio.h>
#include <string.h>
#include "pilha.h"

/*
A função recebe uma frase e imprime-a com as palavras invertidas, 
utilizando a estrutura de Pilha. Retorna 1 caso tenha erro, 
senão, retorna 0.
*/
int inverteFrase(char *frase){
    char *letra = frase; //ponteiro para um caractere da frase
    Stack *pilha = newStack(); //cria uma nova pilha

    if(!pilha){
        printf("Erro ao inverter a frase\n");
        return 1;
    }

    for(int i = 0; i <= strlen(frase); i++){
        
        if(*letra != ' ' && *letra != '\0' && *letra != '\n'){
         
            //empilha a letra
            push(pilha, (int) *letra);
        }else{

            //desempilha todas as letras
            for(int j = getLengthStack(pilha); j > 0; j--){
                printf("%c", pop(pilha)); //imprime a pilha
            }
            printf("%c", *letra); //e o caractere :)
        }

        letra++;
    }
    printf("\n");

    deleteStack(pilha);

    return 0;
}

int main(int argc, char const *argv[]){
    char frase[200];

    printf("Digite uma frase: \n");
    scanf("%[^\n]", frase);

    printf("\nFrase inicial: \n%s\n", frase);

    printf("Frase Final: \n");
    
    if(inverteFrase(frase)){
        return 1;
    }

    return 0;
}
