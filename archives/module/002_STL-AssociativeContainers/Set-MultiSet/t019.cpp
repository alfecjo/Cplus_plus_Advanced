#include <set>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        std::cout << *start << " ";
    }
}

int main()
{
    int t[] = {1, 10, 5, 8, 4, 5, 6, 3, 9, 7, 2, 4};

    // multiset (permite valores repetidos e mantém ordenação)
    multiset<int> s1(t, t + 12);

    cout << "S1: ";
    print(s1.begin(), s1.end()); // imprime os elementos ordenados, incluindo repetições
    cout << endl;

    // Busca intervalo de elementos [4,6]
    cout << "Encontrando intervalo [4,6]:\n";
    multiset<int>::iterator it1 = s1.lower_bound(4); // aponta para o primeiro >= 4
    multiset<int>::iterator it2 = s1.upper_bound(6); // aponta para o primeiro > 6
    print(it1, it2);                                 // imprime todos os 4, 5, 5, 6
    cout << endl
         << endl;

    // Busca o intervalo de todos os elementos iguais a 4
    cout << "Buscando valor único usando equal_range\n";
    pair<multiset<int>::iterator, multiset<int>::iterator> p = s1.equal_range(4);
    print(p.first, p.second); // imprime todos os elementos iguais a 4
    cout << endl;

    return 0;
}
