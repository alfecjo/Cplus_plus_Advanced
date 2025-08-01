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

// Função que preenche o map com pares {valor, valor}
template<class T, class U>
void fillMap(map<T, T>& m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start));
    }
}

// Tipo para armazenar o retorno do insert (iterator e bool)
typedef pair<map<int, int>::iterator, bool> Pair;

// Verifica se a inserção teve sucesso
void check(const Pair& result) {
    if (result.second == true) {
        cout << "Uma nova chave (" << result.first->first << ") foi inserida\n";
    } else {
        cout << "Falha na inserção, chave " << result.first->first << " já existe\n";
    }
}

int main() {
    int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};
    map<int, int> m1;
    fillMap(m1, t, t + 10);

    print(m1.begin(), m1.end());

    cout << "\nPrimeira versão do insert:\n";
    cout << "Tentando inserir uma chave duplicada (10):\n";
    Pair p = m1.insert(pair<int, int>(10, 10));  // Já existe
    check(p);
    print(m1.begin(), m1.end());

    cout << "\nInserindo chave nova (4) com valor já existente (10):\n";
    p = m1.insert(pair<int, int>(4, 10));  // chave nova, valor repetido permitido
    check(p);
    print(m1.begin(), m1.end());

    cout << "\nInserindo chave e valor novos (13,13):\n";
    p = m1.insert(pair<int, int>(13, 13));
    check(p);
    print(m1.begin(), m1.end());

    cout << "\nSegunda versão do insert (com hint):\n";
    auto it1 = m1.insert(m1.find(10), pair<int, int>(11, 11));  // Inserido
    auto it2 = m1.insert(m1.find(11), pair<int, int>(11, 11));  // Já existe
    if (it1 == it2) {
        cout << "Segunda inserção (11,11) não teve sucesso\n";
    }
    print(m1.begin(), m1.end());

    cout << "\nTerceira versão do insert (range de outro map):\n";
    int t2[] = {4, 10, 15, 21, 0};
    map<int, int> m2;
    fillMap(m2, t2, t2 + 5);
    m1.insert(m2.begin(), m2.end());  // Insere os que não estão no m1
    print(m1.begin(), m1.end());

    return 0;
}
