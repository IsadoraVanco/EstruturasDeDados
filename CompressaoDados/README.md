# Compressão de dados

* Consiste na utilização de um conjunto de métodos com o intuito da redução do espaço armazenado em unidades de memória secundária ou mesmo primária de um sistema computacional.
* Um arquivo comprimido terá seu tamanho reduzido, como saída resultante da aplicação de um algoritmo de compactação de alguma aplicação, como, por exemplo, gzip, winzip ou winrar.
* Na internet, a compressão ajuda a diminuir a quantidade de tráfego na grande rede, aumentando a velocidade de navegação, realização de downloads de arquivos e visualização de vídeos.
* Arquivos compactados são preferíveis quando há interesse de armazenamento de maior número de dados possível no menor espaço de memória secundária disponível, como em pen-drives, memmory cards, discos rígidos e demais unidades de memória.
* Muitos arquivos de extensões famosas, como pdf (textos, e-books), mp3 (áudio, músicas), gif (imagens, fotos), zip (arquivos em geral), mpg (vídeos), utilizam algoritmos de compactação em suas concepções.
* Arquivos são sequências de bytes, caracteres alfabéticos, numéricos e símbolos imprimíveis ou não. Se começarmos a raciocinar sobre essas sequências, é provável que comecemos a imaginar maneiras de reorganizar ou representar tais sequências de uma maneira que a quantidade de bytes possa ser reduzida.
* Representação de uma fonte de dados da maneira mais precisa possível utilizando um menor número de bits;
* Fazer com que a mesma quantidade de informação caiba em um espaço menor;
* Eliminar as redundâncias: recorrências de letras, dígitos ou pixels;
* Receptor deve ser capaz de decodificar os dados para acessar a informação;
```
Exemplos:
‘AAAAAA’, que ocupa 6 bytes, poderia ser comprimida para 
‘6A’, que ocupa 2 bytes

AATTTT representa-se por: 
*4T (decodifica por meio de uma tabela).
```

## Compressão x Compactação
* **Compressão:**
    - Mudança na representação de algum dado para reduzir seu tamanho
    - Compressão do HD: reduzir o tamanho dos arquivos
* **Compactação:**
    - União de dados que não estão unidos
    - Compactação do HD: juntar partes disjuntas (desfragmentar)

## Desvantagens

* Custo de processamento na compressão e na descompressão;
* Custo para armazenar a tabela de símbolos ou dicionário;
* Ganhos expressivos são obGdos apenas com métodos de compressão que não permitem reconstruir os dados exatamente da maneira como eram antes da compressão.