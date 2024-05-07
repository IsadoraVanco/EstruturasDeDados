# Algoritmo de Kruskal

* O algoritmo de Prim se inicia com um vértice e cresce uma única árvore a partir dele.
* O algoritmo de Kruskal constrói uma floresta (várias árvores) ao longo do tempo, e que são unidas ao final do processo.
* **Princípio**: a aresta de menor peso sempre pertence à AGM
* Escolha a aresta de menor peso entre todas as arestas que conectam quaisquer dois vértices em A
* A nova aresta não pode ligar vértices na mesma árvore (não pode formar ciclo)

# Funcionamento

* Considera cada vértice como uma árvore independente (floresta)
* A cada iteração, o algoritmo procura a aresta de menor peso que conecta duas árvores diferentes
* Os vértices das árvores selecionadas passam a fazer parte de uma mesma árvore
* Esse processo continua até que
    - Todos os vértices façam parte da árvore
    - Não se pode encontrar uma aresta que satisfaça essa condição (grafo desconexo)