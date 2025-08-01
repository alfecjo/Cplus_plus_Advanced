#include <iostream>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

void print(const int& value)
{
    cout << value << " ";
}

// Functor (objeto função) que imprime um valor - também precisa ser const para uso com set
struct Print
{
    void operator()(const int& value) const
    {
        cout << value << " ";
    }
};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Cria uma lista (container sequencial) com os valores do array
    list<int> l1(t, t + 10);

    cout << "Print all elements of the list - using function\n";
    // Usa o algoritmo for_each para percorrer todos os elementos da lista
    for_each(l1.begin(), l1.end(), print);
    cout << endl << endl;

    cout << "Print all elements of the list - using function object\n";
    // Usa o algoritmo for_each com um functor (objeto função)
    for_each(l1.begin(), l1.end(), Print());
    cout << endl << endl;

    // Agora o mesmo com um container associativo: set
    // Lembrando que o set não permite modificar seus elementos durante a iteração
    set<int> s1(t, t + 10);

    // Usa o algoritmo for_each para percorrer todos os elementos do set
    cout << "Print all elements of the set - using function\n";
    for_each(s1.begin(), s1.end(), print);
    cout << endl << endl;

    // Usa o algoritmo for_each com um functor (objeto função) para o set
    cout << "Print all elements of the set - using function object\n";
    for_each(s1.begin(), s1.end(), Print());
    cout << endl << endl;

    return 0;
}
