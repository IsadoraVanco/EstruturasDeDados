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

Aqui temos:
* **Exemplos**:
    - **C**: Exemplos de outras fontes