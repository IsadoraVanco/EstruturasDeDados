#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "pilha.h"

/*
    Representa um ponto no tabuleiro
*/
typedef struct {
    int x, y;
    int dx = 0;
    int dy = 0;
    Pilha *caminhos;
}Personagem;

//******************** TABULEIRO ********************

/*
Libera o espaço da memória reservado para o tabuleiro.
*/
void apagaTabuleiro(int** matriz);

/*
Mostra o tabuleiro convertido na tela.
*/
void mostraTabuleiro(int **matriz);

/*
Armazena o tabuleiro em uma matriz, retornando seu ponteiro 
caso prossiga com sucesso, senão, retorna 0. Além disso,
guarda a coordenada inicial do persongem.
*/
int **armazenaTabuleiro(char *nomeArquivo, Personagem *coordenadaPersonagem);


//******************** BORDAS ********************

/*
Verifica se as coordenadas fazem parte da borda do tabuleiro.
*/
int ehBorda(int x, int y);

/*
Verifica se falta caractere de parede na borda do tabuleiro.
*/
int faltaBorda(int x, int y, int ponto);

#endif