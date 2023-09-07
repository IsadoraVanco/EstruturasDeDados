//Exemplo de TAD em C

typedef struct {
    double x, y;
} PONTO;

void inicializaPonto(PONTO *p, int x, int y);
void imprimePonto(PONTO p);
void setPonto(PONTO *P, int x, int y);
void getPonto(PONTO P, int *x, int *y);