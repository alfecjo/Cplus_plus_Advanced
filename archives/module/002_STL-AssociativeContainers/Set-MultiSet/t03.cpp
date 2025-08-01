#include <set>
#include <iostream>
#include <functional> // para usar comparadores como greater<int>

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        std::cout << *start << " ";
    }
}

int main()
{
    int t[] = {1, 10, 8, 4, 6, 5, 3, 9, 7, 2};

    // Criação padrão (ordem crescente)
    set<int> s1(t, t + 10);

    // criação de um segundo set com ordem decrescente
    // Usamos o intervalo [s1.begin(), s1.end()] como origem dos dados
    set<int, greater<int>> s2(s1.begin(), s1.end());

    cout << "Standard iterator:\n";

    // Iterador padrão: percorre do início ao fim (ordem definida pelo set)
    set<int>::iterator it1 = s1.begin();
    for (; it1 != s1.end(); ++it1)
    {
        cout << *it1 << " ";
    }
    cout << endl;

    // Iteração padrão no set com ordem decrescente
    cout << "Reverse iterators:\n";
    it1 = s2.begin();
    for (; it1 != s2.end(); ++it1)
    {
        cout << *it1 << " ";
    }
    cout << endl;

    // Iteradores reversos: percorrem o set de trás para frente
    cout << "Reverse iterators - set s1:\n";
    print(s1.rbegin(), s1.rend()); // reverso do s1 (ordem crescente)
    cout << " :s1"<<endl;

    cout << "Reverse iterators - set s2:\n";
    print(s2.rbegin(), s2.rend()); // reverso do s2 (ordem decrescente)
    cout << " :s2"<<endl;

    cout << "Const iterators:\n";

    // Iteradores constantes: garantem que os elementos não serão modificados
    print(s1.cbegin(), s1.cend());
    cout << " :s1"<<endl;
    print(s2.cbegin(), s2.cend());
    cout << " :s2"<<endl;

    cout << "Const iterators - reverse:\n";

    // Iteradores constantes reversos
    print(s1.crbegin(), s1.crend());
    cout << " :s1"<<endl;
    print(s2.crbegin(), s2.crend());
    cout << " :s2"<<endl;

    /***********************************************************/
    // Observação importante:
    // Em std::set (e também em std::multiset), todos os iteradores são "const",
    // ou seja, não é possível modificar os valores através dos i
}