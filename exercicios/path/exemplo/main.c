// isso é uma tentativa de criar uma manipulação de caminhos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

int main(int argc, char const *argv[]){
    //inicialmente, será estático
    char fullPath[100];
    char path[100]; 
    char normPath[100];
    char fileName[20];
    char* teste = "aaa\\bb\\";
    
    strcpy(fullPath, argv[0]);
    
    int lenFullPath = strlen(teste); //dps mudar para fullpath
    int lenPath, lenNormPath, lenFileName = 0; 
    
    getPath(teste, path, &lenPath);
    normalizePath(path, normPath, &lenNormPath);
    getFileName(teste, fileName, &lenFileName);

    // *******************************************************
    // inicialmente estático
    char fullTeste[50];
    char* pathTeste = "\\a";
    char* fileTeste = "c.txt";
    int lenFullTeste = 0;

    joinFilePath(pathTeste, fileTeste, fullTeste, &lenFullTeste);
    
    // *******************************************************
    // inicialmente estático
    char pathResultante[50];
    char FileResultante[50];
    char ExtResultante[50];

    int lenPathRes, lenFileRes, lenExtRes = 0;

    splitPath(fullTeste, pathResultante, &lenPathRes, FileResultante, &lenFileRes, ExtResultante, &lenExtRes);

    // *******************************************************
    printf("\n******** TESTE *********\n");
    printf("fullpath: %s => %d \n", teste, lenFullPath);
    printf("path: %s => %d \n", path, lenPath);
    printf("normPath: %s => %d \n", normPath, lenNormPath);
    printf("fileName: %s => %d \n", fileName, lenFileName);

    printf("\n******* TESTE 2 ********\n");
    printf("joinPath: %s => %d \n", fullTeste, lenFullTeste);

    printf("\n******* TESTE 3 ********\n");
    printf("=> splitPath: (join)\n");
    printf("path: %s => %d \n", pathResultante, lenPathRes);
    printf("arquivo: %s => %d \n", FileResultante, lenFileRes);
    printf("extensao: %s => %d \n", ExtResultante, lenExtRes);

    return 0;
}