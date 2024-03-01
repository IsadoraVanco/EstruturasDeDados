/**
 * @brief Implementação da Árvore Rubro Negra
*/

#include <stdio.h>
#include <stdlib.h>
#include "Ferramentas/Diretorios/diretorios.h"
#include "Ferramentas/Dot/dot.h"
#include "rubroNegra.h"


/*************************************************************
 * Variáveis globais
*************************************************************/

/**
 * Quantidade de imagens da árvore fque foram geradas
 * durante a execução do programa
*/
int qtdPrints = 0;

/**
 * Quantidade de comparações feitas em uma função para
 * calcular o custo médio
*/
int qtdComparacoes = 0;

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
    
    Node *folhasNulas = (Node *) malloc(sizeof(Node));
    // folhasNulas->pai = NULL;
    folhasNulas->direita = NULL;
    folhasNulas->esquerda = NULL;
    folhasNulas->cor = preto;
    folhasNulas->chave = 0;

    nova->folhasNulas = folhasNulas;
    nova->raiz = folhasNulas;
    // nova->raiz = NULL;
    nova->quantidadeElementos = 0;

    return nova;
}

// Algoritmo do livro do Thomas Cormen
void trocar(ArvoreRubroNegra *arvore, Node *pai, Node *filho){
    printf("->Troca nós pai (%d) e filho (%d)\n", pai->chave, filho->chave);

    if(pai->pai == NULL || pai->pai == arvore->folhasNulas){ // É raíz
        arvore->raiz = filho;
    }else if(pai == pai->pai->esquerda){ // O pai é filho da esquerda
        pai->pai->esquerda = filho;
    }else{      // O pai é filho da direita
        pai->pai->direita = filho;  
    }

    filho->pai = pai->pai;
}

int altura(ArvoreRubroNegra *arvore, Node *no){

    if(no == arvore->folhasNulas){ // Caso base
        return 0;
    }

    // Encontra a altura das outras sub-árvores
    int esquerda = altura(arvore, no->esquerda) + 1;
    int direita = altura(arvore, no->direita) + 1;

    return max(esquerda, direita);
}

int alturaNegra(ArvoreRubroNegra *arvore, Node *no){

    if(no == arvore->folhasNulas){ // Caso base
        return 0;
    }

    // Encontra a altura das outras sub-árvores
    int direita = 0;
    int esquerda = 0;

    if(no->cor == preto){
        direita = alturaNegra(arvore, no->direita) + 1;
        esquerda = alturaNegra(arvore, no->esquerda) + 1;
    }else{
        direita += alturaNegra(arvore, no->direita);
        esquerda += alturaNegra(arvore, no->esquerda);
    }

    return max(esquerda, direita);
}

void contarNos(ArvoreRubroNegra *arvore, Node *no, int *noPreto, int *noVermelho){
    if(no == arvore->folhasNulas){ // Caso base
        return;
    }

    if(no->cor == preto){
        (*noPreto)++;
    }else{
        (*noVermelho)++;
    }

    contarNos(arvore, no->esquerda, noPreto, noVermelho);
    contarNos(arvore, no->direita, noPreto, noVermelho);
}

void obterPorcentagemCores(ArvoreRubroNegra *arvore){
    int nosPretos = 0;
    int nosVermelhos = 0;

    // Desconsiderando os nós folhas nulas
    contarNos(arvore, arvore->raiz, &nosPretos, &nosVermelhos);

    printf("-> Total de nós: %d\n", arvore->quantidadeElementos);
    
    if(arvore->quantidadeElementos == 0){
        printf("-> Nós pretos = nós vermelhos = 0\n");
    }else{
        printf("-> Nós pretos: %d (%.2lf)\n", nosPretos, ((double) nosPretos / arvore->quantidadeElementos) * 100);
        printf("-> Nós Vermelhos: %d (%.2lf)\n", nosVermelhos, ((double) nosVermelhos / arvore->quantidadeElementos) * 100);
    }
}

/*************************************************************
 * Exibições
*************************************************************/

