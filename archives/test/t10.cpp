#include <list>
#include <iostream>

using namespace std;

template <typename T>
ostream& print(T const& start, T const& end) {
    for (T i = start; i != end; ++i)
        cout << *i << " ";
    return cout;
}

int main() {
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list<int> l1(tab, tab + 10);

    // Correção: std::list não suporta operadores aritméticos como +3
    list<int>::iterator it = l1.begin();
    advance(it, 3); // avança para o 4º elemento

    auto it_next = next(it); // iterator para o próximo elemento (5º)

    l1.erase(it, it_next); // remove apenas o 4º elemento

    print(l1.begin(), l1.end()) << endl;

    l1.clear(); // esvazia completamente
    cout << l1.size() << endl;

    return 0;
}
