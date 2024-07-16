/**
 * @brief Menu para testar o grafoLista
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Menu/menu.h"
#include "grafoLista.h"
#include "buscaLargura.h"


void mostrarMenuPrincipal(){
    mostrarTitulo("Busca em largura");
    
    printf("[0] Sair\n");
    printf("[1] Adicionar aresta\n");
    printf("[2] Remover aresta\n");
    printf("[3] Mostrar grafo\n");
    printf("[4] Mostrar caminho no grafo\n");
    printf("[5] Caminho mínimo entre pontos\n");
    printf("\n");
}

int main(int argc, char const *argv[]){
    
    int opcao, valorInteiro = -1;
    int valorInteiro2, valorInteiro3;

    while(valorInteiro <= 0){
        valorInteiro = lerInteiro("=> Quantidade total esperada de vértices do grafoLista: ");
    }

    GrafoLista *grafoLista = inicializarGrafoLista(valorInteiro);
    GrafoBusca *grafoBusca;

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

            inserirArestaGrafoLista(grafoLista, valorInteiro, valorInteiro2, valorInteiro3);
            
            break;
        
        case 2: // Remover
            mostrarOpcao("Remover aresta");

            valorInteiro = lerInteiro("=> Vértice A: ");
            valorInteiro2 = lerInteiro("=> Vértice B: ");
            
            removerArestaGrafoLista(grafoLista, valorInteiro, valorInteiro2);

            break;
        
        case 3:  // Imprimir
            mostrarOpcao("Mostrar grafo");
            
            imprimirGrafoLista(grafoLista);
            criarImagemGrafoLista(grafoLista, false);

            break;

        case 4: // Buscar
            mostrarOpcao("Buscar caminho no grafo");

            valorInteiro = lerInteiro("=> Vértice de origem: ");

            while(valorInteiro < 0 || valorInteiro >= grafoLista->numeroVertices){
                valorInteiro = lerInteiro("=> Vértice de origem: ");
            }
            
            // grafoBusca = criarSubGrafoMatriz(valorInteiro, grafoLista->numeroVertices, grafoLista->matriz);
            grafoBusca = criarSubGrafoLista(valorInteiro, grafoLista->numeroVertices, grafoLista->arestas);
            criarImagemGrafoBusca(grafoBusca, false);
            destruirGrafoBusca(grafoBusca);

            break;

        case 5: // Caminho mínimo
            mostrarOpcao("Caminho mínimo entre pontos");
            
            valorInteiro = lerInteiro("=> Vértice de origem: ");
            while(valorInteiro < 0 || valorInteiro >= grafoLista->numeroVertices){
                valorInteiro = lerInteiro("=> Vértice de origem: ");
            }

            valorInteiro2 = lerInteiro("=> Vértice de chegada: ");
            while(valorInteiro2 < 0 || valorInteiro2 >= grafoLista->numeroVertices){
                valorInteiro2 = lerInteiro("=> Vértice de chegada: ");
            }

            contarCaminhoMinimoLista(valorInteiro, valorInteiro2, grafoLista->numeroVertices, grafoLista->arestas);

            break;
        
        default:
            printf("=> Opção inválida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
