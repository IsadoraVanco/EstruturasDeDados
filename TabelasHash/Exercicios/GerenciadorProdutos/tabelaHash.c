/**
 * @brief Implementação da Tabela Hash com encadeamento 
 * separado e Duplo Hash
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tabelaHash.h"


/************************************************************
 * Variáveis globais
*************************************************************/

/**
 * @brief Constante de multiplicação para a função Hash
 */
double multiplicadorHash = 0;

/************************************************************
 * Funções auxiliares
*************************************************************/

bool ehPrimo(int numero){
    for(int i = numero - 1; i > 1; i--){
        if(numero % i == 0){
            return false;
        }
    }

    return true;
}

void inicializarSorteador(){
    // Inicializa o gerador com a "semente" do tempo
    srand(time(NULL));
    // printf("-> Sorteador inicializado\n");
}

double sortearNumero(){
    // Gera um número entre 0 e 1
    double num = (double) rand() / RAND_MAX;

    // printf("-> Sorteado: %.2lf\n", num);
    return num;
}

/************************************************************
 * Funções Hash
*************************************************************/

int calcularQuantidadeDigitos(int numero){
    // printf("-> Número de dígitos de %d: ", numero);
    if(numero < 0){
        numero *= -1;
    }

    int digitos = 1;

    while(numero > 9){
        numero = numero / 10;
        digitos++;
    }

    // printf("%d\n", digitos);
    return digitos;
}

int calcularDobra(int chave, int numeroDigitos){
    // printf("Número: %d\n", chave);
    // Transforma o número em vetor
    int novoNumero[numeroDigitos];

    for(int i = numeroDigitos - 1; i >= 0; i--){
        novoNumero[i] = chave % 10;
        chave = chave / 10;
    }

    // Calcula a dobra
    int dobra = numeroDigitos / 2;
    for(int i = 0; i < dobra; i++){
        int somaDobra = novoNumero[dobra - i - 1] + novoNumero[dobra + i];
        
        if(somaDobra >= 10){
            somaDobra = somaDobra % 10;
        }

        novoNumero[dobra + i] = somaDobra;
        novoNumero[dobra - i - 1] = 0;
    }

    // Transforma em inteiro novamente
    int numero = 0;
    int multiplicador = 1;

    for(int i = numeroDigitos - 1; i >= 0; i--){
        numero += novoNumero[i] * multiplicador;
        multiplicador *= 10;
    }

    // printf("Número dobrado: %d\n", numero);
    return numero;
}

int metodoDobra(Hash *hash, int chave){
    int tamanho = hash->tamanho;
    int index = chave;

    if(index < 0){
        index *= -1;
    }

    while(index >= tamanho){
        if(tamanho < 10){
            // Não convém ao método da dobra! 
            index--;
        }else{
            // Calcula o número de digitos da chave
            int numeroDigitos = calcularQuantidadeDigitos(index);

            index = calcularDobra(index, numeroDigitos);
        }
    }

    // printf("-> Index da dobra: %d\n", index);
    return index;
}

int metodoMultiplicacao(Hash *hash, int chave){
    if(multiplicadorHash == 0){
        inicializarSorteador();

        while(multiplicadorHash == 0){
            // Gera um multiplicador maior que 0 e 1
            multiplicadorHash = sortearNumero();
        }
        printf("-> Chave multiplicadora: %.3lf\n", multiplicadorHash);
    }

    multiplicadorHash *= chave;
    multiplicadorHash -= (int) multiplicadorHash;

    return (int) hash->tamanho * multiplicadorHash;
}

int metodoDivisao(Hash *hash, int chave){
    if(chave == 0){
        return 0;
    }else if(chave < 0){
        chave *= -1;
    }

    return chave % hash->tamanho;
}

int calcularFuncaoHashEncadeada(Hash *hash, int chave){
    return metodoDivisao(hash, chave);
}

int calcularPrimeiraFuncaoHashDupla(Hash *hash, int chave){
    if(chave < 0){
        chave *= -1;
    }
    return metodoDobra(hash, chave);
}

int calcularHashDuplo(Hash *hash, int chave){
    if(chave < 0){
        chave *= -1;
    }

    int hashDuplo = metodoMultiplicacao(hash, chave);

    if(hashDuplo == 0){
        hashDuplo = 1;
    }

    return hashDuplo;
}

/************************************************************
 * Funções básicas
*************************************************************/

Hash *inicializarHash(TIPO tipo, int qtdElementosConjunto){
    Hash *nova = (Hash *) malloc(sizeof(Hash));

    if(nova == NULL){
        perror("Erro ao alocar espaço para a Hash");
        exit(EXIT_FAILURE);
    }

    int tamanho = calcularTamanhoIdealHash(qtdElementosConjunto);

    nova->quantidadeElementos = 0;
    nova->tamanho = tamanho;
    nova->tabela = (Node **) malloc(sizeof(Node *) * tamanho);
    
    for(int i = 0; i < nova->tamanho; i++){
        nova->tabela[i] = NULL;
    }

    if(tipo != TIPO_DUPLA && tipo != TIPO_ENCADEADA){
        nova->tipo = TIPO_DUPLA;
    }else{
        nova->tipo = tipo;
    }

    return nova;
}

double calcularFatorCargaHash(Hash *hash){
    double fator = (double) hash->quantidadeElementos / hash->tamanho;
    
    printf("->Fator de carga: (%.2lf)\n", fator);

    return fator;
}

