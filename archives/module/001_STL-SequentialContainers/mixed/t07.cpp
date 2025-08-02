#include <list>
#include <deque>
#include <iostream>

using namespace std;

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

    // Construtor de cópia padrão (pode omitir, mas para clareza)
    A(const A &other) : a(other.a) {}
};

// Operador de saída para imprimir A
ostream &operator<<(ostream &c, const A &o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    list<A> l1;
    // Construir a lista manualmente porque não existe construtor list<A>(int*, int*) direto
    for (int i = 0; i < 10; ++i)
    {
        l1.push_back(A(tab[i]));
    }

    deque<A> d1;
    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        d1.insert(d1.begin(), *it); // insere no início de d1, invertendo a ordem
    }

    print(d1.begin(), d1.end()) << endl;

    return 0;
}
