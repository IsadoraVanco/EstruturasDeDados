/*
Faça um programa que leia/gere uma matriz 4x4 e transforme-a
em uma matriz triangular inferior, ou seja, atribuindo zero a todos
os elementos acima da diagonal principal. Imprima a matriz
original e a matriz transformada.
*/
#include <stdio.h>

int main(){
    int matriz[4][4];

    //leitura dos elementos
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz inicial\n\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //Modifica o triângulo
    for(int i = 0; i < 4; i++){
        for(int j = 3; j > i; j--){
            matriz[i][j] = 0;
        }
    }

    printf("\nMatriz final\n\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}