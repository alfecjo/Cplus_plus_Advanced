#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

/*
  Este programa simula a leitura de sinais de intensidade de recepção (RSSI)
  provenientes de dois módulos de rádio diferentes em um sistema embarcado.
  Os dados são armazenados em deques, depois ordenados e fundidos utilizando
  algoritmos da STL como sort() e merge().

  Este tipo de operação pode ser útil, por exemplo, em sistemas de redundância
  de sensores RF, onde os dados devem ser combinados e analisados para melhorar
  a confiabilidade da detecção ou do rastreamento de sinais.
*/

template <class T>
void print(T start, T end) {
    for (; start != end; ++start) {
        std::cout << *start << " ";
    }
    std::cout << endl;
}

// Comparador para ordenação decrescente (ex: sinais mais fortes primeiro)
bool compareDescending(int a, int b) {
    return a > b;
}

int main() {
    // leituras simuladas de RSSI em dBm de dois módulos diferentes
    int sensor1_data[] = { -88, -67, -90, -70, -75, -79, -72 };
    int sensor2_data[] = { -80, -60, -85, -65, -78 };

    // Armazenamento em deques
    deque<int> modulo1(sensor1_data, sensor1_data + 7);
    deque<int> modulo2(sensor2_data, sensor2_data + 5);
    deque<int> sinais_fundidos(modulo1.size() + modulo2.size());

    cout << "Sinais captados pelos módulos:\n";
    cout << "Módulo 1: ";
    print(modulo1.begin(), modulo1.end());
    cout << "Módulo 2: ";
    print(modulo2.begin(), modulo2.end());
    cout << endl;

    cout << "Ordenando os sinais captados por intensidade (mais forte primeiro):\n";
    sort(modulo1.begin(), modulo1.end(), compareDescending);
    sort(modulo2.begin(), modulo2.end(), compareDescending);
    cout << "Módulo 1 ordenado: ";
    print(modulo1.begin(), modulo1.end());
    cout << "Módulo 2 ordenado: ";
    print(modulo2.begin(), modulo2.end());
    cout << endl;

    cout << "Mesclando os sinais ordenados (modo prioridade - dBm):\n";
    merge(modulo1.begin(), modulo1.end(), modulo2.begin(), modulo2.end(),
          sinais_fundidos.begin(), compareDescending);

    cout << "Sinais fundidos (ordenados): ";
    print(sinais_fundidos.begin(), sinais_fundidos.end());
    cout << endl;

    return 0;
}