void exibirArvore(ArvoreRubroNegra *arvore, Node *no){
    char cor[10];

    if(no != arvore->folhasNulas) {
        if(no->cor == vermelho){
            sprintf(cor, "Vermelho");
        }else{
            sprintf(cor, "Preto");
        }

        if(no->pai == arvore->folhasNulas){
            printf("[%d] Cor(%s) Altura(%d) Altura Negra(%d) - Raíz\n", no->chave, cor, altura(arvore, no), alturaNegra(arvore, no));
        } else {
            printf("[%d] Cor(%s) Altura(%d) Altura Negra(%d) - Pai[%d]\n", no->chave, cor, altura(arvore, no), alturaNegra(arvore, no), no->pai->chave);
        }

        exibirArvore(arvore, no->esquerda);
        exibirArvore(arvore, no->direita);
    }
}

void criarImagemArvore(ArvoreRubroNegra *arvore){

    criaPasta("outputs");

    char nome[50];
    sprintf(nome, "./outputs/arvoreRN-%d", qtdPrints);

    // Cria o arquivo da árvore.dot
    ARQUIVODOT *arvoreArquivo = criarNovoArquivo(nome);
    inicializar(arvoreArquivo, TIPO_ARVORE);

    configurarNodes(arvoreArquivo, FORMA_CIRCULO, "red", "red", "black", FONTE_SANS, 12);

    // Adiciona a raíz
    char valor[50]; // :)

    if(arvore->quantidadeElementos == 0){
        sprintf(valor, "NULL");
    }else{
        sprintf(valor, "%d", arvore->raiz->chave);
    }
    
    if(arvore->raiz->cor == vermelho){
        adicionarNovoNode(arvoreArquivo, valor, valor, "circle", "#b81e1e", "#d02222", "black");
    }else{
        adicionarNovoNode(arvoreArquivo, valor, valor, "circle", "#333232", "#3f3f3f", "white");
    }

    // Adiciona recursivamente os outros nós
    adicionarNodeArquivo(arvoreArquivo, arvore, arvore->raiz->esquerda);
    adicionarNodeArquivo(arvoreArquivo, arvore, arvore->raiz->direita);

    finalizar(arvoreArquivo);
    criarImagem(nome);

    qtdPrints++;
}

void adicionarNodeArquivo(ARQUIVODOT *arquivo, ArvoreRubroNegra *arvore, Node *no){
    
    if (no != arvore->folhasNulas && no != NULL) {
        char valorPai[50], valorFilho[50]; // :)
        sprintf(valorPai, "%d", no->pai->chave);
        sprintf(valorFilho, "%d", no->chave);

        if(no->cor == vermelho){
            adicionarNovoNode(arquivo, valorFilho, valorFilho, "circle", "#b81e1e", "#d02222", "black");
        }else{
            adicionarNovoNode(arquivo, valorFilho, valorFilho, "circle", "#333232", "#3f3f3f", "white");
        }

        criarConexaoNodes(arquivo, TIPO_ARVORE, valorPai, valorFilho, "");

        adicionarNodeArquivo(arquivo, arvore, no->esquerda);
        adicionarNodeArquivo(arquivo, arvore, no->direita);
    }
}

/*************************************************************
 * Buscas
*************************************************************/

int calcularCustosBusca(ArvoreRubroNegra *arvore, int valor){
    qtdComparacoes = 0;

    Node *elemento = buscaBinaria(arvore, arvore->raiz, valor);

    if(elemento){
        printf("\nNo endereço: %p\n", elemento);
        printf("A altura total (%d) e altura negra (%d)\n\n", altura(arvore, elemento), alturaNegra(arvore, elemento));
    }

    printf("-> Quantidade de comparações feitas para a busca: %d\n", qtdComparacoes);

    return qtdComparacoes;
}

Node *buscaBinaria(ArvoreRubroNegra *arvore, Node *raiz, TIPO_CHAVE chave){

    // Casos bases 
    if(raiz == arvore->folhasNulas || raiz == NULL){ // Não encontrado
        qtdComparacoes++;
        printf("->Elemento (%d) não encontrado\n", chave);
        
        return NULL;
    }else if(raiz->chave == chave){ //Encontrado
        qtdComparacoes++;
        printf("->Elemento (%d) encontrado\n", chave);

        return raiz;
    }

    //Casos recursivos
    if(raiz->chave > chave){
        qtdComparacoes++;
        buscaBinaria(arvore, raiz->esquerda, chave);
    }else if(raiz->chave < chave){
        qtdComparacoes++;
        buscaBinaria(arvore, raiz->direita, chave);
    }

}

