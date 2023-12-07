# Bubble Sort

Créditos ao prof° Gilberto.

* Os elementos vão “borbulhando/flutuando” a cada iteração do método até a posição correta para ordenação da lista.
* A idéia da ordenação por bolhas é flutuar o maior elemento para o fim.
* Repita n vezes a flutuação.
* Como os elementos são trocados (borbulhados) frequentemente, há um alto custo com troca de elementos.
* O bubble sort realiza múltiplas passagem por uma lista.
* Ele compara itens adjacentes e troca aqueles que estã o fora de ordem.
* Cada passagem pela lista coloca o próximo maior valor na sua posiçã o correta.
* Em essência, cada item se desloca como uma “bolha” para a posição à qual pertence.

**Método de ordenação mais ineficiente**:
* precisa realizar a troca de itens sem saber qual será sua posiçã o Dinal.
* Essas trocas “desnecessárias” são muito custosas.
* **Ordem Assintótica: O(n²)**

* Mas, se durante uma passagem não houver trocas, então sabemos que a lista está ordenada! Por isso, o bubble sort pode ser modificado para terminar antes se descobrir que a lista ficou ordenada.

## Vantagens:
* Algoritmo simples.
* Algoritmo estável.

## Desvantagens:
* O fato de o arquivo já estar ordenado não ajuda a reduzir o número de comparações (o custo continua quadrático).
* Porém o número de movimentações cai para zero.