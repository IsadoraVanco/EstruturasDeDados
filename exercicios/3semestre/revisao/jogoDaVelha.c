/*
Faça um programa para determinar a próxima jogada em um Jogo
da Velha. Assumir que o tabuleiro é representado por uma matriz
de 3x3, onde cada posição representa uma das casas do tabuleiro.
A matriz pode conter os seguintes valores: -1, 0, 1 (representando
respectivamente uma casa contendo uma peça minha (-1), uma
casa vazia do tabuleiro (0), e uma casa contendo uma peça do meu
oponente (1)).
*/
#include <stdio.h>

int main(){
    int tabuleiro[3][3];
    int acabou = 0;
    int jogador = 1;
    int jogadasPossiveis = 9;
    int x, y;

    //inicializa o jogo
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //mostra o primiero tabuleiro
    printf("\n   [0] [1] [2]\n");
    for(int i = 0; i < 3; i++){
        printf("[%d]  ", i);
        for(int j = 0; j < 3; j++){
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    while(!acabou){
        
        printf("\nVez do JOGADOR %d \n ", jogador);

        printf("Digite a coordenada (ex. 0 0): ");
        scanf("%d %d", &x, &y);
        
        //considerando que tudo vai dar certo :)
        tabuleiro[x][y] = jogador;
        jogadasPossiveis--;

        //mostra o tabuleiro
        printf("   [0] [1] [2]\n");
        for(int i = 0; i < 3; i++){
            printf("[%d]  ", i);
            for(int j = 0; j < 3; j++){
                printf("%d  ", tabuleiro[i][j]);
            }
            printf("\n");
        }

        int condicao1 = tabuleiro[x][0] == tabuleiro[x][1] && tabuleiro[x][0] == tabuleiro[x][2];
        int condicao2 = tabuleiro[0][y] == tabuleiro[1][y] && tabuleiro[0][y] == tabuleiro[2][y];
        int condicao3 = ((x == 0 && y == 0) || (x == 2 && y == 2)) && (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]);
        int condicao4 = ((x == 2 && y == 0) || (x == 0 && y == 2)) && (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]);

        if(condicao1 || condicao2 || condicao3 || condicao4){
            acabou = 1;

            printf("\nJOGADOR %d GANHOU!!!\n ", jogador);
        }else if(jogadasPossiveis == 0){
            acabou = 1;

            printf("\nVELHA !!! :) \n");
        }

        jogador *= -1; // muda o jogador
    }

    return 0;
}