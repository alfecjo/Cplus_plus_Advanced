#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

// class que representa uma amostra de sinal analógico
class Sample
{
    float voltage; // tensão em volts

public:
    Sample(float v) : voltage(v) {}

    float getVoltage() const
    {
        return voltage;
    }

    // Operador para comparação (usado no sort)
    bool operator<(const Sample &other) const
    {
        return voltage < other.voltage;
    }

    bool operator>(const Sample &other) const
    {
        return voltage > other.voltage;
    }
};

ostream &operator<<(ostream &os, const Sample &s)
{
    os << s.getVoltage() << "V";
    return os;
}

void printSample(Sample s)
{
    cout << s << ", ";
}

// Função de simulação que retorna leituras de um ADC
vector<Sample> simulateADCReadings()
{
    float rawVoltages[] = {0.12, 2.45, 1.98, 0.05, 3.30, 0.01, 2.78, 1.10, 0.03, 3.10};
    return vector<Sample>(rawVoltages, rawVoltages + 10);
}

int main()
{
    // leitura simulada do ADC
    vector<Sample> samples = simulateADCReadings();

    // Ordena os dados em ordem decrescente
    sort(samples.begin(), samples.end(), greater<Sample>());

    cout << "Sinal ordenado decrescente (com ruído):\n";
    for_each(samples.begin(), samples.end(), printSample);
    cout << "\n\n";

    // Remove ruídos abaixo de 0.1V
    samples.erase(remove_if(samples.begin(), samples.end(), [](Sample s)
                            { return s.getVoltage() < 0.1; }),
                  samples.end());

    cout << "Sinal após filtragem (sem ruído):\n";
    for_each(samples.begin(), samples.end(), printSample);
    cout << "\n\n";

    // calcula média das tensões válidas
    float sum = accumulate(samples.begin(), samples.end(), 0.0f, [](float acc, Sample s)
                           { return acc + s.getVoltage(); });

    float average = samples.empty() ? 0.0f : sum / samples.size();

    cout << "Média das amostras válidas: " << average << "V\n";

    return 0;
}
