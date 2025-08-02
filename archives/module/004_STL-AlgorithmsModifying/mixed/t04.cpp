#include <iostream>     // Para entrada e saída (cout)
#include <algorithm>    // Para usar funções como swap_ranges, sort, for_each
#include <vector>       // Para usar std::vector
#include <deque>        // Para usar std::deque

using namespace std;

// Função auxiliar que imprime um número seguido de vírgula
void printer(int i) {
    cout << i << ", ";
}

int main() {
    // Array de inteiros com 7 elementos
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    // Criação de um deque (fila de duas pontas) d1, inicializado com os elementos do array
    deque<int> d1(mynumbers, mynumbers + 7);

    // Criação de um vetor v1 com os elementos de d1 em ordem reversa (rbegin até rend)
    vector<int> v1(d1.rbegin(), d1.rend());

    // Troca os elementos entre v1 e d1, um por um
    // swap_ranges troca os valores entre os dois contêineres no intervalo [begin, end)
    swap_ranges(v1.begin(), v1.end(), d1.begin()); // LINE I

    // Ordena os elementos do deque d1 em ordem crescente
    sort(d1.begin(), d1.end()); // LINE II

    // Imprime os elementos do deque d1
    for_each(d1.begin(), d1.end(), printer);

    // Imprime os elementos do vetor v1
    for_each(v1.begin(), v1.end(), printer);

    cout << endl; 

    return 0;
}
