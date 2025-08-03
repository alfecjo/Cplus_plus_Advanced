#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
void print(const vector<T>& v, const string& label) {
    cout << label << ": ";
    for (const auto& val : v)
        cout << val << " ";
    cout << "\n";
}

// Predicado: verifica se um valor é positivo
bool isPositive(double v) {
    return v > 0.0;
}

// Predicado: valores acima do limiar (ex: pico de sinal)
bool isAboveThreshold(double v) {
    const double threshold = 0.5;
    return v > threshold;
}

int main() {
    // Simulando uma sequência de amostras de sinal
    vector<double> signal = { -0.3, 0.8, -0.5, 0.6, 0.0, -0.1, 1.0, -0.7, 0.3 };

    print(signal, "Sinal original");

    // Usando partition - NÃO mantém a ordem relativa
    vector<double> partitionedSignal = signal;
    auto it = partition(partitionedSignal.begin(), partitionedSignal.end(), isPositive);

    print(partitionedSignal, "Sinal após partition (> 0)");
    cout << "Número de positivos: " << distance(partitionedSignal.begin(), it) << "\n\n";

    // Usando stable_partition - MANTÉM a ordem relativa
    vector<double> stablePartitionedSignal = signal;
    auto it2 = stable_partition(stablePartitionedSignal.begin(), stablePartitionedSignal.end(), isAboveThreshold);

    print(stablePartitionedSignal, "Sinal após stable_partition (> 0.5)");
    cout << "Número acima do limiar: " << distance(stablePartitionedSignal.begin(), it2) << "\n";

    return 0;
}
