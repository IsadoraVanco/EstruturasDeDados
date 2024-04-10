# Grafos

Estruturas que permitem exibir o relacionamentos de vários pares de objetos. Cada objeto é representado por um **vértice**, que é ligado a outro por meio de uma **aresta**.

## Grafos dirigidos vs não dirigidos

* **Dirigidos:** As arestas possuem direção, até para o mesmo vértice (self-loop). O sentido pode ser duplo. O grau de um vértice desse grafo é medido pelo **grau de saída** (número de arestas que saem dele) somado com o **grau de entrada** (número de arestas que chegam nele).
* **Não dirigidos:** As arestas não têm sentido definido, então podemos pensar em um grafo dirigido de sentido duplo. Não possui auto-laços. O grau de um vértice desse grafo é medido pelo número de arestas que incidem nele.

## Grafos ponderados

São grafos que possuem pesos associados às suas arestas. Esses pesos podem representar custos, distâncias, etc.

## Representações

### Matriz de adjacência 

Utiliza-se uma matriz n x n onde n é o número de vértices. Na matriz, representamos as conexões entre os vértices adicionando um '1' ou outro valor (caso seja ponderado) e '0', caso não exista a relação.

* Considere grafos grandes (com muitos vértices) e esparços (relativamente poucas arestas). Neste caso, a matriz é composta principalmente por zeros e há um consumo de memória desnecessário. Por isso:
* Deve ser utilizada em grafos densos em que a quantidade arestas deve ser próximo número de vértices ao quadrado.
* É muito útil para algoritmos que necessitamos saber com rapidez se existe uma aresta ligando dois vértices.
* A maior **desvantagem** é que a matriz necessita de pelo menos o número de vértices ao quadrado de espaço.

### Listas de adjacência 

Uma lista de adjacências de um grafo com n vértices consiste de um arranjo de n listas ligadas, uma para cada vértice no grafo.
Cada lista possui todos os vizinhos de um determinado vértice. Se o grafo for ponderado, armazena não só o nó vizinho, mas seu peso também.