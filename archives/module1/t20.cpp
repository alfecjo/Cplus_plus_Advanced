#include <vector>
#include <iostream>

using namespace std;

// Função template para imprimir elementos entre dois iteradores
template <typename T>
ostream& print(const T& start, const T& end)
{
    T tmp = start;
    for (; tmp != end; ++tmp)
    {
        cout << *tmp << " ";  // Imprime cada elemento
    }
    return cout;
}

// Classe A com um único atributo inteiro
class A
{
public:
    int a;
public:
    A(int a) : a(a) {}  // Construtor que inicializa 'a'
};

// Sobrecarga correta do operador << para imprimir objetos do tipo A
ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    
    // Cria vetor de objetos A preenchendo manualmente com valores do array 'tab'
    vector<A> v1;
    for (int i = 0; i < 10; ++i)
    {
        v1.push_back(A(tab[i]));
    }

    // Insere o objeto A com valor 0 no final do vetor
    v1.insert(v1.end(), A(0));

    // Imprime todos os elementos do vetor v1
    print(v1.begin(), v1.end()) << endl;

    return 0;
}
