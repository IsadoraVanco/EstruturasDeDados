/*
Crie uma função que receba uma variável struct como parâmetro e inicialize cada 
um de seus atributos com valores default (padrão) conforme as orientações a seguir:
        
    • Matrícula -> valor padrão: 0
    • Nome -> valor padrão: “\0” (caractere nulo)
    • Nota 1 -> valor padrão: 0
    • Nota 2 -> valor padrão: 0
*/
#include <stdio.h>

typedef struct{
    int matricula;
    char nome;
    int nota1;
    int nota2;
}Aluno;

void funcaoDefault(Aluno *aluno){
    aluno->matricula = 0;
    aluno->nome = '\0';
    aluno->nota1 = 0;
    aluno->nota2 = 0;
}

int main(int argc, char const *argv[]){
    Aluno novoAluno;

    funcaoDefault(&novoAluno);
    printf("Novo aluno criado\n");
    
    return 0;
}
