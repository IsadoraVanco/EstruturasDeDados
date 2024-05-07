
# Busca em Largura (BFS)

* Representa um dos mais simples algoritmos de busca em grafos.
* É usado como modelo para alguns algoritmos importantes:
    - Menor caminho;
    - Árvore de cobertura mínima;
* O caminho é medido em número de arestas, ignorando quaisquer pesos que estas tenham.
* Similar ao caminhamento por níveis em árvores.
* Idéia: processa os vértices por níveis, começando por aqueles vértices mais próximos do vértice inicial s e deixando os vértices mais próximos do vértice inicial s e deixando os vértices mais distantes para depois.
* Seja G = (V , A) e um vértice s de G
* BFS percorre as arestas de G descobrindo todos os vértices atingíveis a partir de s.
* BFS determina a distância (em número de arestas) de cada um desses vértices a s.
* Antes de encontrar um vértice à distância k+1 de s, todos os vértices à distância k são encontrados.
* BFS produz uma árvore BFS com raiz em s, que contém todos os vértices acessíveis. Determinando o caminho mínimo ou caminho mais curto (caminho que contém o número mínimo de arestas) de s a t (vértice acessível).

* Para organizar o processo de busca os vértices são pintados:
    - **branco**: não foram descobertos ainda
    - **cinzas**: são a fronteira. O vértice já foi descoberto mais ainda não examinamos os seus vizinhos.
    - **pretos**: são os vértices jádescobertos e seus vizinhos já foram examinados.
* É utilizada uma fila para manter os vértices cinzas

## Exemplos

1. **Problema**: Como saber se existe caminho entre dois vértices?

    **Exemplo**: existe um caminho entre Londrina e Manaus?
    
    **Solução**: usar BFS;
    - Marcar Londrina como raiz;
    - Realizar BFS
    - Ao terminar BFS se Manaus tiver distância diferente de infinito ou se o vértice está pintado de preto, então há caminho, caso contrário, não há

2. **Problema**: Como saber se um grafo é conectado (i.e., se cada par de vértices está conectado por um caminho)?

    **Exemplo**: gostaria de saber se posso voar de qualquer cidade para qualquer cidade.

    **Solução**: usar BFS
    - Escolher um vértice v qualquer de G
    - Executar BFS à partir de v
    - Verificar se todos vértices foram pintados de preto

3. **Problema**: Como saber se um grafo é conectado (i.e., se cada par de vértices está conectado por um caminho)?

    **Exemplo**: gostaria de saber se posso voar de qualquer cidade para qualquer cidade.