Node *encontrarMenor(ArvoreRubroNegra *arvore, Node *no, Node *ant){

    if(no->esquerda != NULL && no->esquerda != arvore->folhasNulas){
        ant = no;

        return encontrarMenor(arvore, no->esquerda, ant);
    }
    printf("->Menor encontrado (%d)\n", no->chave);

    return no;
}

/*************************************************************
 * Rotações
*************************************************************/

// Utilizando o algoritmo do livro do Thomas Cormen
void rotacaoEsquerda(ArvoreRubroNegra *arvore, Node *pai){
    // Nó é filho da direita
    Node *no = pai->direita;   

    // printf("RL: pai = %d e no = %d\n", pai->chave, no->chave);

    // Transforma a subárvore à esquerda 
    pai->direita = no->esquerda;   

    // Se o nó possui um filho à esquerda
    if(no->esquerda != arvore->folhasNulas && no->direita != NULL){
        no->esquerda->pai = pai;
    }

    no->pai = pai->pai;           
    // printf("RL: avo = %d\n", pai->pai->chave);

    if(pai->pai == arvore->folhasNulas){
        // printf("RL: O pai é raiz\n");
        arvore->raiz = no;
    }else if(pai == pai->pai->esquerda){
        pai->pai->esquerda = no;
    }else{
        pai->pai->direita = no;
    }

    no->esquerda = pai;     
    pai->pai = no;
}

// Utilizando o algoritmo do livro do Thomas Cormen
void rotacaoDireita(ArvoreRubroNegra *arvore, Node *pai){
    // Nó é filho da esquerda
    Node *no = pai->esquerda;   

    // printf("RR: pai = %d e no = %d\n", pai->chave, no->chave);
    pai->esquerda = no->direita; 

    if(no->direita != arvore->folhasNulas && no->direita != NULL){    // Se y possui um filho à esquerda
        no->direita->pai = pai;
    }

    no->pai = pai->pai; 

    if(pai->pai == arvore->folhasNulas){
        arvore->raiz = no;
    }else if(pai == pai->pai->direita){
        pai->pai->direita = no;
    }else{
        pai->pai->esquerda = no;
    }

    no->direita = pai;       
    pai->pai = no;
}

/*************************************************************
 * Correções de inserção
*************************************************************/

void corrigirInsercao(ArvoreRubroNegra *arvore, Node *novo){
    Node *pai, *avo;

    // Enquanto o pai do nó a ser modificado (não é a raíz) e é vermelho
    while(novo->pai != arvore->raiz && novo->pai->cor == vermelho){
        printf("\nVerificando nó (%d) com pai vermelho...\n", novo->chave);
        
        pai = novo->pai;
        // printf("Pai %d\n", pai->chave);
        avo = novo->pai->pai;
        // printf("Avo %d\n", avo->chave);

        // se o pai do nó é filho da esquerda
        if(avo->esquerda == pai){   
            corrigirInsercaoEsquerda(arvore, &novo, pai, avo);
        }else{  // se o pai do nó é filho da direita
            corrigirInsercaoDireita(arvore, &novo, pai, avo);
        }
    }

    // Saída bonitinha :)
    if(novo->pai->cor == preto){ 
        printf("\nO nó (%d) tem pai preto\n", novo->chave);
    }else{
        printf("\nO nó (%d) tem pai na raíz\n", novo->chave);
    }

    arvore->raiz->cor = preto;  // Caso 0
    printf("Verificação não é mais necessária\n");
}

