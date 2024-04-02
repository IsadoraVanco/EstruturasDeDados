# Duplo Hash

* Utilizado para tratamento de colisões
* Tenta espalhar os elementos utilizando duas funções de hashing
* A primeira função de hashing, **H1**, é utilizada para calcular a **posição inicial do elemento**
* A segunda função de hashing, **H2**, é utilizada para calcular os **deslocamentos em relação a posição inicial** (no caso de uma colisão)
* A posição de um novo elemento na tabela hash é obtida como sendo:
    ```
    H1 + i * H2
    ```
    onde i é tentativa atual de inserção do elemento

* É necessário que as duas funções de hashing sejam diferentes.
* A segunda função de hashing não pode resultar em um valor igual a ZERO pois, neste caso, não haveria deslocamento