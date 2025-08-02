#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printer(int i) {
    cout << i << ", ";
}

// Função que multiplica um número por 2, passando por referência para alterar o original
void multiply(int& a) {    // Passar por referência para modificar o elemento original
    a = a * 2;             // Modifica o valor do elemento
    // nesse caso é passado o endereço do elemento a ser modificado
}

int main() {
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);

    // Multiplica cada elemento do vetor por 2
    for_each(v1.begin(), v1.end(), multiply);

    /*
    troca o primeiro elemento do vetor pelo último elemento do array
    iter_swap troca v1[0] (6) com mynumbers[6] (5), então:
    v1[0] fica 5 
    mynumbers[6] fica 6
    */
    iter_swap(v1.begin(), mynumbers + 6);

    // Imprime os elementos do vetor após modificações
    for_each(v1.begin(), v1.end(), printer);

    return 0;
}
