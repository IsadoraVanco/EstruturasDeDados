/**
 * @file binaria.c
 * @brief Implementação da Árvore Binária
 * 
*/

/**********************************************************************
 * TYPEDEFS
***********************************************************************/

/**
 * @brief Representa um nó da árvore, armazena uma informação (int),
 * um ponteiro para o nó da esquerda e um ponteiro para o nó da direita.
*/
typedef struct StNode{
    int info;
    struct StNode *esquerda;
    struct StNode *direita;
} Node;

/**
 * @brief Representa a raiz da árvore
*/
typedef struct StRaiz{
    Node* raiz;
    int altura;
} Arvore;

/**********************************************************************
 * MÉTODOS BÁSICOS
***********************************************************************/

Arvore* criaArvore(){
    Arvore *nova = (Arvore *) malloc(sizeof(Arvore));

    return nova;
}

int getAltura(Arvore* raiz){
    return raiz->altura;
}

/**********************************************************************
 * PERCURSOS
***********************************************************************/

void percorrerEmNivel(Arvore* raiz){
/*
Percurso_nivel ( T ) // T é o nó raiz

Esvazia(Fila);
Enfila (T);
Enquanto (Fila não estiver Vazia):

Desenfila (p);
Visita (p);
Enfila (p−>esq);
Enfila (p−>dir);

Fim enquanto;

Fim;
*/
}

void percorrerEmPreordem(Arvore* raiz){
/*
Pre-Ordem ( T )

Esvazia (Pilha);
PUSH (T);
Enquanto(topo != NULO) //pilha não vazia

POP (p); Visita (p);
PUSH (p−>dir);
PUSH (p−>esq);

Fim enquanto;

Fim;
*/
}

void percorrerEmOrdemSimetrica(Arvore* raiz){

}

void percorrerEmPosOrdem(Arvore* raiz){

}