#include <map>
#include <iostream>

using namespace std;

// função genérica para imprimir os pares (chave:valor) entre dois iteradores
template <class T>
void print(T start, T end)
{
    while (start != end)
    {
        cout << start->first << ":" << start->second << " ";
        ++start;
    }
}

// função que preenche um multimap com os elementos de um array
// Cada valor é inserido como par (valor, valor)
template <class T, class U>
void fillMap(multimap<T, T> &m, U start, U end)
{
    for (; start != end; ++start)
    {
        m.insert(pair<T, T>(*start, *start));
    }
}

int main()
{
    int t[] = {2, 10, 8, 4, 5, 5, 3, 10, 7, 2};

    multimap<int, int> m1;

    // Preenche o multimap com os valores do array
    fillMap(m1, t, t + 10);

    // Cria um map a partir do multimap (isso eliminará duplicatas de chave)
    map<int, int> m2(m1.begin(), m1.end());

    cout << "Multimap:\n";
    cout << "Size: " << m1.size() << " Max size: " << m1.max_size() << endl;
    print(m1.begin(), m1.end()); // Mostra todos os pares inseridos (incluindo chaves repetidas)
    cout << endl;

    cout << "Map:\n";
    cout << "Size: " << m2.size() << " Max size: " << m2.max_size() << endl;
    print(m2.begin(), m2.end()); // Mostra apenas uma entrada por chave
    cout << endl;

    // Demonstração do uso de equal_range no multimap
    cout << "\nExemplo com equal_range no multimap (valor 10): ";
    auto range = m1.equal_range(10);  // Retorna o intervalo de todos os pares com chave 10
    print(range.first, range.second); // Imprime todos os pares com chave igual a 10
    cout << endl;

    // Apaga todos os elementos do multimap
    cout << "Deleting all elements from the multimap\n";
    m1.clear();

    // Verifica se o multimap está vazio após o clear()
    if (m1.empty())
    {
        cout << "Multimap is empty!\n";
    }
    else
    {
        print(m1.begin(), m1.end());
        cout << endl;
    }

    // verifica se o map está vazio (não foi apagado)
    if (m2.empty())
    {
        cout << "Map is empty!\n";
    }
    else
    {
        print(m2.begin(), m2.end());
        cout << endl;
    }

    return 0;
}
