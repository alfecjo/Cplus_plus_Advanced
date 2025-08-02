#include <vector>
#include <iostream>
#include <functional>   // Para std::less_equal
#include <algorithm>    // Para generate, reverse_copy, sort, for_each

using namespace std;

// Functor de saída: usado com for_each para imprimir os elementos de um contêiner
template <class T>
struct Out {
    ostream& out;
    Out(ostream& o) : out(o) {}

    void operator()(const T& val) {
        out << val << ", ";
    }
};

// Functor gerador de sequência: gera valores baseados em "start % 7"
struct Sequence {
    int start;
    Sequence(int start) : start(start) {}

    int operator()() {
        return start++ % 7;  // Gera valores cíclicos de 0 a 6
    }
};

int main() {
    vector<int> v1(4);  // Vetor v1 com 4 posições
    vector<int> v2(4);  // Vetor v2 com 4 posições (será usado como destino da cópia reversa)

    // Preenche v1 com valores gerados por Sequence(10)
    // A sequência será: 10 % 7 = 3, 11 % 7 = 4, 12 % 7 = 5, 13 % 7 = 6 → v1 = [3, 4, 5, 6]
    generate(v1.begin(), v1.end(), Sequence(10));

    // Copia os elementos de v1 em ordem reversa para v2, mas no final invertido usando rbegin()
    // v1 = [3, 4, 5, 6] → reverse = [6, 5, 4, 3] → v2 = [3, 4, 5, 6]
    reverse_copy(v1.begin(), v1.end(), v2.rbegin());

    // Ordena v2 usando std::less_equal<int>(), que não é comum nem necessário aqui.
    // std::less_equal funciona como <=, mas sort espera um comparador que retorne true apenas quando a < b.
    // Então usar std::less_equal pode produzir comportamento indefinido.
    // O correto seria usar std::less<int>(), que é o padrão.
    sort(v2.begin(), v2.end(), less<int>());  // Corrigido para evitar comportamento indefinido

    // Imprime os elementos de v2 usando o functor Out
    for_each(v2.begin(), v2.end(), Out<int>(cout));
    cout << endl;

    return 0;
}
