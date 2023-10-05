#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

//******************** CONSTANTES ********************

#define TAMANHO_MINIMO_TABULEIRO 4

/*
    Caracteres de conversão para a leitura do tabuleiro
*/
#define CAMINHO_LIVRE 0 
#define PAREDE 1
#define PERSONAGEM 2
#define CHEGADA 3
#define CAMINHO_EXPLORADO 8 
#define CAMINHO_PERCORRIDO 9

/*
    Caracteres para mostrar o tabuleiro
*/
#define DESENHO_CAMINHO_LIVRE ' '
#define DESENHO_CAMINHO_PERCORRIDO '.'
#define DESENHO_PERSONAGEM '@'
#define DESENHO_PAREDES '#'
#define DESENHO_CHEGADA 'x'

//******************** VARIÁVEIS GLOBAIS ********************

int tamanhoLabirinto = 0;

//******************** TABULEIRO ********************

void apagaTabuleiro(int** matriz){
    for(int i = 0; i < tamanhoLabirinto; i++){
        free(matriz[i]);
    }

    free(matriz);
}

void mostraTabuleiro(int **matriz){
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
                case CAMINHO_EXPLORADO:
                    desenho = DESENHO_CAMINHO_LIVRE;
                    break;
                case CHEGADA:
                    desenho = DESENHO_CHEGADA;
                    break;
                case CAMINHO_PERCORRIDO:
                    desenho = DESENHO_CAMINHO_PERCORRIDO;
                    break;
                case PERSONAGEM:
                    desenho = DESENHO_PERSONAGEM;
                    break;
            }

            printf("%c ", desenho);
        }
        printf("\n");
    }
}

int **armazenaTabuleiro(char *nomeArquivo, Ponto *coordenadaPersonagem){
    FILE *arquivo = fopen(nomeArquivo, "r");

    if(!arquivo){
        printf("ERRO: Arquivo %s não encontrado\n", nomeArquivo);
        return 0;
    }

    fscanf(arquivo, "%d", &tamanhoLabirinto);

    //Verifica se tem um tamanho mínimo 
    if(tamanhoLabirinto < TAMANHO_MINIMO_TABULEIRO){
        printf("ERRO: O labirinto não possui um tamanho mínimo\n");
        fclose(arquivo);
        
        return 0;
    }

    int** matriz = (int **) malloc(tamanhoLabirinto * sizeof(int *));

    for(int i = 0; i < tamanhoLabirinto; i++){
        matriz[i] = (int *) malloc(tamanhoLabirinto * sizeof(int));
    }

    int temChegada = 0;
    int temPartida = 0;

    //Leitura e armazenamento da matriz
    for(int i = 0; i < tamanhoLabirinto; i++){
        for(int j = 0; j < tamanhoLabirinto; j++){
            //Garante que haja apenas caracteres válidos
            if(matriz[i][j] != CAMINHO_LIVRE && 
                matriz[i][j] != PAREDE &&
                matriz[i][j] != PERSONAGEM &&
                matriz[i][j] != CHEGADA){
                    matriz[i][j] = CAMINHO_LIVRE;
            }

            fscanf(arquivo, "%d", &matriz[i][j]);

            if(faltaBorda(i, j, matriz[i][j])){ //Verifica as bordas
                printf("ERRO: O labirinto não possui todas as bordas\n");
                fclose(arquivo);
                apagaTabuleiro(matriz);

                return 0;
            }else if(matriz[i][j] == CHEGADA && !temChegada){ //Verifica se tem ponto de chegada
                temChegada = 1;
            }else if(matriz[i][j] == PERSONAGEM && !temPartida){ //Armazena o ponto de partida (primeiro que encontrar)
                coordenadaPersonagem->x = i;
                coordenadaPersonagem->y = j;

                temPartida = 1;
            }
        }
    }

    fclose(arquivo);
    
    //Verifica se a matriz tem os pontos de partida e chegada
    if(!temChegada || !temPartida){
        printf("ERRO: O labirinto não possui ponto de chegada e/ou ponto de partida definidos\n");
        apagaTabuleiro(matriz);

        return 0;
    }

    return matriz;
}

//******************** BORDAS ********************

int ehBorda(int x, int y){
    return x == 0 || x == (tamanhoLabirinto - 1) || 
            y == 0 || y == (tamanhoLabirinto - 1);
}

int faltaBorda(int x, int y, int ponto){
    return ehBorda(x, y) && ponto != PAREDE;
}

//******************** CAMINHOS ********************

int verificaCoordenada(int **matriz, Ponto *coordenadaPersonagem){
    if(matriz[coordenadaPersonagem->x][coordenadaPersonagem->y] == CHEGADA){
        return 1;
    }

    //Verifica se há caminhos disponíveis para andar
    if(matriz[coordenadaPersonagem->x + 1][coordenadaPersonagem->y] == CHEGADA ||
        matriz[coordenadaPersonagem->x + 1][coordenadaPersonagem->y] == CAMINHO_LIVRE){ //cima
        andar();
    }else if(matriz[coordenadaPersonagem->x][coordenadaPersonagem->y + 1] == CHEGADA ||
        matriz[coordenadaPersonagem->x][coordenadaPersonagem->y + 1] == CAMINHO_LIVRE){ //direita
        andar();
    }else if(matriz[coordenadaPersonagem->x - 1][coordenadaPersonagem->y] == CHEGADA ||
        matriz[coordenadaPersonagem->x - 1][coordenadaPersonagem->y] == CAMINHO_LIVRE){ //baixo
        andar();
    }else if(matriz[coordenadaPersonagem->x][coordenadaPersonagem->y - 1] == CHEGADA ||
        matriz[coordenadaPersonagem->x][coordenadaPersonagem->y - 1] == CAMINHO_LIVRE){ //esquerda
        andar();
    }else{
        voltar();
    }


    return 0;
}