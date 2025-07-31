#include <map>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end) {
    while (start != end) {
        std::cout << start->first << ":" << start->second << " ";
        ++start;
    }
}

template <class T, class U>
void fillMap(map<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main() {
    int t[] = { 1, 10, 8, 4, 6, 5, 3, 9, 7, 2 };
    map<int, int> m1;
    fillMap(m1, t, t + 10);

    // Testando equal_range
    cout << "Usando equal_range no map:\n";
    auto range = m1.equal_range(5);
    if (range.first == range.second)
        cout << "Chave 5 não encontrada\n";
    else {
        cout << "Chave 5 encontrada:\n";
        print(range.first, range.second);
        cout << endl;
    }

    // Chave inexistente
    auto missing = m1.equal_range(20);
    if (missing.first == missing.second)
        cout << "Chave 20 não encontrada\n";

    return 0;
}
