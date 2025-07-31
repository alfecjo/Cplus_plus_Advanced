#include <map>
#include <iostream>

using namespace std;

template <class T>
void print(T start, T end)
{
    while (start != end)
    {
        cout << start->first << ":" << start->second << " "; // Exibe chave:valor
        start++;
    }
}

template <class T, class U>
void fillMap(multimap<T, T> &m, U start, U end)
{
    for (; start != end; ++start)
    {
        m.insert(pair<T, T>(*start, *start)); // Insere (valor, valor)
    }
}

int main()
{
    int t[] = {2, 10, 8, 4, 5, 5, 3, 10, 7, 2};

    multimap<int, int> m1;

    fillMap(m1, t, t + 10);

    // Cria um map (chave única) a partir do multimap
    // Ao copiar do multimap para o map, apenas a primeira ocorrência de cada chave é mantida
    map<int, int> m2(m1.begin(), m1.end());

    cout << "m1: ";
    print(m1.begin(), m1.end());
    cout << endl;

    cout << "m2: ";
    print(m2.begin(), m2.end());
    cout << endl;

    cout << "How many '2s' there are?" << endl;
    cout << "Multimap m1: " << m1.count(2) << endl; // Pode retornar > 1
    cout << "Map m2: " << m2.count(2) << endl;      // No máximo 1 ou 0

    // Verifica se a chave 1 existe no multimap
    if (m1.count(1) > 0)
    {
        cout << "There is '1' in the map\n";
    }
    else
    {
        cout << "There is no '1' in the map\n";
    }

    return 0;
}
