#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Template para imprimir elementos entre iteradores
template <typename T>
ostream& print(const T& start, const T& end)
{
    T tmp = start;
    for (; tmp != end; ++tmp)
    {
        // como v1 é vector<A*>, desreferenciar duas vezes para imprimir o objeto A
        cout << **tmp << " ";  
    }
    return cout;
}

class A
{
public:
    int a;
public:
    A(int a) : a(a) {}
};

// Sobrecarga correta do operador <<
ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

// Preenche vector<A*> com objetos criados dinamicamente
void fill(const int table[], unsigned size, vector<A*>& v)
{
    for (unsigned i = 0; i < size; ++i)
    {
        v.push_back(new A(table[i]));  // LINE I
    }
}

// Função para deletar objetos apontados pelos ponteiros
void del(A* p)
{
    delete p;
}

int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    vector<A*> v1;
    fill(tab, 10, v1);

    // Imprime o vetor na ordem reversa
    print(v1.rbegin(), v1.rend()) << endl;  // LINE II

    // Deleta todos os objetos criados dinamicamente para evitar vazamento de memória
    for_each(v1.begin(), v1.end(), del);

    return 0;
}
