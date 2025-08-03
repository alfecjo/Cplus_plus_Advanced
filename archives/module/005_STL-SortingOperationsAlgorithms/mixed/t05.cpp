#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// função para simular o processamento do nível detectado
void process_signal_level(int level) {
    cout << "Nível detectado: " << level << endl;
}

int main() {
    // Simulação: amostras digitalizadas de um sinal (8 bits)
    int adc_samples[] = { 120, 128, 130, 127, 128, 124, 122, 128, 131 };
    
    // Armazenamos as amostras em uma deque
    deque<int> signal(adc_samples, adc_samples + 9);

    // simulamos a chegada de uma nova amostra ao final da fila
    signal.push_back(128);  // Nível de referência comum em sistemas de 8 bits (meio do intervalo 0–255)

    // Ordenamos os valores para facilitar a análise (ex: para aplicar equal_range)
    sort(signal.begin(), signal.end());

    // Procuramos o intervalo de valores iguais a 128
    pair<deque<int>::iterator, deque<int>::iterator> result =
        equal_range(signal.begin(), signal.end(), 128);

    // Processamos (ou imprimimos) os níveis detectados
    for_each(result.first, result.second, process_signal_level);

    return 0;
}
