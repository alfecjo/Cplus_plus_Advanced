#include <iostream>
#include <set>

using namespace std;

template <typename T>
void printRange(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
    cout << endl;
}

int main()
{
    // contém elementos únicos
    set<int> uniqueSet = {1, 2, 4, 4, 4, 5, 6}; // Os múltiplos 4 serão reduzidos a apenas um
    cout << "Conteúdo do set (valores únicos): ";
    printRange(uniqueSet.begin(), uniqueSet.end()); // Saída: 1 2 4 5 6

    cout << "Usando equal_range(4) em set:\n";
    auto rangeSet = uniqueSet.equal_range(4);
    cout << "Intervalo encontrado: ";
    printRange(rangeSet.first, rangeSet.second); // Saída: 4

    // permite valores repetidos
    multiset<int> multiSet = {1, 2, 4, 4, 4, 5, 6}; // Todos os 4 serão mantidos
    cout << "\nConteúdo do multiset (valores duplicados permitidos): ";
    printRange(multiSet.begin(), multiSet.end()); // Saída: 1 2 4 4 4 5 6

    cout << "Usando equal_range(4) em multiset:\n";
    auto rangeMulti = multiSet.equal_range(4);
    cout << "Intervalo encontrado: ";
    printRange(rangeMulti.first, rangeMulti.second); // Saída: 4 4 4

    return 0;
}
