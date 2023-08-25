#include <iostream>

using namespace std;

int main(){
    //variaveis unitárias
    double *ptr;
    ptr = new double;

    cin >> *ptr;
    cout << *ptr << endl;
    delete ptr;

    //vetores
    int *ptr2;
    ptr2 = new int [10];

    for(int i = 0; i < 10; i++){
        ptr2[i] = i + 1;
    }

    for(int i = 0; i < 10; i++){
        cout << ptr2[i] << endl;
    }
    delete [] ptr2;

    return 0;
}