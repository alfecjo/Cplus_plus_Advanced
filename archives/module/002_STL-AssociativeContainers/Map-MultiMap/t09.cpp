#include <map>
#include <iostream>
#include <functional>

using namespace std;

// função genérica para imprimir pares (chave:valor)
template <class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        start++;
    }
}

// Função para preencher o map com os valores do vetor
template <class T, class U>
void fillMap(map<T, T> &m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main() {
    int t[] = { 1, 10, 8, 4, 6, 5, 3, 9, 7, 2 };

    map<int, int> m1;
    fillMap(m1, t, t + 10);  // preenche m1 com pares (valor, valor)

    // Criação de map com ordem reversa usando greater<int>
    map<int, int, greater<int>> m2(m1.begin(), m1.end());

    // Iterador padrão (ordem crescente)
    cout << "Standard iterator (key only):\n";
    map<int, int>::iterator it1 = m1.begin();
    for (; it1 != m1.end(); ++it1) {
        cout << it1->first << " ";
    }
    cout << endl;

    // Iterador padrão em ordem reversa (com greater)
    it1 = m2.begin();
    for (; it1 != m2.end(); ++it1) {
        cout << it1->first << " ";
    }
    cout << endl;

    // iteradores reversos (acessam do fim ao início)
    cout << "Reverse iterators:\n";
    print(m1.rbegin(), m1.rend());
    cout << endl;
    print(m2.rbegin(), m2.rend());
    cout << endl;

    // Iteradores constantes (não permitem modificação)
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

    // Modificação com iteradores:
    map<int, int>::const_iterator cit1 = m1.begin();  // Const: não permite modificação
    it1 = m1.begin();                                 // Não const: pode alterar o valor
    it1->second = 100;                                // OK: alterando o valor
    // it1->first = 101;                              // ERRO: chave não pode ser alterada
    // cit1->second = 102;                            // ERRO: const_iterator não permite

    // --- USO DE equal_range() ---
    cout << "\nBuscando chave 5 com equal_range:\n";
    pair<map<int, int>::iterator, map<int, int>::iterator> range = m1.equal_range(5);

    if (range.first == range.second)
        cout << "Chave 5 não encontrada\n";
    else {
        cout << "Chave 5 encontrada: ";
        print(range.first, range.second);
        cout << endl;
    }

    return 0;
}
