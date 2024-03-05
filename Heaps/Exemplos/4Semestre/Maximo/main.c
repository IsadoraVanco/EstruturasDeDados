/**
 * @brief Testando o Heap Máximo
*/

#include <stdio.h>
#include "heapMaximo.h"


/**
 * @brief Mostra o menu principal de opções
*/
void mostraMenuPrincipal();

/**
 * @brief Mostra o cabeçalho para o inicio da opção
 * @param texto O texto que ficará no cabeçalho
 */
void mostraOpcao(char *texto);

/**
 * @brief Lê um número inteiro e o retorna
 * @param texto O texto que será exibido na hora da leitura
 * @return O número inteiro lido
*/
int leInteiro(char *texto);

int main(int argc, char const *argv[]){
    
    int opcao, valor;

    Heap *heap = inicializarHeap();

    do{
        mostraMenuPrincipal();
        opcao = leInteiro("=>Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirHeap(heap);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            valor = leInteiro("=>Valor para inserir: ");

            mostraOpcao("Inserir Elemento");
            inserirNo(heap, valor);

            break;
        
        case 2: // Remover
            mostraOpcao("Remover primeiro elemento");
            removerNo(heap);
           
            break;
        
        case 3:  // Imprimir
            mostraOpcao("Imprimir Heap");
            imprimirHeap(heap);
            
            break;

        case 4: // Buscar
            valor = leInteiro("=>Valor para buscar: ");

            mostraOpcao("Busca no Heap");
            buscarValor(heap, valor);

            break;
        
        default:
            printf("=>Opção invalida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}

void mostraMenuPrincipal(){
    printf("\n******************************************\n");
    printf("\tHeap Máximo\n");
    printf("******************************************\n\n");
    printf("[0]Sair\n");
    printf("[1]Inserir\n");
    printf("[2]Remover\n");
    printf("[3]Imprimir\n");
    printf("[4]Buscar\n");
    printf("\n");
}

void mostraOpcao(char *texto){
    printf("\n=====================================\n");
    printf("\t%s\n", texto);
    printf("=====================================\n\n");
}

int leInteiro(char *texto){
    int opcao;

    printf("%s", texto);
    scanf("%d", &opcao);

    return opcao;
}

