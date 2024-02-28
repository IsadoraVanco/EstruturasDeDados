
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

void troca(Arvore *arvore, Node *u, Node *v){
    if(u->pai == NULL){
        arvore->raiz = v;
    }else if(u == u->pai->esquerda){
        u->pai->esquerda = v;
    }else{
        u->pai->direita = v;
    }

    v->pai = u->pai;
}

void apagar(Arvore *arvore, Node *z){
    Node *y = z;
    Node *x;

    int corY = y->cor;

    if(z->esquerda == NULL){
        x = z->direita;
        troca(arvore, z, z->direita);
    }else if(z->direita == NULL){
        x = z->esquerda;
        troca(arvore, z, z->esquerda);
    }else{
        y = menor(z->direita);
        corY = y->cor;
        x = y->direita;

        if(y->pai == z){
            x->pai = y;
        }else{
            troca(arvore, y, y->direita);
            y->direita = z->direita;
            y->direita->pai = y;
        }

        troca(arvore, z, y);
        y->esquerda = z->esquerda;
        y->esquerda->pai = y;
        y->cor = z->cor;
    }

    if(corY == preto){
        corrigeApagar(arvore, x);
    }
    
}

void corrigeApagar(Arvore *arvore, Node *x){
    
    while(x != arvore->raiz && x->cor == preto){
        if(x == x->pai->esquerda){      // filho da esquerda
            w = x->pai->direita;
            
            if(w->cor == vermelho){ // Caso 1
                // o irmão de x é vermelho
                w->cor = preto;
                x->pai->cor = vermelho;
                rotacaoL(arvore, x->pai);
                w = x->pai->direita;
            }

            if(w->esquerda->cor == preto && w->direita->cor == preto){ // Caso 2
                // o irmaão de x é preto e os filhos são pretos
                w->cor = vermelho;
                x = x->pai;
            }else if(w->direita->cor == preto){     // Caso 3
                // o irmão de x é preto, o filho da esquerda de w é vermelho 
                // e o filho da direita de w é preto
                w->esquerda->cor = preto;
                w->cor = preto;
                rotacaoR(arvore, w);
                w = x->pai->direita;
            }else{      // Caso 4
            // O irmão de x é preto, o filho à direita de w é vermelho
                w->cor = x->pai->cor;
                x->pai->cor = preto;
                w->direita->cor = preto;
                rotacaoL(arvore, x->pai);
                x = arvore->raiz;
            }

        }else{      // filho da direita
            w = x->pai->esquerda;
            
            if(w->cor == vermelho){ // Caso 1
                // o irmão de x é vermelho
                w->cor = preto;
                x->pai->cor = vermelho;
                rotacaoL(arvore, x->pai);
                w = x->pai->esquerda;
            }

            if(w->esquerda->cor == preto && w->direita->cor == preto){ // Caso 2
                // o irmaão de x é preto e os filhos são pretos
                w->cor = vermelho;
                x = x->pai;
            }else if(w->esquerda->cor == preto){     // Caso 3
                // o irmão de x é preto, o filho da esquerda de w é vermelho 
                // e o filho da direita de w é preto
                w->direita->cor = preto;
                w->cor = preto;
                rotacaoR(arvore, w);
                w = x->pai->esquerda;
            }else{      // Caso 4
            // O irmão de x é preto, o filho à direita de w é vermelho
                w->cor = x->pai->cor;
                x->pai->cor = preto;
                w->esquerda->cor = preto;
                rotacaoL(arvore, x->pai);
                x = arvore->raiz;
            }
        }

        x->cor = preto;
    }
}