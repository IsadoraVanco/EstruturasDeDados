# Quick Sort

* Ideia básica: Dividir e Conquistar
* Um elemento é escolhido como pivô;
* "Particionar": os dados são rearranjados
* valores menores do que o pivô sã o colocados antes dele e os maiores, depois
* Recursivamente ordena as 2 partições
* Vantagem em relação ao MergeSort: Os subarranjos são ordenados localmente, então não é necessário combinar!!

* Algoritmo para o particionamento:
    - Escolha arbitrariamente um pivôx.
    - Percorra o vetor a partir da esquerda atéque v[i] >= x.
    - Percorra o vetor a partir da direita atéque v[j] <= x.
    - Troque v[i] com v[j].
    - Continue este processo atéos apontadores i e j se cruzarem.

* Concluı́do o particionamento, o vetor v[esq..dir] está particionado de tal forma que:
    - Os itens em v[esq], v[esq + 1], ..., v[j] são menores ou iguais a x (pivô ).
    - Os itens em v[i], v[i + 1], ..., v[dir] são maiores ou iguais a x (pivô ).

* Pode-se concluir então que o pivôx encontra-se na posição correta de ordenação!
* Divida o algoritmo em duas partes.
* Ordene as duas partes usando chamadas recursivas.
* Intercale as duas partes, obtendo um conjunto ordenado de todos os elementos.

## Vantagens:
* É extremamente eficiente para ordenar arquivos. 
* Requer apenas uma pequena pilha como memória auxiliar.
* Requer **O(n log n)** comparações em média (caso médio) para ordenar n itens.

## Desvantagens:
* Tem um pior caso com **O(n2)** comparações. 
* Implementação delicada e difı́cil: um pequeno engano pode levar a efeitos inesperados. 
* O método não é estável.