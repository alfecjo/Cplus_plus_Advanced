#include <map>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end)
{
    while (start != end)
    {
        std::cout << start->first << ":" << start->second << " ";
        start++;
    }
}

// Função que preenche um map com elementos do vetor, usando o valor como chave e como valor
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
    int t[] = {1, 10, 8, 4, 5, 6, 3, 9, 7, 2};
    map<int, int> m1;

    // Preenche o map com os elementos do vetor t
    fillMap(m1, t, t + 10);

    cout << "m1: ";
    print(m1.begin(), m1.end()); // Imprime todos os elementos do map
    cout << endl;

    // Busca intervalo de chaves entre 4 e 6 (inclusive 4, exclusivo 6)
    cout << "Buscando intervalo de chaves [4,6):\n";
    map<int, int>::iterator it1 = m1.lower_bound(4); // aponta para a primeira chave >= 4
    map<int, int>::iterator it2 = m1.upper_bound(6); // aponta para a primeira chave > 6
    print(it1, it2);
    cout << endl
         << endl;

    // Busca o intervalo de elementos com a chave 4 (no map só existe no máximo um)
    cout << "Buscando intervalo de chave única com equal_range(4):\n";
    pair<map<int, int>::iterator, map<int, int>::iterator> p = m1.equal_range(4);
    print(p.first, p.second);
    cout << endl;

    return 0;
}
