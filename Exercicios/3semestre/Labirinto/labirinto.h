/*
    Módulo com todas as funções de manipulação
    do labirinto
*/

//******************** DEFINIÇÕES ********************

/*
    Caracteres de conversão da leitura do mapa
*/
#define CAMINHO_LIVRE 0
#define PAREDE 1
#define PARTIDA 2
#define CHEGADA 3

/*
    Caracteres que vão compor o mapa
*/
#define DESENHO_CAMINHO_LIVRE
#define DESENHO_CAMINHO_PERCORRIDO '.'
#define DESENHO_PERSONAGEM '@'
#define DESENHO_PAREDES '#'
#define DESENHO_CHEGADA 'o'

/*
    Representa um ponto no mapa
*/
typedef struct {
    int x, y;
}Ponto;

//******************** VARIÁVEIS GLOBAIS ********************

int acabou = 0; //Representa se o jogo acabou
int tamanhoLabirinto; //Representa o número de linhas e colunas da matriz N x N
Ponto chegada = {0, 0}; //Representa o ponto de chegada
Ponto partida = {0, 0}; //Representa o ponto de partida

//******************** FUNÇÕES ********************

/*
Verifica se o ponto em (x, y) é uma borda e se possui
um caractere. Se falta ao menos um caractere para fechar as bordas, 
retorna 1, senão, 0.
*/
int faltaBorda(int x, int y, int ponto);

/*
Armazena a coordenada do ponto de chegada.
*/
void setChegada(int x, int y);

/*
Armazena a coordenada do ponto de partida.
*/
void setPartida(int x, int y);

/*
Mostra o tabuleiro do labirinto.
*/
void mostraTabuleiro(int* matriz);

/*
Libera o espaço na memória ocupado pelo tabuleiro.
*/
void encerraTabuleiro(int* matriz);