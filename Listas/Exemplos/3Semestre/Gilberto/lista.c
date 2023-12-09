/**
 * @file listaSimples.c
 * @brief Implementação de uma estrutura de 
 * lista ligada, pelo profº Gilberto
*/

/**********************************************************************
 * TYPEDEFS
***********************************************************************/

typedef struct{
    Celula* inicio;
    int tamanho;
} Lista;

typedef struct cel{
    int valor;
    struct cel *prox;
}Celula;

/**********************************************************************
 * FUNÇÕES BÁSICAS
***********************************************************************/

Lista *inicializar(){

    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->tamanho = 0;
    nova->inicio = NULL;

    return nova;
}

Celula *buscar(Lista* lista, int v){

    Celula* cel = lista->inicio;

    while(cel != NULL){
        if(cel->valor == v){
            return cel;
        }else{
            cel = cel->prox;
        }
    }

    return NULL;
}

void apagar(Lista *lista){

    Celula *atual = lista->inicio;
    Celula *proximo = atual->prox;

    for(int i = lista->tamanho; i > 0; i--){
        free(atual);
        atual = proximo;
        proximo = atual->prox;
    }

    free(lista);
}

/**********************************************************************
 * INSERÇÕES
***********************************************************************/

void inserirInicio(Lista *lista, int v){

    Celula *nova = malloc (sizeof(Celula));

    nova->valor = v;
    nova->prox = lista->inicio;

    lista->inicio = nova;
    lista->tamanho++;
}

void inserirNoMeio(Lista *lista, int v, int pivo){

    Celula *nova = (Celula *) malloc(sizeof(Celula));
    nova->valor = v;

    Celula *anterior = buscar(lista, pivo);

    nova->prox = anterior->prox;
    anterior->prox = nova;

    lista->tamanho++;
}

// Tratando a posição como de um vetor [0, 1, 2, 3,...]
void inserirNaPosicao(Lista *lista, int v, int posicao){

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
        atual = atual->prox;
    }

    nova->prox = atual;
    anterior->prox = nova;

    lista->tamanho++;
}