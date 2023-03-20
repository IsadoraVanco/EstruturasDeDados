// isso é uma tentativa de criar uma manipulação de caminhos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

void getPath(char *fullPath, char *path, int lenPath){
    // para que o lenPath?
    printf("********* GETPATH ********\n");

    char* ultimoCaractere = fullPath + (strlen(fullPath) - 1);

    // printf("%d\n", strrchr(fullPath, '\\'));
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
                
                //retira a ultima barra (apenas para procurar)
                char novoCaminho[nElementos - 1];
                strncpy(novoCaminho, fullPath, nElementos - 2); //copia sem a ultima barra
                novoCaminho[nElementos - 1] = '\0';
                printf("NOVO caminho %s => %d\n", novoCaminho, strlen(novoCaminho));
                
                //procura a penultima barra (1) tentativa
                // printf("ultimo %d\n", ptrUltimo);
                // ptrUltimo = strrchr(fullPath, '\\');
                // posicaoUltima = ptrUltimo - fullPath;
                // printf("NOVO ultimo %d\n", ptrUltimo);
                // nElementos = posicaoUltima + 1;
                // printf("NOVA ultima barra em %d\n", posicaoUltima);

                //(2) tentativa 
                while(){ //começa da ultima barra e vai até a anterior
                    
                }
                
                // strcpy(caminho, novoCaminho);
                // strncpy(caminho, fullPath, nElementos);
                // caminho[nElementos] = '\0';
                // strcpy(path, caminho);

                strcpy(path, "");

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
}

void getFileName(char *fullPath, char *fileName, char *lenFileName){

}

void splitPath(char *fullPath, char *path, int lenPath, 
    char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq){


}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath){

}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath){

}



void normalizePath(char *path, char *normPath, int lenNormPath){

}