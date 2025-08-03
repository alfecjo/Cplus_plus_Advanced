#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> // para back_inserter

using namespace std;


template <typename T>
void print(const T& val) {
    cout << val << " ";
}

int main() {
    // simulando uma sequência codificada de bits (ex: após modulação ou codificação de canal)
    vector<int> bit_stream = {1, 0, 1, 1, 0, 0, 1, 0};

    cout << "Sinal codificado (bit stream original):\n";
    for_each(bit_stream.begin(), bit_stream.end(), print<int>);
    cout << "\n\n";

    // inversão da sequência de bits (ex: simular efeitos de reversão no tempo ou testes de canal)
    reverse(bit_stream.begin(), bit_stream.end());
    cout << "Sinal codificado após reverse (modificação in-place):\n";
    for_each(bit_stream.begin(), bit_stream.end(), print<int>);
    cout << "\n\n";

    // Suponha agora que temos uma nova cadeia de bits
    vector<int> received_bits = {1, 1, 0, 1, 0, 1, 0, 0};
    cout << "Sinal recebido (original):\n";
    for_each(received_bits.begin(), received_bits.end(), print<int>);
    cout << "\n";

    // eesejamos uma cópia invertida, sem alterar a original (ex: para aplicar decodificação reversa)
    vector<int> reversed_copy;
    reverse_copy(received_bits.begin(), received_bits.end(), back_inserter(reversed_copy));

    cout << "Sinal recebido (invertido com reverse_copy):\n";
    for_each(reversed_copy.begin(), reversed_copy.end(), print<int>);
    cout << "\n";

    return 0;
}