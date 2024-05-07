# Dijkstra

* Algoritmo que calcula o caminho mais curto, em termos do peso total das arestas, entre um nó inicial e todos os demais nós no grafo.
* O peso total das arestas é a soma dos pesos das arestas que compõem o caminho.
* O peso nas arestas crucial, como quando queremos achar a rota mais curta entre duas cidades.
* Para cada vértice v do grafo, mantemos um atributo d[v] que é um limite superior para o peso do caminho mais curto do nó inicial s a v.
* Dizemos que d[v] é uma estimativa de caminho mais curto, inicialmente feito (infinito)
* Também armazenamos o vértice que precede v (p[v]- precedente de v) no caminho mais curto de s a v.
* Faça a estimativa de distância de s a qualquer vértice ser infinita
* Exceto, claro, a distância de s a s, que é 0
* Ou seja, d[s] = 0 e d[v] = (infinito) para todo v + s
* Dijkstra tem um limitante importante:
    - Os pesos das arestas devem ser não-negativos
    - Além disso, a implementação de existeAberto() e menorDist() é crucial para a velocidade do algoritmo 
* Para uma melhor implementação, busque uma com filas de prioridade

## Algoritmo

* Faça os precedentes dos nós serem um valor qualquer
* Na prática, podemos fazer p[v] = -1, já que não temos vértice de indice-1 na estrutura GRAFO
* Marco todos os vértices como “abertos”.
* Enquanto houver vértice aberto:
    - Escolha o vértice aberto u cuja estimativa seja a menor dentre os demais abertos
    - Feche u
    - Para todo nó aberto v na adjacência de u:
        - Some d[u] ao peso da aresta (u, v)
        - Caso a soma seja menor que d[v], atualize d[v] e faça p[v] = u
        - Procedimento chamado de relaxamento da aresta (u, v)

* Inicialize o grafo com d[s] = 0, d [v] = ∞, para todo v ≠ s, e p[v] = -1 para todo v
* Faça aberto[v] = true para todo v no grafo
* Enquanto houver vértice aberto:
    - Escolha u cuja estimativa seja a menor dentre os abertos
    - Feche u
    - Para todo nó aberto v na adjacência de u:
        - Relaxe a aresta (u, v)

## Observações

* Fechamos um nó u somente se já conhecemos a menor distância deste ao nó inicial s
* Então fazemos o relaxamento de seus vizinhos:
    - Sabemos a menor distância de s a u
    - Temos a estimativa de s a v, v vizinho de u
    - Buscamos saber se a distância de s a u mais a distância (u, v) é melhor que a estimativa atual de s a v. Se for, atualizamos essa estimativa.
* Note que, além da distância, o caminho também pode ser obtido!
* Basta olhar os antecedentes, percorrendo do nó final ao inicial.

## Resumo

* Possui um ponto de partida;
* Pode ser orientado ou não;
* O Custo das arestas não podem ser negativos;
* Grafo Conexo 