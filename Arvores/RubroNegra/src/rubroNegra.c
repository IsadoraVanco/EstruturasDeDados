/**
 * @brief Implementação da Árvore Rubro Negra
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Ferramentas/Diretorios/diretorios.h"
#include "../../Ferramentas/Dot/dot.h"
#include "rubroNegra.h"


/*************************************************************
 * Variáveis globais
*************************************************************/

/*
    Conta quantas imagens da árvore foram geradas 
    durante a execução do programa
*/
int qtdPrints = 0;

/*************************************************************
 * Auxiliares
*************************************************************/

int max(int a, int b){

    return (a > b)? a : b;
}

/************************************************************
 * Funções básicas
*************************************************************/

ArvoreRubroNegra *inicializarArvore(){
    ArvoreRubroNegra *nova = malloc(sizeof(ArvoreRubroNegra));
    
    // Node *folhasNulas = (Node *) malloc(sizeof(Node));
    // folhasNulas->pai = NULL;
    // folhasNulas->direita = NULL;
    // folhasNulas->esquerda = NULL;
    // folhasNulas->cor = preto;
    // folhasNulas->chave = 0;

    // nova->folhasNulas = folhasNulas;
    // nova->raiz = folhasNulas;
    nova->raiz = NULL;
    nova->quantidadeElementos = 0;

    return nova;
}

int altura(Node *no){

    if(no == NULL){ // Caso base
        return 0;
    }

    // Encontra a altura das outras sub-árvores
    int esquerda = altura(no->esquerda) + 1;
    int direita = altura(no->direita) + 1;

    return max(esquerda, direita);
}

int alturaNegra(Node *no){

    if(no == NULL){ // Caso base
        return 0;
    }

    // Encontra a altura das outras sub-árvores
    int esquerda = altura(no->esquerda) + 1;
    int direita = altura(no->direita) + 1;

    return max(esquerda, direita);
}

/**********************************
 * Exibição
***********************************/

void exibirArvore(Node *no){
    char cor[10];

    if (no != NULL) {
        if(no->cor == vermelho){
            sprintf(cor, "Vermelho");
        }else{
            sprintf(cor, "Preto");
        }

        if(no->pai == NULL){
            printf("[%d] Cor(%s) Altura(%d) - Raíz\n", no->chave, cor, altura(no));
        } else {
            printf("[%d] Cor(%s) Altura(%d) - Pai[%d]\n", no->chave, cor, altura(no), no->pai->chave);
        }

        exibirArvore(no->esquerda);
        exibirArvore(no->direita);
    }
}

void criarImagemArvore(ArvoreRubroNegra *arvore){

    if(criaPasta("outputs")){
        printf("Ou pasta já criada\n");
    }

    char nome[50];
    sprintf(nome, "./outputs/arvoreRubro-%d", qtdPrints);

    // Cria o arquivo da árvore.dot
    ARQUIVODOT *arvoreArquivo = criarNovoArquivo(nome);
    inicializar(arvoreArquivo, TIPO_ARVORE);

    configurarNodes(arvoreArquivo, FORMA_CIRCULO, "red", "red", "black", FONTE_SANS, 12);

    // Adiciona a raíz
    char valor[50]; // :)
    sprintf(valor, "%d", arvore->raiz->chave);
    
    if(arvore->raiz->cor == vermelho){
        adicionarNovoNode(arvoreArquivo, valor, valor, "", "#b81e1e", "#d02222", "black");
    }else{
        adicionarNovoNode(arvoreArquivo, valor, valor, "", "#333232", "#3f3f3f", "white");
    }

    // Adiciona recursivamente os outros nós
    adicionarNodeArquivo(arvoreArquivo, arvore->raiz->esquerda);
    adicionarNodeArquivo(arvoreArquivo, arvore->raiz->direita);

    finalizar(arvoreArquivo);
    criarImagem(nome);

    qtdPrints++;
}

