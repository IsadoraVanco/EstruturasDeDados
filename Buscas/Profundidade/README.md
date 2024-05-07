# Busca em profundidade

* A idéia é proseguir a busca sempre a partir do vértice descoberto mais recentemente, até que este não tenha mais vizinhos descobertos. Neste caso, volta-se na busca
para o precursor desse vértice.
* Oposto de BFS que explora o vértice mais antigo primeiro
* DFS devolve uma floresta
* A idéia principal é buscar verticalmente, sempre que possível.
* Sempre que um novo vértice v é descoberto, ele deve ser explorado por completo.
* Quando v é totalmente explorado, fazer backtracking totalmente explorado, fazer backtracking para o seu predecessor.
* Os vértices recebem 2 rótulos:
    - **d[.]**: o momento em que o vértice foi descoberto (tornou-se cinza)
    - **f[.]**: o momento em que examinamos os seus vizinhos (tornou-se preto)
* O vértice é branco até d , cinza entre d e f e preto a partir de f.

## Classificação das arestas

* **Arestas da árvore**: são arestas que pertencem a alguma das árvores DFS da floresta.
* **Arestas de retorno**: arestas (u,v) que não pertencem a árvore DFS. Conectam um vértice u com um ancestral v em uma árvore DFS. Self-loops são considerados arestas de retorno.
* **Arestas de avanço**: arestas (u,v) que não pertencem a árvore DFS. Conectam um vértice u a um descendente v em uma árvore DFS.
* **Arestas de cruzamento**: Todas as outras arestas.

## Exemplos

1. **Intuição**: Procurar uma saída de um labirinto
    - vai fundo atrás da saída (tomando decisões a cada encruzilhada)
    - volta a última encruzilhada quando encontrar um beco sem saída ou encontrar um lugar já visitado.