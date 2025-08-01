#include <map>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        ++start;
    }
}

template <class T, class U>
void fillMap(multimap<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert({*start, *start});
    }
}

int main() {
    int t[] = {2, 10, 8, 4, 5, 5, 3, 10, 7, 2};  // Vários valores duplicados
    multimap<int, int> m1;
    fillMap(m1, t, t + 10);

    multimap<int, int, greater<int>> m2(m1.begin(), m1.end());

    cout << "Standard iterator (key only):\n";
    multimap<int, int>::iterator it1 = m1.begin();
    for (; it1 != m1.end(); ++it1) {
        cout << it1->first << " ";
    }
    cout << endl;

    it1 = m2.begin();
    for (; it1 != m2.end(); ++it1) {
        cout << it1->first << " ";
    }
    cout << "\n\n";

    cout << "Reverse iterators:\n";
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

    multimap<int, int>::const_iterator cit1 = m1.begin(); // iterador constante

    it1 = m1.begin();
    it1->second = 100;  // Pode modificar o valor
    
    // it1->first = 123; // Não pode modificar a chave

    // cit1->second = 200; // Const iterator: não pode modificar value

    return 0;
}
