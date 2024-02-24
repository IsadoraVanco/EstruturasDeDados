
// Node z já alocado (versão do livro)
void inserir(Arvore *arvore, Node *z){
    Node *y = NULL;
    Node *x = arvore->raiz;

    while(x != NULL){
        y = x;

        if(z->chave < x->chave){
            x = x->esquerda;
        }else{
            x = x->direita;
        }
    }

    z->pai = y;

    if(y == NULL){
        arvore->raiz = z;
    }else if(z->chave < y->chave){
        y->esquerda = z;
    }else{
        y->direita = z;
    }

    z->esquerda = NULL;
    z->direita = NULL;
    z->cor = vermelho;

    arrumaInsercao(arvore, z);
}

void arrumaInsercao(Arvore *arvore, Node *z){

    while(z->pai->cor == vermelho){
        if(z->pai == z->pai->pai->esquerda){
            y = z->pai->pai->direita;

            if(y->cor == vermelho){         // Caso 1
                z->pai->cor = preto;
                y->cor = preto;
                z->pai->pai->cor = vermelho;
                z = z->pai->pai;
            }else if(z == z->pai->direita){ // Caso 2
                z = z->pai;

                rotacaoL(arvore, z);
            }

            z->pai->cor = preto;            // Caso 3
            z->pai->pai->cor = vermelho;
            rotacaoR(arvore, z->pai->pai);
        }else{                              
            y = z->pai->pai->esquerda;

            if(y->cor == vermelho){         // Caso 1
                z->pai->cor = preto;
                y->cor = preto;
                z->pai->pai->cor = vermelho;
                z = z->pai->pai;
            }else if(z == z->pai->esquerda){ // Caso 2
                z = z->pai;

                rotacaoR(arvore, z);
            }

            z->pai->cor = preto;            // Caso 3
            z->pai->pai->cor = vermelho;
            rotacaoL(arvore, z->pai->pai);
        }
    }

    arvore->raiz->cor = preto;
}

// Utilizando o algoritmo do livro
void rotacaoR(Arvore *arvore, Node *x){
    Node *y = x->esquerda;   // Define y

    x->esquerda = y->direita;   // Transforma a subárvore à esquerda

    if(y->direita != NULL){    // Se y possui um filho à esquerda
        y->direita->pai = x;
    }

    y->pai = x->pai;            // Liga o pai de x a y

    if(x->pai == NULL){
        arvore->raiz = y;
    }else if(x == x->pai->direita){
        x->pai->direita = y;
    }else{
        x->pai->esquerda = y;
    }

    y->direita = x;        // Coloca x à esquerda de y
    x->pai = y;
}

// Utilizando o algoritmo do livro
void rotacaoL(Arvore *arvore, Node *x){
    Node *y = x->direita;   // Define y

    x->direita = y->esquerda;   // Transforma a subárvore à esquerda

    if(y->esquerda != NULL){    // Se y possui um filho à esquerda
        y->esquerda->pai = x;
    }

    y->pai = x->pai;            // Liga o pai de x a y

    if(x->pai == NULL){
        arvore->raiz = y;
    }else if(x == x->pai->esquerda){
        x->pai->esquerda = y;
    }else{
        x->pai->direita = y;
    }

    y->esquerda = x;        // Coloca x à esquerda de y
    x->pai = y;
}
