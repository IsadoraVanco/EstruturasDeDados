// isso é uma tentativa de criar uma manipulação de caminhos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

int main(int argc, char const *argv[]){
    //inicialmente, será estático
    char fullPath[100];
    char path[100]; 
    
    char* teste = "\\\\aaa\\bb\\";
    
    strcpy(fullPath, argv[0]);
    int lenPath = 0; 
    int lenFullPath = strlen(teste); //dps mudar para fullpath

    getPath(teste, path, lenPath);
    
    printf("\n******** TESTE *********\n");
    printf("fullpath: %s\n", teste);
    printf("lenFullPath: %d\n", lenFullPath);
    printf("path: %s\n", path);

    // printf("%d \n", lenPath);

    return 0;
}