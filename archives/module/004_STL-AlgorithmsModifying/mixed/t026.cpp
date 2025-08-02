#include <vector>
#include <iostream>
#include <functional>   // std::less, std::greater, etc. (não usado diretamente aqui)
#include <algorithm>    // std::generate, std::partition, std::for_each, etc.

using namespace std;

// Functor de saída — Imprime cada valor do container com vírgula
template <class T>
struct Out
{
    ostream &out;

    // Construtor que recebe um ostream (como cout)
    Out(ostream &o) : out(o) {}

    // Operador de chamada que imprime o valor recebido
    void operator()(const T &val)
    {
        out << val << ", ";
    }
};

// Functor que gera uma sequência numérica
struct Sequence
{
    int start;

    // Construtor: inicializa com valor de início
    Sequence(int start) : start(start) {}

    // Operador que retorna o próximo valor da sequência (com módulo 7)
    int operator()()
    {
        return start++ % 7;
    }
};

// Functor que retorna true para números pares (apesar do nome ser 'Odd')
struct Odd
{
    bool operator()(int v)
    {
        return v % 2 == 0;
    }
};

int main()
{
    vector<int> v1(4);  // Cria um vetor com 4 elementos inteiros (inicializados como 0)

    // Preenche o vetor de trás para frente (usando reverse iterators) com a sequência a partir de 10
    // Exemplo do resultado esperado: {13%7=6, 12%7=5, 11%7=4, 10%7=3} → v1 = {6, 5, 4, 3}
    generate(v1.rbegin(), v1.rend(), Sequence(10));  

    // Esta linha está incorreta:
    // partition(v1.begin(), v1.begin(), Odd()); → Fatiamento com intervalo vazio
    // Isso não faz nada, pois início == fim, então não há elementos para particionar.

    // CORREÇÃO:
    partition(v1.begin(), v1.end(), Odd());

    // Aqui estamos particionando os elementos de v1 usando o predicado Odd (pares vão para frente)
    partition(v1.begin(), v1.end(), Odd());  // CORREÇÃO da LINE II

    // Imprime todos os elementos de v1, separados por vírgula
    for_each(v1.begin(), v1.end(), Out<int>(cout));

    return 0;
}
