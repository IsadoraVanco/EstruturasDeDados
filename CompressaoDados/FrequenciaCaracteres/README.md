# Frequência de Caracteres - Run Length Encoding (RLE)

* Conhecida como Run-length encoding (RLE).
* Usado em arquivos textos;
* Determinar a quantidade de símbolos idênticos consecutivos existentes no texto;
* Cada uma das sequências máximas de símbolos idênticos é substituída por um número indicando da frequência do símbolo em questão, seguido do símbolo
* Textos que contêm números como símbolos podem causar problema, uma vez que o número pode ser confundido com frequência
* Solução: usar um caractere de escape, como @

Exemplos:
```
Cadeira Original: 
GGCTAACAAACAAGAAACATAAACAGAATAGGCGCCCT
Cadeira Compactada: 2G1C1T2A1C3A1C2A1G3A1C1A1T3A1C1A1G2A1T1A2G1C1G3C1
```
```
Cadeira Original: 
GGCTAACAAACAAGAAACATAAACAGAATAGGCGCCCT
Cadeira Compactada:
2GCT2AC3AC2AG3ACAT3ACAG2ATA2GCG3CT
```
```
Cadeia Original: 
AAA33333BA6666888DDDDDDD99999999999AABBB
Cadeia Compactada: 
3A5@3BA4@63@87D11@92A3B
```