/**
 * @brief Testando a Árvore Rubro-Negra
*/

#include <stdio.h>
#include "rubroNegra.h"

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

    ArvoreRubroNegra *arvore = inicializarArvore();
    Node *elemento;

    printf("arvore %d, %p\n", arvore->quantidadeElementos, arvore->raiz);

    do{
        mostraMenuPrincipal();
        opcao = leInteiro("=>Comando: ");

        switch (opcao){
        case 0: // Sair
            destruirArvore(arvore);
            printf("Obrigada! Até mais...\n\n");

            break;

        case 1: // Inserir
            valor = leInteiro("=>Valor para inserir: ");
            inserir(arvore, valor);

            break;
        
        case 2: // Remover
            valor = leInteiro("=>Valor para remover: ");
            apagar(arvore, valor);

            break;
        
        case 3:  // Imprimir
            printf("\n================================\n");
            printf("\tImprimir árvore\n");
            printf("================================\n\n");

            exibirArvore(arvore, arvore->raiz);
            printf("\n");
            criarImagemArvore(arvore);

            break;

        case 4: // Buscar
            valor = leInteiro("=>Valor para buscar: ");

            printf("================================\n");
            printf("\tBusca árvore\n");
            printf("================================\n");
            elemento = buscaBinaria(arvore, arvore->raiz, valor);

            if(elemento){
                printf("Endereço: %p\n", elemento);
                printf("A altura do nó é %d\n", altura(arvore, elemento));
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
    printf("\n******************************************\n");
    printf("\tÁrvore Vermelha e Preta\n");
    printf("******************************************\n\n");
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
