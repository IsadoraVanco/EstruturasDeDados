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
        
        //Anda para uma posição válida
        // acabou = verificaCoordenada(tabuleiro, &coordenadasPersonagem, caminhoPercorrido);

        //Espera
        delay(200);
        acabou = 1;

    }while(!acabou);

    //Mostra todo o caminho percorrido
    mostraCaminho(personagem.caminhos);

    apagaPilha(personagem.caminhos);
    apagaTabuleiro(tabuleiro);

    return 0;
}
