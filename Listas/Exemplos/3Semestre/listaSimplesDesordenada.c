/**
 * @file listaSimplesDesordenada.c
 * @brief Implementação de uma estrutura de lista ligada desordenada, 
 * baseado no código do profº Gilberto
 * OBS: Em caso de dúvidas, tente fazer um teste de mesa,
 * ou seja, crie um exemplo e faça passo a passo no papel
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaSimplesDesordenada.h"


/**********************************************************************
 * TYPEDEFS
***********************************************************************/

// /*
//     Representa cada celula da lista
// */
// typedef struct cel{
//     int valor;              // Cada célula irá guardar um valor inteiro
//     struct cel *proximo;    // O endereço para a próxima célula da lista
// } Celula;

/*
    Representa a cabeça da lista e suas informações
*/
// typedef struct{
//     Celula* inicio; // Guarda a célula que está no inicio da lista
//     int tamanho;    // Guarda o tamanho da lista 
// } Lista;

/**********************************************************************
 * FUNÇÕES BÁSICAS
***********************************************************************/

/*
    Inicializa uma lista: criando um espaço para
    uma cabeça da lista, sem elementos dentro.
    Retorna o endereço da lista criada.
*/
Lista *inicializarLista(){

    Lista *nova = (Lista *) malloc(sizeof(Lista));  // Novo espaço
    nova->tamanho = 0;                              // A lista começa sem elementos
    nova->inicio = NULL;                            // Ainda não existe elementos para apontar

    return nova;                                    //Retorna o endereço de onde foi criada a lista
}

/*
    Apaga uma lista: percorre todos os elementos e 
    libera o espaço da memória, depois libera o espaço
    alocado para a cabeça da lista. 
*/
void apagarLista(Lista *lista){                 // Receb como parâmetro o endereço da cabeça da lista

    Celula *atual = lista->inicio;              // Começa com a primeira célula da lista
    Celula *proxima = atual->proximo;           // Começa com a segunda célula da lista

    // Se a lista não possuir elementos, não entra no loop
    for(int i = lista->tamanho; i > 0; i--){    // Percorre todos os elementos da lista
        free(atual);                            // Libera o espaço da célula atual

        atual = proxima;                        // Guardará o endereço da próxima célula, para depois liberar o espaço
        proxima = atual->proximo;               // Já pega o endereço da célula seguinte à próxima
    }

    free(lista);                                // Libera o espaço da cabeça da lista
}

/*
    Busca um elemento na lista: Procura pelo conteúdo 
    da célula (um número inteiro) e retorna o endereço
    da célula encontrada.
*/
Celula *buscar(Lista* lista, int valor){                        // Recebe como parâmetro o endereço da cabeça da lista e o valor a ser procurado

    Celula* celula = lista->inicio;                             // Começa com a primeira célula da lista 

    while(celula != NULL){                                      // Procura pelo elemento na lista: O NULL representa o fim da lista, ou seja, enquanto a célula é um elemento da lista

        if(celula->valor == valor){                             // Se a célula atual possui o valor desejado
            return celula;                                      // Retorna o endereço da célula
        }else{                                                  // Se não:
            celula = celula->proximo;                           // A célula atual agora armazena o endereço da próxima célula
        }
    }

    printf("Elemento %d não encontrado na lista\n", valor);
    return NULL;                                                // Se não achou o valor na lista, retorna NULL
}

/*
    Função para verificar se a lista está vazia
*/
bool ehListaVazia(Lista *lista){    // Recebe como parâmetro a cabeça da lista
    return lista->tamanho == 0;     // Retorna o resultado da operação lógica: true se for verdade, false para caso contrário
}

/*
    Mostra todos os elementos da lista.
*/
void mostraLista(Lista *lista){                 // Recebe como parâmetro a cabeça da lista
    if(ehListaVazia(lista)){                    // Verifica se a lista está vazia
        printf("Não existem elementos para serem mostrados\n");

        return;
    }

    Celula *celula = lista->inicio;             // Representa cada célula que iremos percorrer

    for(int i = 0; i < lista->tamanho; i++){    // Percorre os elementos da lista
        printf("%d ", celula->valor);
        celula = celula->proximo;               // Vai para a próxima célula da lista
    }
    printf("\n");

}

/**********************************************************************
 * INSERÇÕES
***********************************************************************/

