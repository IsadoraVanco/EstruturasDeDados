/**
 * @brief Exercício do rato no labirinto
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "grafoLista.h"
#include "buscaLargura.h"

bool estaArmazenado(char* string, int tamanho, char matriz[][10]){
    for(int i = 0; i < tamanho; i++){
        if(strcmp(string, matriz[i]) == 0){
            return true;
        }
    }

    return false;
}

int procurarIndice(char *string, int tamanho, char matriz[][10]){
    for(int i = 0; i < tamanho; i++){
        if(strcmp(string, matriz[i]) == 0){
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]){
    int pontos = 0;
    int ligacoes = 0;

    int entrada = -1;
    int saida = -1;
    int queijo = -1;

    // Leitura dos pontos e ligações
    while(pontos < 4 || pontos > 4000){
        printf("=> Número de pontos (4 - 4000): ");
        scanf("%d", &pontos);
    }

    while(ligacoes < 4 || ligacoes > 5000){
        printf("=> Número de ligações (4 - 5000): ");
        scanf("%d", &ligacoes);
    }

    GrafoLista *grafoLista = inicializarGrafoLista(pontos);

    char todosPontos[pontos][10];
    int indicePontos = 0;

    // Inicializa os valores dos pontos
    for(int i = 0; i < pontos; i++){
        strcpy(todosPontos[i], "");
    }
    
    // Lê e armazena os pontos
    for(int i = 0; i < ligacoes; i++){
        char pontoA[10], pontoB[10];
        int indiceA, indiceB;
        
        printf("=> Ligação [%d]: ", i);
        scanf("%s %s", pontoA, pontoB);

        if(!estaArmazenado(pontoA, pontos, todosPontos)){
            strcpy(todosPontos[indicePontos++], pontoA);

            if(strcmp(pontoA, "Entrada") == 0){
                entrada = indicePontos - 1;
            }else if(strcmp(pontoA, "Saida") == 0){
                saida = indicePontos - 1;
            }else if(strcmp(pontoA, "*") == 0){
                queijo = indicePontos - 1;
            }

            indiceA = indicePontos - 1;
        }else{
            indiceA = procurarIndice(pontoA, pontos, todosPontos);
        }

        if(!estaArmazenado(pontoB, pontos, todosPontos)){
            strcpy(todosPontos[indicePontos++], pontoB);

            if(strcmp(pontoB, "Entrada") == 0){
                entrada = indicePontos - 1;
            }else if(strcmp(pontoB, "Saida") == 0){
                saida = indicePontos - 1;
            }else if(strcmp(pontoB, "*") == 0){
                queijo = indicePontos - 1;
            }

            indiceB = indicePontos - 1;
        }else{
            indiceB = procurarIndice(pontoB, pontos, todosPontos);
        }

        // Faz a conexão no grafo
        inserirArestaGrafoLista(grafoLista, indiceA, indiceB, 1);
        inserirArestaGrafoLista(grafoLista, indiceB, indiceA, 1);
    }

    criarImagemGrafoLista(grafoLista, false);

    // Calcula a distancia da entrada até o queijo e do queijo até a saida
    int distancia = contarCaminhoMinimoLista(entrada, queijo, pontos, grafoLista->arestas);
    distancia += contarCaminhoMinimoLista(queijo, saida, pontos, grafoLista->arestas);

    destruirGrafoLista(grafoLista);
    
    printf("-> Caminho mínimo total : %d\n", distancia);

    return 0;
}
