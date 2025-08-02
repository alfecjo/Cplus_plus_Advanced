#include <iostream>
#include <algorithm>  // Para std::transform e std::for_each
#include <vector>     // Container sequencial dinâmico
#include <set>        // Container ordenado com elementos únicos
#include <deque>      // Container com inserção eficiente nas extremidades

using namespace std;

// Função que imprime um inteiro, usada com for_each
void printer(int i) {
    cout << i << ", ";
}

// Função binária que soma dois inteiros
int add(int a, int b) {
    return a + b;
}

int main() {
    // Um array de inteiros
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    // Cria um vector (sequência preservada) a partir do array
    vector<int> v1(mynumbers, mynumbers + 7);  // [3, 9, 0, 2, 1, 4, 5]

    // Cria um set (ordem crescente, elementos únicos)
    set<int> s1(mynumbers, mynumbers + 7);     // {0, 1, 2, 3, 4, 5, 9}

    // Cria um deque vazio (poderia ser vector também)
    deque<int> d1;

    // Usa transform para somar elementos de s1 e v1
    // ⚠️ ATENÇÃO: como `d1` está vazio, é necessário usar inserter para preencher
    transform(
        s1.begin(),         // Início da primeira sequência (set ordenado)
        s1.end(),           // Fim da primeira sequência
        v1.begin(),         // Início da segunda sequência (vector)
        back_inserter(d1),  // Inserção dos resultados no final de `d1`
        add                 // Função binária que soma os elementos
    );

    // Imprime os elementos de `d1`
    for_each(d1.begin(), d1.end(), printer);

    return 0;
}
