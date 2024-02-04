/**
 * @brief Testando a árvore AVL
*/

#include <stdio.h>
#include "arvoreAvl.h"

int main(int argc, char const *argv[])
{
    int opcao, valor;
    No *raiz = NULL;

    do{
        printf("\n[0]Sair\n[1]Inserir\n[2]Remover\n[3]Imprimir\n\n");
        printf("=>Comando: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 0:
            printf("Obrigada! Até mais...\n\n");
            break;

        case 1:
            printf("Valor para inserir: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        
        case 2:
            printf("Valor para remover: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        
        case 3:
            printf("Imprimindo árvore:\n");
            //começando com o nivel 1
            imprimir(raiz, 1);
            break;
        
        default:
            printf("Opção invalida. Digite novamente\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
