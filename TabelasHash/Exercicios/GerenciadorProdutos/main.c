/**
 * @brief Menu para o Gerenciamento de Inventário
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "tabelaHash.h"


void mostrarMenuPrincipal(){
    mostrarTitulo("Gerenciamento de inventário");
    
    printf("[0] Sair\n");
    printf("[1] Adicionar produto\n");
    printf("[2] Remover produto\n");
    printf("[3] Listar produtos\n");
    printf("[4] Buscar produto\n");
    printf("[5] Calcular Fator de Estoque\n");
    printf("\n");
}

int main(int argc, char const *argv[]){
    
    int maxEncadeada, maxDupla;
    int opcao, valorInteiro;
    double valorDouble;
    char *string;
    Node *elemento;

    valorInteiro = lerInteiro("=> Quantidade total esperada de elementos: ");

    Hash *hashDupla = inicializarHash(TIPO_DUPLA, valorInteiro);
    Hash *hashEncadeada = inicializarHash(TIPO_ENCADEADA, valorInteiro);
    maxEncadeada = valorInteiro * 2;
    maxDupla = valorInteiro * 4;

    inicializarSorteador();

    do{
        mostrarMenuPrincipal();
        opcao = lerInteiro("=> Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirHash(hashEncadeada);
            destruirHash(hashDupla);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            mostrarOpcao("Adicionar produto");

            string = lerString("=> Digite a descrição do produto: ");
            valorDouble = lerDouble("=> Digite o valor do produto: ");

            if(valorDouble <= 200){
                // A hash encadeada não fica cheia!
                valorInteiro = sortearNumeroInteiro(0, maxEncadeada);
                elemento = criarNode(valorInteiro, string, valorDouble);
                inserirHash(hashEncadeada, elemento);
            }else{
                if(!estarCheia(hashDupla)){
                    valorInteiro = sortearNumeroInteiro(maxEncadeada + 1, maxDupla);
                    elemento = criarNode(valorInteiro, string, valorDouble);
                    inserirHash(hashDupla, elemento);
                }else{
                    printf("-> O estoque de valores acima de R$200,00 está cheio!\n");
                }
            }

            free(string);
            
            break;
        
        case 2: // Remover
            mostrarOpcao("Remover produto");

            valorInteiro = lerInteiro("=> Digite o ID para remover: ");
            
            if(valorInteiro <= maxEncadeada){
                removerHash(hashEncadeada, valorInteiro);
            }else{
                removerHash(hashDupla, valorInteiro);
            }

            break;
        
        case 3:  // Imprimir
            mostrarOpcao("Listar produtos");
            
            printf("-> Até R$200,00\n");
            mostrarHash(hashEncadeada);
            
            printf("-> Acima de R$200,00\n");
            mostrarHash(hashDupla);

            break;

        case 4: // Buscar
            mostrarOpcao("Buscar produto");

            valorInteiro = lerInteiro("=> Digite o ID para buscar: ");
            if(valorInteiro <= maxEncadeada){
                buscarHash(hashEncadeada, valorInteiro);
            }else{
                buscarHash(hashDupla, valorInteiro);
            }

            break;

        case 5: // Calcula o Fator de Carga
            mostrarOpcao("Calcular Fator de Estoque");
            
            printf("-> Até R$200,00\n");
            calcularFatorCargaHash(hashEncadeada);
            
            printf("-> Acima de R$200,00\n");
            calcularFatorCargaHash(hashDupla);

            break;
        
        default:
            printf("=> Opção inválida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
