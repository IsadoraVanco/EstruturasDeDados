# Bellman-Ford

* O algoritmo de Bellman-Ford permite a existência de arestas de peso negativo e produz a resposta correta.
* informa se grafo contém ciclo de peso negativo acessível
da origem
* não entra em loop
* Estruturas utilizadas:
    - Vetores p e d:
    - p[v]: pai do vértice v
    - d[u] : distância da origem s até u
* **Relaxamento**:
    - Também utilizado pelo algoritmo de Dijkstra
    - Consiste em verificar se pode ser encontrado um caminho mais curto para v (do que aquele encontrado até o momento), passando pelo vértice corrente u.