/**
 * @brief Implementação do Heap Máximo
*/

#include <stdio.h>
#include <stdlib.h>
#include "processos.h"


/************************************************************
 * Variáveis globais
*************************************************************/
/**
 * Armazena se a ultima remoção foi feita no Heap de Prioridades
*/
int removerPrioridades = 0;

/************************************************************
 * Funções Básicas
*************************************************************/

Heap *inicializarHeap(TIPO_HEAP tipo){
    
    if(tipo != MAXIMO && tipo != MINIMO){
        printf("-> Tipo do Heap não definido!\n");
        return NULL;
    }

    Heap *novo = malloc(sizeof(Heap));
    novo->qtdElementos = 0;
    novo->totalElementos = 0;
    novo->tipo = tipo;
    // Inicializa o heap com um elemento nulo
    novo->heap = (Processo *) calloc(1, sizeof(Processo));

    return novo;
}

int pai(int indice){
    return indice / 2;
}

int esquerda(int indice){
    return indice * 2;
}

int direita(int indice){
    return (indice * 2) + 1;
}

int heapVazio(Heap *heap){
    return heap->qtdElementos <= 0;
}

// void construirHeap(Heap *heap){ 
//     int quantidade = heap->qtdElementos;
    
//     // Verifica apenas os nós de dentro
//     if(heap->tipo == MAXIMO){
//         for(int i = quantidade; i >= 1; i--){
//             subirPrioridade(heap, i);
//         }
//     }else{
//         for(int i = quantidade; i >= 1; i--){
//             subirTempo(heap, i);
//         }
//     }
// }

/************************************************************
 * Imprimir
*************************************************************/

void imprimirProcessos(Heap *heap){
    
    // Saída bonitinha :)
    if(heapVazio(heap)){
        printf("-> Não há elementos no Heap!\n");
        return;
    }

    for(int i = 1; i <= heap->qtdElementos; i++){
        printf("[%d]: PID(%d) PRIORIDADE(%d) TEMPO(%d)\n", i, heap->heap[i].pid, heap->heap[i].prioridade, heap->heap[i].tempoEspera);
    }
}

/************************************************************
 * Buscar
*************************************************************/

int buscarProcesso(Heap *heap, int id){
    for(int i = 1; i <= heap->qtdElementos; i++){
        if(heap->heap[i].pid == id){
            printf("-> Processo[%d] encontrado no índice %d\n", id, i);
            printf("-> Tempo de espera[%d] Prioridade[%d]\n", heap->heap[i].tempoEspera, heap->heap[i].prioridade);
            return i;
        }
    }
    
    printf("-> Processo (%d) não encontrado!\n", id);
    return -1;
}

/************************************************************
 * Subir e descer nós => Heap Máximo (Prioridade)
*************************************************************/

void subirPrioridade(Heap *heap, int indice){ 
    int noPai = pai(indice);

    if(noPai < indice && noPai > 0){

        if(heap->heap[indice].prioridade > heap->heap[noPai].prioridade){
            // Troca os nós
            printf("-> Nó (%d) sobe e pai (%d) desce\n", heap->heap[indice].pid, heap->heap[noPai].pid);
            
            // Processo *temp = &(heap->heap[indice]);
            // heap->heap[indice] = heap->heap[noPai];
            // heap->heap[noPai] = *temp;
            int tempPid = heap->heap[indice].pid;
            int tempTempo = heap->heap[indice].tempoEspera;
            int tempPrioridade = heap->heap[indice].prioridade;

            heap->heap[indice].pid = heap->heap[noPai].pid;
            heap->heap[indice].tempoEspera = heap->heap[noPai].tempoEspera;
            heap->heap[indice].prioridade = heap->heap[noPai].prioridade;

            heap->heap[noPai].pid = tempPid;
            heap->heap[noPai].tempoEspera = tempTempo;
            heap->heap[noPai].prioridade = tempPrioridade;

            subirPrioridade(heap, noPai);
        }
    }
}

