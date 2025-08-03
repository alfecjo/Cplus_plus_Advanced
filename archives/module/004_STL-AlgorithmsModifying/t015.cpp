#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> // para back_inserter

using namespace std;

// Função utilitária para imprimir sinais
template <typename T>
void print_signal(const vector<T>& signal, const string& label) {
    cout << label << ": ";
    for (auto bit : signal)
        cout << bit << " ";
    cout << "\n";
}

int main() {
    // Simulando um sinal digital com bits embaralhados por erro de sincronismo
    vector<int> bit_stream = {1, 0, 1, 1, 0, 0, 1, 0};

    print_signal(bit_stream, "Sinal original");

    // Simular um erro de alinhamento: o bit "1" que deveria estar no começo está na posição 3
    // Vamos rotacionar a partir desse ponto
    auto middle = bit_stream.begin() + 3;

    rotate(bit_stream.begin(), middle, bit_stream.end());

    print_signal(bit_stream, "Sinal após std::rotate");

    // Explicação:
    // Os 3 primeiros bits (1, 0, 1) foram movidos para o final.
    // A nova ordem começa de fato no índice 3 anterior (1), que era o bit de sincronismo esperado.

    return 0;
}
