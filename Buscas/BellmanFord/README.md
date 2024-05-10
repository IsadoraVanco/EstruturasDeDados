# Bellman-Ford

* O algoritmo de Bellman-Ford permite a existência de arestas de peso negativo e produz a resposta correta.
* Informa se grafo contém ciclo de peso negativo acessível da origem
* não entra em loop
* **Relaxamento**:
    - Também utilizado pelo algoritmo de Dijkstra
    - Consiste em verificar se pode ser encontrado um caminho mais curto para v (do que aquele encontrado até o momento), passando pelo vértice corrente u