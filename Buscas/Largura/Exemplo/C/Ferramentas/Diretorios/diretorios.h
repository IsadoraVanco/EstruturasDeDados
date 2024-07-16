/**
 * @brief Manipulação de diretorios
*/
#ifndef _DIRETORIOS_H_
#define _DIRETORIOS_H_

#ifdef _WIN32
    #include <direct.h>
    //define a função mkdir() para windows
    #define mkdir(path, mode) _mkdir(path)
#else
    #include <sys/stat.h>
#endif

/**
 * @brief Cria uma pasta no sistema
 * @param nomePasta O nome da pasta
 * @return Retorna 0 caso a operação tenha sido concluída
 * com sucesso, se não, retorna 1.
 */
int criaPasta(char* nomePasta);

#endif