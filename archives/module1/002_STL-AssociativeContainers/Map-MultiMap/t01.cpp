#include <map>
#include <iostream>
#include <functional>
#include <iomanip>

using namespace std;

// Imprime pares chave:valor do multimap
template <class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        ++start;
    }
    cout << endl;
}

// preenche o multimap com pares chave:valor (onde valor = chave)
template <class T, class U>
void fillMap(multimap<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start)); // permite duplicatas
    }
}

int main() {
    int t[] = { 2, 10, 8, 4, 5, 5, 3, 10, 7, 2 };

    // inicialização padrão
    multimap<int, int> m1;
    fillMap(m1, t, t + 10); // Elementos repetidos são permitidos

    // Construtor por intervalo de iteradores
    multimap<int, int> m2(m1.begin(), m1.end());
    print(m2.begin(), m2.end());

    // Construtor de cópia
    multimap<int, int> m3(m2);
    print(m3.begin(), m3.end());

    // Multimap com ordenação decrescente
    multimap<int, int, greater<int>> m4(m1.begin(), m1.end());
    print(m4.begin(), m4.end());

    // Não permitido: tipos incompatíveis
    // multimap<int, greater<int>> m5(m3);

    // Atribuição entre multimaps do mesmo tipo
    multimap<int, int> m6;
    m6 = m3;
    print(m6.begin(), m6.end());

    // Não permitido: tipos incompatíveis na atribuição
    // m6 = m4;

    return 0;
}
