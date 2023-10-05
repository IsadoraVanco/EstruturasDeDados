#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

//******************** CONSTANTES ********************

#define TAMANHO_MINIMO_TABULEIRO 4

/*
    Caracteres de conversão para a leitura e impressão do mapa (vísiveis)
*/
#define CAMINHO_LIVRE 0 
#define PAREDE 1
#define PERSONAGEM 2
#define CHEGADA 3
#define CAMINHO_PERCORRIDO 9 //Caminho que está na pilha (rastro)

/*
    Caracteres que vão definir caminhos já percorridos no labirinto (não visíveis)
*/
#define BLOQUEIO 4 //Flag para não passar pelo caminho

/*
    Caracteres para mostrar o tabuleiro
*/
#define DESENHO_CAMINHO_LIVRE ' '
#define DESENHO_PAREDES '#'
#define DESENHO_PERSONAGEM '@'
#define DESENHO_CHEGADA 'x'
#define DESENHO_CAMINHO_PERCORRIDO '.'

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

    //Aloca um espaço para a matriz do labirinto
    int** matriz = (int **) malloc(tamanhoLabirinto * sizeof(int *));
    for(int i = 0; i < tamanhoLabirinto; i++){
        matriz[i] = (int *) malloc(tamanhoLabirinto * sizeof(int));
    }

    //Inicializa a matriz de caminhos percorridos
    caminhos = malloc(tamanhoLabirinto * sizeof(int *));
    for(int i = 0; i < tamanhoLabirinto; i++){
        caminhos[i] = calloc(tamanhoLabirinto, sizeof(int));
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
                caminhos[i][j] = BLOQUEIO; //Inicia com uma flag na chegada
                temChegada = 1;
            }else if(matriz[i][j] == PERSONAGEM && !temPartida){ //Armazena o ponto de partida (primeiro que encontrar)
                personagem->x = i;
                personagem->y = j;

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

//******************** CAMINHOS ********************

int verificaCoordenada(int **matriz, Personagem *personagem){

    int x = personagem->x;
    int y = personagem->y;

    //Verifica se o personagem está no ponto de chegada
    if(matriz[x][y] == CHEGADA){
        return 1;
    }

    //Verifica se o ponto com o deslocamento anterior é válido, se não, testa outros


    int direcoes[4][2] = {
        {x, y + 1}, //Direita
        {x + 1, y}, //Baixo
        {x, y - 1}, //Esquerda
        {x - 1, y} //Cima
    };

    //Número de direções válidas para percorrer a partir do ponto
    int numeroDirecoes = 0;

    //Classifica o tipo do caminho e atualiza a coordenada caso haja um válido
    for(int i = 0; i < 4; i++){
        if(matriz[direcoes[i][0]][direcoes[i][1]] == CAMINHO_LIVRE &&
            caminhos[direcoes[i][0]][direcoes[i][1]] != BLOQUEIO){
            //Atualiza as novas coordenadas do personagem
            personagem->x = direcoes[i][0]; 
            personagem->y = direcoes[i][1];

            //Atualiza a direção que está seguindo (dx dy)

            numeroDirecoes++;
        }
    }

    //mudar o ponto no personagem (depois)
    Ponto ponto = {personagem->x, personagem->y};

    //Atualiza o mapa de caminhos  
    caminhos[x][y] = numeroDirecoes;
    
    //Adiciona o personagem na matriz do labirinto
    matriz[personagem->x][personagem->y] = PERSONAGEM;
    //Adiciona a nova coordenada na Pilha
    adicionaPilha(personagem->caminhos, &ponto);

    if(numeroDirecoes == 0){ //Caminho sem saída ou encruzilhada já percorrida
        
        //voltar => procurar uma nova encruzilhada ou encerrar
        //retira o rastro da matriz
        //diminui a encruzilhada e encerra
        //adiciona um bloqueio 
    }else if(numeroDirecoes == 1){ //Caminho reto
        matriz[x][y] = CAMINHO_PERCORRIDO; //coloca um rastro no mapa
    }else{ //Encruzilhada

        //verifica se algum ponto disponivel é o ponto que estava (voltando)
    }

    return 0;
}

void apagaCaminhos(){
    for(int i = 0; i < tamanhoLabirinto; i++){
        free(caminhos[i]);
    }

    free(caminhos);
}

void mostraMatriz(){
    printf("\nMATRIZ AUXILIAR DE CAMINHOS\n\n");

    for(int i = 0; i < tamanhoLabirinto; i++){
        for(int j = 0; j < tamanhoLabirinto; j++){
            printf("%d ", caminhos[i][j]);
        }
        printf("\n");
    }
}