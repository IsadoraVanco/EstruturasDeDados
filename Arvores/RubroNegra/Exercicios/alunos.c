/**
 * @brief Testando cadastro de aluno com Red Black
*/

#include <stdio.h>
#include "../Exemplos/C/rubroNegra.h"

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

    ArvoreRubroNegra *arvore = inicializarArvore();
    Node *elemento;

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

            mostraOpcao("Inserir");
            inserir(arvore, valor);

            break;
        
        case 2: // Remover
            valor = leInteiro("=>Valor para remover: ");

            mostraOpcao("Remover");
            apagar(arvore, valor);

            break;
        
        case 3:  // Imprimir
            mostraOpcao("Imprimir");
            exibirArvore(arvore, arvore->raiz);

            printf("\n");
            criarImagemArvore(arvore);

            break;

        case 4: // Buscar
            valor = leInteiro("=>Valor para buscar: ");

            mostraOpcao("Buscar ");
            calcularCustosBusca(arvore, valor);

            break;

        case 5: // Obtem porcentagem de cores
            mostraOpcao("Porcentagem de categorias");
            obterPorcentagemCores(arvore);

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
    printf("\tCadastro de alunos\n");
    printf("******************************************\n\n");
    printf("[0]Sair\n");
    printf("[1]Cadastrar aluno\n");
    printf("[2]Remover aluno\n");
    printf("[3]Imprimir IDs\n");
    printf("[4]Buscar ID\n");
    printf("[5]Porcentagem de categorias\n");
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
