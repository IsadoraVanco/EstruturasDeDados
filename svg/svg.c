//Isso é uma tentativa para a criação de um arquivo SVG. Comecemos...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"

ArqSvg abreEscritaSvg(char* fn){
    //fn já estará com a extensão .svg?
    //cria o arquivo para escrita
    char nome[strlen(fn) + 5];
    strcpy(nome, fn);
    strcat(nome, ".svg");

    // printf("o nome do novo arquivo svg eh %s\n", nome);

    FILE* arquivo;
    // abre e escreve no final caso exista, cria caso contrário
    arquivo = fopen(nome, "a");
    // printf("arquivo criado.\n");

    //caso não tenha sido possivel, retorna NULL
    if(arquivo == NULL){
        return NULL;
    }

    //tags iniciais do arquivo SVG
    // fprintf(arquivo, "frase teste\n");
    fputs("<?xml version='1.0' encoding='ISO-8859-1' standalone='no'?>\n", arquivo);
    fputs("<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 20010904//EN'", arquivo);
    fputs("\t'http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd'>\n", arquivo);
    fputs("<svg xmlns='http://www.w3.org/2000/svg'\n", arquivo);
    fputs("\txmlns:xlink='http://www.w3.org/1999/xlink' xml:space='preserve'\n", arquivo);
    fputs("\twidth='500px' height='500px'\n \tviewBox='-20 -20 300 300'\n", arquivo);
    fputs("\tzoomAndPan='disable'\n \tstyle='background-color:grey'>\n\n", arquivo);   

    printf("inicio\n");
    //retorna o ponteiro para o arquivo
    return arquivo;
}

void preparaDecoracao(ArqSvg fsvg, char *deco, int decoLen, char *corBorda, char *corPreenchimento,
	char* larguraBorda, double transparencia, double transparenciaPreenchimento, double transparenciaBorda){
    //deco[decoLen] = vetor de decoração

    //limpa o vetor de decoração 
    strcpy(deco, "");
    char* decos[decoLen]; //vetor com valores 

    //faz tudo a caralhada de comparação e atribuição
    if(strcmp(corBorda, "NULL") != 0){ //caso o atributo não seja NULL, adiciona no vetor 

    }
    if(strcmp(corPreenchimento, "NULL") != 0){

    }
    if(strcmp(larguraBorda, "NULL") != 0){

    }
    if(transparencia >= 0){

    }
    if(transparenciaPreenchimento >= 0){

    }
    if(transparenciaBorda >= 0){

    }

    //modifica o vetor e o arquivo 
                
}

void escreveCirculoSvg(ArqSvg fsvg, double xc, double yc, double r, char *deco){
    //se o vetor deco for NULL, não tem decoração

    //escreve um circulo no fsvg

}

void escreveRetanguloSvg(ArqSvg fsvg, double x, double y, double larg, double alt, char *deco){

    //se o vetor deco for NULL, não tem decoração
    //escreve um retangulo no fsvg
    char texto[350];
    char valor[20];

    strcpy(texto, ""); //garante que não terá lixo 
    strcat(texto, "\t<rect x='");
    sprintf(valor, "%lf", x);
    strcat(texto, valor);
    strcat(texto, "' y='");
    sprintf(valor, "%lf", y);
    strcat(texto, valor);
    strcat(texto, "' width='");
    sprintf(valor, "%lf", larg);
    strcat(texto, valor);
    strcat(texto, "' height='");
    sprintf(valor, "%lf", alt);
    strcat(texto, valor);
    strcat(texto, "' ");

    // printf("%s", texto);
    fputs(texto, fsvg);
    
    // if(strcmp(deco, "NULL") != 0){
    //     for(int i = 0; i < 6; i++){ //até 6 atributos a mais
    //         if(strcmp(deco[i], "") != 0){
    //             fputs(deco[i], fsvg);
    //         }
    //     }
    // }

    fputs("></rect>\n", fsvg);

    // printf("adicionado rect\n");
}

void escreveLinhaSvg(ArqSvg fsvg, double x1, double y1, double x2, double y2, char *deco){
    //se o vetor deco for NULL, não tem decoração

    //escreve um texto no fsvg
}

void preparaDecoracaoTexto(ArqSvg fsvg, char *deco, int decoLen, char *fontFamily, char *fontStyle,
    char *fontWeight, char *fontSize, char *fontColor, char *textAnchor){

        //faz todas as comparações como no prepara decoração pra imagens

        //modifica o vetor de decorações

}

void escreveTextoSvg(ArqSvg fsvg, double x, double y, char *txt, char *decoTxt){
    //insere no fsvg o texto
}

void fechaSvg(ArqSvg fsvg){
    
    fputs("\n</svg>", fsvg);
    fclose(fsvg);
}