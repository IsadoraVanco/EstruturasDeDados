#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "tabuleiro.h"
#include "tools.h"

//******************** GLOBAIS ********************

int main(int argc, char const *argv[]){
    //Representa se o jogo acabou
    int acabou = 0;
    
    //Guarda as coordenadas do personagem
    Ponto coordenadaPersonagem = {0, 0};

    //Le o labirinto e retorna o ponteiro para a matriz alocada
    int **tabuleiro = armazenaTabuleiro("labirinto.txt", &coordenadaPersonagem);

    if(!tabuleiro){
        return 1;
    }

    //Inicia a pilha de caminho percorrido
    Pilha *caminhoPercorrido = criaPilha();

    //Loop andando no caminho
    do{
        //Limpa a tela
        clear();

        //Mostra o tabuleiro 
        mostraTabuleiro(tabuleiro);
        
        //Verifica se há outros caminhos possíveis
        // acabou = verificaCoordenada(tabuleiro, &coordenadasPersonagem);


        //Espera
        delay(200);
        acabou = 1;

    }while(!acabou);

    //Mostra todo o caminho percorrido
    mostraCaminho(caminhoPercorrido);

    apagaPilha(caminhoPercorrido);
    apagaTabuleiro(tabuleiro);

    return 0;
}
