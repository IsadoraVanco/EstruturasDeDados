/*
    Implementações de todas as funções para manipulação
    de arquivo.
*/
#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "labirinto.h"

int* leArquivo(){
    FILE *arquivo = fopen("labirinto.txt", "r");

    if(!arquivo){
        printf("ERRO: Arquivo labirinto.txt não encontrado\n");
        return 0;
    }

    fscanf(arquivo, "%d", &tamanhoLabirinto);

    //Verifica se tem um tamanho mínimo 
    if(tamanhoLabirinto < 4){
        printf("ERRO: O labirinto não possui um tamanho mínimo de 4\n");
        return 0;
    }

    int* matriz = malloc(tamanhoLabirinto * tamanhoLabirinto * sizeof(int));

    //Leitura e armazenamento da matriz
    for(int i = 0; i < tamanhoLabirinto; i++){
        for(int j = 0; j < tamanhoLabirinto; j++){
            fscanf(arquivo, "%d", &matriz[i][j]);

            if(faltaBorda(i, j, matriz[i][j])){ //Verifica as bordas
                printf("ERRO: O labirinto não possui todas as bordas\n");
                fclose(arquivo);
                free(matriz);

                return 1;
            }else if(matriz[i][j] == CHEGADA){ //Armazena o ponto de chegada
                setChegada(i, j);
            }else if(matriz[i][j] == PARTIDA){ //Armazena o ponto de partida
                setPartida(i, j);
            }
        }
    }

    fclose(arquivo);
    
    //Verifica se a matriz tem os pontos de partida e chegada
    if(!temChegada() && !temPartida()){
        printf("ERRO: O labirinto não possui ponto de chegada e/ou ponto de partida definidos\n");
        free(matriz);

        return 1;
    }

    return matriz;
}

