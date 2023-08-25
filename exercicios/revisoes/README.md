# Exercícios de Revisão 

Créditos ao profº Gilberto, autor dos exercícios.

## Conteúdos abordados:

* Vetor: palindromo

    1. Números palíndromos são aqueles que escritos da direita para a esquerda têm o mesmo valor quando escritos da esquerda para a direita. Exemplo: 545; 789987; 97379; 123454321; etc. Escreva um programa que verifique se um dado vetor A de 10 elementos inteiros é um palíndromo, ou seja, se o primeiro elemento do vetor e igual ao último, se o segundo elemento do vetor é igual ao penúltimo e assim por diante até verificar todos os elementos ou chegar à conclusão que o vetor não é um palíndromo.

* Matrizes: matrizTriangular, jogoDaVelha

    1. Faça um programa para determinar a próxima jogada em um Jogo da Velha. Assumir que o tabuleiro é representado por uma matriz de 3x3, onde cada posição representa uma das casas do tabuleiro. A matriz pode conter os seguintes valores: -1, 0, 1 (representando respectivamente uma casa contendo uma peça minha (-1), uma casa vazia do tabuleiro (0), e uma casa contendo uma peça do meu oponente (1)).

    2. Faça um programa que leia/gere uma matriz 4x4 e transforme-a em uma matriz triangular inferior, ou seja, atribuindo zero a todos os elementos acima da diagonal principal. Imprima a matriz original e a matriz transformada.

* Funções: funcaoDefault

    1. Crie uma função que receba uma variável struct como parâmetro e inicialize cada um de seus atributos com valores default (padrão) conforme as orientações a seguir:
        
        • Matrícula -> valor padrão: 0
        • Nome -> valor padrão: “\0” (caractere nulo)
        • Nota 1 -> valor padrão: 0
        • Nota 2 -> valor padrão: 0

* Ponteiros: trocaValores

    1. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B, e B terá o valor de A.

    2. Faça um programa que possua uma função para:
        • Ler 2 notas e retorna-las por parâmetro (chamar uma função dedicada a ler 2 notas válidas e que devolva os 2 números lidos);
        • Calcular a média simples e a média ponderada e retorna-las por parâmetro, onde a segunda nota tem peso 2. 
        (média ponderada = (n1 + n2 ∗ 2)/3);

* TAD: numeroComplexo
    1. Implemente um TAD “Número Complexo” e implemente as seguintes operações:
        • Inicializa: atribui valores para os campos
        • Imprime: imprime o número da forma “R + Ci”
        • Copia: Copia o valor de um número para outro
        • Soma: Soma dois números complexos
        • EhReal: testa se um número é real

        • Por fim, faça um pequeno programa para testar o seu TAD

        *Lembre-se que em números complexos, cada número possui os campos real e
        imaginário