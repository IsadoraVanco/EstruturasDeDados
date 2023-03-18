#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StStr{
  char s[500];
};
  
void preenche(Lista L){
  int *pi;
  for (int i = 0; i<20; i++){
    pi = (int *) malloc(sizeof(int));
    *pi = i;
    insert(L,pi);
  }
}

void concat (Item it, Clausura c){
  int *i = (int *) it;
  struct StStr *cstr = (struct StStr *)c;
  char istr[50];

  sprintf(istr," + %d",*i);
  strcat(cstr->s,istr);  

}

void soma (Item it, Clausura c){
  int *i = (int *) it;
  int *res = (int *)c;
  *res = (*res) + (*i);
}

Item dobra(Item it){
   int *i = (int *) it;
   int *novo = (int *) malloc (sizeof(int));
   *novo = 2 * (*i);
   return novo;
}
  
void main(){
  Lista L1,L2;
  int somaTotal = 0;
  struct StStr cl;
  cl.s[0] = '\0';

  L1 = createLista(50);
  L2 = createLista(50);

  preenche(L1);

  fold(L1,concat, &cl);
  printf("%s",cl.s);

  fold(L1,soma, &somaTotal);
  printf(" = %d\n",somaTotal);

  L2 = map(L1,dobra);
  cl.s[0] = '\0';
  fold(L2,concat, &cl);
  printf("%s",cl.s);
}