void descerPrioridade(Heap *heap, int indice){
    int quantidade = heap->qtdElementos;
    int esq = esquerda(indice);
    int dir = direita(indice);
    int maior = indice;

    // Verifica qual o maior
    if(esq <= quantidade && esq > 0 && heap->heap[esq].prioridade > heap->heap[indice].prioridade){
        maior = esq;
    }
    if(dir <= quantidade && dir > 0 && heap->heap[dir].prioridade > heap->heap[maior].prioridade){
        maior = dir;
    }

    // Se achou um maior na esquerda ou direita
    if(maior != indice){
        // Troca os nós
        printf("-> Nó (%d) desce e pai (%d) sobe\n", heap->heap[indice].pid, heap->heap[maior].pid);
        
        // Processo *temp = &(heap->heap[indice]);
        // heap->heap[indice] = heap->heap[maior];
        // heap->heap[maior] = *temp;

        int tempPid = heap->heap[indice].pid;
        int tempTempo = heap->heap[indice].tempoEspera;
        int tempPrioridade = heap->heap[indice].prioridade;

        heap->heap[indice].pid = heap->heap[maior].pid;
        heap->heap[indice].tempoEspera = heap->heap[maior].tempoEspera;
        heap->heap[indice].prioridade = heap->heap[maior].prioridade;

        heap->heap[maior].pid = tempPid;
        heap->heap[maior].tempoEspera = tempTempo;
        heap->heap[maior].prioridade = tempPrioridade;

        descerPrioridade(heap, maior);
    }
}

/************************************************************
 * Subir e descer nós => Heap Mínimo (Tempo)
*************************************************************/

void subirTempo(Heap *heap, int indice){ 
    int noPai = pai(indice);

    if(noPai < indice && noPai > 0){

        if(heap->heap[indice].tempoEspera < heap->heap[noPai].tempoEspera){
            // Troca os nós
            printf("-> Nó (%d) sobe e pai (%d) desce\n", heap->heap[indice].pid, heap->heap[noPai].pid);
            
            // Processo *temp = &(heap->heap[indice]);
            // heap->heap[indice] = heap->heap[noPai];
            // heap->heap[noPai] = *temp;
            int tempPid = heap->heap[indice].pid;
            int tempTempo = heap->heap[indice].tempoEspera;
            int tempPrioridade = heap->heap[indice].prioridade;

            heap->heap[indice].pid = heap->heap[noPai].pid;
            heap->heap[indice].tempoEspera = heap->heap[noPai].tempoEspera;
            heap->heap[indice].prioridade = heap->heap[noPai].prioridade;

            heap->heap[noPai].pid = tempPid;
            heap->heap[noPai].tempoEspera = tempTempo;
            heap->heap[noPai].prioridade = tempPrioridade;

            subirTempo(heap, noPai);
        }
    }

}

void descerTempo(Heap *heap, int indice){
    int quantidade = heap->qtdElementos;
    int esq = esquerda(indice);
    int dir = direita(indice);
    int menor = indice;

    // Verifica qual o menor
    if(esq <= quantidade && esq > 0 && heap->heap[esq].tempoEspera < heap->heap[indice].tempoEspera){
        menor = esq;
    }
    if(dir <= quantidade && dir > 0 && heap->heap[dir].tempoEspera < heap->heap[menor].tempoEspera){
        menor = dir;
    }

    // Se achou um maior na esquerda ou direita
    if(menor != indice){
        // Troca os nós
        printf("-> Nó (%d) desce e pai (%d) sobe\n", heap->heap[indice].pid, heap->heap[menor].pid);
        
        // Processo *temp = &(heap->heap[indice]);
        // heap->heap[indice] = heap->heap[menor];
        // heap->heap[menor] = *temp;

        // trocar para ponteiros :)
        int tempPid = heap->heap[indice].pid;
        int tempTempo = heap->heap[indice].tempoEspera;
        int tempPrioridade = heap->heap[indice].prioridade;

        heap->heap[indice].pid = heap->heap[menor].pid;
        heap->heap[indice].tempoEspera = heap->heap[menor].tempoEspera;
        heap->heap[indice].prioridade = heap->heap[menor].prioridade;

        heap->heap[menor].pid = tempPid;
        heap->heap[menor].tempoEspera = tempTempo;
        heap->heap[menor].prioridade = tempPrioridade;

        descerTempo(heap, menor);
    }
}

