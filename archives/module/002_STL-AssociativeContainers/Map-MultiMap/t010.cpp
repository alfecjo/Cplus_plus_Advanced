#include <map>
#include <iostream>
#include <functional>

using namespace std;

// idem print genérico de antes
template <class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        start++;
    }
}

//  usando multimap (permite chaves repetidas)
template <class T, class U>
void fillMap(multimap<T, T> &m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main() {
    int t[] = { 2, 10, 8, 4, 5, 5, 3, 10, 7, 2 };

    multimap<int, int> m1;
    fillMap(m1, t, t + 10);  // Aqui teremos chaves duplicadas

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
    cout << endl;

    cout << "Reverse iterators:\n";
    print(m1.rbegin(), m1.rend());
    cout << endl;
    print(m2.rbegin(), m2.rend());
    cout << endl;

    cout << "Const iterators: \n";
    print(m1.cbegin(), m1.cend());
    cout << endl;
    print(m2.cbegin(), m2.cend());
    cout << endl;

    cout << "Const iterators - reverse: \n";
    print(m1.crbegin(), m1.crend());
    cout << endl;
    print(m2.crbegin(), m2.crend());
    cout << endl;

    // Modificação permitida somente com iterator não-constante
    multimap<int, int>::const_iterator cit1 = m1.begin();
    it1 = m1.begin();
    it1->second = 100;  // OK
    
    // it1->first = 101; // ERRO - a chave (key) é imutável, tanto no map quanto no multimap wereversed...

    // cit1->second = 102; // ERRO

    // --- USO DE equal_range() ---
    cout << "\nBuscando chave 5 com equal_range:\n";
    auto range = m1.equal_range(5);

    if (range.first == range.second)
        cout << "Chave 5 não encontrada\n";
    else {
        cout << "Chave 5 encontrada: ";
        print(range.first, range.second);
        cout << endl;
    }

    // extra: chave 10 (também aparece 2 vezes)
    cout << "Chave 10 encontrada: ";
    print(m1.equal_range(10).first, m1.equal_range(10).second);
    cout << endl;

    return 0;
}
