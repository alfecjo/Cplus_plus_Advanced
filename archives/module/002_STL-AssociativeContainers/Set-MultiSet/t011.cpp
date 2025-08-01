#include <set>
#include <iostream>
#include <functional> // para std::greater

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
    cout << endl;
}

int main()
{
    int t[] = {9, 10, 8, 15, 6, 15, 3, 9, 7, 2};

    // Criação de um multiset com ordenação decrescente (maior para menor)
    multiset<int, greater<int>> s1(t, t + 10);

    // Impressão  multiset
    print(s1.begin(), s1.end());
    cout << endl;

    // Remoção de um elemento a partir de um iterador (primeira ocorrência de 15)
    // aqui, o iterador aponta para a primeira ocorrência do valor 15
    cout << "Positioning and removing value (15) at a specific position (iterator):\n";
    multiset<int>::iterator it = s1.find(15);
    s1.erase(it);
    print(s1.begin(), s1.end());
    cout << endl;

    // já aqui, a remoção elimina todas as ocorrências do valor 9...
    // remoção de todas as ocorrências de um valor específico (9)
    cout << "Removing specific value (9) from the multiset:\n";
    s1.erase(9);
    print(s1.begin(), s1.end());
    cout << endl;

    // Remoção de um intervalo de elementos a partir do valor 6 até o final
    cout << "Removing a range of elements:\n";
    s1.erase(s1.find(6), s1.end());
    print(s1.begin(), s1.end());
    cout << endl;

    // Remoção de todos os elementos do multiset
    cout << "Removing all elements from the multiset\n";
    s1.clear();
    cout << "Size of s1: " << s1.size() << endl;
    print(s1.begin(), s1.end());
    cout << endl;
    return 0;
}
