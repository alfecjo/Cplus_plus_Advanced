#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>  // std::greater
#include <numeric>     // std::accumulate

using namespace std;

// Functor para imprimir elementos com separação
template <typename T>
struct PrintWithComma {
    ostream& out;
    PrintWithComma(ostream& o) : out(o) {}
    void operator()(const T& val) const {
        out << val << ", ";
    }
};

// Functor que simula a aquisição de sinal com ruído
struct SignalGenerator {
    mt19937 rng;  // gerador aleatório
    uniform_real_distribution<double> dist;

    SignalGenerator(double min_val, double max_val)
        : rng(random_device{}()), dist(min_val, max_val) {}

    double operator()() {
        return dist(rng);  // valor aleatório entre min_val e max_val
    }
};

// Filtro simples: remove valores abaixo de um limiar
vector<double> applyThresholdFilter(const vector<double>& input, double threshold) {
    vector<double> filtered;
    copy_if(input.begin(), input.end(), back_inserter(filtered),
            [threshold](double val) { return val >= threshold; });
    return filtered;
}

int main() {
    // Simula a leitura de 10 sinais com valores entre 0.0 e 10.0
    vector<double> raw_signals(10);
    generate(raw_signals.begin(), raw_signals.end(), SignalGenerator(0.0, 10.0));

    cout << "Raw signals: ";
    for_each(raw_signals.begin(), raw_signals.end(), PrintWithComma<double>(cout));
    cout << endl;

    // Aplica um filtro de limiar: apenas sinais >= 5.0 serão considerados válidos
    vector<double> filtered_signals = applyThresholdFilter(raw_signals, 5.0);

    cout << "Filtered signals (>= 5.0): ";
    for_each(filtered_signals.begin(), filtered_signals.end(), PrintWithComma<double>(cout));
    cout << endl;

    // Ordena os sinais filtrados em ordem decrescente
    sort(filtered_signals.begin(), filtered_signals.end(), greater<double>());

    cout << "Sorted filtered signals (descending): ";
    for_each(filtered_signals.begin(), filtered_signals.end(), PrintWithComma<double>(cout));
    cout << endl;

    // Cálculo de uma grandeza física simulada: média dos sinais válidos (ex: tensão média)
    if (!filtered_signals.empty()) {
        double average = accumulate(filtered_signals.begin(), filtered_signals.end(), 0.0) / filtered_signals.size();
        cout << "Average signal value: " << average << " V" << endl;
    } else {
        cout << "No valid signals above threshold." << endl;
    }

    return 0;
}
