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
    fputs("<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 20010904//EN'\n", arquivo);
    fputs("\t'http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd'>\n", arquivo);
    fputs("<svg xmlns='http://www.w3.org/2000/svg'\n", arquivo);
    fputs("\txmlns:xlink='http://www.w3.org/1999/xlink' xml:space='preserve'\n", arquivo);
    fputs("\twidth='500px' height='500px'\n \tviewBox='-20 -20 300 300'\n", arquivo);
    fputs("\tzoomAndPan='disable'\n \tstyle='background-color:grey'>\n\n", arquivo);   

    // printf("inicio\n");
    //retorna o ponteiro para o arquivo
    return arquivo;
}

void preparaDecoracao(ArqSvg fsvg, char* deco, int decoLen, char *corBorda, char *corPreenchimento,
	double larguraBorda, double transparencia, double transparenciaPreenchimento, double transparenciaBorda){
    // pq precisa do argumento fsvg? chama a função de escreve aqui dentro?
    //deco[decoLen] = vetor de decoração ??

    int indice = 0;
    char texto[decoLen];
    char valor[20];

    //limpa o vetor de decoração 
    // for(int i = 0; i < decoLen; i++){
    //     strcpy(&deco[i], "");
    // }
    // strcpy(deco, "");
    strcpy(texto, "");
    
    //faz comparação e atribuição
    if(strcmp(corBorda, "NULL") != 0){ //caso o atributo não seja NULL, adiciona no vetor 
        strcat(texto, "stroke='");
        strcat(texto, corBorda);
        strcat(texto, "' ");
        // char* cb = texto;
        // strcpy(&deco[indice], cb);
        // indice++;
    }
    if(strcmp(corPreenchimento, "NULL") != 0){
        strcat(texto, "fill='");
        strcat(texto, corPreenchimento);
        strcat(texto, "' ");
        // char* cp = texto;
        // strcpy(&deco[indice], cp);
        // indice++;
    }
    if(larguraBorda >= 0){
        strcat(texto, "stroke-width='");
        sprintf(valor, "%lf", larguraBorda);
        strcat(texto, valor);
        strcat(texto, "' ");
        // char* lb = texto;
        // strcpy(&deco[indice], lb);
        // indice++;
    }
    if(transparencia >= 0){
        strcat(texto, "opacity='");
        sprintf(valor, "%lf", transparencia);
        strcat(texto, valor);
        strcat(texto, "' ");
        // char* t = texto;
        // strcpy(&deco[indice], t);
        // indice++;
    }
    if(transparenciaPreenchimento >= 0){
        strcat(texto, "fill-opacity='");
        sprintf(valor, "%lf", transparenciaPreenchimento);
        strcat(texto, valor);
        strcat(texto, "' ");
        // char* tp = texto;
        // strcpy(&deco[indice], tp);
        // indice++;
    }
    if(transparenciaBorda >= 0){
        strcat(texto, "stroke-opacity='");
        sprintf(valor, "%lf", transparenciaBorda);
        strcat(texto, valor);
        strcat(texto, "' ");
        // char* tb = texto;
        // strcpy(&deco[indice], tb);
        // indice++;
    }

    // for(int i = 0; i < decoLen; i++){
    //     printf("%s ui\n", &deco[i]);
    // }
    // fputs(texto, fsvg);
    // deco = texto;    
    strcpy(deco, texto);
    // printf("%s\n", deco);
   
}

void escreveCirculoSvg(ArqSvg fsvg, double xc, double yc, double r, char *deco){

    char texto[350];
    char valor[20];

    printf("cir\n");
    //faz as conversões para string 
    strcpy(texto, ""); //garante que não terá lixo 
    strcat(texto, "\t<circle cx='");
    sprintf(valor, "%lf", xc);
    strcat(texto, valor);
    strcat(texto, "' cy='");
    sprintf(valor, "%lf", yc);
    strcat(texto, valor);
    strcat(texto, "' r='");
    sprintf(valor, "%lf", r);
    strcat(texto, valor);
    strcat(texto, "' ");

    // printf("%s", texto);

    // se o vetor deco for NULL, não tem decoração
    if(strcmp(deco, "NULL") != 0){
        strcat(texto, deco);
        printf("cir\n");
        // printf("ei %s", texto);
    }

    fputs(texto, fsvg);
    fputs("></circle>\n", fsvg);
}

void escreveRetanguloSvg(ArqSvg fsvg, double x, double y, double larg, double alt, char *deco){

    char texto[350];
    char valor[20];

    printf("ret2\n");
    //faz as conversões para string 
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
    
    printf("%s\n", texto);

    printf("%s\n", deco);
    //se o vetor deco for NULL, não tem decoração
    if(strcmp(deco, "NULL") != 0){
        strcat(texto, deco);
        printf("ret\n");
        // printf("ei %s", texto);
    }

    fputs(texto, fsvg);
    fputs("></rect>\n", fsvg);

    // printf("adicionado rect\n");
}

