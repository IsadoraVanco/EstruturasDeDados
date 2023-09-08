// Exemplo de Pilha do profº Gilberto
typedef struct cel{
    int valor;
    struct cel* proximo;
} Celula;

typedef struct{
    Celula* topo;
    int tamanho;
} Pilha;

Pilha* NEW_PILHA();
int POP(Pilha* pilha);
int PUSH(int v, Pilha* pilha);
int DELETE_PILHA(Pilha *pilha);