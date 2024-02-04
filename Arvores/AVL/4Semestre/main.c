/**
 * @brief Testando a Árvore AVL
*/

#include <stdio.h>
#include "arvoreAvl.h"

/**
 * @brief Mostra o menu de opções
*/
void mostraMenu();

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
    inicializar(arvore);

    do{
        mostraMenu();
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
            printf("Imprimindo árvore:\n");
            //começando com o nivel 1
            imprimir(raiz, 1);

            break;

        case 4: // Buscar
            valor = leInteiro("=>Valor para buscar: ");
            elemento = buscaBinaria(&arvore, valor);

            if(elemento){
                printf("Elemento %d encontrado no endereço %p\n", valor, elemento);
                printf("O nó pai está em %p e vale %d\n", buscaNo(&arvore, valor, &elemento), elemento->chave);
            }

            break;
        
        default:
            printf("Opção invalida. Digite novamente\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}

void mostraMenu(){
    printf("*******************\n");
    printf("\tÁrvore AVL\n\n");
    printf("[0]Sair\n");
    printf("[1]Inserir\n");
    printf("[2]Remover\n");
    printf("[3]Imprimir\n");
    printf("[4]Buscar\n\n");
}

int leInteiro(char *texto){
    int opcao;

    printf("%s", texto);
    scanf("%d", &opcao);

    return opcao;
}
