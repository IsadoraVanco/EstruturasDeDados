/**
 * @brief Testar o algoritmo Bellman Ford do exercicio
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafoLista.h"
#include "bellmanFord.h"


int main(int argc, char const *argv[]){
    
   int numeroCidades, numeroRotas;

   printf("=> Número de cidades: ");
   scanf("%d", &numeroCidades);

   while(numeroCidades <= 0){
        printf("=> Número de cidades: ");
        scanf("%d", &numeroCidades);
   }

   printf("=> Número de rotas: ");
   scanf("%d", &numeroRotas);

   while(numeroRotas <= 0){
        printf("=> Número de rotas: ");
        scanf("%d", &numeroRotas);
   }

   GrafoLista *grafoLista = criarGrafoLista(numeroCidades);

    printf("=> Rotas:\n");
   for(int i = 0; i < numeroRotas; i++){
        int origem, destino, peso;
        scanf("%d %d %d", &origem, &destino, &peso);
        inserirArestaBidirecionadaGrafoLista(grafoLista, origem, destino, peso);
   }

   int origem;

   printf("=> Origem: ");
   scanf("%d", &origem);

   GrafoBellmanFord *grafoBellman = criarBellmanLista(grafoLista, origem);
   
   if(grafoBellman){
        criarImagemBellmanFord(grafoBellman, false);
        destruirGrafoBellmanFord(grafoBellman);
    }

   destruirGrafoLista(grafoLista);

    return 0;
}
