#include <iostream>
#include <stack>

int main() {
    // Cria uma pilha vazia usando um contêiner std::deque como padrão
    std::stack<int> pilha;

    // Inserindo elementos na pilha
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    // Acessando o elemento do topo da pilha (sem removê-lo)
    std::cout << "Topo da pilha: " << pilha.top() << std::endl;

    // Removendo elementos da pilha
    pilha.pop(); // Remove o elemento do topo (30)

    // Verificando se a pilha está vazia
    if (pilha.empty()) {
        std::cout << "A pilha está vazia." << std::endl;
    } else {
        std::cout << "A pilha não está vazia." << std::endl;
    }

    // Tamanho da pilha
    std::cout << "Tamanho da pilha: " << pilha.size() << std::endl;

    return 0;
}
