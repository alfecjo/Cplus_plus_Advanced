#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

// Impressão dos valores filtrados
void printer(int sample) {
    cout << sample << " ";
}

int main() {
    // Simulação de amostras recebidas de um sinal digital (ex: via UART)
    int received_samples[] = { 12, 48, 7, 30, 18, 25, 35 };

    // Armazenamento das amostras em uma fila dupla
    deque<int> signal_samples(received_samples, received_samples + 7);

    // Ordenação das amostras recebidas
    sort(signal_samples.begin(), signal_samples.end());

    // Nova amostra recebida posteriormente (poderia ter vindo por SPI/I2C/etc.)
    signal_samples.push_back(40);

    // Define um limiar mínimo para considerar "sinal válido"
    int threshold = 25;

    // Busca o primeiro elemento estritamente maior que o limiar
    auto it = upper_bound(signal_samples.begin(), signal_samples.end(), threshold);

    // exibe as amostras consideradas válidas (acima do limiar)
    cout << "Amostras acima do limiar (" << threshold << "):\n";
    for_each(it, signal_samples.end(), printer);

    cout << endl;
    return 0;
}
