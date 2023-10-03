/*
    Implementações das funções de manipulação
    do labirinto.
*/
#include "labirinto.h"

int ehBorda(int x, int y){
    return x == 0 || x == (tamanhoLabirinto - 1) || 
            y == 0 || y == (tamanhoLabirinto - 1);
}

int faltaBorda(int x, int y, int ponto){
    return ehBorda(x, y) && ponto != PAREDE;
}

void setChegada(int x, int y){
    chegada->x = x;
    chegada->y = y;
}

int ehChegada(int x, int y){
    if(chegada->x == x && chegada->y == y) return 1 : return 0;
}

int temChegada(int x, int y){
    return chegada->x != 0 && chegada->y != 0;
}

int temPartida(int x, int y){
    return partida->x != 0 && partida->y != 0;
}

void setPartida(int x, int y){
    partida->x = x;
    partida->y = y;
}

void mostraTabuleiro(int *matriz){
    for(int i = 0; i < tamanhoLabirinto; i++){
        for(int j = 0; j < tamanhoLabirinto; j++){
            char desenho;

            switch(matriz[i][j]){
                case PAREDE:
                    desenho = DESENHO_PAREDES;
                    break;
                case CAMINHO_LIVRE:
                    desenho = DESENHO_CAMINHO_LIVRE;
                    break;
                case CHEGADA:
                    desenho = DESENHO_CHEGADA;
                
            }
        }
    }
}

void encerraTabuleiro(int* matriz){
    free(matriz);
}