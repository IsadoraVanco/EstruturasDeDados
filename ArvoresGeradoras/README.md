# Árvores Geradoras

* Seja T uma árvore com n vértices, então: 
    - T é conexo e sem ciclos; 
    - T possui n− 1 arestas; 
    - Cada aresta de T é uma ponte; 
    - T é um grafo planar (sem o cruzamento de arestas); 
    - Se n>1, então T possui pelo menos dois vértices folhas (ou terminais). 

* Alguns problemas de otimização combinatória podem ser  formulados através de um tipo de grafo específico  conhecido como árvore
* Uma árvore é um grafo conexo  (existe caminho entre qualquer par de seus nós) e acíclico (sem ciclos). Ou seja,uma árvore é um grafo conexo sem ciclos.
* Dado um grafo conectado e não orientado, uma árvore geradora desse grafo é um subgrafo que é uma árvore e  conecta todos os nós juntos.
* Um único grafo pode ter muitas árvores diferentes.
* Uma árvore geradora mínima (MST) para um grafo ponderado, conectado e não orientado é uma árvore geradora com peso/custo/distância menor ou igual ao peso/custo/distância de todas as outras árvores geradoras. O custo de uma árvore geradora é a soma dos custos de cada aresta da árvore de arborescência.
* Seja G= (V, E) um grafo conexo com uma função de peso w: E → R
    - O peso de uma árvore geradora T de G é definido como a soma dos pesos de todas as arestas de
    ```
    w(T) = somatorio de (u,v) [w] 
    
    onde :
        (u,v) pertence a T e
        w pertence a (u,v) 
    ```
    - A meta é achar uma árvore geradora de peso mínimo para G: Árvore Geradora Mínima / Minimum Spanning Tree

* **Corte**: Um corte (S, V-S) de um grafo não direcionado G = (V, E) é uma partição de seu conjunto de vértices

*  Existem dois algoritmos clássicos na literatura para  resolver o problema da AGM:
    * **Algoritmo de Prim**
    * **Algoritmo de Kruskal**

* Ambos são considerados algoritmos gulosos.
* A estratégia gulosa defende que a menor escolha a cada passo deve ser feita, mesmo que tal escolha não nos leve a uma solução ótima ao final da execução. (Melhor escolha imediata)