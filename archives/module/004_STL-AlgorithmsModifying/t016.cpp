#include <iostream>
#include <vector>
#include <algorithm>
#include <random>   // Para std::mt19937 e std::random_device
#include <chrono>   // Para usar tempo como semente opcional

using namespace std;

void print_signal(const vector<int>& signal, const string& label) {
    cout << label << ": ";
    for (int bit : signal)
        cout << bit << " ";
    cout << "\n";
}

int main() {
    // sinal binário codificado com bits de paridade
    vector<int> signal = {1, 0, 1, 1, 0, 0, 1, 0};  // 8 bits

    print_signal(signal, "Sinal original");

    // Criando um gerador de números aleatórios moderno
    random_device rd;                         // Fonte de aleatoriedade real (hardware)
    mt19937 gen(rd());                        // Mersenne Twister com semente baseada em rd

    // embaralha o sinal com std::shuffle
    shuffle(signal.begin(), signal.end(), gen);

    print_signal(signal, "Sinal embaralhado com std::shuffle");

    return 0;
}

/*
é possível controlar o comportamento do embaralhamento usando uma semente fixa 
em mt19937, útil para testes reproduzíveis:

mt19937 gen(2025); // sempre embaralha da mesma forma
*/
