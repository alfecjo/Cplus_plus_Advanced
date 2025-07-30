#include <list>
#include <deque>
#include <iostream>

using namespace std;

// Função genérica para imprimir elementos entre iteradores
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

    // Construtor que inicializa 'a'
    A(int a) : a(a) {}

    // Construtor de cópia correto que copia 'a'
    A(const A& other) : a(other.a) {}

    // Opcional: construtor padrão (útil em alguns casos)
    A() : a(0) {}
};

// Sobrecarga do operador << para imprimir objetos A
ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9,10};

    // Criando a lista l1 de objetos A a partir do array de ints tab
    list<A> l1;
    for (int i = 0; i < 10; ++i)
    {
        l1.push_back(A(tab[i]));
    }

    deque<A> d1;

    // Inserindo elementos no início do deque para inverter a ordem
    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        d1.insert(d1.begin(), *it);  // usa *it para acessar o objeto A
    }

    print(d1.begin(), d1.end()) << endl;

    return 0;
}
