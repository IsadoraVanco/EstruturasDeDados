# Selection Sort

* Seleciona do n-ésimo menor (ou maior) elemento da lista.
* Troca do n-ésimo menor (ou maior) elemento com a n-ésima posição da lista.
* È realizada apenas uma única troca a cada iteração.
* A idéia da ordenação por seleção éprocurar o menor elemento do vetor (ou maior) e movimentá-lo para a primeira (última) posição do vetor.
* Repetir para os n elementos do vetor.

## Vantagens:

* Custo linear no tamanho da entrada para o número de movimentos de registros.
* É o algoritmo a ser utilizado para arquivos com registros muito grandes (alto custo de movimentação).
* É muito interessante para arquivos pequenos.

## Desvantagens:

* O fato de o arquivo já estar ordenado não ajuda em nada, pois o custo continua quadrático.
* O algoritmo não é estável.