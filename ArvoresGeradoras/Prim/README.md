# Algoritmo de Prim

* Começa em um vértice até atar todos os vértices.
* Analisa a cada nó todas as possibilidades de transição e seus custos e escolhe o menor deles.
* Vai analisando a cada iteração o menor caminho e guarda-o na solução que seráretornada no final.
* Considera um vértice inicialmente na árvore
* A cada iteração, o algoritmo procura a aresta de menor peso que conecte um vértice da árvore a outro que ainda não esteja na árvore.
* Esse vértice é adicionado a árvore e o processo se repete.
* Esse processo continua até que
    - Todos os vértices façam parte da árvore
    - Não se pode encontrar uma aresta que satisfaça essa condição (grafo desconexo)

## Resumo

* Possui um ponto de partida; 
* Não pode ser orientado; 
* Os pesos podem ser iguais;
* Combinação linear entre os vértices
* Grafo Conexo;
* Acíclico;