#include <map>
#include <iostream>
#include <functional>

using namespace std;

template<class T>
void print(T start, T end) {
    while (start != end) {
        cout << start->first << ":" << start->second << " ";
        start++;
    }
}

// Função para preencher um multimap com chaves e valores iguais
template<class T, class U>
void fillMap(multimap<T, T> & m, U start, U end) {
    for (; start != end; ++start) {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main() {
    int t[] = {2, 10, 9, 40, 6, 15, 3, 9, 7, 2};

    // Cria um multimap e insere os pares do vetor
    multimap<int, int> m1;
    fillMap(m1, t, t + 10);
    print(m1.begin(), m1.end()); cout << endl << endl;

    cout << "Removendo um elemento específico (com chave 15):\n";
    multimap<int, int>::iterator it = m1.find(15);
    m1.erase(it);  // Remove o primeiro par com chave 15
    print(m1.begin(), m1.end()); cout << endl << endl;

    cout << "Removendo todos os pares com chave 9:\n";
    m1.erase(9);  // Remove todos os pares com chave 9
    print(m1.begin(), m1.end()); cout << endl << endl;

    cout << "Removendo um intervalo de elementos (de 10 até o fim):\n";
    m1.erase(m1.find(10), m1.end());
    print(m1.begin(), m1.end()); cout << endl << endl;

    cout << "Limpando completamente o multimap:\n";
    m1.clear();
    cout << "Tamanho de m1: " << m1.size() << endl;

    return 0;
}
