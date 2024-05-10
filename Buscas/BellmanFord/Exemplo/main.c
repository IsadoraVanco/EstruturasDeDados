/**
 * @brief Menu para testar o algoritmo Bellman Ford
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Menu/menu.h"
#include "grafoLista.h"
#include "bellmanFord.h"


void mostrarMenuPrincipal(){
    mostrarTitulo("Bellman Ford");
    
    printf("[0] Sair\n");
    printf("[1] Adicionar aresta\n");
    printf("[2] Remover aresta\n");
    printf("[3] Mostrar grafo\n");
    printf("[4] Mostrar caminhos do grafo\n");
    printf("\n");
}

int main(int argc, char const *argv[]){
    
    int opcao, valorInteiro = -1;
    int valorInteiro2, valorInteiro3;

    while(valorInteiro <= 0){
        valorInteiro = lerInteiro("=> Quantidade total esperada de vértices do grafo: ");
    }

    GrafoLista *grafoLista = criarGrafoLista(valorInteiro);
    GrafoBellmanFord *grafoBellman;

    do{
        mostrarMenuPrincipal();
        opcao = lerInteiro("=> Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirGrafoLista(grafoLista);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            mostrarOpcao("Adicionar aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            valorInteiro3 = lerInteiro("=> Peso: ");

            inserirArestaBidirecionadaGrafoLista(grafoLista, valorInteiro, valorInteiro2, valorInteiro3);
            
            break;
        
        case 2: // Remover
            mostrarOpcao("Remover aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            
            removerArestaBidirecionadaGrafoLista(grafoLista, valorInteiro, valorInteiro2);

            break;
        
        case 3:  // Imprimir
            mostrarOpcao("Mostrar grafo");
            
            imprimirGrafoLista(grafoLista);
            criarImagemGrafoLista(grafoLista, false);

            break;

        case 4: // Buscar caminho
            mostrarOpcao("Mostrar caminhos do grafo");

            valorInteiro = lerInteiro("=> Vértice de origem: ");

            while(valorInteiro < 0 || valorInteiro >= grafoLista->numeroVertices){
                valorInteiro = lerInteiro("=> Vértice de origem: ");
            }
            
            grafoBellman = criarBellmanLista(grafoLista, valorInteiro);
            
            if(grafoBellman){
                criarImagemBellmanFord(grafoBellman, false);
                destruirGrafoBellmanFord(grafoBellman);
            }

            break;
        
        default:
            printf("=> Opção inválida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
