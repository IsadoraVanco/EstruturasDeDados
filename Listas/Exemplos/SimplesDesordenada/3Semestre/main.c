/**
 * @file main.c
 * @brief Teste para a lista Simples Desordenada
*/

#include <stdio.h>
#include "listaSimplesDesordenada.h"

int main(int argc, char const *argv[]){

    Lista *novaLista = inicializarLista();

    inserirNaPosicao(novaLista, 0, 3333);
    inserirFim(novaLista, 4444);
    inserirInicio(novaLista, 1111);
    inserirNoMeio(novaLista, 3434, 3333);

    removerInicio(novaLista);
    mostraLista(novaLista);
    removerPosicao(novaLista, 8);
    removerFim(novaLista);
    mostraLista(novaLista);
    removerMeio(novaLista, 3333);
    mostraLista(novaLista);

    apagarLista(novaLista);

    return 0;
}
