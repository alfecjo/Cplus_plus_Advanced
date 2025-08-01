#include <iostream>
#include <vector>
#include <algorithm> //  STL como for_each e adjacent_find
#include <string>
#include <iterator>
#include <list>

using namespace std;

template <class T>
void print(const T &value)
{
    cout << value << " ";
}

// Functor (classe com operador ()) que compara dois caracteres ignorando se são maiúsculos ou minúsculos
struct Compare
{
    bool operator()(const char &f, const char &s)
    {
        return tolower(f) == tolower(s); // compara ignorando letras maiúsculas e minúsculas
    }
};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4};

 
    vector<int> v1(t, t + 18);

    for_each(v1.begin(), v1.end(), print<int>);
    cout << endl
         << endl;

    // Buscando o primeiro par de elementos adjacentes iguais no vetor
    cout << "Searching for a pair of elements:\n";
    vector<int>::iterator found = adjacent_find(v1.begin(), v1.end());

    if (found != v1.end())
    {
        // Se encontrou, exibe o valor e a posição
        cout << "Pair of elements " << *found << " has been found at position: "
             << distance(v1.begin(), found) << endl;
    }
    else
    {
        cout << "Pair of the same elements could not be found\n";
    }
    cout << endl;

    // Array de caracteres
    char ts[] = {'a', 'b', 'c', 'a', 'A', 'b', 'D', 'A', 'b', 'C', 'a', 'f'};

    // Criação de uma lista com os caracteres
    list<int> l1(ts, ts + 12); // OBS: mais correto seria list<char>, mas para o exemplo serve...

    // Busca por pares adjacentes na lista com comparação personalizada (ignora maiúsculas/minúsculas)
    list<int>::iterator founds = adjacent_find(l1.begin(), l1.end(), Compare());

    if (founds != l1.end())
    {
        // Exibe se encontrou um par de letras iguais (ignorando case) 'a', 'A',
        cout << "Pair of elements " << *founds << " has been found at position: "
             << distance(l1.begin(), founds) << endl;
    }
    else
    {
        cout << "Pair of the same elements could not be found\n";
    }

    return 0;
}
