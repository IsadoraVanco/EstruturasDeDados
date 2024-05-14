# Bellman Ford

Créditos à profª Vanessa, autora do exercício.

Desenvolva um algoritmo para determinar o caminho de menor custo de uma cidade de origem para todas as outras cidades na rede, considerando que os custos das arestas podem ser negativos. Você deve utilizar o algoritmo de Bellman-Ford para esta tarefa.
 
## Dados
 
1. Número de cidades (nós) na rede: n
2. Número de rotas (arestas) disponíveis: m
3. Lista de rotas entre as cidades com seus respectivos custos, onde cada rota é representada por um trio (origem, destino, custo).
 
## Tarefas
 
1. Implemente o algoritmo de Bellman-Ford.
2. Utilize o algoritmo para determinar o menor caminho do nó de origem (especificado no início da execução do algoritmo) para todos os outros nós na rede.
3. Identifique se existe um ciclo de custo negativo que seja alcançável a partir do nó de origem. Se existir, o algoritmo deve reportar sua existência.
 
## Exemplo de Entrada
```
Número de cidades: 5
Número de rotas: 8
Rotas:  
(0, 1, -1)
(0, 2, 4)
(1, 2, 3)
(1, 3, 2)
(1, 4, 2)
(3, 2, 5)
(3, 1, 1)
(4, 3, -3)
```