/*
    Insere um elemento no inicio da lista
*/
void inserirInicio(Lista *lista, int valor){    // Recebe como parâmetro o endereço da cabeça da lista e o valor a ser inserido

    Celula *nova = malloc (sizeof(Celula));     // Cria um espaço para uma nova célula na memória e guarda o endereço em 'nova'

    nova->valor = valor;                        // A nova célula recebe o valor que será inserido
    nova->proximo = lista->inicio;              // Atribui o endereço da próxima célula para o inicio da lista, dessa forma, o novo elemento estará antes de toda lista já criada

    lista->inicio = nova;                       // Atribui a nova célula como inicio da lista
    lista->tamanho++;                           // Aumenta o atributo que armazena o tamanho da lista
}

/*
    Insere um elemento no meio da lista: 
    Como a lista é desordenada, busca pelo elemento 
    pivo que já está na lista e insere o novo elemento
    depois dele.
*/
void inserirNoMeio(Lista *lista, int valor, int pivo){  // Recebe como parâmetro o endereço da cabeça da lista, o valor a ser inserido e o valor de referência

    Celula *anterior = buscar(lista, pivo);             // Procura pelo elemento que possui o valor do pivo

    if(anterior == NULL){                               // Se não encontrou o valor pivo na lista
        printf("O valor %d não foi encontrado na lista\n", pivo);

        return;                                         // Retorna: não insere na lista
    }

    Celula *nova = (Celula *) malloc(sizeof(Celula));   // Cria um espaço para uma nova célula na memória e guarda o endereço em 'nova'
    
    nova->valor = valor;                                // A nova célula recebe o valor que será inserido
    nova->proximo = anterior->proximo;                  // A célula seguinte à nova será a célula que é seguinte ao elemento procurado, dessa forma, o novo elemento será seguinte ao pivo

    anterior->proximo = nova;                           // A célula com valor pivo ficará antes da nova, é importante fazer essa atribuição para não perder o resto da lista
    lista->tamanho++;                                   // Aumenta o atributo que armazena o tamanho da lista
}

/*
    Insere o elemento no fim da lista
*/
void inserirFim(Lista *lista, int valor){               // Recebe como parâmetro o endereço da cabeça da lista e o valor a ser inserido
    
    Celula *nova = (Celula *) malloc(sizeof(Celula));   // Cria um espaço para uma nova célula na memória e guarda o endereço em 'nova'
    nova->valor = valor;                                // A nova célula recebe o valor que será inserido
    nova->proximo = NULL;                               // A nova célula aponta para NULL, pois será o último elemento da lista

    Celula *anterior = lista->inicio;                   // Será a célula que guardará o endereço do último elemento da lista
    
    while(anterior->proximo != NULL){                   // Procura pelo último elemento
        anterior = anterior->proximo;
    }

    anterior->proximo = nova;                           // O último elemento da lista aponta para a nova célula
}

/*
    Insere um elemento na posição desejada, 
    tratando a posição como de um vetor [0, 1, 2, 3,...]
*/
void inserirNaPosicao(Lista *lista, int posicao, int valor){    // Recebe como parâmetro a cabeça da lista, a posição e o valor a ser inserido

    if(posicao == 0){                                           // Se for no inicio da lista
        inserirInicio(lista, valor);                            // Utiliza da função inserir no inicio

        return;
    }else if(posicao >= lista->tamanho || posicao < 0){               // Se a posição desejada não existe na lista
        printf("Não é possível inserir um elemento na posição %d\n", posicao);

        return;
    }

    Celula *nova = (Celula *) malloc(sizeof(Celula));           // Cria um espaço para uma nova célula na memória e guarda o endereço em 'nova'
    nova->valor = valor;                                        // A nova célula recebe o valor que será inserido

    Celula *atual = lista->inicio;                              // Irá representar a célula que estará na posição que queremos adicionar o novo elemento
    Celula *anterior = NULL;                                    // Irá representar a célula anterior à nova

    for(int i = 0; i < posicao; i++){                           // Procura a célula da posição desejada
        anterior = atual;                                       // A célula anterior agora tem a posição da atual
        atual = atual->proximo;                                 // E a atual agora tem a posição da posterior à ela
    }

    nova->proximo = atual;                                      // A nova célula ficará antes da atual
    anterior->proximo = nova;                                   // E a anterior ficará antes da nova

    lista->tamanho++;                                           // Aumenta o tamanho da lista
}   

