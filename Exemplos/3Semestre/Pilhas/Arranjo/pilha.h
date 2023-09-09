// Exemplo de Pilha como Arranjo do profº Gilberto
typedef struct{
    int *pilha;
    int tamanho;
    int topo;
} Pilha;

/*
Cria uma estrutura de Pilha com o tamanho especificado, e 
retorna o seu ponteiro.
*/
Pilha* createStack(int tamanho);
/*
Retira o último elemento da pilha e o retorna.
*/
int pop(Pilha *pilha);
/*
Adiciona o valor no topo da pilha, caso tenha espaço.
Retorna 0 se teve sucesso, e 1, caso contrário.
*/
int push(Pilha *pilha, int valor);

/*
Retorna 1 se a pilha estiver vazia, 0 caso contrário.
*/
int isStackEmpty(Pilha *pilha);

/*
Retorna 1 se a pilha estiver cheia, 0 caso contrário.
*/
int isStackFull(Pilha *pilha);

/*
Apaga a estrutura da Pilha da memória
*/
void deleteStack(Pilha *pilha);