#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "pilha.h"

/*
    Representa o personagem do tabuleiro
*/
typedef struct {
    int x, y;
    int dx, dy;
    Pilha *caminhos;
}Personagem;

//******************** BORDAS ********************

/*
Verifica se as coordenadas fazem parte da borda do tabuleiro.
*/
int ehBorda(int x, int y);

/*
Verifica se falta caractere de parede na borda do tabuleiro.
*/
int faltaBorda(int x, int y, int ponto);

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

//******************** CAMINHOS ********************

/*
Escolhe a próxima coordenada para o personagem andar, caso ainda haja, retorna 0,
senão, retorna 1.
*/
int verificaCoordenada(int **matriz, Personagem *personagem);

/*
Libera o espaço alocado pela matriz auxiliar de caminhos.
*/
void apagaCaminhos();

/*
Mostra a matriz de caminhos.
*/
void mostraMatriz();

#endif