void adicionarNodeArquivo(ARQUIVODOT *arquivo, Node *no){
    
    if (no != NULL) {
        char valorPai[50], valorFilho[50]; // :)
        sprintf(valorPai, "%d", no->pai->chave);
        sprintf(valorFilho, "%d", no->chave);

        if(no->cor == vermelho){
            adicionarNovoNode(arquivo, valorFilho, valorFilho, "", "#b81e1e", "#d02222", "black");
        }else{
            adicionarNovoNode(arquivo, valorFilho, valorFilho, "", "#333232", "#3f3f3f", "white");
        }

        criarConexaoNodes(arquivo, TIPO_ARVORE, valorPai, valorFilho, "");

        adicionarNodeArquivo(arquivo, no->esquerda);
        adicionarNodeArquivo(arquivo, no->direita);
    }
}

/**********************************
 * Buscas
***********************************/

Node *buscaBinaria(Node *raiz, TIPO_CHAVE chave){

    // Casos bases 
    if(raiz == NULL){ // Não encontrado
        printf("\n->Elemento (%d) não encontrado\n", chave);
        return NULL;
    }else if(raiz->chave == chave){ //Encontrado
        printf("\n->Elemento (%d) encontrado\n", chave);
        return raiz;
    }

    //Casos recursivos
    if(raiz->chave > chave){
        buscaBinaria(raiz->esquerda, chave);
    }else if(raiz->chave < chave){
        buscaBinaria(raiz->direita, chave);
    }

}

Node *encontraMenor(Node *p, Node *ant){

    if(p->esquerda != NULL){
        ant = p;

        return encontraMenor(p->esquerda, ant);
    }
    printf("->Menor encontrado (%d)\n", p->chave);

    return p;
}

/**********************************
 * Rotações
***********************************/

