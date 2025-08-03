#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// para impressão de amostras
void printSample(double value) {
    cout << value << "V, ";
}

// Critério de ordenação: compara parte inteira da amostra (simula agrupamento de níveis)
bool compareByIntegerPart(double a, double b) {
    return int(a) < int(b);
}

int main() {
    // Amostras simuladas de um sinal analógico (em volts)
    vector<double> signalSamples = { 3.33, 9.19, 0.22, 2.12, 1.14, 4.45, 5.55 };

    cout << "Amostras originais:\n";
    for_each(signalSamples.begin(), signalSamples.end(), printSample);
    cout << "\n\n";

    // Remover ruídos: suponha que 2.12V é considerado ruído espúrio
    signalSamples.erase(remove(signalSamples.begin(), signalSamples.end(), 2.12), signalSamples.end());

    // Ordenar agrupando pelas partes inteiras (ex: 1.x, 2.x, 3.x...)
    stable_sort(signalSamples.begin(), signalSamples.end(), compareByIntegerPart);

    // Imprimir resultado final
    cout << "Amostras filtradas e ordenadas:\n";
    for_each(signalSamples.begin(), signalSamples.end(), printSample);
    cout << endl;

    return 0;
}
