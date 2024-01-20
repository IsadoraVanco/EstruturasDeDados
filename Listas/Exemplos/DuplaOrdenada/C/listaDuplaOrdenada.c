/**
 * @file listaDuplaOrdenada.c
 * @brief Implementação de uma estrutura de lista duplamente encadeada ordenada, 
 * baseado no código do Programe Seu Futuro (https://youtube.com/@programeseufuturo?si=yMJOy3Cuoom1gP0D)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

void inserirInicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;

        if(*lista){ //Se há outros elementos na lista
            (*lista)->anterior = novo;
        }

        *lista = novo;
    }else{
        printf("Erro ao alocar memória\n");
    }
}

void inserirFim(No **lista, int num){
    No *aux;
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL){ //É o primeiro elemento da lista
            *lista = novo;
            novo->anterior = NULL;
        }else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memória\n");
    }
}

void inserirMeio(No **lista, int num, int ant){
    No *aux;
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL){ //É o primeiro elemento da lista
            *lista = novo;
            novo->anterior = NULL;
            novo->proximo = NULL;
        }else{
            aux = *lista;
            while(aux->proximo && aux->valor != ant){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memória\n");
    }
}

void inserirOrdenado(No **lista, int num){
    No *aux;
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL){ //É o primeiro elemento da lista
            *lista = novo;
            novo->anterior = NULL;
            novo->proximo = NULL;

        }else if(novo->valor < (*lista)->valor){ // É menor que o primeiro/todos
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;

            if(aux->proximo){
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memória\n");
    }
}

No* remover(No **lista, int num){
    No *aux;
    No *remover = NULL;

    if(*lista){ 
        if((*lista)->valor == num){ //Se for o primeiro elemento da lista
            remover = *lista;
            *lista = remover->proximo;

            if(*lista){ //Caso exista mais elementos na lista
                (*lista)->anterior = NULL;
            }
        }else{
            aux = *lista;

            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }

            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;

                if(aux->proximo){
                    aux->proximo->anterior = aux;
                }
            }
        }
    }

    return remover;
}

No* buscar(No **lista, int num){
    No *aux;
    No *no = NULL;

    aux = *lista;

    while(aux && aux->valor != num){
        aux = aux->proximo;
    }

    if(aux){
        no = aux;
    }

    return no;
}

void imprimirDoInicio(No *no){
    printf("Lista (do inicio para o fim): \n");

    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }

    printf("\n");
}

No* ultimoElemento(No **lista){
    No *aux = *lista;

    while(aux){
        aux = aux->proximo;
    }

    return aux;
}

void imprimirDoFim(No *no){
    printf("Lista (do fim para o inicio): \n");

    while(no){
        printf("%d ", no->valor);
        no = no->anterior;
    }

    printf("\n");
}