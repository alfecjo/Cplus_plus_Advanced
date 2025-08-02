#include <vector>
#include <iostream>
#include <functional> // Para std::less
#include <algorithm>  // Para generate, reverse_copy, sort, for_each

using namespace std;

// Functor de saída: imprime cada elemento com vírgula
template <class T>
struct Out
{
    ostream &out; // Referência à saída (ex: cout)

    // Construtor recebe um ostream (ex: cout)
    Out(ostream &o) : out(o) {}

    // Função operador para imprimir cada valor
    void operator()(const T &val)
    {
        out << val << ", ";
    }
};

// Functor gerador de sequência
// Produz valores de start % 7, e incrementa start a cada chamada
struct Sequence
{
    int start;

    Sequence(int start) : start(start) {}

    int operator()()
    {
        return start++ % 7;
    }
};

int main()
{
    vector<int> v1(4); // Vetor com 4 posições
    vector<int> v2(4); // Outro vetor com 4 posições

    // Preenche v1 com valores de Sequence(10)
    // start = 10 → 10%7 = 3, 11%7 = 4, 12%7 = 5, 13%7 = 6
    // Resultado: v1 = [3, 4, 5, 6]
    generate(v1.begin(), v1.end(), Sequence(10));

    // reverse_copy copia os elementos de v1 para v2 na ordem reversa
    // Porém usando v2.rbegin(), acaba restaurando a ordem original
    // v1:       [3, 4, 5, 6]
    // reverse:  [6, 5, 4, 3]
    // v2.rbegin: coloca [3, 4, 5, 6] novamente
    reverse_copy(v1.begin(), v1.end(), v2.rbegin());

    // Ordena v2 usando comparador padrão (menor que)
    // Nesse caso, como já está ordenado, nada muda
    sort(v2.begin(), v2.end(), less<int>());

    // Imprime v2: [3, 4, 5, 6]
    for_each(v2.begin(), v2.end(), Out<int>(cout));
    cout << endl;

    return 0;
}