void escreveLinhaSvg(ArqSvg fsvg, double x1, double y1, double x2, double y2, char *deco){

    char texto[350];
    char valor[20];

    printf("lin2\n");
    //faz as conversões para string 
    strcpy(texto, ""); //garante que não terá lixo 
    strcat(texto, "\t<line x1='");
    sprintf(valor, "%lf", x1);
    strcat(texto, valor);
    strcat(texto, "' y1='");
    sprintf(valor, "%lf", y1);
    strcat(texto, valor);
    strcat(texto, "' x2='");
    sprintf(valor, "%lf", x2);
    strcat(texto, valor);
    strcat(texto, "' y2='");
    sprintf(valor, "%lf", y2);
    strcat(texto, valor);
    strcat(texto, "' ");

    // printf("%s", texto);

    //se o vetor deco for NULL, não tem decoração
    if(strcmp(deco, "NULL") != 0){
        strcat(texto, deco);
        printf("lin\n");
        // printf("ei %s", texto);
    }

    fputs(texto, fsvg);
    fputs("/>\n", fsvg);

}

void preparaDecoracaoTexto(ArqSvg fsvg, char *deco, int decoLen, char *fontFamily, char *fontStyle,
    char *fontWeight, double fontSize, char *fontColor, char *textAnchor){
    // pq precisa do argumento fsvg?

    int indice = 0;
    char texto[decoLen];
    char valor[20];

    strcpy(texto, "");
    
    if(strcmp(fontFamily, "NULL") != 0){ //caso o atributo não seja NULL, adiciona no vetor 
        strcat(texto, "font-family='");
        strcat(texto, fontFamily);
        strcat(texto, "' ");
        // char* cb = texto;
        // strcpy(&deco[indice], cb);
        // indice++;
    }
    if(strcmp(fontStyle, "NULL") != 0){
        strcat(texto, "font-style='");
        strcat(texto, fontStyle);
        strcat(texto, "' ");
        // char* cp = texto;
        // strcpy(&deco[indice], cp);
        // indice++;
    }
    if(strcmp(fontWeight, "NULL") != 0){
        strcat(texto, "font-weight='");
        strcat(texto, fontWeight);
        strcat(texto, "' ");
        // char* cp = texto;
        // strcpy(&deco[indice], cp);
        // indice++;
    }
    //faz comparação e atribuição
    if(fontSize >= 0){
        strcat(texto, "font-size='");
        sprintf(valor, "%lf", fontSize);
        strcat(texto, valor);
        strcat(texto, "' ");
        // char* lb = texto;
        // strcpy(&deco[indice], lb);
        // indice++;
    }
    if(strcmp(fontColor, "NULL") != 0){
        strcat(texto, "fill='");
        strcat(texto, fontColor);
        strcat(texto, "' ");
        // char* cp = texto;
        // strcpy(&deco[indice], cp);
        // indice++;
    }
    if(strcmp(textAnchor, "NULL") != 0){
        strcat(texto, "text-anchor='");
        strcat(texto, textAnchor);
        strcat(texto, "' ");
        // char* cp = texto;
        // strcpy(&deco[indice], cp);
        // indice++;
    }
    

    // for(int i = 0; i < decoLen; i++){
    //     printf("%s ui\n", &deco[i]);
    // }
    // fputs(texto, fsvg);
    // deco = texto;    
    strcpy(deco, texto);
    // printf("%s\n", deco);
   

}

void escreveTextoSvg(ArqSvg fsvg, double x, double y, char *txt, char *decoTxt){
    
    char texto[350];
    char valor[20];

    printf("txt2\n");
    //faz as conversões para string 
    strcpy(texto, ""); //garante que não terá lixo 
    strcat(texto, "\t<text x='");
    sprintf(valor, "%lf", x);
    strcat(texto, valor);
    strcat(texto, "' y='");
    sprintf(valor, "%lf", y);
    strcat(texto, valor);
    strcat(texto, "' ");
    

    //se o vetor deco for NULL, não tem decoração
    if(strcmp(decoTxt, "NULL") != 0){
        strcat(texto, decoTxt);
        printf("txt\n");
        // printf("ei %s", texto);
    }

    // printf("%s", texto);
    // fputs(texto, fsvg);

    fputs(texto, fsvg);
    strcpy(texto, ">");
    strcat(texto, txt);
    strcat(texto, "</text>\n");

    fputs(texto, fsvg);
}

void fechaSvg(ArqSvg fsvg){
    
    fputs("\n</svg>", fsvg);
    fclose(fsvg);
}