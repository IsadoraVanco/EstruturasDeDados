/*
Créditos ao profº Gilberto, autor do exercício.

Crie um programa que receba uma sequência de caracteres contendo
uma expressão aritmé tica e que verifica se a sequência de parênteses e
colchetes está bem-formada (ou seja, parênteses e colchetes são
fechados na ordem inversa àquela em que foram abertos).

Por exemplo:
A expressão [A+(B*C)] está bem-formada,
enquanto que (A*([B+D)/C] está malformada.

-Utilize uma pilha para resolver o problema!
-Armazene a entrada em uma sequência de caracteres (string) e como é hábito
em C, o último caractere da string é \0.
*/

#include <stdio.h>
#include <string.h>
#include "pilha.h"

/*
A função recebe uma expressão aritmética e verifica se os colchetes, 
chaves e parênteses foram abertos e fechados corretamente.
Retorna 1 caso tenha erro, senão, retorna 0.
*/
int verificaExpressao(char *expressao){
    int ultimo; //caso exista erro, representará a chave com possível erro
    int erro = 0; //aponta erro :)
    char *letra = expressao; //ponteiro para um caractere da expressão
    
    Stack *pilha = newStack(); //cria uma nova pilha

    for(int i = 0; i < strlen(expressao); i++){
        
        if(*letra == '('){
            push(pilha, ')');
            ultimo = i;

        }else if(*letra == '['){
            push(pilha, ']');
            ultimo = i;

        }else if(*letra == '{'){
            push(pilha, '}');
            ultimo = i;

        }else if(*letra == ')' || *letra == ']' || *letra == '}'){ //se o caractere for uma das chaves fechando
            if(pop(pilha) == 0 || pop(pilha) != *letra){ //chaves fechando a mais OU ordem está errada
                ultimo = i;                             
                i = strlen(expressao); //para o laço
                erro = 1;
            }
        }

        letra++;
    }
    
    printf("\n%s\n", expressao);
    
    if(isEmptyStack(pilha) && !erro){
        printf("A expressão está correta\n");
    }else{ //faltou ou sobrou chaves para fechar
        for(int i = 0; i < ultimo; i++){
            printf(" ");
        }
        printf("^\n");
        printf("Existe um erro na expressão\n");

    }

    deleteStack(pilha);

    return 0;
}

int main(int argc, char const *argv[]){
    char expressao[200];

    printf("Digite uma expressao: \n");
    scanf("%[^\n]", expressao);

    if(verificaExpressao(expressao)){
        printf("Erro ao verificar a expressão.\n");
        return 1;
    }
    
    return 0;
}
