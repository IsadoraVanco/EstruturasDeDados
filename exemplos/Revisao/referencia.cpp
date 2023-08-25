#include <iostream>

using namespace std;

void funcao(int &var){
    var = 10;
}

int main(){
    int a = 2;
    funcao(a);
    cout << a;
}