#include <map>
#include <iostream>
#include <functional>

using namespace std;

// função genérica para imprimir pares (key:value)
template <class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        ++start;
    }
}

// Função auxiliar para preencher um map com pares key=value
template <class T, class U>
void fillMap(map<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert({*start, *start});
    }
}

int main() {
    int t[] = {1, 10, 8, 4, 6, 5, 3, 9, 7, 2};
    map<int, int> m1;
    fillMap(m1, t, t + 10); // preenchendo map com pares (key=value)

    // Ordenação decrescente usando comparador greater<>
    map<int, int, greater<int>> m2(m1.begin(), m1.end());

    cout << "Standard iterator (key only):\n";
    map<int, int>::iterator it1 = m1.begin();
    for (; it1 != m1.end(); ++it1) {
        cout << it1->first << " ";
    }
    cout << endl;

    it1 = m2.begin();
    for (; it1 != m2.end(); ++it1) {
        cout << it1->first << " ";
    }
    cout << "\n\n";

    cout << "Reverse iterators (key:value):\n";
    print(m1.rbegin(), m1.rend());
    cout << endl;
    print(m2.rbegin(), m2.rend());
    cout << "\n\n";

    cout << "Const iterators:\n";
    print(m1.cbegin(), m1.cend());
    cout << endl;
    print(m2.cbegin(), m2.cend());
    cout << "\n\n";

    cout << "Const reverse iterators:\n";
    print(m1.crbegin(), m1.crend());
    cout << endl;
    print(m2.crbegin(), m2.crend());
    cout << "\n\n";

    // -------------------------------
    // Modificações com iteradores
    // -------------------------------

    map<int, int>::const_iterator cit1 = m1.begin(); // iterador constante

    it1 = m1.begin(); // iterador comum (não-const)
    it1->second = 100;  // Pode modificar o valor (value)
    
    // it1->first = 999; // Não pode modificar a chave (key)

    // cit1->second = 102; // Não pode modificar value com const_iterator

    return 0;
}