void corrigirInsercaoEsquerda(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo){
    // O tio à direita do nó
    Node *tio = avo->direita;

    // Se o tio é folha nula
    if(tio == arvore->folhasNulas || tio->cor == preto){
        // Caso 2
        if(pai->direita == *no){    
            printf("\n*** Caso 2 (esquerda) ***\n");
            printf("\ta) O nó é da direita;\n");
            printf("\tb) O pai é rubro da esquerda;\n");
            printf("\tc) O tio é negro;\n");

            printf("\n=> Procedimentos:\n\n");

            rotacaoEsquerda(arvore, pai);
            printf("1. Rotaciona o pai para a esquerda;\n");

            (*no) = (*no)->esquerda; 
            pai = (*no)->pai;
            avo = pai->pai;
            printf("2. Desce a verificação para o pai (%d);\n", pai->chave);

            printf("3. Vai para o caso 3;\n");
        }
        
        // Caso 3 
        printf("\n*** Caso 3 (esquerda) ***\n");
        printf("\ta) O nó é da esquerda;\n");
        printf("\tb) O pai é rubro da esquerda;\n");
        printf("\tc) O tio é negro;\n");

        printf("\n=> Procedimentos:\n\n");

        pai->cor = preto;
        printf("1. O pai fica preto;\n");

        avo->cor = vermelho;
        printf("2. O avô fica rubro;\n");

        rotacaoDireita(arvore, avo);
        printf("3. Rotaciona o avô para a direita;\n");

    }else if(tio->cor == vermelho){  // Caso 1
        printf("\n*** Caso 1 (esquerda) ***\n");
        printf("\ta) O nó é da esquerda ou direita;\n");
        printf("\tb) O pai é rubro da esquerda;\n");
        printf("\tc) O tio é rubro;\n");

        printf("\n=> Procedimentos:\n\n");

        pai->cor = preto;
        tio->cor = preto;
        printf("1. O pai e o tio ficam pretos;\n");

        avo->cor = vermelho;
        printf("2. O avô fica rubro;\n");

        *no = (*no)->pai->pai;
        printf("3. Sobe a verificação para o avô (%d);\n", (*no)->chave);
    }
}

void corrigirInsercaoDireita(ArvoreRubroNegra *arvore, Node **no, Node *pai, Node *avo){
    // O tio à esquerda do nó
    Node *tio = avo->esquerda;

    // Se o tio é folha nula
    if(tio == arvore->folhasNulas || tio->cor == preto){
        // Caso 2
        if(pai->esquerda == *no){  
            printf("\n*** Caso 2 (direita) ***\n");
            printf("\ta) O nó é da esquerda;\n");
            printf("\tb) O pai é rubro da direita;\n");
            printf("\tc) O tio é negro;\n");

            printf("\n=> Procedimentos:\n\n");

            rotacaoDireita(arvore, pai);
            printf("1. Rotaciona o pai para a direita;\n");

            (*no) = (*no)->direita; 
            pai = (*no)->pai;
            avo = pai->pai;
            printf("2. Desce a verificação para o pai (%d);\n", pai->chave); 

            printf("3. Vai para o caso 3;\n");
        }
            
        // Caso 3
        printf("\n*** Caso 3 (direita) ***\n");
        printf("\ta) O nó é da direita;\n");
        printf("\tb) O pai é rubro da direita;\n");
        printf("\tc) O tio é negro;\n");

        printf("\n=> Procedimentos:\n\n");

        pai->cor = preto;
        printf("1. O pai fica preto;\n");

        avo->cor = vermelho;
        printf("2. O avô fica rubro;\n");

        rotacaoEsquerda(arvore, avo);
        printf("3. Rotaciona o avô para a esquerda;\n");

    }else if(tio->cor == vermelho){     // Caso 1
        printf("\n*** Caso 1 (direita) ***\n");
        printf("\ta) O nó é da esquerda ou direita;\n");
        printf("\tb) O pai é rubro da direita;\n");
        printf("\tc) O tio é rubro;\n");

        printf("\n=> Procedimentos:\n\n");

        pai->cor = preto;
        tio->cor = preto;
        printf("1. O pai e o tio ficam pretos;\n");

        avo->cor = vermelho;
        printf("2. O avô fica rubro;\n");

        *no = (*no)->pai->pai;
        printf("3. Sobe a verificação para o avô (%d);\n", (*no)->chave);
    }
}

/*************************************************************
 * Inserção
*************************************************************/

Node *criarNovoNo(ArvoreRubroNegra *arvore, TIPO_CHAVE chave){
    Node *novo = malloc(sizeof(Node));
    
    if(novo){
        novo->chave = chave;
        novo->cor = vermelho;       // Todo novo nó deve ser vermelho (regra)
        novo->pai = arvore->folhasNulas;
        novo->esquerda= arvore->folhasNulas;
        novo->direita = arvore->folhasNulas;
    }else{
        printf("Erro ao alocar espaço para o novo nó\n");
        exit(EXIT_FAILURE);         // Tratamento de erro 
    }

    return novo;
}

