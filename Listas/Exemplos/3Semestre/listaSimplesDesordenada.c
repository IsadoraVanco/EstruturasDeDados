/**
 * @file listaSimplesDesordenada.c
 * @brief Implementação de uma estrutura de lista ligada desordenada, 
 * baseado no código do profº Gilberto
 * OBS: Em caso de dúvidas, tente fazer um teste de mesa,
 * ou seja, crie um exemplo e faça passo a passo no papel
*/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 * TYPEDEFS
***********************************************************************/

/*
    Representa a cabeça da lista e suas informações
*/
typedef struct{
    Celula* inicio; // Guarda a célula que está no inicio da lista
    int tamanho;    // Guarda o tamanho da lista 
} Lista;

/*
    Representa cada celula da lista
*/
typedef struct cel{
    int valor;              // Cada célula irá guardar um valor inteiro
    struct cel *proximo;    // O endereço para a próxima célula da lista
} Celula;

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
        return;                                         // Retorna: não insere na lista
    }

    Celula *nova = (Celula *) malloc(sizeof(Celula));   // Cria um espaço para uma nova célula na memória e guarda o endereço em 'nova'
    
    nova->valor = valor;                                // A nova célula recebe o valor que será inserido
    nova->proximo = anterior->proximo;                  // A célula seguinte à nova será a célula que é seguinte ao elemento procurado, dessa forma, o novo elemento será seguinte ao pivo

    anterior->proximo = nova;                           // A célula com valor pivo ficará antes da nova, é importante fazer essa atribuição para não perder o resto da lista
    lista->tamanho++;                                   // Aumenta o atributo que armazena o tamanho da lista
}


void inserirFim(Lista *lista, int v){
    
    Celula *nova = (Celula *) malloc(sizeof(Celula));
    nova->valor = v;
    nova->proximo = NULL;

    Celula *cel = lista->inicio;
    
    while(cel->proximo != NULL){
        cel = cel->proximo;
    }

    cel->proximo = nova;
}

// Tratando a posição como de um vetor [0, 1, 2, 3,...]
void inserirNaPosicao(Lista *lista, int posicao, int v){

    if(posicao == 0){ //Se for no inicio
        inserirInicio(lista, v);

        return;
    }

    Celula *nova = (Celula *) malloc(sizeof(Celula));
    nova->valor = v;

    Celula *atual = lista->inicio;
    Celula *anterior = NULL;

    for(int i = 0; i < posicao; i++){
        anterior = atual;
        atual = atual->proximo;
    }

    nova->proximo = atual;
    anterior->proximo = nova;

    lista->tamanho++;
}


// Tratando a posição como o endereço de um elemento
// o novo elemento será inserido no lugar dele
// OBS: não é implementação do Gilberto
void inserirElementoNaPosicao(Lista *lista, Celula* posicao, int v){

}


/**********************************************************************
 * REMOÇÕES
***********************************************************************/

int removerInicio(Lista *lista){

    Celula *cel = lista->inicio;
    int v = cel->valor;

    lista->inicio = cel->proximo;

    free(cel);
    return v; //Não é obrigatório, o retorno pode ser void
}

void removerMeio(Lista *lista, int v){

    Celula *ant = NULL;
    Celula *cel = lista->inicio;

    while(cel != NULL && cel->valor != v){
        ant = cel;
        cel = cel->proximo;
    }

    if(cel == NULL){
        return;
    }

    ant->proximo = cel->proximo;
    free(cel);
}

int removerFim(Lista *Lista){

    Celula* cel = lista->inicio;

    while(cel->proximo != NULL){
        cel = cel->proximo;
    }

    int v = cel->valor;

    free(cel);
    return v;
}