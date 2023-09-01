/*
Estrutura de Pilha utiizando ponteiros
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