void inserir(ArvoreRubroNegra *arvore, TIPO_CHAVE chave){

    // Se o novo nó é raíz
    if(arvore->raiz == arvore->folhasNulas){
        Node *novo = criarNovoNo(arvore, chave);
        novo->cor = preto;

        arvore->raiz = novo;
        arvore->quantidadeElementos++;

        printf("* Elemento (%d) adicionado na raíz\n", chave);
        return;
    }

    Node *pai = arvore->folhasNulas;
    Node *aux = arvore->raiz;

    // Procura o melhor lugar para o novo
    while(aux != arvore->folhasNulas){
        pai = aux;

        if(aux->chave > chave){
            aux = aux->esquerda;
        }else if(aux->chave < chave){
            aux = aux->direita;
        }else{
            printf("* Elemento (%d) já inserido na árvore\n", chave);
            return;
        }
    }

    Node *novo = criarNovoNo(arvore, chave);

    novo->pai = pai;

    // Faz as ligações de pai e filho
    if(pai->chave > chave){
        pai->esquerda = novo;
    }else{
        pai->direita = novo;
    }

    arvore->quantidadeElementos++;
    printf("* Elemento (%d) adicionado na árvore\n", chave);

    corrigirInsercao(arvore, novo);
}

/*************************************************************
 * Correções de exclusões
*************************************************************/

// Utilizando o algoritmo do livro do Thomas Cormen
void corrigeApagar(ArvoreRubroNegra *arvore, Node *no){

    while(no != arvore->raiz && no->cor == preto){

        // Saída bonitinha :)
        if(no == arvore->folhasNulas){
            printf("\nVerificando caso para nó folha...\n");
        }else{
            printf("\nVerificando nó preto (%d) para exclusão...\n", no->chave);
        }
        
        printf("\n***** Caso 3 (DUPLO PRETO) *****\n");
        
        if(no == no->pai->esquerda){      // filho da esquerda
            printf("* Nó (%d) é filho da esquerda\n", no->chave);
            
            corrigirApagarEsquerda(arvore, &no);
        }else{      // filho da direita
            printf("* Nó (%d) é filho da direita\n", no->chave);
        
            corrigirApagarDireita(arvore, &no);
        }
    }

    no->cor = preto;
}

