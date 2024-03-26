/**
 * @brief Implementação da Tabela Hash com encadeamento separado
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "encadeadaSeparada.h"


/************************************************************
 * Funções auxiliares
*************************************************************/

bool ehPrimo(int numero){
    for(int i = numero - 1; i > 1; i--){
        if(numero % i == 0){
            return false;
        }
    }

    return true;
}

/************************************************************
 * Funções básicas
*************************************************************/

HashEncadeada *inicializaHash(int qtdElementosConjunto){
    HashEncadeada *nova = (HashEncadeada *) malloc(sizeof(HashEncadeada));

    if(nova == NULL){
        perror("Erro ao alocar espaço para a Hash");
        exit(EXIT_FAILURE);
    }

    int tamanho = calcularTamanhoIdealHash(qtdElementosConjunto);

    nova->quantidadeElementos = 0;
    nova->tamanho = tamanho;
    nova->tabela = (Node **) malloc(sizeof(Node *) * tamanho);

    for(int i = 0; i < nova->tamanho; i++){
        nova->tabela[i] = NULL;
    }

    return nova;
}

int funcaoHash(HashEncadeada *hash, int chave){
    if(chave == 0){
        return 0;
    }else if(chave < 0){
        chave *= -1;
    }

    return chave % hash->tamanho;
}

double calcularFatorCargaHash(HashEncadeada *hash){
    double fator = (double) hash->quantidadeElementos / hash->tamanho;
    
    printf("->Fator de carga: (%.2lf)\n", fator);

    return fator;
}

int calcularTamanhoIdealHash(int qtdElementosConjunto){
    if(qtdElementosConjunto <= 2){
        int recomendado = 5;
        printf("-> Quantidade de elementos muito baixa. Tamanho recomendado: (%d)\n", recomendado);
        
        return recomendado;
    }else{
        int tamanho = 2 * qtdElementosConjunto;

        while(!ehPrimo(tamanho)){
            tamanho++;
        }
        
        printf("-> Tamanho recomendado para %d elementos: (%d)\n", qtdElementosConjunto, tamanho);

        return tamanho;
    }
}

/************************************************************
 * Inserção
*************************************************************/

void inserirHash(HashEncadeada *hash, Node *novo){
    int index = funcaoHash(hash, novo->valor);

    printf("-> Inserido no index [%d]\n", index);
    // printf("tabela %p\n", &(hash->tabela[index]));
    // printf("tabela %p\n", hash->tabela[index]);
    // printf("tabela* %p\n", *(hash->tabela[index])); // Node
    inserirNodeOrdenado(&(hash->tabela[index]), novo);
    hash->quantidadeElementos++;
}

/************************************************************
 * Busca
*************************************************************/

Node *buscarValorHash(HashEncadeada *hash, int valor){
    int index = funcaoHash(hash, valor);

    Node *elemento = buscarNode(&(hash->tabela[index]), valor);

    if(elemento != NULL){
        printf("-> Valor encontrado no index [%d]\n", index);
    }else{
        printf("-> Valor não encontrado no index [%d]\n", index);
    }

    return elemento;
}

/************************************************************
 * Mostrar
*************************************************************/

void mostrarHash(HashEncadeada *hash){
    
    for(int i = 0; i < hash->tamanho; i++){
        printf("[%d] ", i);
        mostrarNodes(&(hash->tabela[i]));
        // printf("%p\n", hash->tabela[i]);
    }
}

/************************************************************
 * Remoção
*************************************************************/

void removerValorHash(HashEncadeada *hash, int valor){
    int index = funcaoHash(hash, valor);

    printf("-> Valor procurado no index [%d]\n", index);
    removerNode(&(hash->tabela[index]), valor);
    hash->quantidadeElementos--;

}

/************************************************************
 * Destruição
*************************************************************/

void destruirHash(HashEncadeada *hash){
    for(int i = 0; i < hash->tamanho; i++){
        if(&(hash->tabela[i]) != NULL){
            destruirNodes(&(hash->tabela[i]));
        }
    }

    free(hash->tabela);
    free(hash);
    printf("-> Hash apagada\n");
}