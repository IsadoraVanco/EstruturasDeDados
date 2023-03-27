// isso é uma tentativa de criar uma manipulação de caminhos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

// depois verificar padrão e melhorar o codigo -_-
void getPath(char *fullPath, char *path, int* lenPath){
    // lenPath => transformado em ponteiro para atualizar o valor dele...
    printf("\n********* GETPATH ********\n");

    char* ultimoCaractere = fullPath + (strlen(fullPath) - 1);

    // considerando desde o diretorio raiz 
    if(strrchr(fullPath, '\\') > 0){ //verifica se existe uma barra
        // encontra a primeira ocorrência
        char* ptrPrimeiro = strchr(fullPath, '\\');
        int posicaoPrimeira = ptrPrimeiro - fullPath;
        printf("primeira barra em %d\n", posicaoPrimeira); 

        // encontra a ultima ocorrência
        char* ptrUltimo = strrchr(fullPath, '\\');
        int posicaoUltima = ptrUltimo - fullPath;
        printf("ultima barra em %d\n", posicaoUltima);
        
        //ptr - fullPath => subtrai os endereços de memória apontados por ptr e str. 
        // O resultado é um valor do tipo ptrdiff_t, que representa a diferença entre esses 
        // dois endereços em bytes.

        int posicaoUltimoCaractere = strlen(fullPath) - 1;
        int nElementos = posicaoUltima + 1; //caso o ultimo esteja em 0
        char caminho[nElementos + 1]; //numero de elementos + caractere nulo

        if(posicaoPrimeira == posicaoUltima - 1){ //há apenas as barras // da raíz
            printf("apenas barra da raiz \n");

            strncpy(caminho, fullPath, nElementos);
            caminho[nElementos] = '\0';
            strcpy(path, caminho); //considerando que vai ter o '/0'

        }else if(ptrPrimeiro == ptrUltimo){//há apenas uma barra '/'
            printf("uma barra\n");

            // se for o primeiro ou ultimo caractere = não tem path
            if(ptrPrimeiro == fullPath || ptrPrimeiro == ultimoCaractere){ 
                printf("sem path.\n");

                strcpy(path, "");

            }else{
                strncpy(caminho, fullPath, nElementos);
                caminho[nElementos] = '\0';
                strcpy(path, caminho);

            }
        }else{//se existe ao menos um diretório
            printf("ao menos um dir\n");

            if(posicaoUltima == posicaoUltimoCaractere){ //se a ultima barra for o ultimo caractere
                printf("barra eh o ultimo caractere\n");
                
                //começa do caractere anterior a ultima barra e encontra a barra anterior
                for(int i = strlen(fullPath) - 2; i >= 0; i--){ 
                    if(fullPath[i] == '\\'){
                        posicaoUltima = i;
                        break;
                    }
                }
                printf("NOVA ultima barra em %d\n", posicaoUltima);
                
                nElementos = posicaoUltima + 1;

                //se a barra achada for a primeira e for o primeiro caractere, então não tem path
                if(posicaoPrimeira == posicaoUltima && posicaoPrimeira == 0){ 
                    printf("sem path.");
                    strcpy(path, "");
                }else{
                    strncpy(caminho, fullPath, nElementos);
                    caminho[nElementos] = '\0';
                    strcpy(path, caminho);
                }
            }else{
                strncpy(caminho, fullPath, nElementos);
                caminho[nElementos] = '\0';
                strcpy(path, caminho);
                
            }
        }
    }else{
        printf("sem path.");
        strcpy(path, "");
    }
    *(lenPath) = strlen(path);
}

