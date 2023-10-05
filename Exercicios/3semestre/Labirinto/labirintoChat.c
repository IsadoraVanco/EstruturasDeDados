#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Estrutura para representar uma posição no labirinto
typedef struct {
    int x, y;
} Posicao;

// Tamanho máximo para o labirinto
#define MAX 100

// Definição de pilha
typedef struct {
    Posicao dados[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para empilhar uma posição
void empilhar(Pilha *pilha, Posicao pos) {
    pilha->topo++;
    pilha->dados[pilha->topo] = pos;
}

// Função para desempilhar uma posição
Posicao desempilhar(Pilha *pilha) {
    Posicao pos = pilha->dados[pilha->topo];
    pilha->topo--;
    return pos;
}

// Função para imprimir o labirinto
void imprimirLabirinto(int labirinto[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labirinto[i][j] == 1) {
                printf("# ");
            } else if (labirinto[i][j] == 0) {
                printf(". ");
            } else if (labirinto[i][j] == 2) {
                printf("o ");
            } else if (labirinto[i][j] == 3) {
                printf("@ ");
            }
        }
        printf("\n");
    }
}

// Função para verificar se uma posição é válida no labirinto
int ehPosicaoValida(int labirinto[MAX][MAX], int n, int m, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labirinto[x][y] == 0;
}

// Função de backtracking para resolver o labirinto com simulação de passos
int resolverLabirinto(int labirinto[MAX][MAX], int n, int m, Posicao inicio, Posicao destino) {
    Pilha pilha;
    inicializarPilha(&pilha);

    // Empilhe a posição inicial
    empilhar(&pilha, inicio);

    // Movimentos possíveis (cima, baixo, esquerda, direita)
    int movX[4] = { -1, 1, 0, 0 };
    int movY[4] = { 0, 0, -1, 1 };

    while (!pilhaVazia(&pilha)) {
        Posicao atual = desempilhar(&pilha);
        labirinto[atual.x][atual.y] = 4; // Marque o caminho

        usleep(500000); // Pausa de meio segundo (500000 microssegundos)

        system("clear"); // Limpa a tela (para sistemas Unix-like, use "cls" para Windows)

        imprimirLabirinto(labirinto, n, m);

        // Chegamos ao destino
        if (atual.x == destino.x && atual.y == destino.y) {
            return 1; // Labirinto resolvido
        }

        // Tente movimentos possíveis
        for (int i = 0; i < 4; i++) {
            int newX = atual.x + movX[i];
            int newY = atual.y + movY[i];

            if (ehPosicaoValida(labirinto, n, m, newX, newY)) {
                Posicao proxima = {newX, newY};
                empilhar(&pilha, proxima);
            }
        }
    }

    return 0; // Não há caminho até o destino
}

int main() {
    int n, m;
    FILE *arquivo;
    
    arquivo = fopen("labirinto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo labirinto.txt\n");
        return 1;
    }

    // Leitura das dimensões do labirinto
    fscanf(arquivo, "%d", &n);
    m = n;

    int labirinto[MAX][MAX];
    Posicao inicio, destino;

    // Leitura do labirinto do arquivo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(arquivo, "%d", &labirinto[i][j]);
            if (labirinto[i][j] == 2) {
                inicio.x = i;
                inicio.y = j;
            } else if (labirinto[i][j] == 3) {
                destino.x = i;
                destino.y = j;
            }
        }
    }

    fclose(arquivo);

    printf("Labirinto original:\n");
    imprimirLabirinto(labirinto, n, m);

    if (resolverLabirinto(labirinto, n, m, inicio, destino)) {
        printf("\nLabirinto resolvido:\n");
        imprimirLabirinto(labirinto, n, m);
    } else {
        printf("\nNão há caminho no labirinto.\n");
    }

    return 0;
}
