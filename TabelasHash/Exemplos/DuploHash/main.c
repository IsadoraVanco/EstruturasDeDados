/**
 * @brief Testando a Hash Dupla
*/

#include <stdio.h>
#include "duploHash.h"


/**
 * @brief Mostra o menu principal de opções
*/
void mostrarMenuPrincipal();

/**
 * @brief Mostra o cabeçalho para o inicio da opção
 * @param texto O texto que ficará no cabeçalho
 */
void mostrarOpcao(char *texto);

/**
 * @brief Lê um número inteiro e o retorna
 * @param texto O texto que será exibido na hora da leitura
 * @return O número inteiro lido
*/
int lerInteiro(char *texto);

int main(int argc, char const *argv[]){
    
    int opcao, valor;

    valor = lerInteiro("=> Quantidade total esperada de elementos: ");

    Hash *hash = inicializarHash(valor);
    Node *elemento;

    do{
        mostrarMenuPrincipal();
        opcao = lerInteiro("=> Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirHash(hash);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            valor = lerInteiro("=> Valor para inserir: ");

            mostrarOpcao("Inserir");
            if(!estarCheia(hash)){
                elemento = criarNode(valor);
                inserirHash(hash, elemento);
            }

            break;
        
        case 2: // Remover
            valor = lerInteiro("=> Valor para remover: ");

            mostrarOpcao("Remover");
            removerValorHash(hash, valor);

            break;
        
        case 3:  // Imprimir
            mostrarOpcao("Imprimir");
            mostrarHash(hash);

            break;

        case 4: // Buscar
            valor = lerInteiro("=> Valor para buscar: ");

            mostrarOpcao("Buscar");
            buscarValorHash(hash, valor);

            break;

        case 5: // Calcula o Fator de Carga
            mostrarOpcao("Calcular Fator de Carga");
            calcularFatorCargaHash(hash);

            break;
        
        default:
            printf("=> Opção invalida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}

void mostrarMenuPrincipal(){
    printf("\n******************************************\n");
    printf("\tHash Dupla\n");
    printf("******************************************\n\n");
    printf("[0] Sair\n");
    printf("[1] Inserir valor\n");
    printf("[2] Remover valor\n");
    printf("[3] Imprimir valores\n");
    printf("[4] Buscar valor\n");
    printf("[5] Calcular Fator de Carga\n");
    printf("\n");
}

void mostrarOpcao(char *texto){
    printf("\n=====================================\n");
    printf("\t%s\n", texto);
    printf("=====================================\n\n");
}

int lerInteiro(char *texto){
    int opcao;

    printf("%s", texto);
    scanf("%d", &opcao);

    return opcao;
}
