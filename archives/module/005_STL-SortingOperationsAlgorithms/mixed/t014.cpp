#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class SignalLevel {
    int intensity;  // Intensidade do sinal (ex: RSSI em dBm)
public:
    SignalLevel(int intensity) : intensity(intensity) {}

    int getIntensity() const {
        return intensity;
    }

    // Operador < necessário para ordenação e uso em set
    bool operator<(const SignalLevel& other) const {
        return intensity < other.intensity;
    }
};

ostream& operator<<(ostream& os, const SignalLevel& s) {
    os << s.getIntensity() << "dBm";
    return os;
}

void printSignal(const SignalLevel& s) {
    cout << s << " ";
}

int main() {
    // amostras coletadas de intensidade de sinal em uma estação base
    int measurements[] = { -70, -85, -60, -70, -90, -75, -80 };

    // aqui usando deque para armazenar as amostras, que podem mudar de tamanho dinamicamente
    deque<SignalLevel> signals(measurements, measurements + 7);

    // Ordena para permitir buscas binárias
    sort(signals.begin(), signals.end());

    cout << "Sinais ordenados:\n";
    for_each(signals.begin(), signals.end(), printSignal);
    cout << "\n\n";

    // Criar um conjunto (set) para armazenar níveis únicos de sinal
    set<SignalLevel> uniqueSignals(measurements, measurements + 7);

    // Valores de interesse para verificar a presença no conjunto e no vetor ordenado
    SignalLevel query1(-70);  // Verificar se -70 dBm foi medido
    SignalLevel query2(-65);  // Verificar se -65 dBm foi medido

    cout << "Verificando presença no conjunto (set) e no deque ordenado:\n";
    cout << query1 << " está no conjunto? " 
    // A função binary_search recebe um objeto do tipo SignalLevel para fazer 
    // essa busca, usando o operador < que você definiu.
         << (binary_search(uniqueSignals.begin(), uniqueSignals.end(), query1) ? "Sim" : "Não") << "\n";
    cout << query1 << " está no deque? " 
         << (binary_search(signals.begin(), signals.end(), query1) ? "Sim" : "Não") << "\n";

    cout << query2 << " está no conjunto? " 
         << (binary_search(uniqueSignals.begin(), uniqueSignals.end(), query2) ? "Sim" : "Não") << "\n";
    cout << query2 << " está no deque? " 
         << (binary_search(signals.begin(), signals.end(), query2) ? "Sim" : "Não") << "\n";

    return 0;
}