void corrigirApagarEsquerda(ArvoreRubroNegra *arvore, Node **no){
    // printf("* irmão do Nó (%d) \n", (*no)->pai->direita->chave);
    Node *irmao = (*no)->pai->direita;
    
    if(irmao->cor == vermelho){     // Caso 3.1
        printf("\n*** Caso 3.1 (esquerda) ***\n");
        printf("\ta) O nó é preto;\n");
        printf("\tb) O irmão é vermelho;\n");

        printf("\n=> Procedimentos:\n\n");
        
        (*no)->pai->cor = vermelho;
        printf("1. Pai fica vermelho;\n");

        irmao->cor = preto;
        printf("2. Irmão fica preto;\n");

        rotacaoEsquerda(arvore, (*no)->pai);
        printf("3. Rotaciona o pai para a esquerda;\n");

        irmao = (*no)->pai->direita;      
        printf("4. Sobe a verificação para (%d);\n", irmao->chave);
        printf("5. Vai para o caso 3.2, 3.3 ou 3.4\n");

    }
    
    // Caso 3.2
    if(irmao->esquerda->cor == preto && irmao->direita->cor == preto){  
        printf("\n*** Caso 3.2 (esquerda) ***\n");
        printf("\ta) O nó é preto;\n");
        printf("\tb) O irmão é preto;\n");
        printf("\tc) Os filhos do irmão são pretos;\n");

        printf("\n=> Procedimentos:\n\n");

        irmao->cor = vermelho;
        printf("1. Irmão fica rubro;\n");

        (*no) = (*no)->pai;
        printf("2. Sobe a verificação para o pai (%d);\n", (*no)->chave);

    }else{
        // Caso 3.3
        if(irmao->direita->cor == preto){           
            printf("\n*** Caso 3.3 (esquerda) ***\n");
            printf("\ta) O nó é preto;\n");
            printf("\tb) O irmão é preto;\n");
            printf("\tc) O filho da direita do irmão é preto;\n");

            printf("\n=> Procedimentos:\n\n");

            irmao->cor = vermelho;             
            printf("1. O irmão fica rubro;\n");
            
            irmao->esquerda->cor = preto;
            printf("2. O filho esquerdo do irmão fica preto;\n");

            rotacaoDireita(arvore, irmao);
            printf("3. Rotaciona o irmão para a direita;\n");

            irmao = (*no)->pai->direita; 
            printf("4. Atualiza o irmão (%d);\n", irmao->chave);
            printf("5. Vai para o caso 3.4;\n");
        } 
        
        // Caso 3.4
        printf("\n*** Caso 3.4 (esquerda) ***\n");
        printf("\ta) O nó é preto;\n");
        printf("\tb) O irmão é preto;\n");
        printf("\tc) O filho da direita do irmão é vermelho;\n");

        printf("\n=> Procedimentos:\n\n");
        
        Node *pai = (*no)->pai;
        // printf("no pai %d\n", pai->chave);

        irmao->cor = pai->cor;
        printf("1. O irmão copia a cor do pai;\n");

        pai->cor = preto;
        irmao->direita->cor = preto;
        printf("2. O pai e o sobrinho da direita ficam preto;\n");

        rotacaoEsquerda(arvore, pai);
        printf("3. Rotaciona o pai para a esquerda;\n");

        // no = pai->pai;
        // printf("no pai %d\n", no->chave);
        (*no) = arvore->raiz;         
        printf("4. Atualiza a cor da raíz (%d);\n", (*no)->chave);
    }
}

void corrigirApagarDireita(ArvoreRubroNegra *arvore, Node **no){

    Node *irmao = (*no)->pai->esquerda;
    
    if(irmao->cor == vermelho){ // Caso 3.1
        printf("\n*** Caso 3.1 (direita) ***\n");
        printf("\ta) O nó é preto;\n");
        printf("\tb) O irmão é vermelho;\n");

        printf("\n=> Procedimentos:\n\n");
        
        (*no)->pai->cor = vermelho;
        printf("1. Pai fica rubro;\n");

        irmao->cor = preto;
        printf("2. Irmão fica preto;\n");

        rotacaoDireita(arvore, (*no)->pai);
        printf("3. Rotaciona o pai para a direita;\n");

        irmao = (*no)->pai->esquerda;       // será?
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

        (*no) = (*no)->pai;
        printf("2. Sobe a verificação para o pai (%d);\n", (*no)->chave);

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

            irmao = (*no)->pai->esquerda;       // Será?
            printf("4. Atualiza o irmão (%d);\n", irmao->chave);
            printf("5. Vai para o caso 3.4;\n");
        } 
        
        // Caso 3.4
        printf("\n*** Caso 3.4 (direita) ***\n");
        printf("\ta) O nó é preto;\n");
        printf("\tb) O irmão é preto;\n");
        printf("\tc) O filho da esquerda do irmão é vermelho;\n");

        printf("\n=> Procedimentos:\n\n");
        
        Node *pai = (*no)->pai;

        irmao->cor = pai->cor;
        printf("1. O irmão copia a cor do pai;\n");

        pai->cor = preto;
        irmao->esquerda->cor = preto;
        printf("2. O pai e o sobrinho da esquerda ficam preto;\n");
        rotacaoDireita(arvore, pai);
        printf("3. Rotaciona o pai para a direita;\n");

        // (*no) = pai->pai;
        // printf("no pai %d\n", pai->chave);

        (*no) = arvore->raiz;         
        printf("4. Atualiza a cor da raíz (%d);\n", (*no)->chave);
    }
}

/*************************************************************
 * Exclusões
*************************************************************/