int calcularTamanhoIdealHash(int qtdElementosConjunto){
    if(qtdElementosConjunto <= 2){
        int recomendado = 5;
        printf("-> Quantidade de elementos muito baixa. Tamanho recomendado: (%d)\n", recomendado);
        
        return recomendado;
    }else{
        int tamanho = 2 * qtdElementosConjunto;

        while(!ehPrimo(tamanho)){
            tamanho++;
        }
        
        printf("-> Tamanho recomendado para %d elementos: (%d)\n", qtdElementosConjunto, tamanho);

        return tamanho;
    }
}

bool estarCheia(Hash *hash){
    return hash->quantidadeElementos == hash->tamanho;
}

/************************************************************
 * Inserção
*************************************************************/

void inserirHash(Hash *hash, Node *novo){
    printf("-> Inserir ID [%d]\n", novo->id);

    if(hash->tipo == TIPO_DUPLA){
        inserirHashDupla(hash, novo);
    }else{
        inserirHashEncadeada(hash, novo);
    }
}

void inserirHashDupla(Hash *hash, Node *novo){
    if(estarCheia(hash)){
        printf("-> A tabela está cheia!\n");

        return;
    }

    // Calcula o primeiro index
    int index = calcularPrimeiraFuncaoHashDupla(hash, novo->id);
    int tamanho = hash->tamanho;

    // Calcula o segundo index se necessário
    if(hash->tabela[index] != NULL){
        printf("-> Já existe um elemento em [%d]\n", index);

        int hashDuplo = calcularHashDuplo(hash, novo->id);

        while(hash->tabela[index] != NULL){
            index += hashDuplo;

            if(index >= tamanho){
                index -= tamanho;
            }

            printf("-> Tenta novamente em [%d]\n", index);
        }
    }
    
    hash->tabela[index] = novo;
    printf("-> Inserido no index [%d]\n", index);

    hash->quantidadeElementos++;
}

void inserirHashEncadeada(Hash *hash, Node *novo){
    int index = calcularFuncaoHashEncadeada(hash, novo->id);

    printf("-> Inserido no index [%d]\n", index);
    // printf("tabela %p\n", &(hash->tabela[index]));
    // printf("tabela %p\n", hash->tabela[index]);
    // printf("tabela* %p\n", *(hash->tabela[index])); // Node
    inserirNodeOrdenado(&(hash->tabela[index]), novo);
    hash->quantidadeElementos++;
}

/************************************************************
 * Busca
*************************************************************/
void buscarHash(Hash *hash, int ID){
    if(hash->tipo == TIPO_DUPLA){
        buscarHashDupla(hash, ID);
    }else{
        buscarHashEncadeada(hash, ID);
    }
}

int buscarHashDupla(Hash *hash, int valor){
    int index = calcularPrimeiraFuncaoHashDupla(hash, valor);
    int tamanho = hash->tamanho;

    Node *elemento = hash->tabela[index];

    if(elemento == NULL || elemento->id != valor){
        printf("-> Valor não encontrado no index [%d]\n", index);

        int hashDuplo = calcularHashDuplo(hash, valor);

        for(int i = 0; i < tamanho; i++){
            index += hashDuplo;

            if(index >= tamanho){
                index -= tamanho;
            }

            elemento = hash->tabela[index];
            printf("-> Tenta novamente em [%d]\n", index);

            if(elemento != NULL && elemento->id == valor){
                break;
            }
        }
        
        if(elemento == NULL || elemento->id != valor){
            printf("-> Valor não encontrado na tabela\n");
            return -1;
        }
    }

    printf("-> Valor encontrado no index [%d]\n", index);
    mostrarNode(elemento);
    return index;
}

Node *buscarHashEncadeada(Hash *hash, int valor){
    int index = calcularFuncaoHashEncadeada(hash, valor);

    Node *elemento = buscarNode(&(hash->tabela[index]), valor);

    if(elemento != NULL){
        printf("-> Valor encontrado no index [%d]\n", index);
        mostrarNode(elemento);
    }else{
        printf("-> Valor não encontrado no index [%d]\n", index);
    }

    return elemento;
}

/************************************************************
 * Mostrar
*************************************************************/

void mostrarHash(Hash *hash){
    
    for(int i = 0; i < hash->tamanho; i++){
        printf("[%d]\n", i);
        mostrarNodes(&(hash->tabela[i]));
    }
}

/************************************************************
 * Remoção
*************************************************************/

void removerHash(Hash *hash, int ID){
    if(hash->tipo == TIPO_DUPLA){
        removerHashDupla(hash, ID);
    }else{
        removerHashEncadeada(hash, ID);
    }
}

void removerHashDupla(Hash *hash, int valor){
    int index = buscarHashDupla(hash, valor);

    if(index >= 0){
        free(hash->tabela[index]);
        hash->tabela[index] = NULL;
        hash->quantidadeElementos--;

        printf("-> Valor removido da tabela\n");
    }
}

void removerHashEncadeada(Hash *hash, int valor){
    int index = calcularFuncaoHashEncadeada(hash, valor);

    printf("-> Valor procurado no index [%d]\n", index);
    removerNode(&(hash->tabela[index]), valor);
    hash->quantidadeElementos--;

}

/************************************************************
 * Destruição
*************************************************************/

void destruirHash(Hash *hash){
    for(int i = 0; i < hash->tamanho; i++){
        if(&(hash->tabela[i]) != NULL){
            destruirNodes(&(hash->tabela[i]));
        }
    }

    free(hash->tabela);
    free(hash);
    printf("-> Hash apagada\n");
}