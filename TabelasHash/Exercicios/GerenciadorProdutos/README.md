# Tabela Hash

Desenvolva um sistema de gerenciamento de inventário para uma loja, que deve ser capaz de adicionar produtos, buscar produtos pelo código de identificação e remover produtos do inventário. Cada produto tem um **código de identificação único** (um número inteiro), uma **descrição** (uma string) e um **preço**.
Para este sistema, você deve implementar duas versões de tabela hash:
 
1. **Tabela Hash com Encadeamento Separado**: Use listas encadeadas para resolver colisões. Os produtos adicionados nesta tabela devem ter o preço até R$200,00
2. **Tabela Hash com Encadeamento Aberto**: Use Duplo Hash para resolver colisões. Os produtos adicionados nesta tabela devem ter o preço maior que R$200,00
 
Ambas as tabelas hash devem suportar as operações básicas de **inserção**, **busca** e **remoção** de produtos.
 
- A função hash para ambas as tabelas deve ser bem projetada para **distribuir uniformemente os produtos**, minimizando as colisões. Utilize **funções hashs diferentes** para cada abordagem, sendo que uma delas deve ser o **método de dobra**.
- Implemente funções para inserir, buscar pelo código de identificação, e remover produtos.
- Implemente as funções de **inicialização**, **destruição**, **inserção**, **busca** e **remoção** para ambas as versões da tabela hash.