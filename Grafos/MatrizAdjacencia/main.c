/**
 * @brief Menu para testar o grafo
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "grafoMatriz.h"


void mostrarMenuPrincipal(){
    mostrarTitulo("Grafo - Matriz");
    
    printf("[0] Sair\n");
    printf("[1] Adicionar aresta\n");
    printf("[2] Remover aresta\n");
    printf("[3] Mostrar grafo\n");
    printf("[4] Vizinhos de um vértice\n");
    printf("[5] Número de arestas\n");
    printf("\n");
}

int main(int argc, char const *argv[]){
    
    int opcao, valorInteiro = -1;
    int valorInteiro2, valorInteiro3;

    while(valorInteiro <= 0){
        valorInteiro = lerInteiro("=> Quantidade total esperada de vértices: ");
    }

    Grafo *grafo = inicializarGrafo(valorInteiro);

    do{
        mostrarMenuPrincipal();
        opcao = lerInteiro("=> Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirGrafo(grafo);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            mostrarOpcao("Adicionar aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            valorInteiro3 = lerInteiro("=> Peso: ");

            inserirAresta(grafo, valorInteiro, valorInteiro2, valorInteiro3);
            
            break;
        
        case 2: // Remover
            mostrarOpcao("Remover aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            
            removerAresta(grafo, valorInteiro, valorInteiro2);

            break;
        
        case 3:  // Imprimir
            mostrarOpcao("Mostrar grafo");
            
            imprimirGrafo(grafo);
            criarImagemGrafo(grafo, false);

            break;

        case 4: // Buscar
            mostrarOpcao("Vizinhos de um vértice");

            valorInteiro = lerInteiro("=> Vértice: ");
            
            verificarVerticePossuiVizinho(grafo, valorInteiro);

            break;

        case 5: // Número de arestas
            mostrarOpcao("Número de arestas");
            
            retornarNumeroArestas(grafo);

            break;
        
        default:
            printf("=> Opção inválida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
