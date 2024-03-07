# Gerenciador de processos

Créditos à profª Vanessa, autora do exercício.

Desenvolva um sistema de gerenciamento de prioridades para um sistema operacional que precisa equilibrar a execução de processos baseando-se em duas métricas críticas: a prioridade de execução e o tempo de espera. Para isso, você utilizará duas estruturas de dados Heap: um Heap Máximo para gerenciar os processos com base na prioridade de execução, e um Heap Mínimo para gerenciar os processos com base no tempo de espera. Este sistema ajudará o escalonador do sistema operacional a decidir qual processo executar a seguir, considerando tanto a urgência quanto a justiça no tempo de espera.
 
Alguns pontos a serem considerados:
 
1. Estrutura de Processo: Primeiramente, defina uma estrutura Processo em C que contenha, no mínimo, os seguintes campos:
   - int pid: Um identificador único para o processo.
   - int prioridade: Um valor inteiro que representa a prioridade de execução do processo. Valores mais altos indicam maior prioridade.
   - int tempoEspera: Um valor inteiro que representa o tempo que o processo está esperando para ser executado. Valores mais altos indicam um maior tempo de espera.
 
2. Implementação dos Heaps Máximo e Mínimo:
   - Implemente um Heap Máximo para organizar os processos por prioridade de execução.
   - Implemente um Heap Mínimo para organizar os processos por tempo de espera.
   - Ambos os heaps devem suportar operações de inserção (inserirProcesso), remoção do processo no topo (removerProcessoTopo), e verificação se o heap está vazio (heapVazio).
 
3. Funções Requeridas:
   - Para cada Heap (Máximo e Mínimo), implemente as seguintes funções:
        * void **inserirProcesso**(Processo heap, int* tamanhoAtual, Processo novoProcesso): Insere um novo processo no heap apropriado, mantendo as propriedades do heap.
        * Processo **removerProcessoTopo**(Processo* heap, int* tamanhoAtual): Remove e retorna o processo no topo do heap.
        * int **heapVazio**(int tamanhoAtual): Retorna 1 se o heap estiver vazio, caso contrário retorna 0.
   - Implemente uma função void **imprimirProcessos**(Processo* heap, int tamanho) que imprime a lista de processos em cada heap, de acordo com sua prioridade ou tempo de espera.
   -  Implemente uma função que permita entrar com uma quantidade n de processos tanto para o Heap Máximo, quanto para o Heap Mínimo.
