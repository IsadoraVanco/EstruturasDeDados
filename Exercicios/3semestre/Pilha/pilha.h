/*
Celula representa cada elemento que está na Pilha.
*/
typedef struct cel{
    int data;
    struct cel* next;
} Celula;

/*
Pilha representa as informações de uma determinada estrtura de Pilha.
*/
typedef struct{
    Celula* top;
    int length;
} Stack;

/*
Cria uma estrutura de Pilha e retorna o seu ponteiro.
*/
Stack* newStack();

/*
Retorna 1 se a Pilha estiver vazia, 0 caso contrário.
*/
int isEmptyStack(Stack *Stack);

/*
Adiciona o valor no topo da Pilha, caso tenha espaço.
Retorna 0 se teve sucesso, e 1, caso contrário.
*/
int push(Stack* Stack, int data);

/*
Retira o último elemento da Pilha e o retorna.
*/
int pop(Stack* Stack);

/*
Retorna o tamanho da Pilha.
*/
int getLengthStack(Stack *Stack);

/*
Procura na Pilha uma informação, copia a posição (a 
partir do primeiro elemento colocado na Pilha) caso 
a ache na estrutura e retorna 0, se não, retorna 1.
*/
int searchInStack(Stack *stack, int data, int *position);

/*
Copia a informação que está na posição indicada da Pilha.
Caso não haja a posição indicada (a partir do primeiro 
elemento colocado na Pilha), retorna 1, se não, retorna 0.
*/
int getElementInStack(Stack *stack, int position, int *data);

/*
Apaga a estrutura da Pilha da memória e todas as células.
*/
int deleteStack(Stack *Stack);