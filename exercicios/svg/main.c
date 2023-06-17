//Isso é uma tentativa para criar um arquivo SVG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"

//começaremos informando os parametros dos elementos do SVG
// por meio dos comandos de 'svg.h'
int main(int argc, char const *argv[]){
    ArqSvg arquivo = abreEscritaSvg("arquivo");
    char decoImagens[200]; 
    char decoTexto[200];

    // arrumar gambiarra :( "NULL"
    preparaDecoracao(arquivo, decoImagens, 200, "blue", "yellow", 4, -1, 0.5, 0.9);
    escreveRetanguloSvg(arquivo, 0, 0, 5, 10, decoImagens);

    escreveRetanguloSvg(arquivo, 50, 0, 10, 10, "NULL");

    preparaDecoracao(arquivo, decoImagens, 200, "red", "pink", 2, 1, -1, -1);
    escreveCirculoSvg(arquivo, 30, 40, 20, decoImagens);

    escreveLinhaSvg(arquivo, 0, 0, 70, 70, "NULL");
    escreveTextoSvg(arquivo, 2, 88, 180, "HELLO WORLD!", "NULL");

    preparaDecoracaoTexto(arquivo, decoTexto, 200, "sans-serif", FS_ITALIC, FW_BOLD, 14, "green", TA_START);
    escreveTextoSvg(arquivo, 40, 20, 0, "TESTE", decoTexto);

    fechaSvg(arquivo);    
    return 0;
}