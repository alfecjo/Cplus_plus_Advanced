#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>  // std::search
#include <iomanip>    // std::hex, std::setw

using namespace std;

// Função para imprimir uma sequência de bytes (útil para debug)
void printBuffer(const vector<uint8_t>& buffer) {
    for (auto byte : buffer)
        cout << "0x" << hex << setw(2) << setfill('0') << (int)byte << " ";
    cout << dec << endl; // Volta para base decimal
}

int main() {
    // Simulando um buffer de dados recebido via UART
    vector<uint8_t> rxBuffer = {
        0x12, 0x00, 0xFF, 0xAA, 0xBB, 0xCC, 0x10, 0x11,
        0xAA, 0xBB, 0xCC, 0xAA, 0xBB, 0xCC, 0x20, 0x30
    };

    // assinatura esperada de um pacote válido (start frame)
    vector<uint8_t> pattern = { 0xAA, 0xBB, 0xCC };

    cout << "Buffer recebido:\n";
    printBuffer(rxBuffer);
    cout << "\nProcurando padrão: ";
    printBuffer(pattern);
    cout << endl;

    // Ponteiro de busca no buffer
    auto it = rxBuffer.begin();
    int count = 0;

    // std::search procura a primeira ocorrência subsequente do padrão
    // Enquanto houver possibilidade de encontrar o padrão
    while ((it = search(it, rxBuffer.end(), pattern.begin(), pattern.end())) != rxBuffer.end()) {
        cout << "Padrão encontrado na posição: " << distance(rxBuffer.begin(), it) << endl;

        // avança um byte para continuar procurando (caso queira encontrar sobreposições)
        ++it;
        count++;
    }

    if (count == 0) {
        cout << "Padrão não encontrado no buffer.\n";
    }

    return 0;
}
