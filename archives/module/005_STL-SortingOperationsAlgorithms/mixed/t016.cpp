#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

class SignalLevel {
    int dBm;

public:
    SignalLevel(int dBm) : dBm(dBm) {}

    int getValue() const {
        return dBm;
    }

    bool operator<(const SignalLevel& other) const {
        return dBm < other.dBm;  // menor dBm = sinal mais fraco
    }
};

ostream& operator<<(ostream& stream, const SignalLevel& level) {
    stream << level.getValue() << " dBm";
    return stream;
}

void printer(SignalLevel s) {
    cout << s << ", ";
}

int main() {
    // Simulando medições de sinal
    int raw_measurements[] = { -70, -85, -60, -90, -75, -65, -88 };

    vector<SignalLevel> signals(raw_measurements, raw_measurements + 7);

    // Ordenar em ordem decrescente (mais forte para mais fraco)
    sort(signals.begin(), signals.end(), [](const SignalLevel& a, const SignalLevel& b) {
        return a.getValue() > b.getValue();  // decrescente
    });

    cout << "Níveis de sinal ordenados (mais forte -> mais fraco):\n";
    for_each(signals.begin(), signals.end(), printer);
    cout << "\n\n";

    // Mostrar os 3 sinais mais fortes
    cout << "Top 3 sinais mais fortes:\n";
    for (int i = 0; i < 3 && i < signals.size(); ++i) {
        cout << "- " << signals[i] << endl;
    }

    // Verificar se há sinal abaixo de -85 dBm
    bool weak_signal_detected = any_of(
        signals.begin(),
        signals.end(),
        [](SignalLevel s) { return s.getValue() < -85; }
    );

    if (weak_signal_detected)
        cout << "\n  Sinal fraco detectado abaixo de -85 dBm!\n";
    else
        cout << "\n  Todos os sinais estão acima de -85 dBm.\n";

    return 0;
}
