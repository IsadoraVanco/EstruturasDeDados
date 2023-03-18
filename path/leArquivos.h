#ifndef _LE_ARQUIVOS__
#define _LE_ARQUIVOS__

/* EXERCICIO: escrever a descricao do modulo e das operacoes */
// arquivo organizado em linhas: // aaaa bbb cccc dddd eeee

typedef void *ArqCmds;

ArqCmds abreArquivoCmd(char *fn);

bool leLinha (ArqCmds ac,char *buf, int bufLen);
// aaaa bbbb ccccc dddd eeee

void getParametroI(ArqCmds ac, char *buf, int i, char *paramI, int paramILen);
// i==2: ccccc

void getParametroDepoisI(ArqCmds ac, char *buf, int i, char *paramI, int paramILen);
// i==2: ccccc dddd eeee

void fechaArquivoCmd(ArqsCmds);

#endif