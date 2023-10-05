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
#define CAMINHO_PERCORRIDO 9 //Caminho que está na pilha

/*
    Caracteres que vão definir caminhos já percorridos no labirinto
*/
#define CAMINHO_EXPLORADO 1 //Caminho já explorado
#define BLOQUEIO 4 //Flag para não passar pelo caminho

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
int **caminhos; //Representa os caminhos percorridos e as encruzilhadas

//******************** BORDAS ********************

int ehBorda(int x, int y){
    return x == 0 || x == (tamanhoLabirinto - 1) || 
            y == 0 || y == (tamanhoLabirinto - 1);
}

int faltaBorda(int x, int y, int ponto){
    return ehBorda(x, y) && ponto != PAREDE;
}

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

int **armazenaTabuleiro(char *nomeArquivo, Personagem *personagem){
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
                personagem->x = i;
                personagem->y = j;

                temPartida = 1;
            }
        }
    }

    fclose(arquivo);

    //Inicializa a matriz de caminhos percorridos
    caminhos = malloc(tamanhoLabirinto * sizeof(int *));

    for(int i = 0; i < tamanhoLabirinto; i++){
        caminhos[i] = calloc(tamanhoLabirinto, sizeof(int));
    }
    
    //Verifica se a matriz tem os pontos de partida e chegada
    if(!temChegada || !temPartida){
        printf("ERRO: O labirinto não possui ponto de chegada e/ou ponto de partida definidos\n");
        apagaTabuleiro(matriz);

        return 0;
    }

    return matriz;
}

//******************** CAMINHOS ********************

int verificaCoordenada(int **matriz, Personagem *personagem){

    int x = personagem->x;
    int y = personagem->y;

    //Verifica se o personagem está no ponto de chegada
    if(matriz[x][y] == CHEGADA){
        return 1;
    }

    int direcoes[4][2] = {
        {x, y + 1}, //Direita
        {x + 1, y}, //Cima
        {x, y - 1}, //Esquerda
        {x - 1, y} //Baixo
    };

    //Número de direções válidas para percorrer a partir do ponto
    int numeroDirecoes = 0;

    //Classifica se é uma encruzilhada
    for(int i = 0; i < 4; i++){
        if(matriz[direcoes[i][0]][direcoes[i][1]] == CAMINHO_LIVRE){
            personagem->x = direcoes[i][0]; //Coordenada do personagem atualizadas
            personagem->y = direcoes[i][1];
            numeroDirecoes++;
        }
    }

    //Classifica o ponto como encruzilhada ou ponto para andar
    if(numeroDirecoes == 0){
        //voltar
    }else if(numeroDirecoes == 1){
        matriz[x][y] = CAMINHO_PERCORRIDO;
        caminhos[x][y] = ;
    }else{
        caminhos[x][y] = numeroDirecoes;
    }

    return 0;
}