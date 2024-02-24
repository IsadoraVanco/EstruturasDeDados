/**
 * @brief Funções de manipulação de diretórios
*/

#include "diretorios.h"
#include <stdio.h>


int criaPasta(char* nomePasta){
    printf("Criando pasta %s...\n", nomePasta);

    #ifdef _WIN32
        if (mkdir(nomePasta) != 0) {
            printf("ERRO ao criar pasta\n");

            return 1;
        }
        return 0;

    #else
        //0777 é o número octal de permissões para as mudanças na pasta (Linux)
        if (mkdir(nomePasta, 0777) != 0) {
            printf("ERRO ao criar pasta\n");

            return 1;
        }
        return 0;

    #endif
}