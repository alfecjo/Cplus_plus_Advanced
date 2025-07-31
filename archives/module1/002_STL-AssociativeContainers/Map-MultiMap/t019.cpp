#include <map>
#include <iostream>

using namespace std;

template<class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        start++;
    }
    cout << endl;
}

// Função para preencher o multimap com pares {valor, valor}
template<class T, class U>
void fillMap(multimap<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main() {
    int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};
    multimap<int, int> m1;
    fillMap(m1, t, t + 10);

    print(m1.begin(), m1.end());

    cout << "\nPrimeira versão do insert: inserindo chave duplicada (10)\n";
    m1.insert(pair<int, int>(10, 10));  // Permitido
    print(m1.begin(), m1.end());

    cout << "\nInserindo chave e valor novos (13,13):\n";
    m1.insert(pair<int, int>(13, 13));
    print(m1.begin(), m1.end());

    cout << "\nSegunda versão do insert (com hint):\n";
    auto it1 = m1.insert(m1.find(10), pair<int, int>(11, 11));
    auto it2 = m1.insert(m1.find(11), pair<int, int>(11, 11));
    if (it1 == it2) {
        cout << "Inserção não foi bem-sucedida\n";
    } else {
        cout << "Inserção foi bem-sucedida\n";
    }
    print(m1.begin(), m1.end());

    cout << "\nTerceira versão do insert (range):\n";
    int t2[] = {4, 10, 15, 21, 0};
    multimap<int, int> m2;
    fillMap(m2, t2, t2 + 5);
    m1.insert(m2.begin(), m2.end());  // Permite tudo
    print(m1.begin(), m1.end());

    return 0;
}
