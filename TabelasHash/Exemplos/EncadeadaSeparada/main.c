/**
 * @brief Testando a Hash Encadeada
*/

#include <stdio.h>
#include "encadeadaSeparada.h"


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

    valor = leInteiro("=>Quantidade total esperada de elementos: ");

    HashEncadeada *hash = inicializaHash(valor);
    Node *elemento;

    do{
        mostraMenuPrincipal();
        opcao = leInteiro("=>Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirHash(hash);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            valor = leInteiro("=>Valor para inserir: ");

            mostraOpcao("Inserir");
            elemento = criarNode(valor);
            inserirHash(hash, elemento);

            break;
        
        case 2: // Remover
            valor = leInteiro("=>Valor para remover: ");

            mostraOpcao("Remover");
            removerValorHash(hash, valor);

            break;
        
        case 3:  // Imprimir
            mostraOpcao("Imprimir");
            mostrarHash(hash);

            // printf("\n");
            // criarImagemArvore(hash);

            break;

        case 4: // Buscar
            valor = leInteiro("=>Valor para buscar: ");

            mostraOpcao("Buscar");
            buscarValorHash(hash, valor);

            break;

        case 5: // Calcula o Fator de Carga
            mostraOpcao("Calcular Fator de Carga");
            calcularFatorCargaHash(hash);

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
    printf("\tHash com Encadeamento\n");
    printf("******************************************\n\n");
    printf("[0] Sair\n");
    printf("[1] Inserir valor\n");
    printf("[2] Remover valor\n");
    printf("[3] Imprimir valores\n");
    printf("[4] Buscar valor\n");
    printf("[5] Calcular Fator de Carga\n");
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
