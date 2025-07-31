#include <map>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end)
{
    while (start != end)
    {
        cout << start->first << ":" << start->second << " ";
        start++;
    }
}

template <class T, class U>
void fillMap(map<T, T> &m, U start, U end)
{
    for (; start != end; ++start)
    {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main()
{
    int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};

    map<int, int> m1;
    fillMap(m1, t, t + 10);

    // Mostra o conteúdo do map (ordem crescente das chaves automaticamente)
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    cout << "Removendo elemento por iterador (elemento 15):\n";
    map<int, int>::iterator it = m1.find(15);
    m1.erase(it); // Remove o elemento cuja chave é 15
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    cout << "Removendo chave específica (9):\n";
    m1.erase(9); // Remove a chave 9, se existir
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    cout << "Removendo um intervalo de elementos (de 10 até o fim):\n";
    m1.erase(m1.find(10), m1.end()); // Remove todas as chaves >= 10
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    cout << "Removendo todos os elementos do map:\n";
    m1.clear();
    cout << "Tamanho de m1: " << m1.size() << endl;

    return 0;
}
