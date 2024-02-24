/**
 * @brief Funções do arquivo .dot implementadas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dot.h"


/************************************************************
 * Funções básicas
*************************************************************/

ARQUIVODOT criarNovoArquivo(char *nomeArquivo){
    char nome[strlen(nomeArquivo) + 5];
    sprintf(nome, "%s.dot", nomeArquivo);

    FILE *novo = fopen(nome, "w");

    return novo;
}

void inicializar(ARQUIVODOT arquivo, char *tipo){
    fprintf(arquivo, "%s grafo {\n", tipo);      
    fflush(arquivo);   // Escreve os textos do buffer no arquivo
}

void finalizar(ARQUIVODOT arquivo){
    fprintf(arquivo, "}\n");      
    fclose(arquivo);   // Escreve os textos do buffer no arquivo
}

/************************************************************
 * Funções dos Nodes
*************************************************************/

void configurarNodes(ARQUIVODOT arquivo, char *forma, char *corBorda, 
    char *corFundo, char *corFonte, char *nomeFonte, int tamanhoFonte){

    fprintf(arquivo, "\tnode [shape=\"%s\", style=filled, color=\"%s\" fillcolor=\"%s\" ", forma, corBorda, corFundo);
    fprintf(arquivo, "fontcolor=\"%s\" fontname=\"%s\" fontsize=%d];\n", corFonte, nomeFonte, tamanhoFonte);
    fflush(arquivo);   // Escreve os textos do buffer no arquivo
}

void adicionarNovoNode(ARQUIVODOT arquivo, char *nome, char *texto, 
    char *forma, char *corBorda, char *corFundo, char *corFonte){
    
    fprintf(arquivo, "\t\"%s\" [label= \"%s\" shape=\"%s\" ", nome, texto, forma);
    fprintf(arquivo, "fontcolor=\"%s\" color=\"%s\" fillcolor=\"%s\"];\n", corFonte, corBorda, corFundo);
    fflush(arquivo);   // Escreve os textos do buffer no arquivo
}

/************************************************************
 * Funções dos Edges
*************************************************************/

void configurarEdges(ARQUIVODOT arquivo, char *forma, char *corBorda, 
    char *corFundo, char *corFonte, char *nomeFonte, int tamanhoFonte){
    
    fprintf(arquivo, "\tedge [shape=\"%s\" color=\"%s\" fillcolor=\"%s\" ",  forma, corBorda, corFundo);
    fprintf(arquivo, "fontcolor=\"%s\" fontname=\"%s\" fontsize=\"%d\"];\n", corFonte, nomeFonte, tamanhoFonte);
    fflush(arquivo);   // Escreve os textos do buffer no arquivo
}

void criarConexaoNodes(ARQUIVODOT arquivo, char *tipo, char *nodePai, 
    char *nodeFilho, char *texto){

    char conexao[5];

    if(strcmp(tipo, TIPO_ARVORE) == 0){
        sprintf(conexao, "->");
    }else{
        sprintf(conexao, "--");
    }

    fprintf(arquivo, "\t%s %s %s [label=\"%s\"];\n", nodePai, conexao, nodeFilho, texto);
    fflush(arquivo);   // Escreve os textos do buffer no arquivo
}

/************************************************************
 * Funções de automatização
*************************************************************/

void criarImagem(char *nomeDot){

    char nomeArqDot[strlen(nomeDot) + 5];
    char nomeArqPng[strlen(nomeDot) + 5];

    sprintf(nomeArqDot, "%s.dot", nomeDot);
    sprintf(nomeArqPng, "%s.png", nomeDot);

    char command[strlen(nomeArqDot) + strlen(nomeArqPng) + 20];

    sprintf(command, "dot -Tpng %s -o %s", nomeArqDot, nomeArqPng);
    system(command);
}