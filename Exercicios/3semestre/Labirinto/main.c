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
    Personagem personagem = {0};

    //Inicia a pilha de caminho percorrido
    personagem.caminhos = criaPilha();
    
    //Le o labirinto e retorna o ponteiro para a matriz alocada
    int **tabuleiro = armazenaTabuleiro("labirinto.txt", &personagem);

    if(!tabuleiro){
        return 1;
    }

    //Loop andando no caminho
    do{
        //Limpa a tela
        clear();

        //Mostra o tabuleiro 
        mostraTabuleiro(tabuleiro);
        
        //Verifica se ele andará ou encerrará
        acabou = verificaCoordenada(tabuleiro, &personagem);

        //Espera
        delay(200);

    }while(!acabou);

    //Mostra todo o caminho percorrido
    mostraCaminho(personagem.caminhos);
    mostraMatriz();

    apagaPilha(personagem.caminhos);
    apagaTabuleiro(tabuleiro);
    apagaCaminhos();

    return 0;
}
