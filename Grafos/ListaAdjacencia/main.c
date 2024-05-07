/**
 * @brief Menu para testar o grafo de lista de adjacência
*/

#include <stdio.h>
#include <stdlib.h>
#include "Menu/menu.h"
#include "grafoLista.h"


void mostrarMenuPrincipal(){
    mostrarTitulo("Grafo - Lista");
    
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

    GrafoLista *grafo = inicializarGrafoLista(valorInteiro);

    do{
        mostrarMenuPrincipal();
        opcao = lerInteiro("=> Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirGrafoLista(grafo);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            mostrarOpcao("Adicionar aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            valorInteiro3 = lerInteiro("=> Peso: ");

            inserirArestaGrafoLista(grafo, valorInteiro, valorInteiro2, valorInteiro3);
            
            break;
        
        case 2: // Remover
            mostrarOpcao("Remover aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            
            removerArestaGrafoLista(grafo, valorInteiro, valorInteiro2);

            break;
        
        case 3:  // Imprimir
            mostrarOpcao("Mostrar grafo");
            
            imprimirGrafoLista(grafo);
            criarImagemGrafoLista(grafo, false);

            break;

        case 4: // Buscar
            mostrarOpcao("Vizinhos de um vértice");

            valorInteiro = lerInteiro("=> Vértice: ");
            
            verificarVerticePossuiVizinho(grafo, valorInteiro);

            break;

        case 5: // Número de arestas
            mostrarOpcao("Número de arestas");
            
            retornarNumeroArestasGrafoLista(grafo);

            break;
        
        default:
            printf("=> Opção inválida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
