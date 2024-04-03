# Tabelas Hash

As Tabelas Hash são estruturas utilizadas para busca rápida de elementos.
São implementadas com vetores e listas encadeadas em algumas situações.

* **Tamanho (T)**: define o tamanho da tabela Hash, a quantidade máxima de elementos. Para definir um bom tamanho para a tabela Hash, multiplique a quantidade de elementos do conjunto de dados que será armazenado por 2, e encontre qual o número primo mais próximo do resultado. É ideal que sobre espaços!
        
        T = 2 * qtd de elementos do conjunto ->(primo mais próximo)
* **Função de espalhamento (FE)**: é a função que gera uma "chave" a ser utiizado como índice de acesso na tabela. É definida pelo resto da divisão entre a chave do elemento e o tamanho da tabela.

        FE = chave do elemento % T
* **Fator de carga (F)**: é um fator que indicará se sua tabela está bem baleanceada. O ideal é que a tabela não esteja nem muito cheia (perto de 1), indicando que a tabela não guardará muitos valores, e nem muito vazia (perto de 0), pois isto indica que estaria perdendo memória.
        
        F = Qtd de elementos do conjunto / T ->(entre 0 e 1, o ideal é proximo a 0,5)
* **Colisões**: é possível que ocorra em uma tabela, quando a função de espalhamento não está bem planejada ou há muitos dados, gerando as mesmas chaves para códigos diferentes.
    - Uma solução para isto é adicionar o elemento de chave repetida no proximo espaço vazio.
    - Outra solução é implementar uma tabela de listas encadeadas, assim, todos os elementos de mesma chave estarão na lista.

## Funções de Espalhamento (Hash)

### Método da divisão

* Fácil e eficiente, por isso muito empregado.
* A chave x é dividida pela dimensão da tabela m, e o resto da divisão é usado como endereço-base. Isto é, 
        ```
        h(x) = h mod m
        ```
        resultando em endereços no intervalo [0, m – 1]
* Alguns valores de m são melhores que outros.
* Se m é um número par, h(x) será par quando x for par e ímpar quando x for ímpar. Não é uma boa solução.
* Se m for uma potência de 2, h(x) dependerá apenas de alguns dígitos de x. A situação é pior.
* Existem alguns critérios que têm sido aplicados com bons resultados práticos.
* Escolher m de modo que seja um número primo não próximo a uma potência de 2.
* Escolher m tal que não possua divisores primos menores que 20.

### Método da dobra

* Suponha a chave como uma sequência de dígitos escritos num pedaço de papel.
* O método em questão consiste em “dobrar” esse papel, de maneira que os dígitos se sobreponham.
* Esses devem ser somados sem levar em consideração o “vai um”.
* Pode ser utilizado com números binários, com a operação de OU Exclusivo

### Método da multiplicação

* Apresenta algumas variações, sendo a mais conhecida o método do “meio do quadrado”.
* A chave é multiplicada por ela mesma.
* O resultado é armazenada em palavra de memória de b bits.
* O número de bits necessário para forma o endereço-base de uma chave é então retirado dos b bits.
* Descartando-se os bits excessivos da extrema direita e da extrema esquerda.

## No repositório

Aqui temos:
* **Exemplos**:
      - **DuploHash**: Tabela com duplo Hash
      - **EncadeadaSeparada**: Tabela com lista encadeada simples
      - **Simples**: Tabela simples
* **Exercicios**:
      - **GerenciamentoInventario**: Um sistema de gerenciamento de inventário