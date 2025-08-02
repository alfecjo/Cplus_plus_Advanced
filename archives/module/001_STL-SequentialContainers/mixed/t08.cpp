#include <list>
#include <deque>
#include <iostream>

using namespace std;

// Função template para imprimir elementos de um container entre [start, end)
template <typename T>
ostream& print(const T& start, const T& end)
{
    T tmp = start;
    for (; tmp != end; ++tmp)  // percorre o container
    {
        cout << *tmp << " ";   // imprime o valor apontado pelo iterador
    }
    return cout;
}

class A
{
public:
    int a;

    // Construtor que inicializa 'a' com valor dado
    A(int a) : a(a) {}

    // Construtor de cópia que copia o membro 'a' do objeto passado
    A(const A& other) : a(other.a) {}
};

// Sobrecarga do operador de saída para imprimir objetos do tipo A
ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = { 1,2,3,4,5,6,7,8,9,10 };
    
    // Cria uma lista de objetos A, inserindo elementos de tab manualmente
    list<A> l1;
    for (int i = 0; i < 10; ++i)
        l1.push_back(A(tab[i]));

    deque<A> d1;

    // Itera sobre a lista l1
    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        // Insere o elemento atual *it no início do deque d1
        // Isso reverte a ordem dos elementos
        d1.insert(d1.begin(), *it);
    }

    // Imprime os elementos do deque
    print(d1.begin(), d1.end()) << endl;

    return 0;
}
