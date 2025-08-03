#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// representa um canal de frequência
class FrequencyChannel {
    int frequencyMHz;
    int interference_dBm;

public:
    FrequencyChannel(int freq, int interf)
        : frequencyMHz(freq), interference_dBm(interf) {}

    int getFreq() const { return frequencyMHz; }
    int getInterference() const { return interference_dBm; }

    // usado para ordenação com base na interferência (menor é melhor)
    bool operator<(const FrequencyChannel& other) const {
        return interference_dBm < other.interference_dBm;
    }

    // usado para comparar igualdade (por exemplo, ao remover)
    bool operator==(const FrequencyChannel& other) const {
        return frequencyMHz == other.frequencyMHz &&
               interference_dBm == other.interference_dBm;
    }
};

// impressão 
ostream& operator<<(ostream& os, const FrequencyChannel& ch) {
    os << "[Freq: " << ch.getFreq() << " MHz, Interf: "
       << ch.getInterference() << " dBm]";
    return os;
}

// Função para impressão no for_each
void printChannel(FrequencyChannel ch) {
    cout << ch << endl;
}

int main() {
    // Lista de canais disponíveis (freq, interferência)
    vector<FrequencyChannel> channels = {
        {1800, -90},
        {1805, -75},
        {1810, -85},
        {1815, -95},
        {1820, -70},
        {1825, -92}
    };

    cout << "Canais recebidos:\n";
    for_each(channels.begin(), channels.end(), printChannel);

    // Ordena por interferência (menor valor dBm = melhor canal)
    sort(channels.begin(), channels.end());

    cout << "\nCanais ordenados por interferência:\n";
    for_each(channels.begin(), channels.end(), printChannel);

    // Remove canais com interferência pior que -85 dBm
    channels.erase(
        remove_if(channels.begin(), channels.end(),
                  [](const FrequencyChannel& ch) {
                      return ch.getInterference() > -85;
                  }),
        channels.end());

    cout << "\n Canais com alta interferência foram removidos:\n";
    for_each(channels.begin(), channels.end(), printChannel);

    return 0;
}
