#include <iostream>
#include <vector>
#include <algorithm>   // std::shuffle
#include <random>      // std::mt19937, std::random_device

using namespace std;

// Impressão genérica de containers
template <typename T>
void print(const T& value) {
    cout << hex << "0x" << value << " ";
}

int main() {
    // Simulação: Buffer de leitura UART (RS232)
    vector<int> uart_buffer = { 0x10, 0xFF, 0xA5, 0x7E, 0x00, 0xB2, 0x13, 0x9C, 0xE1, 0x04 };

    cout << "Buffer UART original (dados recebidos):\n";
    for_each(uart_buffer.begin(), uart_buffer.end(), print<int>);
    cout << "\n\n";

    // Simulando ruído/interferência ou erro de ordenação
    random_device rd;
    mt19937 gen(rd());

    // Embaralhamento com std::shuffle (mais compatível que std::ranges::shuffle)
    shuffle(uart_buffer.begin(), uart_buffer.end(), gen);

    cout << "Buffer embaralhado (simulando distorção na recepção RS232):\n";
    for_each(uart_buffer.begin(), uart_buffer.end(), print<int>);
    cout << "\n\n";

    return 0;
}
