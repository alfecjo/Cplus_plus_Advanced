#include <set>
#include <iostream>

using namespace std;

// template que imprime os elementos entre dois iteradores
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
    int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};

    // cria um set ordenado em ordem decrescente (usando greater<int>)
    set<int, greater<int>> s1(t, t + 10);

    // Imprime o conteúdo inicial do set
    print(s1.begin(), s1.end());
    cout << " -s1" << endl;

    // Remoção de um elemento usando um iterador
    cout << "Removendo o elemento 15 (usando iterator):\n";
    auto it = s1.find(15);
    if (it != s1.end())
        s1.erase(it);
    print(s1.begin(), s1.end());
    cout << " -s1" << endl;

    // Remoção de um valor específico
    cout << "Removendo o valor 9 diretamente:\n";
    s1.erase(9);
    print(s1.begin(), s1.end());
    cout << endl;

    // remoção de um intervalo de elementos
    cout << "Removendo elementos a partir do valor 6 até o fim:\n";
    auto it_range = s1.find(6);
    if (it_range != s1.end())
        s1.erase(it_range, s1.end());
    print(s1.begin(), s1.end());
    cout << " -s1" << endl;

    // Remoção de todos os elementos
    cout << "Removendo todos os elementos do set:\n";
    s1.clear();
    cout << "Tamanho final de s1: " << s1.size() << endl;

    return 0;
}
