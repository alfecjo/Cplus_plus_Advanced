#include <iostream>
#include <set>

using namespace std;

//entre com valores inteiros positivos, um ímpar e um par...
int main()
{
    // Declaração de dois conjuntos do tipo set (inteiros, ordenação crescente)
    set<int> s1;
    set<int> s2;

    // Entrada dos limites inferior e superior
    unsigned start_value;
    cin >> start_value;
    unsigned stop_value;
    cin >> stop_value;

    // Primeiro laço: separa os números ímpares para s1 e pares para s2
    for (int i = start_value; i <= stop_value; ++i)
    {
        if (i % 2)
            s1.insert(i);  // ímpares
        else
            s2.insert(i);  // pares
    }

    // Segundo laço: inverte a lógica anterior
    // Adiciona os ímpares em s2 e pares em s1
    // Como set não permite duplicatas, os valores já inseridos não são repetidos
    for (int i = start_value; i <= stop_value; ++i)
    {
        if (i % 2)
            s2.insert(i);
        else
            s1.insert(i);
    }

    // Laço duplo: percorre todos os pares possíveis entre s1 e s2
    // Soma cada elemento de s1 com cada elemento de s2 e imprime
    for (auto x1 : s1)
    {
        for (auto x2 : s2)
        {
            cout << x1 + x2 << " ";
        }
        cout << endl;
    }

    // Iteração reversa: soma elemento a elemento de s1 e s2 em ordem reversa
    // Atenção: esse laço assume que s1 e s2 têm o mesmo número de elementos,
    // caso contrário, it2 poderá ultrapassar o fim do conjunto
    for (set<int>::reverse_iterator it1 = s1.rbegin(), it2 = s2.rbegin();
         it1 != s1.rend(); ++it1, ++it2)
    {
        cout << *it1 + *it2 << " ";
    }
    cout << endl;

    // Mesmo laço que o anterior, mas usando auto (dedução automática do tipo)
    for (auto it1 = s1.rbegin(), it2 = s2.rbegin();
         it1 != s1.rend(); ++it1, ++it2)
    {
        cout << *it1 + *it2 << " ";
    }
    cout << endl;

    return 0;
}
