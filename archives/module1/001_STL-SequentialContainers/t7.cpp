#include <list>
#include <deque>
#include <iostream>

using namespace std;

template <typename T>
ostream& print(const T& start, const T& end)
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

    // Construtor
    A(int a) : a(a) {}

    // Construtor de cópia correto (copia o valor de 'a')
    // errado: A(const A& a)

    A(const A& other) : a(other.a) {}

    // Opcional: más já visando construtor padrão para permitir listas vazias ou declarações sem parâmetros...
    A() : a(0) {}
};

// Operador << para imprimir objetos A
ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9,10};

    // Cria a lista l1 de objetos A usando um loop para criar cada A a partir de tab
    list<A> l1;
    for(int i = 0; i < 10; ++i)
    {
        l1.push_back(A(tab[i]));
    }

    deque<A> d1;

    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        d1.insert(d1.begin(), *it);  // insere no início do deque (inverte ordem)
    }

    print(d1.begin(), d1.end()) << endl;

    return 0;
}
