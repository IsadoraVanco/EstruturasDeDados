/**
 * @brief Gerenciador de processos
*/

#include <stdio.h>
#include "processos.h"


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
    
    // Heap mínimo de processos por prioridade
    Heap *prioridades = inicializarHeap(MAXIMO);
    // Heap mínimo de processos por tempo
    Heap *tempos = inicializarHeap(MINIMO);

    int opcao, valor1, valor2;

    do{
        mostraMenuPrincipal();
        opcao = leInteiro("=> Comando: ");
        valor1 = 0;
        valor2 = 0;

        switch (opcao){
        case 0: // Sair
            destruirProcessos(prioridades);
            destruirProcessos(tempos);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            while(valor1 <= 0){
                valor1 = leInteiro("=> Prioridade do processo: ");
            }

            while(valor2 <= 0){
                valor2 = leInteiro("=> Tempo de espera do processo: ");
            }

            mostraOpcao("Inserir Processo");
            inserirProcesso(prioridades, valor1, valor2);
            inserirProcesso(tempos, valor1, valor2);

            break;
        
        case 2: // Remover
            mostraOpcao("Remover processo");
            removerProcessoTopoAmbos(prioridades, tempos);
           
            break;
        
        case 3:  // Imprimir
            mostraOpcao("Imprimir Processos");
            printf("=> Por PRIORIDADE:\n");
            imprimirProcessos(prioridades);
            printf("\n=> Por TEMPO:\n");
            imprimirProcessos(tempos);
            
            break;

        case 4: // Buscar
            valor1 = leInteiro("=> ID do processo: ");

            mostraOpcao("Buscar Processo");
            printf("=> Em PRIORIDADE:\n");
            buscarProcesso(prioridades, valor1);
            printf("\n=> Em TEMPO:\n");
            buscarProcesso(tempos, valor1);

            break;
        
        default:
            printf("=> Opção invalida. Digite novamente.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}

void mostraMenuPrincipal(){
    printf("\n******************************************\n");
    printf("\tGerenciador de processos\n");
    printf("******************************************\n\n");
    printf("[0] Sair\n");
    printf("[1] Inserir\n");
    printf("[2] Remover\n");
    printf("[3] Imprimir\n");
    printf("[4] Buscar\n");
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

