# Merge Sort

* A execução do MergeSort pode ser facilmente descrita por uma árvore binária:
    - Cada nó representa uma chamada recursiva do MergeSort.
    - O nó raiz é a chamada inicial.
    - Os nós folha são vetores de 1 ou 2 números (casos base).

* Divida o algoritmo em duas partes.
* Ordene as duas partes usando chamadas recursivas.
* Intercale as duas partes, obtendo um conjunto ordenado de todos os elementos.

* A altura h da árvore de execução é O(log n).
* A quantidade de operações em cada nı́vel da árvore é assintoticamente igual a O(n).
* Logo: algoritmo é **O(n log n)**.

## Vantagens:
* MergeSort é O(n log n).
* Indicado para aplicações que tem restrição de tempo (executa sempre em um determinado tempo para n).
* Passı́vel de ser transformado em estável.
* Tomando certos cuidados na implementação da intercalação.
* Fácil Implementação.

## Desvantagens:
* Utiliza memória auxiliar, em O(n).
* Na prática émais lento que QuickSort no caso médio.