# Labirinto com Backtracking usando pilhas

Créditos ao prof° Gilberto, autor do exercício.

Um dos desafios frequentemente abordados com o uso de pilhas envolve a resolução de labirintos, que são enigmas concebidos como testes para avaliar o desempenho das estruturas de dados. Além disso, as pilhas desempenham um papel crucial na aplicação de algoritmos de Backtracking, que envolvem a criação de pontos de referência para permitir que o algoritmo faça retornos a estados/pontos anteriores. Em um labirinto, por exemplo, podemos encontrar um caminho correto empilhando cada espaço avançado e desempilhando espaços quando chegar a um ponto sem saída, até algum espaço que possibilita a tomada de outro caminho. Nesta lógica, ao final do algoritmo a pilha irá conter o caminho correto. E uma pilha vazia indica que não há solução para o labirinto apresentado.

Você deve criar um programa na linguagem de programação C cujo objetivo é encontrar um caminho de um ponto de partida para um ponto de chegada no labirinto. Este programa deve utilizar pilhas para encontrar uma solução para o labirinto, seguindo estas regras:
- Você pode mover-se nas quatro direções cardeais (cima, baixo, esquerda e direita).
- Você não pode atravessar paredes.
- O labirinto deve ser fechado.
- A implementação do Backtracking deve garantir que todas as opções sejam consideradas até encontrar o ponto de destino, ou determinar que não há caminho possível.

## Entrada:

Cada instância de entrada é dada por um arquivo texto chamado "labirinto.txt" contendo na primeira linha um valor inteiro n para a dimensão do labirinto (considere o labirinto sempre como uma matriz quadrada). Em seguida, nas próximas n linhas do arquivo, você deverá inserir a matriz do labirinto como números inteiros separados por espaço considerando a seguinte legenda:
- 1 – Parede.
- 0 – Caminho livre/vazio.
- 2 – Posição inicial do personagem.
- 3 – Posição de chegada.

Este arquivo será lido a partir do mesmo diretório onde se encontra o programa principal. No programa, ao imprimir o labirinto, utilize sua criatividade para substituir os números acima por caracteres/elementos de acordo com sua imaginação.

Segue um exemplo do arquivo de entrada "labirinto.txt":

    9
    1 1 1 1 1 1 1 1 1 
    1 2 1 0 0 0 1 0 1
    1 0 1 0 1 0 0 0 1
    1 0 0 0 1 0 1 0 1
    1 1 1 1 1 0 1 3 1
    1 1 1 1 1 0 1 1 1
    1 0 0 0 0 0 0 0 1
    1 1 0 1 1 1 1 1 1
    1 1 1 1 1 1 1 1 1 

Que poderia ser impresso da seguinte maneira (sugestão):


    # # # # # # # # #
    # o #       #   #
    #   #   #       #
    #       #   #   #
    # # # # #   # @ # 
    # # # # #   # # #
    #               #
    # #   # # # # # #
    # # # # # # # # #

## Saída:

Impressão direto no terminal da pilha contendo o caminho correto encontrado, indicando as posições de cada célula da matriz que compõem o caminho.
Exiba também, em tempo real, o personagem andando no labirinto mostrando o seu "rastro" indo e voltando (pode ser com um ponto, ou qualquer outro caractere que quiser).

Exemplo:

    # # # # # # # # #
    # . # . . . #   #
    # . # . # . . . #
    # . . . #   # . #
    # # # # #   # o # 
    # # # # #   # # #
    #               #
    # #   # # # # # #
    # # # # # # # # #

Caminho correto: (2,1) (3,1) (3,2) (3,3) ....

Perceba que ao final da execução, o personagem deve se encontrar na posição final!

Atenção às instruções:
- Trabalhos inteiramente copiados da internet ou de demais colegas terão a nota zerada.
- A entrega será via Google Classroom.
- Entregar dentro de uma pasta zipada com seu nome completo todos os arquivos necessários para a execução.
- É OBRIGATÓRIO utilizar PILHAS e TADs para implementar o trabalho! (Outros recursos podem ser utilizados, desde que os obrigatórios citados acima estejam presentes).
- O trabalho poderá ser feito individualmente ou em duplas.
- O labirinto deve funcionar para qualquer labirinto dado como entrada (e não somente o de exemplo), seguindo os padrões informados e considerando que ele seja fechado dos quatro lados. Ainda, o arquivo de entrada deve seguir o mesmo padrão do exemplo e o mesmo nome "labirinto.txt"!
- Peço que todos sigam EXATAMENTE as instruções de entrada, por favor. Deixem o programa de vocês preparado para ler um arquivo com o nome "labirinto.txt" (contendo o labirinto no formato apresentado) assim que for executado. A partir da leitura, a forma que vocês forem utilizar para armazenar/carregar/printar o labirinto para utilizá-lo no processamento fica a cargo de vocês. Pois como eu disse, eu vou carregar vários labirintos diferentes nos programas de vocês para testar a eficácia. Então peço muita atenção neste padrão pois devido ao volume de trabalhos que terei para corrigir, preciso que todos estejam no mesmo padrão de entrada para que o processo de correção fique mais ágil e facilite a vida do professor!
- Qualquer dúvida, estou à disposição.