// Utilizando o algoritmo do livro do Thomas Cormen
void rotacaoEsquerda(ArvoreRubroNegra *arvore, Node *x){
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

// Utilizando o algoritmo do livro do Thomas Cormen
void rotacaoDireita(ArvoreRubroNegra *arvore, Node *x){
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

/*************************************************************
 * Correções
*************************************************************/

void arrumaInsercao(ArvoreRubroNegra *arvore, Node *novo){
    Node *pai, *avo;

    // Enquanto o pai do nó a ser modificado (não é a raíz) e é vermelho
    while(novo != arvore->raiz && novo->pai->cor == vermelho){
        printf("Arruma nó %d...\n", novo->chave);
        pai = novo->pai;
        // printf("Pai %d\n", pai->chave);
        avo = novo->pai->pai;
        // printf("Avo %d\n", avo->chave);

        // se o pai do nó é filho da esquerda
        if(avo->esquerda == pai){   
            correcaoEsquerda(arvore, &novo, pai, avo);
        }else{  // se o pai do nó é filho da direita
            correcaoDireita(arvore, &novo, pai, avo);
        }

        printf("Proximo verificar: %d\n", novo->chave);
    }

    arvore->raiz->cor = preto;  // Caso 0
}

void correcaoEsquerda(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo){
    // O tio à direita do nó
    Node *tio = avo->direita;

    // Se o tio é folha nula
    if(tio == NULL){
        if(pai->direita == *no){   // Caso 2 
            printf("=> Caso 2 (esquerda):\n");
            printf("\t1.Nó é da direita\n");
            printf("\t2.Seu pai é rubro da esquerda\n");
            printf("\t3.O tio é negro\n");

            rotacaoEsquerda(arvore, pai);
            // rotacaoDireita(arvore, pai);

            (*no) = (*no)->esquerda;          // Desce a verificação em 1 nível e cai no caso 3
        }else{                          // Caso 3 
            printf("=> Caso 3 (esquerda):\n");
            printf("\t1.Nó é da esquerda\n");
            printf("\t2.Seu pai é rubro da esquerda\n");
            printf("\t3.O tio é negro\n");

            pai->cor = preto;
            avo->cor = vermelho;

            rotacaoDireita(arvore, avo);
            // rotacaoEsquerda(arvore, pai);
        }
    }else if(tio->cor == vermelho){       // Caso 1
        printf("=> Caso 1 (esquerda):\n");
        printf("\t1.Nó é da esquerda ou direita\n");
        printf("\t2.Seu pai é rubro da esquerda\n");
        printf("\t3.O tio é rubro\n");

        pai->cor = preto;
        avo->cor = vermelho;
        tio->cor = preto;

        *no = (*no)->pai->pai;
        printf("av %d\n", (*no)->chave);                   // Sobe a verificação em 2 níveis
        printf("avv %d\n", avo->chave);                   // Sobe a verificação em 2 níveis
    }
}

void correcaoDireita(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo){
    // O tio à esquerda do nó
    Node *tio = avo->esquerda;

    // Se o tio é folha nula
    if(tio == NULL || tio->cor == preto){
        if(pai->esquerda == *no){  // Caso 2
            printf("=> Caso 2 (direita):\n");
            printf("\t1.Nó é da esquerda\n");
            printf("\t2.Seu pai é rubro da direita\n");
            printf("\t3.O tio é negro\n");

            rotacaoDireita(arvore, pai);
            // rotacaoEsquerda(arvore, pai);

            (*no) = (*no)->direita;           // Desce a verificação em 1 nível e cai no caso 3
        }else{                          // Caso 3
            printf("=> Caso 3 (direita):\n");
            printf("\t1.Nó é da direita\n");
            printf("\t2.Seu pai é rubro da direita\n");
            printf("\t3.O tio é negro\n");

            pai->cor = preto;
            avo->cor = vermelho;

            rotacaoEsquerda(arvore, avo);
            // rotacaoDireita(arvore, pai);
        }
    }else if(tio->cor == vermelho){       // Caso 1
        printf("=> Caso 1 (direita):\n");
        printf("\t1.Nó é da esquerda ou direita\n");
        printf("\t2.Seu pai é rubro da direita\n");
        printf("\t3.O tio é rubro\n");

        pai->cor = preto;
        avo->cor = vermelho;
        tio->cor = preto;

        *no = (*no)->pai->pai;                   // Sobe a verificação em 2 níveis
    
        printf("av %d\n", (*no)->chave);                   // Sobe a verificação em 2 níveis
        printf("avv %d\n", avo->chave);
    }
}

/**********************************
 * Inserção
***********************************/

Node *criarNovoNo(TIPO_CHAVE chave){
    Node *novo = calloc(1, sizeof(Node));
    
    if(novo){
        novo->chave = chave;
        novo->cor = vermelho;       // Todo novo nó deve ser vermelho (regra)
    }else{
        printf("Erro ao alocar espaço para o novo nó\n");
        exit(EXIT_FAILURE);         // Tratamento de erro 
    }

    return novo;
}

void inserir(ArvoreRubroNegra *arvore, TIPO_CHAVE chave){

    // Se o novo nó é raíz
    if(arvore->raiz == NULL){
        Node *novo = criarNovoNo(chave);
        novo->cor = preto;
        arvore->raiz = novo;
        arvore->quantidadeElementos++;

        printf("\n::Elemento (%d) adicionado na raíz\n", chave);
        return;
    }

    Node *pai = NULL;
    Node *aux = arvore->raiz;

    // Procura o melhor lugar para o novo
    while(aux != NULL){
        pai = aux;

        if(aux->chave > chave){
            aux = aux->esquerda;
        }else if(aux->chave < chave){
            aux = aux->direita;
        }else{
            printf("\n::Elemento (%d) já inserido na árvore\n", chave);
            return;
        }
    }

    Node *novo = criarNovoNo(chave);

    novo->pai = pai;

    // Faz as ligações de pai e filho
    if(pai->chave > chave){
        pai->esquerda = novo;
    }else{
        pai->direita = novo;
    }

    arvore->quantidadeElementos++;
    printf("\n::Elemento (%d) adicionado na árvore\n", chave);

    arrumaInsercao(arvore, novo);
}

/**********************************
 * Exclusões
***********************************/

// Algoritmo do livro
void troca(ArvoreRubroNegra *arvore, Node *u, Node *v){
    printf("(Troca nós)\n");

    if(u->pai == NULL){
        arvore->raiz = v;
    }else if(u == u->pai->esquerda){
        u->pai->esquerda = v;
    }else{
        u->pai->direita = v;
    }

    v->pai = u->pai;            // Será?
}

// Algoritmo do livro
void apagar(ArvoreRubroNegra *arvore, TIPO_CHAVE chave){
    printf("\n================================\n");
    printf("\tRemover elemento\n");
    printf("================================\n");

    // Procura pelo elemento na árvore que será apagado
    Node *deletado = buscaBinaria(arvore->raiz, chave);

    if(deletado == NULL){   // Não encontrou o elemento na árvore
        return;
    }

    printf("->Analisando caso para exclusão de (%d):\n", deletado->chave);

    Node *aux = NULL;

    // Guarda a cor inicial do nó que será deletado
    COR corInicial = deletado->cor;

    if(deletado->esquerda == NULL && deletado->direita == NULL){
        printf("* O nó não tem filhos\n");

        if(deletado == arvore->raiz){
            printf("* É raíz\n");

            arvore->raiz = NULL;
            free(deletado);
            return;
        }else{
            printf("* É folha\n");

            if(deletado->pai->esquerda == deletado){
                // Nó era filho da esquerda
                deletado->pai->esquerda = NULL;
            }else{
                // Nó era filho da direita
                deletado->pai->direita = NULL;
            }
        }

    }else if(deletado->esquerda == NULL){
        printf("* O nó possui um filho a direita\n");
    
        aux = deletado->direita;
        aux->pai = deletado->pai;

        troca(arvore, deletado, aux);
    }else if(deletado->direita == NULL){
        printf(":: O nó possui um filho a esquerda\n");

        aux = deletado->esquerda;
        aux->pai = deletado->pai;

        troca(arvore, deletado, aux);
    }else{
        printf("* O nó possui dois filhos\n");

        Node *anterior;
        Node *menor = encontraMenor(deletado->direita, anterior);

        // Guarda a cor do menor
        corInicial = menor->cor;

        aux = menor->direita;

        // if(aux == NULL){    // aux é uma folha nula
        //     if(menor->pai != deletado){
        
        //         // troca(arvore, menor, menor->direita);   // ???
        //         // aux->pai = menor->pai;
        //         menor->pai->esquerda = NULL;

        //         menor->direita = deletado->direita;
        //         menor->direita->pai = menor;
        //     }
        // }else{
        //     if(menor->pai == deletado){
        //         aux->pai = menor;
        //     }else{
        //         // troca(arvore, menor, menor->direita);   // ???
        //         aux->pai = menor->pai;
        //         menor->pai->esquerda = aux;

        //         menor->direita = deletado->direita;
        //         menor->direita->pai = menor;
        //     }
        // }
        
        if(aux != NULL){
            if(menor->pai == deletado){
                aux->pai = menor;
            }else{
                aux->pai = menor->pai;
            }
        }

        if(menor->pai != deletado){
            menor->pai->esquerda = aux;
            menor->direita = deletado->direita;
            menor->direita->pai = menor;
        }

        menor->esquerda = deletado->esquerda;
        menor->esquerda->pai = menor;
        menor->cor = deletado->cor;
        menor->pai = deletado->pai;

        troca(arvore, deletado, menor);
    }

    criarImagemArvore(arvore);  //teste :)
    
    // Se o nó removido é preto, precisa balancear a arvore (duplo preto)
    if(corInicial == preto){
        corrigeApagar(arvore, aux);
    }

    // Se o nó é rubro, remove normalmente
    free(deletado);
    printf(":: Nó removido\n");
}

// Algoritmo do livro
void corrigeApagar(ArvoreRubroNegra *arvore, Node *no){
    printf("=> Corrigindo a exclusão:\n");

    Node *irmao;

    while(no != arvore->raiz && (no == NULL || no->cor == preto)){
        printf("***** Caso 3 (DUPLO PRETO) *****\n");

        if(no == NULL){ // concertar!!
            printf("Folha nula\n");
            return;
        }
        
        if(no == no->pai->esquerda){      // filho da esquerda
            printf("-> Nó (%d) é filho da esquerda\n", no->chave);
            
            irmao = no->pai->direita;
            
            if(irmao->cor == vermelho){     // Caso 3.1
                printf("\n*** Caso 3.1 (esquerda) ***\n");
                printf("\ta) O nó é preto;\n");
                printf("\tb) O irmão é vermelho;\n");

                printf("\n=> Procedimentos:\n\n");
                
                irmao->cor = preto;
                printf("1. Pai fica preto;\n");

                no->pai->cor = vermelho;
                printf("2. Irmão fica rubro;\n");

                rotacaoEsquerda(arvore, no->pai);
                printf("3. Rotaciona o pai para a esquerda;\n");

                irmao = no->pai->direita;       // será?
                printf("4. Sobe a verificação para (%d);\n", irmao->chave);
                printf("5. Vai para o caso 3.2, 3.3 ou 3.4\n");

            }else if(irmao->esquerda->cor == preto && irmao->direita->cor == preto){  // Caso 3.2
                printf("\n*** Caso 3.2 (esquerda) ***\n");
                printf("\ta) O nó é preto;\n");
                printf("\tb) O irmão é preto;\n");
                printf("\tc) Os filhos do irmão são pretos;\n");

                printf("\n=> Procedimentos:\n\n");

                irmao->cor = vermelho;
                printf("1. Irmão fica rubro;\n");

                no = no->pai;
                printf("2. Sobe a verificação para o pai (%d);\n", no->chave);

            }else{
                // Caso 3.3
                if(irmao->direita->cor == preto){           
                    printf("\n*** Caso 3.3 (esquerda) ***\n");
                    printf("\ta) O nó é preto;\n");
                    printf("\tb) O irmão é preto;\n");
                    printf("\tc) O filho da direita do irmão é preto;\n");

                    printf("\n=> Procedimentos:\n\n");

                    irmao->cor = vermelho;              // preto?
                    printf("1. O irmão fica rubro;\n");
                    
                    irmao->esquerda->cor = preto;
                    printf("2. O filho esquerdo do irmão fica preto;\n");

                    rotacaoDireita(arvore, irmao);
                    printf("3. Rotaciona o irmão para a direita;\n");

                    irmao = no->pai->direita;       // Será?
                    printf("4. Atualiza o irmão (%d);\n", irmao->chave);
                    printf("5. Vai para o caso 3.4;\n");
                } 
                
                // Caso 3.4
                printf("\n*** Caso 3.4 (esquerda) ***\n");
                printf("\ta) O nó é preto;\n");
                printf("\tb) O irmão é preto;\n");
                printf("\tc) O filho da direita do irmão é vermelho;\n");

                printf("\n=> Procedimentos:\n\n");
                
                irmao->cor = no->pai->cor;
                printf("1. O irmão copia a cor do pai;\n");

                no->pai->cor = preto;
                irmao->direita->cor = preto;
                printf("2. O pai e o sobrinho da direita ficam preto;\n");

                rotacaoEsquerda(arvore, no->pai);
                printf("3. Rotaciona o pai para a esquerda;\n");

                no = arvore->raiz;           // esta certo? 
                printf("4. Atualiza a nova raíz (%d);\n", no->chave);
            }

        }else{      // filho da direita
            printf("-> Nó (%d) é filho da direita\n", no->chave);
            
            irmao = no->pai->esquerda;
            
            if(irmao->cor == vermelho){ // Caso 3.1
                printf("\n*** Caso 3.1 (direita) ***\n");
                printf("\ta) O nó é preto;\n");
                printf("\tb) O irmão é vermelho;\n");

                printf("\n=> Procedimentos:\n\n");
                
                irmao->cor = preto;
                printf("1. Pai fica preto;\n");

                no->pai->cor = vermelho;
                printf("2. Irmão fica rubro;\n");

                rotacaoDireita(arvore, no->pai);
                printf("3. Rotaciona o pai para a direita;\n");

                irmao = no->pai->esquerda;       // será?
                printf("4. Sobe a verificação para (%d);\n", irmao->chave);
                printf("5. Vai para o caso 3.2, 3.3 ou 3.4\n");

            }else if(irmao->esquerda->cor == preto && irmao->direita->cor == preto){  // Caso 3.2
                printf("\n*** Caso 3.2 (direita) ***\n");
                printf("\ta) O nó é preto;\n");
                printf("\tb) O irmão é preto;\n");
                printf("\tc) Os filhos do irmão são pretos;\n");

                printf("\n=> Procedimentos:\n\n");

                irmao->cor = vermelho;
                printf("1. Irmão fica rubro;\n");

                no = no->pai;
                printf("2. Sobe a verificação para o pai (%d);\n", no->chave);

            }else{
                // Caso 3.3
                if(irmao->esquerda->cor == preto){           
                    printf("\n*** Caso 3.3 (direita) ***\n");
                    printf("\ta) O nó é preto;\n");
                    printf("\tb) O irmão é preto;\n");
                    printf("\tc) O filho da esquerda do irmão é preto;\n");

                    printf("\n=> Procedimentos:\n\n");

                    irmao->cor = vermelho;              // preto?
                    printf("1. O irmão fica rubro;\n");
                    
                    irmao->direita->cor = preto;
                    printf("2. O filho direito do irmão fica preto;\n");

                    rotacaoEsquerda(arvore, irmao);
                    printf("3. Rotaciona o irmão para a esquerda;\n");

                    irmao = no->pai->esquerda;       // Será?
                    printf("4. Atualiza o irmão (%d);\n", irmao->chave);
                    printf("5. Vai para o caso 3.4;\n");
                } 
                
                // Caso 3.4
                printf("\n*** Caso 3.4 (direita) ***\n");
                printf("\ta) O nó é preto;\n");
                printf("\tb) O irmão é preto;\n");
                printf("\tc) O filho da esquerda do irmão é vermelho;\n");

                printf("\n=> Procedimentos:\n\n");
                
                irmao->cor = no->pai->cor;
                printf("1. O irmão copia a cor do pai;\n");

                no->pai->cor = preto;
                irmao->esquerda->cor = preto;
                printf("2. O pai e o sobrinho da esquerda ficam preto;\n");

                rotacaoDireita(arvore, no->pai);
                printf("3. Rotaciona o pai para a direita;\n");

                no = arvore->raiz;           // esta certo? 
                printf("4. Atualiza a nova raíz (%d);\n", no->chave);
            }
        }
    }
    
    no->cor = preto;
}

void destruirAux(Node *subRaiz){

    //Casos bases
    if(subRaiz == NULL){ // Não é nó
        return;
    }else if(subRaiz->esquerda == NULL && subRaiz->direita == NULL){ // Nó folha
        printf("Elemento follha %d removido\n", subRaiz->chave);
        free(subRaiz);
        return;
    }
    
    // Casos recursivos
    if(subRaiz->esquerda != NULL && subRaiz->direita != NULL){ //Nó com 2 filhos 
        destruirAux(subRaiz->esquerda);
        destruirAux(subRaiz->direita);
    }else{  // Nó com um filho
        if(subRaiz->esquerda != NULL){
            destruirAux(subRaiz->esquerda);
        }else{
            destruirAux(subRaiz->direita);
        }
    }

    // printf("Elemento %d removido\n", subRaiz->chave);
    free(subRaiz);
}

void destruirArvore(ArvoreRubroNegra *arvore){

    // Se a árvore foi inicializada
    if(arvore->quantidadeElementos > 0){
        destruirAux(arvore->raiz->esquerda);
        destruirAux(arvore->raiz->direita);

        free(arvore->raiz);
    }

    free(arvore);
    // printf("Árvore apagada\n");
}
