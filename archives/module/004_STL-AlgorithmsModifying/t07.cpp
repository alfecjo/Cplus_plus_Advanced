#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>  // necessário para std::accumulate


using namespace std;

void print(double val) {
    cout.precision(2);
    cout << fixed << val << " ";
}

// Simula a "quantização uniforme" (como em um codificador PCM)
struct Quantizer {
    double step;

    Quantizer(double step_size) : step(step_size) {}

    double operator()(double sample) {
        return round(sample / step) * step;
    }
};

// Simula um pré-processamento: remoção de DC offset
struct RemoveDCOffset {
    double mean;

    RemoveDCOffset(double mean_value) : mean(mean_value) {}

    double operator()(double sample) {
        return sample - mean;
    }
};

int main() {
    // Sinal simulado de voz (amostras em kHz normalizadas de -1.0 a 1.0)
    vector<double> voice_samples = {0.12, 0.15, 0.38, -0.22, -0.50, -0.48, -0.10, 0.05, 0.18, 0.30};

    cout << "Sinal de voz original (amostras normalizadas):\n";
    for_each(voice_samples.begin(), voice_samples.end(), print);
    cout << endl << endl;

    // etapa 1: remover offset DC (simplesmente média subtraída)
    double mean = accumulate(voice_samples.begin(), voice_samples.end(), 0.0) / voice_samples.size();
    transform(voice_samples.begin(), voice_samples.end(), voice_samples.begin(), RemoveDCOffset(mean));

    cout << "Após remoção do DC offset (média = " << mean << "):\n";
    for_each(voice_samples.begin(), voice_samples.end(), print);
    cout << endl << endl;

    // etapa 2: aplicar quantização com step fixo
    double step = 0.1;
    transform(voice_samples.begin(), voice_samples.end(), voice_samples.begin(), Quantizer(step));

    cout << "Após quantização (step = " << step << "):\n";
    for_each(voice_samples.begin(), voice_samples.end(), print);
    cout << endl << endl;

    return 0;
}
