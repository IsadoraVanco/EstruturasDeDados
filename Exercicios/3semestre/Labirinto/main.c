#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
// #include "arquivo.h"
// #include "labirinto.h"

//Define o sistema que está utilizando
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#define TAMANHO_MINIMO_TABULEIRO 4

/*
    Caracteres de conversão da leitura do mapa
*/
#define CAMINHO_LIVRE 0 
#define PAREDE 1
#define PERSONAGEM 2
#define CHEGADA 3
#define CAMINHO_EXPLORADO 8 
#define CAMINHO_PERCORRIDO 9

/*
    Caracteres que vão compor o mapa
*/
#define DESENHO_CAMINHO_LIVRE ' '
#define DESENHO_CAMINHO_PERCORRIDO '.'
#define DESENHO_PERSONAGEM '@'
#define DESENHO_PAREDES '#'
#define DESENHO_CHEGADA 'x'

//VARIAVEIS GLOBAIS
int tamanhoLabirinto = 0;
int acabou = 0;

/*
Faz o delay de um tempo em milissegundos.
*/
void delay(int tempo){
    #ifdef WIN32
    //windows
    Sleep(tempo);
    #else
    //linux
    usleep(1000 * tempo);
    #endif
}

/*
    Limpa o terminal
*/
void clear(){
    #ifdef WIN32
    //windows
    system("cls");
    #else
    //linux
    system("clear");
    #endif
}

//labirinto
/*
    Representa um ponto no mapa
*/
typedef struct {
    int x, y;
}Ponto;

int ehBorda(int x, int y){
    return x == 0 || x == (tamanhoLabirinto - 1) || 
            y == 0 || y == (tamanhoLabirinto - 1);
}

int faltaBorda(int x, int y, int ponto){
    return ehBorda(x, y) && ponto != PAREDE;
}

void mostraTabuleiro(int **matriz){
    for(int i = 0; i < tamanhoLabirinto; i++){
        for(int j = 0; j < tamanhoLabirinto; j++){
            char desenho;

            switch(matriz[i][j]){
                case PAREDE:
                    desenho = DESENHO_PAREDES;
                    break;
                case CAMINHO_LIVRE || CAMINHO_EXPLORADO:
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

void apagaTabuleiro(int** matriz){
    for(int i = 0; i < tamanhoLabirinto; i++){
        free(matriz[i]);
    }

    free(matriz);
}

/*
    Verifica onde está o 
*/
int procuraPersonagem(){

}

//arquivo

int **leArquivo(char *nomeArquivo, Ponto *coordenadaPersonagem){
    FILE *arquivo = fopen(nomeArquivo, "r");

    if(!arquivo){
        printf("ERRO: Arquivo %s não encontrado\n", nomeArquivo);
        return 0;
    }

    fscanf(arquivo, "%d", &tamanhoLabirinto);
    // printf("tamanho: %d\n", tamanhoLabirinto);

    //Verifica se tem um tamanho mínimo 
    if(tamanhoLabirinto < TAMANHO_MINIMO_TABULEIRO){
        printf("ERRO: O labirinto não possui um tamanho mínimo\n");
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
            // printf("[%d][%d] %d", i, j, matriz[i][j]);

            if(faltaBorda(i, j, matriz[i][j])){ //Verifica as bordas
                printf("ERRO: O labirinto não possui todas as bordas\n");
                fclose(arquivo);
                free(matriz);

                return 0;
            }else if(matriz[i][j] == CHEGADA && !temPartida){ //Armazena o ponto de chegada (primeiro que encontrar)
                temChegada = 1;
            }else if(matriz[i][j] == PERSONAGEM && !temPartida){ //Armazena o ponto de partida (primeiro que encontrar)
                coordenadaPersonagem.x = i;
                coordenadaPersonagem.y = j;

                temPartida = 1;
            }
        }
        // printf("\n");
    }

    fclose(arquivo);
    
    //Verifica se a matriz tem os pontos de partida e chegada
    if(!temChegada || !temPartida){
        free(matriz);
        printf("ERRO: O labirinto não possui ponto de chegada e/ou ponto de partida definidos\n");

        return 0;
    }

    return matriz;
}


int main(int argc, char const *argv[]){
    //Guarda as coordenadas do personagem
    Ponto *coordenadaPersonagem = (Ponto *) malloc(sizeof(Ponto));

    //Le o labirinto e retorna o ponteiro para a matriz alocada
    int **tabuleiro = leArquivo("labirinto.txt", coordenadaPersonagem);

    if(!tabuleiro){
        free(coordenadaPersonagem);
        return 1;
    }

    Stack caminhoPercorrido = newStack();

    //Loop andando no caminho
    do{
        //Limpa a tela
        clear();

        //Mostra o tabuleiro 
        mostraTabuleiro(tabuleiro);
        
        //Adiciona a coordenada na pilha
        push(caminhoPercorrido, coordenadaPersonagem);

        //Verifica se há outros caminhos possíveis

        //Anda uma casa ou encerra o programa


        //Espera
        delay(500);

        // acabou = 1;
    }while(!acabou);
    // printf("mostra\n");
    // mostraTabuleiro(tabuleiro);

    deleteStack(caminhoPercorrido);
    apagaTabuleiro(tabuleiro);

    return 0;
}
