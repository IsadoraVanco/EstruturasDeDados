//Isso é uma tentativa para a criação de um arquivo SVG. Comecemos...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"

ArqSvg abreEscritaSvg(char* fn){
    //cria o arquivo com a extensão .svg
    char ext[] = {".svg"};
    char nomeArquivo[strlen(fn) + strlen(ext) + 1];
    sprintf(nomeArquivo, "%s%s", fn, ext);

    // abre o arquivo para escrita, caso já exista, substitui
    FILE* arquivo;
    arquivo = fopen(nomeArquivo, "w");

    //caso não tenha sido possivel, retorna NULL
    if(arquivo == NULL){
        printf("!!! ERRO ao criar arquivo SVG !!!\n");
        return NULL;
    }

    //tags iniciais do arquivo SVG
    fputs("<?xml version='1.0' encoding='ISO-8859-1' standalone='no'?>\n", arquivo);
    fputs("<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 20010904//EN'\n", arquivo);
    fputs("\t'http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd'>\n", arquivo);
    fputs("<svg xmlns='http://www.w3.org/2000/svg'\n", arquivo);
    fputs("\txmlns:xlink='http://www.w3.org/1999/xlink' xml:space='preserve'\n", arquivo);
    fputs("\twidth='500px' height='500px'\n \tviewBox='-20 -20 300 300'\n", arquivo);
    fputs("\tzoomAndPan='disable'>\n\n", arquivo);   

    //retorna o ponteiro para o arquivo
    return arquivo;
}

void preparaDecoracao(ArqSvg fsvg, char* deco, int decoLen, char *corBorda, char *corPreenchimento,
	double larguraBorda, double transparencia, double transparenciaPreenchimento, double transparenciaBorda){

    //string para escrever todo o texto 
    char texto[decoLen];
    strcpy(texto, "");
    
    //faz comparação e atribuição dos valores
    //se o valor é NULL, ignora
    if(strcmp(corBorda, "") != 0 && strcmp(corBorda, "NULL") != 0){ 
        sprintf(texto, "stroke='%s' ", corBorda);
    }
    if(strcmp(corPreenchimento, "") != 0 && strcmp(corPreenchimento, "NULL") != 0){
        sprintf(texto, "fill='%s' ", corPreenchimento);
    }
    //se o valor é negativo, ignora
    if(larguraBorda >= 0){ 
        sprintf(texto, "stroke-width='%lf' ", larguraBorda);
    }
    if(transparencia >= 0){
        sprintf(texto, "opacity='%lf' ", transparencia);
    }
    if(transparenciaPreenchimento >= 0){
        sprintf(texto, "fill-opacity='%lf' ", transparenciaPreenchimento);
    }
    if(transparenciaBorda >= 0){
        sprintf(texto, "stroke-opacity='%lf' ", transparenciaBorda);
    }
   
    //copia todo o texto para o vetor de decoração
    strcpy(deco, texto);   
}

void escreveCirculoSvg(ArqSvg fsvg, double xc, double yc, double r, char *deco){

    fprintf(fsvg, "\t<circle cx='%lf' cy='%lf' r='%lf' ", xc, yc, r);

    // se o vetor deco for NULL, não tem decoração
    if(strcmp(deco, "") != 0 && strcmp(deco, "NULL") != 0){
        fprintf(fsvg, "%s", deco);
    }

    fprintf(fsvg, "></circle>\n");
}

void escreveRetanguloSvg(ArqSvg fsvg, double x, double y, double larg, double alt, char *deco){

    fprintf(fsvg, "\t<rect x='%lf' y='%lf' width='%lf' height='%lf' ", x, y, larg, alt);
    
    //se o vetor deco for NULL, não tem decoração
    if(strcmp(deco, "") != 0 && strcmp(deco, "NULL") != 0){
        fprintf(fsvg, "%s", deco);
    }

    fprintf(fsvg, "></rect>\n");
}

void escreveLinhaSvg(ArqSvg fsvg, double x1, double y1, double x2, double y2, char *deco){

    fprintf(fsvg, "\t<line x1='%lf' y1='%lf' x2='%lf' y2='%lf' ", x1, y1, x2, y2);

    //se o vetor deco for NULL, não tem decoração
    if(strcmp(deco, "") != 0 && strcmp(deco, "NULL") != 0){
        fprintf(fsvg, "%s", deco);
    }

    fprintf(fsvg, "/>\n");
}

void preparaDecoracaoTexto(ArqSvg fsvg, char *deco, int decoLen, char *fontFamily, char *fontStyle,
    char *fontWeight, char *fontSize, char *fontColor, char *textAnchor){

    //string para escrever todo o texto 
    char texto[decoLen];
    strcpy(texto, "");
    
    //faz comparação e atribuição dos valores
    //se o valor é NULL, ignora
    if(strcmp(fontFamily, "") != 0 && strcmp(fontFamily, "NULL") != 0){ 
        sprintf(texto, "font-family='%s' ", fontFamily);
    }
    if(strcmp(fontStyle, "") != 0 && strcmp(fontStyle, "NULL") != 0){
        sprintf(texto, "font-style='%s' ", fontStyle);
    }
    if(strcmp(fontWeight, "") != 0 && strcmp(fontWeight, "NULL") != 0){
        sprintf(texto, "font-weight='%s' ", fontWeight);
    }
    if(strcmp(fontSize, "") != 0 && strcmp(fontSize, "NULL") != 0){
        sprintf(texto, "font-size='%s' ", fontSize);
    }
    if(strcmp(fontColor, "") != 0 && strcmp(fontColor, "NULL") != 0){
        sprintf(texto, "fill='%s' ", fontColor);
    }
    if(strcmp(textAnchor, "") != 0 && strcmp(textAnchor, "NULL") != 0){
        sprintf(texto, "text-anchor='%s' ", textAnchor);
    }
    
    //copia todo o texto para o vetor de decoração
    strcpy(deco, texto);
}

void escreveTextoSvg(ArqSvg fsvg, double x, double y, double rotate, char *txt, char *decoTxt){
  
    fprintf(fsvg, "\t<text x='%lf' y='%lf' transform='rotate(%lf, %lf, %lf)' ", x, y, rotate, x, y);
    
    //se o vetor deco for NULL, não tem decoração
    if(strcmp(decoTxt, "") != 0 && strcmp(decoTxt, "NULL") != 0){
        fprintf(fsvg, "%s", decoTxt);
    }

    fprintf(fsvg, ">%s</text>\n", txt);
}

void fechaSvg(ArqSvg fsvg){
    
    fputs("\n</svg>", fsvg);
    fclose(fsvg);
}