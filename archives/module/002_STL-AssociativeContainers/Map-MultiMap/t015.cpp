#include <map>
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

template <class T, class U>
void fillMap(multimap<T, T> &m, U start, U end)
{
    for (; start != end; ++start)
    {
        m.insert(pair<T, T>(*start, *start)); // permite múltiplos valores para a mesma chave
    }
}

int main()
{
    // Vetor com valores duplicados (ex.: 9 e 2 aparecem mais de uma vez)
    int t[] = {2, 10, 9, 40, 6, 15, 3, 9, 7, 2};

    // Declaração do multimap
    multimap<int, int> m1;

    // Preenche o multimap com os valores do vetor
    fillMap(m1, t, t + 10);
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    // Remove um único elemento usando iterador da chave 15
    cout << "Removing element from a certain position - iterator of element 15:\n";
    multimap<int, int>::iterator it = m1.find(15);
    if (it != m1.end())
        m1.erase(it); // remove só o primeiro {15, 15} encontrado
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    // Remove todos os elementos com chave 9
    cout << "Removing certain value (9) from the multimap:\n";
    m1.erase(9); // todos os pares com chave 9 são removidos
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    // Remove um intervalo de elementos do multimap
    cout << "Removing range of iterators - starting with element 10 to the end:\n";
    m1.erase(m1.find(10), m1.end()); // remove todos os elementos a partir da chave 10
    print(m1.begin(), m1.end());
    cout << endl
         << endl;

    // Limpa completamente o multimap
    cout << "Removing all the elements from the multi map\n";
    m1.clear(); // esvazia o multimap
    cout << "M1 size: " << m1.size() << endl;

    return 0;
}
