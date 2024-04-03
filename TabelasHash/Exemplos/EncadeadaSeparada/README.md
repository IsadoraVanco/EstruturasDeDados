# Hash com encadeamento separado

* Não procura por posições vagas (valor NULL) dentro do array que define a tabela
* Armazena dentro de cada posição do array o início de uma lista dinâmica encadeada
* É dentro dessa lista que serão armazenadas as colisões (elementos com chaves iguais) para aquela posição do array
* A lista dinâmica encadeada mantida em cada posição da tabela pode ser ordenada ou não

- Lista não ordenada:
    * Inserção tem complexidade O(1) no pior caso: basta inserir o elemento no início da lista.
    * Busca tem complexidade O(M) no pior caso: busca linear

- Desvantagem
    * Quantidade de memória consumida: gastamos mais memória para manter os ponteiros que ligam os diferentes elementos dentro de cada lista