/**********************************************************************
 * REMOÇÕES
***********************************************************************/

/*
    Remove o primeiro elemento da lista
*/
int removerInicio(Lista *lista){        // Recebe como parâmetro a cabeça da lista

    if(ehListaVazia(lista)){            // Verifica se a lista está vazia
        printf("Não existem elementos para serem removidos\n");

        return 0;
    }

    Celula *celula = lista->inicio;     // Guardamos o endereço da primeira célula
    int valor = celula->valor;          // Guardamos o valor que estava na primeira célula

    lista->inicio = celula->proximo;    // Faz a cabeça da lista apontar para a segunda célula

    free(celula);                       // Libera o espaço da memória que a célula ocupava
    return valor;                       //Não é obrigatório, o retorno pode ser void. Neste caso, retorna o valor da célula retirada
}

/*
    Remove um elemento do meio da lista,
    procurando pelo valor que está armazenado nela
*/
void removerMeio(Lista *lista, int valor){              // Recebe como parâmetro a cabeça da lista e o valor que será removido

    if(ehListaVazia(lista)){                            // Verifica se a lista está vazia
        printf("Não existem elementos para serem removidos\n");

        return;
    }

    Celula *anterior = NULL;                            // Representará a célula anterior à que será removida
    Celula *celula = lista->inicio;                     // Representará a célula que será removida

    while(celula != NULL && celula->valor != valor){    // Procura pela célula que possui o mesmo valor do parâmetro
        anterior = celula;                              // A célula anterior agora tem o endereço na célula atual
        celula = celula->proximo;                       // A célula atual agora tem o endereço da sua posterior
    }

    if(celula == NULL){                                 // Se a célula chegou ao fim da lista, então não encontrou o valor
        printf("Valor %d não encontrado na lista\n", valor);

        return;
    }

    anterior->proximo = celula->proximo;                // A célula anterior à que será removida agora aponta para a posterior da celula que será removida
    free(celula);                                       // Libera o espaço alocado para a célula
}

/*
    Remove o último elemento da lista
*/
int removerFim(Lista *lista){       // Recebe como parâmetro a cabeça da lista

    if(ehListaVazia(lista)){        // Verifica se a lista está vazia
        printf("Não existem elementos para serem removidos\n");

        return 0;
    }

    Celula* celula = lista->inicio; // Representará a célula que será apagada. Começa com o endereço do primeiro elemento  

    while(celula->proximo != NULL){ // Percorre a lista até o último elemento
        celula = celula->proximo;   // O endereço guardado na célula agora recebe o endereço da próxima célula
    }

    int valor = celula->valor;      // Guarda o valor armazenado na célula que será removida

    free(celula);                   // Libera o espaço alocado na memória para a célula
    return valor;                   // Não é obrigatório, pode ser retorno void. Neste caso, retorna o valor que estava armazenado na célula removida
}

/*
    Remove um elemento da lista, 
    tratando a posição como um indice, como em
    vetores [0, 1, 2, 3 ...]
*/
void removerPosicao(Lista *lista, int posicao){     // Recebe como parâmetro a cabeça da lista e a posição (inteiro) a ser removida

    if(ehListaVazia(lista)){                        // Verifica se a lista está vazia
        printf("Não existem elementos para serem removidos\n");

        return;
    }

    if(posicao == 0){                         // Se for no inicio da lista
        removerInicio(lista);                       // Utiliza da função remover no inicio

        return;
    }else if(posicao >= lista->tamanho || posicao < 0){   // Se a posição desejada não existe na lista
        printf("Não é possível remover um elemento na posição %d\n", posicao);

        return;
    }

    Celula *anterior = NULL;                        // Representará a célula anterior à que será removida
    Celula *celula = lista->inicio;                 // Representará a célula que será removida

    for(int i = 0; i < posicao; i++){               // Percorre até a posição desejada
        anterior = celula;                          // A célula anterior agora tem o endereço na célula atual
        celula = celula->proximo;                   // A célula atual agora tem o endereço da sua posterior
    }

    anterior->proximo = celula->proximo;            // A célula anterior à que será removida agora aponta para a posterior da celula que será removida
    free(celula);                                   // Libera o espaço alocado para a célula
}