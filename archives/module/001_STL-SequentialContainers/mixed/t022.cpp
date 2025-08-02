#include <vector>
#include <iostream>

using namespace std;

// Função genérica para imprimir um intervalo
template <typename T>
ostream& print(const T& start, const T& end)
{
    T tmp = start;
    for (; tmp != end; ++tmp)
    {
        cout << *tmp << " ";    // LINE II
    }
    return cout;
}

// Classe A com construtor e atributo público
class A
{
public:
    int a;

    A(int a) : a(a) {}  // Construtor
};

// Sobrecarga do operador << para imprimir objetos da classe A
ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Criando um vetor de A, construindo cada objeto com base em 'tab'
    vector<A> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(A(tab[i]));   // Converte cada int em A

    v1.insert(v1.end(), A(0));     // Inserindo A(0) ao final

    print(v1.begin(), v1.end()) << endl;  // Imprimindo os valores

    return 0;
}
