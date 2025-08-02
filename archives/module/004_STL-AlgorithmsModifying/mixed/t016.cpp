#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int v)
{
    cout << v << ", ";
}

// Struct para gerar uma sequência crescente começando de um valor inicial
struct Sequence
{
    int start; // valor atual da sequência

    // Construtor que inicializa o valor inicial
    Sequence(int start) : start(start)
    {
    }

    // Operador função que retorna o valor atual e incrementa para o próximo
    int operator()()
    {
        return start++; // retorna o valor atual e incrementa depois
    }
};

int main()
{
    vector<int> v1(7); // cria vetor com 7 posições

    // Preenche o vetor chamando Sequence(1) 7 vezes,
    // gerando valores de 1 a 7 sequencialmente
    generate_n(v1.begin(), 7, Sequence(1)); 

    // Imprime os valores do vetor
    for_each(v1.begin(), v1.end(), print);

    return 0;
}
