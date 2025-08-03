#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
Imagine que você está desenvolvendo um firmware que lê amostras de um sensor
 analógico e aplica processamento digital básico — por exemplo:
 - Soma de offset (calibração).
 - Média com outro vetor (ex: média entre amostra e valor de referência).
 - Inversão de sequência (ex: delay invertido).
 - Armazenamento de resultados em listas de processamento.
*/

// imprime valores com 2 casas decimais
template <class T>
void print(const T &value)
{
    cout << fixed << setprecision(2) << value << " ";
}

// Functor para aplicar um offset de calibração
struct Calibrate
{
    float offset;
    Calibrate(float o) : offset(o) {}
    float operator()(float sample) const
    {
        return sample + offset;
    }
};

// Functor para calcular média entre valor da amostra e referência
struct Average
{
    float operator()(float a, float b) const
    {
        return (a + b) / 2.0f;
    }
};

int main()
{
    // Simulando 10 amostras brutas de sensor
    float raw_samples[] = {2.5, 2.7, 2.9, 3.0, 3.2, 3.3, 3.5, 3.6, 3.7, 3.8};
    size_t n = sizeof(raw_samples) / sizeof(raw_samples[0]);

    // etapa 1: Armazenar amostras ----------
    vector<float> sensor_buffer(raw_samples, raw_samples + n);
    cout << "== Amostras brutas ==\n";
    for_each(sensor_buffer.begin(), sensor_buffer.end(), print<float>);
    cout << "\n\n";

    // etapa 2: Calibração (offset de +0.1V) ----------
    list<float> calibrated(n);
    transform(sensor_buffer.begin(), sensor_buffer.end(), calibrated.begin(), Calibrate(0.1f));

    cout << "== Após calibração (+0.1V) ==\n";
    for_each(calibrated.begin(), calibrated.end(), print<float>);
    cout << "\n\n";

    // etapa 3: Delay invertido usando copy_backward ----------
    vector<float> delayed(n, 0.0);
    copy_backward(sensor_buffer.begin(), sensor_buffer.end(), delayed.end());

    cout << "== Delay invertido (copy_backward) ==\n";
    for_each(delayed.begin(), delayed.end(), print<float>);
    cout << "\n\n";

    // etapa 4: Troca de metades do buffer ----------
    swap_ranges(sensor_buffer.begin(), sensor_buffer.begin() + n / 2,
                sensor_buffer.begin() + n / 2);

    cout << "== Buffer com metades trocadas (swap_ranges) ==\n";
    for_each(sensor_buffer.begin(), sensor_buffer.end(), print<float>);
    cout << "\n\n";

    // etapa 5: Média entre sensor atual e calibrado invertido ----------
    list<float> avg_result(n);
    transform(sensor_buffer.begin(), sensor_buffer.end(),
              calibrated.rbegin(), avg_result.begin(), Average());

    cout << "== Média entre buffer trocado e calibração invertida ==\n";
    for_each(avg_result.begin(), avg_result.end(), print<float>);
    cout << "\n";

    return 0;
}
