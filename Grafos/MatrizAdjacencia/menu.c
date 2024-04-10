/**
 * @brief Implementações para o Menu
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"


/************************************************************
 * Funções auxiliares
*************************************************************/

int sortearNumeroInteiro(int minimo, int maximo){
    // Inicializa a semente para gerar números aleatórios
    // srand(time(NULL));

    // Calcula o intervalo (maximo - minimo + 1)
    int intervalo = maximo - minimo + 1;

    // Gera um número aleatório dentro do intervalo
    int numeroSorteado = minimo + rand() % intervalo;

    return numeroSorteado;
}

/************************************************************
 * Mostrar 
*************************************************************/

void mostrarTitulo(char* texto){
    printf("\n******************************************\n");
    printf("\t%s\n", texto);
    printf("******************************************\n\n");
}

void mostrarOpcao(char *texto){
    printf("\n=====================================\n");
    printf("\t%s\n", texto);
    printf("=====================================\n\n");
}

/************************************************************
 * Leituras
*************************************************************/

int lerInteiro(char *texto){
    int opcao;

    printf("%s", texto);
    scanf("%d", &opcao);

    return opcao;
}

double lerDouble(char *texto){
    double opcao;

    printf("%s", texto);
    scanf("%lf", &opcao);

    return opcao;
}

char *lerString(char *texto){
    char *opcao = malloc(sizeof(char) * 200);

    printf("%s", texto);
    scanf("%s", opcao);

    return opcao;
}