#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    // cria um vetor a partir do array
    vector<int> v(mynumbers, mynumbers + 7);

    // cria um multimap (permite chaves repetidas)
    multimap<int, string> m;

    // percorre o vetor e insere no multimap
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        stringstream s;
        s << *i << *i << *i; // Concatena o valor 3 vezes como string

        m.insert(pair<int, string>(*i, s.str())); // insere no multimap
    }

    // cria um par de iteradores para o intervalo de chaves iguais a 4
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range;
    range = m.equal_range(4);

    // Percorre o intervalo de elementos com chave = 4
    for (multimap<int, string>::iterator i = range.first; i != range.second; i++)
    {
        cout << i->first << ", "; // Imprime a chave (4)
    }

    return 0;
}
