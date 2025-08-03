#include <deque>
#include <iostream>
#include <algorithm>  // for lower_bound, for_each
#include <iomanip>    // for std::fixed, std::setprecision

using namespace std;

// Função para imprimir uma amostra com 2 casas decimais
void print_sample(double val) {
    cout << fixed << setprecision(2) << val << " ";
}

int main() {
    // Simulação de amostras lidas por um ADC (ex: sensor de temperatura ou sinal RF)
    double samples_array[] = { 0.15, 0.33, 0.89, 1.01, 0.44, 0.76, 1.23 };

    // Armazenar as amostras em um deque para permitir inserções rápidas em ambas as extremidades
    deque<double> signal_samples(samples_array, samples_array + 7);

    // nova amostra capturada que deve ser adicionada ao fim do buffer
    signal_samples.push_back(1.35); // Suponha que veio de uma nova leitura ADC

    // Limiar mínimo para considerar uma amostra como válida (ex: acima do ruído)
    double detection_threshold = 0.75;

    // garantir que a sequência esteja ordenada antes de usar lower_bound
    sort(signal_samples.begin(), signal_samples.end());

    // Encontrar a primeira amostra que atinge ou ultrapassa o limiar
    auto it = lower_bound(signal_samples.begin(), signal_samples.end(), detection_threshold);

    cout << "Amostras acima do limiar de detecção (" << detection_threshold << "):\n";

    // imprimir apenas os valores relevantes
    for_each(it, signal_samples.end(), print_sample);

    cout << "\n";

    return 0;
}