// Utilizando o algoritmo do livro do Thomas Cormen
void apagar(ArvoreRubroNegra *arvore, TIPO_CHAVE chave){

    // Procura pelo elemento na árvore que será apagado
    Node *deletado = buscaBinaria(arvore, arvore->raiz, chave);

    // Não encontrou o elemento na árvore
    if(deletado == NULL || deletado == arvore->folhasNulas){   
        return;
    }

    printf("->Analisando caso para exclusão de (%d):\n\n", deletado->chave);

    Node *aux = arvore->folhasNulas;

    // Guarda a cor inicial do nó que será deletado
    COR corInicial = deletado->cor;

    if(deletado->esquerda == arvore->folhasNulas && deletado->direita == arvore->folhasNulas){
        printf("* O nó não tem filhos\n");

        aux->pai = deletado->pai;

        if(deletado->pai == arvore->folhasNulas){
            printf("* É raíz\n");

            arvore->raiz = arvore->folhasNulas;

        }else{
            printf("* É folha\n");
            
            // Atribui as folhas nulas para o pai 
            if(deletado->pai->esquerda == deletado){
                // Nó era filho da esquerda
                deletado->pai->esquerda = arvore->folhasNulas;
            }else{
                // Nó era filho da direita
                deletado->pai->direita = arvore->folhasNulas;
            }
        }

    }else if(deletado->esquerda == arvore->folhasNulas){
        printf("* O nó possui um filho a direita\n");

        // Aux é o filho da direita do deletado
        aux = deletado->direita;
        aux->pai = deletado->pai;

        trocar(arvore, deletado, aux);
    }else if(deletado->direita == arvore->folhasNulas){
        printf("* O nó possui um filho a esquerda\n");

        // Aux é o filho à esquerda do deletado
        aux = deletado->esquerda;
        aux->pai = deletado->pai;

        trocar(arvore, deletado, aux);
    }else{
        printf("* O nó possui dois filhos\n");

        Node *anterior;
        Node *menor = encontrarMenor(arvore, deletado->direita, anterior);

        // Guarda a cor do menor
        corInicial = menor->cor;

        // Guarda os filhos a direita do menor
        aux = menor->direita;

        if(menor->pai != deletado){
            aux->pai = menor->pai;
            menor->pai->esquerda = aux;
            menor->direita = deletado->direita;
            menor->direita->pai = menor;
        }else{
            aux->pai = menor;
        }

        menor->esquerda = deletado->esquerda;
        menor->esquerda->pai = menor;
        menor->cor = deletado->cor;  // será?
        menor->pai = deletado->pai;

        trocar(arvore, deletado, menor); //pra que?
    }

    // printf("\n");
    // criarImagemArvore(arvore);  //teste :)
    
    // Se o nó removido é preto, precisa balancear a arvore (duplo preto)
    if(corInicial == preto){
        // printf("Aux %d\n", aux->chave);
        corrigeApagar(arvore, aux);
    }else{
        printf("\nO nó é vermelho");
    }

    free(deletado);
    arvore->quantidadeElementos--;
    printf("\nA verificação não é mais necessária. Nó removido.\n");
}

void destruirNos(ArvoreRubroNegra *arvore, Node *subRaiz){

    //Casos bases
    if(subRaiz == NULL || subRaiz == arvore->folhasNulas){ // Não é nó
        return;
    }else if(subRaiz->esquerda == arvore->folhasNulas && subRaiz->direita == arvore->folhasNulas){ // Nó folha
        // printf("Elemento follha %d removido\n", subRaiz->chave);
        free(subRaiz);
        return;
    }
    
    // Casos recursivos
    if(subRaiz->esquerda != arvore->folhasNulas && subRaiz->direita != arvore->folhasNulas){ //Nó com 2 filhos 
        destruirNos(arvore, subRaiz->esquerda);
        destruirNos(arvore, subRaiz->direita);
    }else{  // Nó com um filho
        if(subRaiz->esquerda != arvore->folhasNulas){
            destruirNos(arvore, subRaiz->esquerda);
        }else{
            destruirNos(arvore, subRaiz->direita);
        }
    }

    free(subRaiz);
}

void destruirArvore(ArvoreRubroNegra *arvore){

    // Se a árvore foi inicializada
    if(arvore->quantidadeElementos > 0){
        destruirNos(arvore, arvore->raiz->esquerda);
        destruirNos(arvore, arvore->raiz->direita);

        free(arvore->raiz);
    }

    free(arvore->folhasNulas);
    free(arvore);
}
