#include <set>
#include <iostream>
#include <functional>

using namespace std;

// para imprimir qualquer intervalo (como iteradores)
template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
}

int main()
{
    int t[] = {1, 10, 8, 4, 5, 6, 3, 9, 7, 2};

    // Cria um set (conjunto) a partir do array.
    // O set automaticamente remove duplicatas (se houver) e ordena os elementos.
    set<int> s1(t, t + 10);

    cout << "S1: ";
    print(s1.begin(), s1.end()); // imprime o conjunto ordenado
    cout << endl;

    // Busca elementos no intervalo fechado [4,6] (inclusive 4, exclusivo 6+)
    cout << "Encontrando intervalo [4,6]:\n";
    set<int>::iterator it1 = s1.lower_bound(4); // primeiro >= 4
    set<int>::iterator it2 = s1.upper_bound(6); // primeiro >= 6
    print(it1, it2);                            // imprime os elementos entre 4 e 6
    cout << endl
         << endl;

    // equal_range retorna um par com o mesmo resultado de lower_bound e upper_bound
    cout << "Buscando valor específico com equal_range\n";
    pair<set<int>::iterator, set<int>::iterator> p = s1.equal_range(4);
    print(p.first, p.second); // imprime o elemento igual a 4 ( 0 elemento se não existir ou 1 no caso do set - unicidade)
    cout << endl;

    // equal_range retorna um par com o mesmo resultado de lower_bound e upper_bound
    cout << "Buscando valor específico com equal_range, más não encontra nada\n";
    cout << endl;
    pair<set<int>::iterator, set<int>::iterator> p1 = s1.equal_range(14);
    if (p1.first == p1.second)
    {
        cout << "Não há elemento igual a 14 no set\n";
    }
    else
    {
        cout << "Elemento igual a 14 encontrado: ";
        // imprime o elemento igual a 14 
        print(p1.first, p1.second); // nunca será!!!
        cout << endl;
    }

    return 0;
}
