#include <stdlib.h>
#include "tools.h"

//Define o sistema que está utilizando
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif


void delay(int tempo){
    #ifdef WIN32
    //windows
    Sleep(tempo);
    #else
    //linux
    usleep(1000 * tempo);
    #endif
}

void clear(){
    #ifdef WIN32
    //windows
    system("cls");
    #else
    //linux
    system("clear");
    #endif
}