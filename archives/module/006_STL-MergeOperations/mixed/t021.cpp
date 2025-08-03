#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Classe representando uma leitura de sensor
class SensorReading {
    int temperature;

public:
    SensorReading() : temperature(0) {}
    SensorReading(int temp) : temperature(temp) {}

    int getTemperature() const { return temperature; }
};

// Comparação necessária para sort() e merge()
bool operator<(const SensorReading &a, const SensorReading &b) {
    return a.getTemperature() < b.getTemperature();
}

// Operador para imprimir
ostream &operator<<(ostream &stream, const SensorReading &reading) {
    stream << reading.getTemperature() << "°C";
    return stream;
}

// Função para imprimir via for_each
void printReading(SensorReading r) {
    cout << r << ", ";
}

int main() {
    SensorReading sensorAData[] = {23, 19, 30, 25};
    SensorReading sensorBData[] = {22, 21, 29, 24};

    vector<SensorReading> readingsA(sensorAData, sensorAData + 4);
    vector<SensorReading> readingsB(sensorBData, sensorBData + 4);

    sort(readingsA.begin(), readingsA.end());
    sort(readingsB.begin(), readingsB.end());

    // Pegando os 2 maiores valores de cada sensor
    vector<SensorReading> merged(4);
    merge(readingsA.begin() + 2, readingsA.end(),
          readingsB.begin() + 2, readingsB.end(),
          merged.begin());

    cout << "Leituras mais recentes dos sensores (ordenadas): ";
    for_each(merged.begin(), merged.end(), printReading);
    cout << endl;

    return 0;
}
