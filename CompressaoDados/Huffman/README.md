# Algoritmo de Huffman

* É um método de compactação que usa as probabilidades de ocorrência dos símbolos no conjunto de dados a ser compactado para determinar códigos de tamanho variável para cada símbolo.
* Idéia é usar caracteres (símbolos) com número variável de bits
* Caracteres mais comuns na mensagem são codificados com menos bits e caracteres menos comuns com mais
* Tem por objetivo a construção de uma árvore binária baseada na frequência de uso das letras do alfabeto de modo que as mais frequentemente utilizadas apareçam mais perto da raiz.
* Esta árvore binária é construída da baixo para cima (das folhas para a raiz) , começando a partir das letras menos usadas até atingir a raiz.

```
Sequência de caracteres:
FAAFEEEAAAAEEEECCAAAAAAAAACFFCCAAAACCCBAA
ABBBBAAAAAAAADDDDBBBBBBDDDDAAAAAADDDDD
DAAAAEE

Caracteres: FECBDA
Frequência: 5 9 12 13 16 45 (respectivamente)

- Faz a árvore binária
- Cada caractere possui um código

Sem compactação
01000110010000010100000101000110010001010100010101000101010000010100000101000001010000010100010101000101010001010100010101000011010000110100000101000001010000010100000101000001010000010100000101000001010000010100001101000110010001100100001101000011010000010100000101000001010000010100001101000011010000110100001001000001010000010100000101000010010000100100001001000100100000101000001010000010100000101000001010000010100000101000001010010001000100010001000100010001000010010000100100001001000010010000100100001001000100010001000100010001000100010000010100000101000001010000010100000101000001010001000100010001000100010001000100010001000100010000010100000101000001010000010100010101000101
Com compactação
11000011001101110111010000110111011101110110010000000000010011001100100100000010010010010100010110110110100000000111111111111101101101101101101111111111111000000111111111111111111000011011101
```

## Decodificação

* Para decodificar uma mensagem obtida, basta ir utilizando cada bit da mensagem para percorrer a arvore de Huffman desde a raiz até alguma folha, quando se obtém o símbolo decodificado. Volte então para a raiz e continue a percorrer a árvore para decodificar o próximo símbolo.