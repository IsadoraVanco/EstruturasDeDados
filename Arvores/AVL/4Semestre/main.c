/**
 * @brief Testando a Árvore AVL
*/

#include <stdio.h>
#include "arvoreAvl.h"

/**
 * @brief Mostra o menu principal de opções
*/
void mostraMenuPrincipal();

/**
 * @brief MOstra o menu de opções de impressões
*/
void mostraMenuImpressao();

/**
 * @brief Lê um número inteiro e o retorna
 * @param texto O texto que será exibido na hora da leitura
 * @return O número inteiro lido
*/
int leInteiro(char *texto);

int main(int argc, char const *argv[]){
    
    int opcao, valor;
    PONT elemento;
    bool rotacionou = false;

    PONT arvore;
    inicializar(&arvore);

    do{
        mostraMenuPrincipal();
        opcao = leInteiro("=>Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirArvore(&arvore);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            valor = leInteiro("=>Valor para inserir: ");
            inserirAVL(&arvore, valor, &rotacionou);

            break;
        
        case 2: // Remover
            valor = leInteiro("=>Valor para remover: ");
            excluirAVL(&arvore, valor, &rotacionou);

            break;
        
        case 3:  // Imprimir
            mostraMenuImpressao();
            valor = leInteiro("=>Escolha um método de impressão: ");

            printf("\n\tImprimindo árvore:\n\n");

            switch(valor){
            case 1:
                exibirArvoreEmOrdem(arvore);
                printf("\n");

                break;

            case 2:
                exibirArvorePreOrdem(arvore);
                printf("\n");

                break;    
            
            case 3:
                exibirArvorePosOrdem(arvore);
                printf("\n");

                break;  
            
            case 4:
                exibirArvore(arvore);

                break;  
            
            case 5:
                exibirArvore2(arvore, -1);

                break;  
            
            default:
                printf("Opção inválida");

                break;
            }

            break;

        case 4: // Buscar
            valor = leInteiro("=>Valor para buscar: ");
            printf("\n");
            elemento = buscaBinaria(arvore, valor);

            if(elemento){
                printf("Endereço: %p\n", elemento);
                printf("A altura do nó é %d\n", altura(elemento));
                // printf("O nó pai está em %p e vale %d\n", buscaNo(arvore, valor, &elemento), elemento->chave);
            }

            break;
        
        default:
            printf("Opção invalida. Digite novamente\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}

void mostraMenuPrincipal(){
    printf("\n***************************\n");
    printf("\tÁrvore AVL\n");
    printf("***************************\n\n");
    printf("[0]Sair\n");
    printf("[1]Inserir\n");
    printf("[2]Remover\n");
    printf("[3]Imprimir\n");
    printf("[4]Buscar\n\n");
}

void mostraMenuImpressao(){
    printf("===================\n\n");
    printf("[1]Simétrica\n");
    printf("[2]Pré-Ordem\n");
    printf("[3]Pós-Ordem\n");
    printf("[4]Inteira\n");
    printf("[5]Inteira com pais\n\n");
}

int leInteiro(char *texto){
    int opcao;

    printf("%s", texto);
    scanf("%d", &opcao);

    return opcao;
}
