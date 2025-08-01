#include <iostream>
#include <set>
#include <vector>

using namespace std;

// função genérica para imprimir qualquer intervalo de iteradores
template <class T>
void print(T start, T end) {
    while (start != end) {
        std::cout << *start << ", ";
        start++;
    }
}

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 7 };

    vector<int> v(mynumbers, mynumbers + 8);

    // multiset com todos os elementos do array
    multiset<int> s1(mynumbers, mynumbers + 8);

    // Para i de 9 até 1, decrementando
    for (int i = 9; i > 0 && !s1.empty(); i--) {
        auto it = s1.begin();  // menor valor
        double x = *it;        // obtém esse valor
        s1.erase(it);          // remove do multiset
        v.push_back(i + x);    // adiciona soma ao vetor
    }

    // imprime o vetor resultante
    print(v.begin(), v.end());
    cout << endl;

    return 0;
}
