/**
 * @brief O menu principal
*/

#ifndef _MENU_PRINCIPAL_
#define _MENU_PRINCIPAL_


/************************************************************
 * Funções auxiliares
*************************************************************/

/**
 * @brief Sorteia um número do intervalo
 * @param minimo O menor número do intervalo
 * @param maximo O maior número do intervalo
 * @return O número sorteado
 */
int sortearNumeroInteiro(int minimo, int maximo);

/************************************************************
 * Mostrar 
*************************************************************/

/**
 * @brief Mostra o cabeçalho para o inicio do menu
 * @param texto O texto que ficará no cabeçalho
*/
void mostrarTitulo(char* texto);

/**
 * @brief Mostra o cabeçalho para o inicio da opção
 * @param texto O texto que ficará no cabeçalho
 */
void mostrarOpcao(char *texto);

/************************************************************
 * Leituras
*************************************************************/

/**
 * @brief Lê um número inteiro e o retorna
 * @param texto O texto que será exibido na hora da leitura
 * @return O número inteiro lido
*/
int lerInteiro(char *texto);

/**
 * @brief Lê um número double e o retorna
 * @param texto O texto que será exibido na hora da leitura
 * @return O número double lido
*/
double lerDouble(char *texto);

/**
 * @brief Lê um texto e o retorna
 * @param texto O texto que será exibido na hora da leitura
 * @return O texto lido
*/
char *lerString(char *texto);

#endif