void normalizePath(char *path, char *normPath, int* lenNormPath){
    // lenNormPath => transformado em int* para modificar o valor
    printf("\n********* NORMALIZEPATH ********\n");
    
    // encontra a ultima barra
    char* ptrUltimo = strrchr(path, '\\');
    int posicaoUltima = ptrUltimo - path;
    int posicaoUltimoCaractere = strlen(path) - 1;
    printf("ultima barra em %d\n", posicaoUltima);
    
    int nElementos = strlen(path);
    char caminho[nElementos];
    
    // se a ultima barra for o ultimo caractere 
    if(posicaoUltima == posicaoUltimoCaractere){
        printf("ultimo caractere\n");

        strncpy(caminho, path, nElementos - 1);
        caminho[nElementos - 1] = '\0';
        strcpy(normPath, caminho);
        
    }else{ //se ja esta normalizado
        strcpy(normPath, path);
    }
    *(lenNormPath) = strlen(normPath);
}

void getFileName(char *fullPath, char *fileName, int *lenFileName){
    // lenFileName => transformado em int* para modificar o valor
    printf("\n********* GETFILENAME ********\n");

    // considerando desde o diretorio raiz 
    if(strrchr(fullPath, '\\') > 0){ //verifica se existe uma barra

        // encontra a ultima barra
        char* ptrUltimo = strrchr(fullPath, '\\');
        int posicaoUltima = ptrUltimo - fullPath;
        printf("ultima barra em %d\n", posicaoUltima);
        
        // int posicaoUltimoCaractere = strlen(fullPath) - 1;
        int nElementos = strlen(fullPath) - posicaoUltima - 1;
        char arquivo[nElementos + 1]; //numero de elementos + caractere nulo

        //verificar se existe uma barra no final
        if(posicaoUltima == strlen(fullPath) - 1){ 
           
            // procura a penultima barra
            for(int i = strlen(fullPath) - 2; i >= 0; i--){ 
                if(fullPath[i] == '\\'){
                    posicaoUltima = i;
                    break;
                }
            }
            printf("NOVA ultima barra em %d\n", posicaoUltima);

            //retira a ultima barra
            nElementos = strlen(fullPath) - posicaoUltima - 2;
        }
        
        strncpy(arquivo, fullPath + posicaoUltima + 1, nElementos);
        arquivo[nElementos] = '\0';
        strcpy(fileName, arquivo);

    }else{ //se não tem barra, não tem diretório, logo é apenas o nome do arquivo
        printf("sem path.");
        strcpy(fileName, fullPath);

    }
    *(lenFileName) = strlen(fileName);
}

void joinFilePath(char *path, char *fileName, char *fullPath, int* lenFullPath){
    // lenFullName => transformado em int* para modificar o valor
    // printf("\n********* JOINFILEPATH ********\n");

    int lenPath = strlen(path);
    int lenFile = strlen(fileName);
    char full[lenFile + lenPath + 1]; //o tamanho de cada string + caractere nulo

    strcpy(full, path);

    // verifica se existe um '/' no final do path e se o path existe
    if(path[lenPath - 1] != '\\' && lenPath > 0){
        strcat(full, "\\");
    }

    strcat(full, fileName);
    strcpy(fullPath, full);

    *(lenFullPath) = strlen(fullPath);
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath){

}

void splitPath(char *fullPath, char *path, int* lenPath, 
    char *nomeArq, int* lenNomeArq, char *extArq, int* lenExtArq){
    // todos len... => transformado em int* para modificar o valor
    printf("\n********* SPLITPATH ********\n");

    getPath(fullPath, path, lenPath);
    getFileName(fullPath, nomeArq, lenNomeArq);

    // encontrar a extensão e separar
    char* ptrUltimo = strrchr(nomeArq, '.'); //ultimo ponto
    int posicaoUltimo = ptrUltimo - nomeArq;
    printf("ultimo ponto em %d\n", posicaoUltimo); 

    if(strrchr(nomeArq, '.') > 0){ //se existe um ponto
        int posicaoUltimoCaractere = strlen(nomeArq) - 1;
        int nElementos = posicaoUltimo + 1; //caso o ultimo esteja em 0
        char ext[nElementos + 1];

        

    }else{
        extArq = "";
        printf("sem extensao\n");
    }
}