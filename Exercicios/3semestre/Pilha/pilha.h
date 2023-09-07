/*
Créditos ao profº Gilberto, autor do exercício.

Implemente uma pilha encadeada com as seguintes funções básicas:
-Criar pilha;
-Verificar se a pilha está vazia;
-Push
-Pop
-Retornar o tamanho da pilha
*/
typedef struct cel{
    int data;
    struct cel* next;
} Celula;

typedef struct{
    Celula* head;
    int length;
} Stack;

Stack* newStack();
int isEmptyStack(Stack *Stack);
int push(Stack* Stack, int data);
int pop(Stack* Stack);
int getLengthStack(Stack *Stack);
int deleteStack(Stack *Stack);