/************************************************************
 * Inserção 
*************************************************************/

void inserirProcesso(Heap *heap, int prioridade, int tempo){
    int quantidade = heap->qtdElementos;

    // Aumenta o tamanho do vetor
    heap->heap = (Processo *) realloc(heap->heap, sizeof(Processo) * (quantidade + 2));

    // Insere
    quantidade++;
    heap->qtdElementos++;
    heap->totalElementos++;
    
    heap->heap[quantidade].pid = heap->totalElementos;
    heap->heap[quantidade].prioridade = prioridade;
    heap->heap[quantidade].tempoEspera = tempo;
    printf("-> novo PID %d Prioridade %d tempo %d\n", heap->heap[quantidade].pid, heap->heap[quantidade].prioridade, heap->heap[quantidade].tempoEspera);

    // Verifica se precisa subir o valor
    if(heap->tipo == MAXIMO){
        subirPrioridade(heap, quantidade);
    }else{
        subirTempo(heap, quantidade);
    }
    printf("-> Processo [%d] adicionado no Heap\n", heap->totalElementos);
}

/************************************************************
 * Remoção
*************************************************************/

int removerProcessoTopo(Heap *heap){
    
    if(heapVazio(heap)){
        printf("-> Não há elementos no Heap\n");

        return -1;
    }

    int quantidade = heap->qtdElementos;
    int valor = heap->heap[1].pid;
    
    // Coloca o último elemento no topo
    heap->heap[1].pid = heap->heap[quantidade].pid;
    heap->heap[1].prioridade = heap->heap[quantidade].prioridade;
    heap->heap[1].tempoEspera = heap->heap[quantidade].tempoEspera;

    // Diminui a quantidade de elementos do total
    heap->heap = (Processo *) realloc(heap->heap, sizeof(Processo) * (quantidade + 1));
    heap->qtdElementos--;

    // Desce o valor do topo
    if(heap->tipo == MAXIMO){
        descerPrioridade(heap, 1);
    }else{
        descerTempo(heap, 1);

    }
    printf("-> Processo [%d] removido do topo do Heap\n", valor);

    return valor;
}

// void removerProcesso(Heap *heap, int id){
//     if(heapVazio(heap)){
//         printf("-> Não há elementos no Heap\n");
//         return;
//     }

//     int idAchado = buscarProcesso(heap, id);

//     if(idAchado <= 0){
//        return;
//     }

//     int quantidade = heap->qtdElementos;

//     // Move os elementos para a esquerda tapando os buracos
//     for(int i = idAchado; i < quantidade; i++){
//         heap->heap[i].pid = heap->heap[i + 1].pid;
//         heap->heap[i].prioridade = heap->heap[i + 1].prioridade;
//         heap->heap[i].tempoEspera = heap->heap[i + 1].tempoEspera;
//     }

//     // Diminui a quantidade de elementos do total
//     heap->heap = (Processo *) realloc(heap->heap, sizeof(Processo) * (quantidade + 1));
//     heap->qtdElementos--;

//     // Transforma em heap denovo
//     construirHeap(heap);

//     printf("->Processo [%d] removido do meio do Heap\n", id);
// }

// void removerProcessoTopoAmbos(Heap *prioridades, Heap *tempos){
//     int pid;
    
//     // Se a última remoção foi feita no heap de prioridades
//     if(removerPrioridades){
//         printf("-> Remove do topo de Tempo de Espera\n\n");
//         pid = removerProcessoTopo(tempos);
//         removerProcesso(prioridades, pid);
//         removerPrioridades = 0;
//     }else{
//         printf("-> Remove do topo de Prioridade\n\n");
//         pid = removerProcessoTopo(prioridades);
//         removerProcesso(tempos, pid);
//         removerPrioridades = 1;
//     }
// }

void destruirProcessos(Heap *heap){

    free(heap->heap);
    free(heap);
}
