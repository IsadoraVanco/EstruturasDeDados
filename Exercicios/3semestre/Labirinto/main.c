#include <stdio.h>
#include "pilha.h"
#include "arquivo.h"
#include "labirinto.h"

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

int main(int argc, char const *argv[]){
    //Le o labirinto e retorna o ponteiro para a matriz alocada
    int *tabuleiro = leArquivo();

    if(!tabuleiro){
        return 1;
    }

    //Loop andando no caminho
    do{
        //Mostra o tabuleiro 
        mostraTabuleiro(tabuleiro);

        //Verifica se há outros caminhos possíveis

        //Anda uma casa ou encerra o programa

        delay(500);
        acabou = 1;
    }while(!acabou);

    encerraTabuleiro(tabuleiro);

    return 0;
}
