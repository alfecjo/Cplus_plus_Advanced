#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Função template para imprimir elementos entre iteradores
template <typename T>
ostream &print(const T &start, const T &end)
{
    T tmp = start;
    for (; tmp != end; ++tmp)
    {
        cout << *tmp << " ";
    }
    return cout;
}

class A
{
public:
    int a;

    A(int a) : a(a) {}

    // Sobrecarga do operador << para imprimir o valor de A
    friend ostream &operator<<(ostream &c, const A &o)
    {
        c << o.a;
        return c;
    }
};

// Função para preencher um vetor de ponteiros para A com base em um array de ints
void fill(const int table[], unsigned size, vector<A *> &v)
{
    for (unsigned i = 0; i < size; ++i)
    {
        v.push_back(new A(table[i]));
    }
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<A *> v1;
    fill(tab, 10, v1); // Preenche o vetor de ponteiros para A

    list<A> l1;

    // Insere na lista l1, no início, os objetos apontados pelos ponteiros
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        l1.push_front(**it);
    }

    // Imprime os elementos da lista l1
    print(l1.begin(), l1.end()) << endl;

    // Libera a memória alocada para os objetos em v1 (importante!)
    for (auto ptr : v1)
    {
        delete ptr;
    }

    return 0; // LINE I

    /*

    Na LINE I — que é o fim do main() — os objetos alocados com new não foram deletados no código, certo?
    Então, neste momento:
    Os 10 objetos criados com new A(...) em fill() ainda existem no heap (não deletados).
    Os 10 objetos cópias inseridos em l1 também existem.
    Ou seja, 20 objetos do tipo A existem no programa no momento da LINE I.
    é umaq boa prática deletar os objetos alocados com new antes de sair do programa para evitar vazamentos de memória.
    */
}
