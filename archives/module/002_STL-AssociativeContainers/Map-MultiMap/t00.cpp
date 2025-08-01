#include <map>
#include <iostream>
#include <functional>
#include <iomanip>

using namespace std;

template <class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":-:" << start->second << "  ";
        ++start;
    }
    cout << endl;
}

// preenche o map com pares chave:valor a partir de um intervalo
template <class T, class U>
void fillMap(map<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start)); // valor = chave
    }
}

int main() {
    int t[] = { 1, 10, 8, 4, 6, 5, 3, 9, 7, 2 };

    // inicialização padrão (map vazio)
    map<int, int> m1;
    fillMap(m1, t, t + 10); // Preenche com os elementos do array

    // inicialização via intervalo de iteradores (construtor por intervalo)
    map<int, int> m2(m1.begin(), m1.end());
    print(m2.begin(), m2.end());

    // Construtor de cópia
    map<int, int> m3(m2);
    print(m3.begin(), m3.end());

    // Usando um comparador diferente (ordem decrescente)
    map<int, int, greater<int>> m4(m1.begin(), m1.end());
    print(m4.begin(), m4.end());

    // não permitido: tipos de mapas incompatíveis (comentado)
    // map<int, greater<int>> m5(m3);

    // Atribuição entre mapas do mesmo tipo
    map<int, int> m6;
    m6 = m3;
    print(m6.begin(), m6.end());

    // Não permitido: atribuição entre mapas com comparadores diferentes (comentado)
    // m6 = m4;

    return 0;
}
