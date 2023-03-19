//Isso é uma tentativa para criar um arquivo SVG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"

//começaremos informando os parametros dos elementos do SVG
// por meio dos comandos de 'svg.h'
int main(int argc, char const *argv[]){
    ArqSvg arquivo = abreEscritaSvg("arquivo");

    escreveRetanguloSvg(arquivo, 0, 0, 5, 10, NULL);
    escreveRetanguloSvg(arquivo, 50, 0, 10, 10, NULL);

    fechaSvg(arquivo);    
    return 0;
}