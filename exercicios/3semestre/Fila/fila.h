/*
Estrutura de Fila utilizando ponteiros
*/

/*
Estrutura da Celula da Fila.
*/
typedef struct cel{
    int data;
    struct cel* next;
} Celula;

/*
Estrutura para as infos da Fila.
*/
typedef struct{
    Celula* head;
    Celula* tail;
    int length;
} Queue;

/*
Cria uma nova estrutura de Fila e retorna o ponteiro para a estrutura criada.
Retorna NULL caso não seja possível criar a estrutura.
*/
Queue *newQueue();

/*
Retorna 1 se a Fila estiver vazia, 0 caso contrário.
*/
int isEmptyQueue(Queue *queue);

/*
Retira um elemento da Fila e retorna um valor. 
Caso a Fila esteja vazia, retorna 0.
*/
int dequeue(Queue *queue);

/*
Adiciona um elemento na Fila.
Retorna 0 se a operação seja concluída com sucesso, 
caso contrário, retorna 1.
*/
int enqueue(Queue *queue, int data);

/*
Retorna o tamanho da Fila.
*/
int getLengthQueue(Queue *queue);

/*
Libera o espaço alocado para a Fila.
*/
void deleteQueue(Queue *queue);
