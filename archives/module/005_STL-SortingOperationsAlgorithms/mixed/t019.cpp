#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// Classe que representa uma medição de pressão (psi)
class PressureMeasurement {
    int psi;  

public:
    PressureMeasurement(int psi) : psi(psi) {}

    int getValue() const {
        return psi;
    }

    // operadores para comparação (necessários para STL)
    bool operator<(const PressureMeasurement& other) const {
        return psi < other.psi;
    }
    bool operator>(const PressureMeasurement& other) const {
        return psi > other.psi;
    }
};

// sobrecarga para facilitar impressão
ostream& operator<<(ostream& os, const PressureMeasurement& p) {
    os << p.getValue() << " psi";
    return os;
}

// Função para imprimir medições
void printMeasurement(const PressureMeasurement& p) {
    cout << p << ", ";
}

int main() {
    // Simulando  medições convertidas do sinal 4-20mA (valores arbitrários)
    int raw_psi_values[] = { 30, 55, 75, 80, 45, 90, 60, 70 };

    // Armazenar medições em vector usando classe PressureMeasurement
    vector<PressureMeasurement> measurements(raw_psi_values, raw_psi_values + 8);

    // ordenar medições em ordem decrescente (pressões maiores primeiro)
    sort(measurements.begin(), measurements.end(), greater<PressureMeasurement>());

    cout << "Medições ordenadas (pressão decrescente):\n";
    for_each(measurements.begin(), measurements.end(), printMeasurement);
    cout << "\n\n";

    // limiar para alerta
    PressureMeasurement alertThreshold(75);

    // encontrar primeiro elemento <= limiar (menor ou igual a 75 psi)
    auto it = lower_bound(measurements.begin(), measurements.end(), alertThreshold, greater<PressureMeasurement>());

    cout << "Medições acima do limiar de alerta (>" << alertThreshold.getValue() << " psi):\n";
    for_each(measurements.begin(), it, printMeasurement);
    cout << "\n\n";

    // verificar se uma medição específica existe
    PressureMeasurement query(60);
    bool found = binary_search(measurements.begin(), measurements.end(), query, greater<PressureMeasurement>());
    cout << "Medição de " << query << (found ? " encontrada.\n" : " NÃO encontrada.\n");

    return 0;
}
