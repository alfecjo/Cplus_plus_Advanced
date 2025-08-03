#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

class SignalStrength {
    int dBm; // valor da potência em dBm
public:
    SignalStrength(int dBm): dBm(dBm) {}

    int getValue() const { return dBm; }

    bool operator < (const SignalStrength& other) const {
        return dBm < other.dBm;
    }
};

ostream& operator<<(ostream& os, const SignalStrength& sig) {
    os << sig.getValue() << " dBm";
    return os;
}

void printSignal(SignalStrength s) {
    cout << s << endl;
}

int main() {
    // níveis de potência medidos em diferentes pontos de uma rede sem fio
    int signalMeasurements[] = { -70, -55, -80, -60, -65, -72, -58 };

    vector<SignalStrength> signals(signalMeasurements, signalMeasurements + 7);

    // ordenar os sinais do mais forte (menos negativo) para o mais fraco
    sort(signals.begin(), signals.end(), greater<SignalStrength>());

    cout << "Níveis de sinal do mais forte para o mais fraco:\n";
    for_each(signals.begin(), signals.end(), printSignal);

    return 0;
}
