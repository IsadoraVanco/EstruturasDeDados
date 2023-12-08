/*
Créditos ao profº Gilberto, autor do exercício.

Faça um programa que simule uma fila de processos em um
sistema operacional. Essa fila terá um tempo para utilizar cada um
dos seus processos. No caso de um processo estar sendo
executado e seu limite de tempo se encerrar, ele é removido e
colocado na fila novamente; dessa maneira, o próximo processo
passa a ser executado, e assim por diante, até que todos os
processos tenham sido executados.

- Este gerenciamento deve ser exibido automaticamente. Ou seja, após definir
os processos e seus tempos limite, e enfileirá-los, o processo se inicia.
- Defina um tempo de espera padrão em segundos para cada unidade de
tempo do seu sistema. Utilize a biblioteca time.h.
*/
#include <stdio.h>
#include <time.h>
#include "fila.h"

/*
Inicializa o sorteador de números. 
*/
void inicializaSorteador(){
    // inicializa o gerador de números aleatórios com a hora atual
    srand(time(NULL));
}

/*
Sorteia um número no intervalo de 1 e máximo e o retorna.
Se maximo for negativo, retorna -1.
*/
int sorteiaNumero(int maximo){
    if(maximo <= 0){
        return -1;
    }

    int num = (rand() % (maximo));
    return num;
}

int main(int argc, char const *argv[]){
    inicializaSorteador();

    int numeroProcessos = sorteiaNumero(20);
    int tempoMaxProcesso = sorteiaNumero(30);

    Queue *fila = newQueue();

    for(int i = 0; i < numeroProcessos; i++){ //Cria a fila de processos
        enqueue(fila, "Processo", inicializaSorteador(tempoMaxProcesso));
    }


    return 0;
}
