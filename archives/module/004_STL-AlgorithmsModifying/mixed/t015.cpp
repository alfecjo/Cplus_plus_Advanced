#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Função para imprimir os elementos do container
void printer(int i) {
    cout << i << ", ";
}

// Struct que gera uma sequência de números com incremento definido
struct sequence {
    int val;  // valor atual da sequência
    int inc;  // incremento a ser aplicado a cada chamada

    // Construtor que inicializa valor inicial e incremento
    sequence(int s, int i) : val(s), inc(i) {}

    // Operador função que retorna o valor atual e incrementa para o próximo
    int operator()() {
        int r = val;   // guarda o valor atual
        val += inc;    // incrementa para a próxima chamada
        return r;      // retorna o valor atual
    }
};

int main() {
    vector<int> v1(7);  // cria vetor com 7 posições

    // Preenche o vetor usando a função geradora sequence(1, 2)
    // Isso vai gerar a sequência: 1, 3, 5, 7, 9, 11, 13
    generate(v1.begin(), v1.end(), sequence(1, 2));

    // Imprime os elementos do vetor
    for_each(v1.begin(), v1.end(), printer);

    return 0;
}
