#include <stdio.h>
#include <stdlib.h>

int tamanhoTabela = 0;

int* inicializarTabela(int tamanho){
    //considerando que 0 não está no conjunto de dados

    tamanhoTabela = tamanho;
    return calloc(sizeof(int) * tamanho);
}

int funcaoHash(int chave){
    return chave % tamanhoTabela;
}

void inserir(int *tabela, int chave){
    int id = funcaoHash(chave);

    while(tabela[id] != 0){ // busca um espaço vazio
        id = funcaoHash(id + 1);
    }

    tabela[id] = valor;
}

int busca(int tabela[], int chave){
    int id = funcaoHash(chave);

    while(tabela[id] != 0){
        if(tabela[id] == chave){
            return tabela[id];
        }else{
            id = funcaoHash(id + 1);
        }
    }

    printf("%d não encontrado \n", chave);
    return 0;
}

void imprimir(int *tabela){
    printf("Tabela Hash:\n");
    
    for(int i = 0; i < tamanhoTabela; i++){
        printf("[%d] %d\n", i, tabela[i]);
    }

    printf("\n");
}

void excluir(int *tabela){
    free(tabela);
}