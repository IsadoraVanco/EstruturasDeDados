/*
Faça um programa que possua uma função para:
• Ler 2 notas e retorna-las por parâmetro (chamar uma função dedicada a ler
2 notas válidas e que devolva os 2 números lidos);
• Calcular a média simples e a média ponderada e retorna-las por parâmetro,
onde a segunda nota tem peso 2. (média ponderada = (�1 + �2 ∗ 2)/3);
*/
#include <stdio.h>

void leNotas(int *nota1, int *nota2){
    printf("Digite duas notas: ");
    scanf("%d %d", nota1, nota2);
}

void calculaMedias(int nota1, int nota2, double *mediaSimples, double *mediaPonderada){
    *mediaSimples = (nota1 + nota2) /2;
    *mediaPonderada = (nota1 + (nota2 * 2)) /3;
}

int main(int argc, char const *argv[]){
    int nota1, nota2;
    double mediaSimples, mediaPonderada;

    leNotas(&nota1, &nota2);
    calculaMedias(nota1, nota2, &mediaSimples, &mediaPonderada);

    printf("As notas são %d e %d\n", nota1, nota2);
    printf("A média é %.3lf e a ponderada é %.3lf\n", mediaSimples, mediaPonderada);

    return 0;
}
