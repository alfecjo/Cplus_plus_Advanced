#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <class T>
void printSignal(const T &value) {
    cout << value << " ";
}

// Estrutura para substituir valores anômalos (ex: 999)
struct RemoveAnomaly {
    int anomaly_value;
    int neutral_value;

    RemoveAnomaly(int anomaly, int neutral) : anomaly_value(anomaly), neutral_value(neutral) {}

    int operator()(int sample) {
        return (sample == anomaly_value) ? neutral_value : sample;
    }
};

// Estrutura para eliminar ruído (neste caso: valores ímpares)
struct FilterOddNoise {
    int replacement_value;

    FilterOddNoise(int value) : replacement_value(value) {}

    int operator()(int sample) {
        return (sample % 2 != 0) ? replacement_value : sample;
    }
};

int main() {
    // Simulando uma sequência de amostras de um sensor com ruídos e valores anômalos
    int raw_samples[] = {25, 999, 42, 39, 100, 999, 77, 60, 33, 98};
    list<int> signal(raw_samples, raw_samples + 10);

    cout << ">> Sinal bruto (coletado do sensor):\n";
    for_each(signal.begin(), signal.end(), printSignal<int>);
    cout << "\n\n";

    // Passo 1: Remover valores anômalos
    cout << ">> Removendo anomalias (999 -> 0):\n";
    transform(signal.begin(), signal.end(), signal.begin(), RemoveAnomaly(999, 0));
    for_each(signal.begin(), signal.end(), printSignal<int>);
    cout << "\n\n";

    // Passo 2: Filtrar ruídos ímpares (torná-los 100)
    cout << ">> Filtrando ruído ímpar (ímpar -> 100):\n";
    transform(signal.begin(), signal.end(), signal.begin(), FilterOddNoise(100));
    for_each(signal.begin(), signal.end(), printSignal<int>);
    cout << "\n\n";

    // Sinal agora está "limpo" para ser transmitido, armazenado ou processado
    cout << ">> Sinal final pronto para transmissão/gravação:\n";
    for_each(signal.begin(), signal.end(), printSignal<int>);
    cout << "\n";

    return 0;
}
