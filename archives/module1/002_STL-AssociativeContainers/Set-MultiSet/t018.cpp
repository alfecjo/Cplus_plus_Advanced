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
    int t[] = {1, 10, 8, 4, 5, 6, 3, 9, 7, 2};

    // set (conjunto ordenado e sem repetições) com os elementos do array
    set<int> s1(t, t + 10);

    cout << "S1: ";
    print(s1.begin(), s1.end()); // imprime todos os elementos do set em ordem crescente
    cout << endl;

    // Busca intervalo de elementos [4,6]
    cout << "Encontrando intervalo [4,6]:\n";
    set<int>::iterator it1 = s1.lower_bound(4); // aponta para o primeiro elemento >= 4
    set<int>::iterator it2 = s1.upper_bound(6); // aponta para o primeiro elemento > 6
    print(it1, it2);                            // imprime os elementos entre 4 e 6 (inclusive 4, exclusivo 7)
    cout << endl
         << endl;

    // busca o intervalo exato de um único valor com equal_range
    cout << "Buscando valor único usando equal_range\n";
    pair<set<int>::iterator, set<int>::iterator> p = s1.equal_range(4);
    // Imprime os elementos iguais a 4 (em set é no máximo 1)
    print(p.first, p.second);
    cout << endl;

    return 0;
}
