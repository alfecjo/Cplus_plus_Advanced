#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

/*
simula um sistema embarcado onde leituras de sinais analógicos são realizadas 
por sensores (como temperatura, pressão, corrente etc.).
Os dados lidos são processados por um microcontrolador (MCU), convertidos via 
ADC (conversor analógico-digital) e armazenados em estruturas de dados.
Utilizamos algoritmos de ordenação como sort() e stable_sort() para 
organizar os dados conforme critérios específicos:
- Ordenação pela leitura bruta do ADC.
- Ordenação considerando a prioridade do sensor (caso de múltiplos sensores com mesmo valor de leitura).
Estes dados poderiam ser usados em sistemas de aquisição de dados, telecomunicações ou monitoramento industrial.
*/

using namespace std;

class SensorLeitura {
public:
    int canal_adc;        // Canal do ADC (0-7 por exemplo)
    int leitura_adc;      // Valor lido (0-1023 para 10 bits)
    string tipo_sensor;   // Tipo (temperatura, pressão, etc.)

    SensorLeitura(int canal_adc, int leitura_adc, string tipo_sensor)
        : canal_adc(canal_adc), leitura_adc(leitura_adc), tipo_sensor(tipo_sensor) {}
};

void printLeitura(const SensorLeitura& s) {
    cout << "Canal: " << s.canal_adc
         << ", Valor ADC: " << s.leitura_adc
         << ", Tipo: " << s.tipo_sensor << endl;
}

// Ordenação crescente do valor de leitura ADC
bool ordenar_por_adc(const SensorLeitura& a, const SensorLeitura& b) {
    return a.leitura_adc < b.leitura_adc;
}

// Ordenação por tipo de sensor (alfabética), estável
bool ordenar_por_tipo(const SensorLeitura& a, const SensorLeitura& b) {
    return a.tipo_sensor < b.tipo_sensor;
}

int main() {
    vector<SensorLeitura> leituras;

    // Simulação de leituras de sensores conectados a diferentes canais ADC
    leituras.push_back(SensorLeitura(2, 512, "Temperatura"));
    leituras.push_back(SensorLeitura(0, 789, "Pressao"));
    leituras.push_back(SensorLeitura(3, 300, "Corrente"));
    leituras.push_back(SensorLeitura(1, 789, "Umidade"));
    leituras.push_back(SensorLeitura(4, 512, "Tensao"));

    cout << "Leituras originais:\n";
    for_each(leituras.begin(), leituras.end(), printLeitura);
    cout << endl;

    // Ordenação instável apenas pelo valor ADC
    sort(leituras.begin(), leituras.end(), ordenar_por_adc);
    cout << "Ordenado por valor ADC (sort):\n";
    for_each(leituras.begin(), leituras.end(), printLeitura);
    cout << endl;

    // Ordenação estável por tipo de sensor
    stable_sort(leituras.begin(), leituras.end(), ordenar_por_tipo);
    cout << "Ordenado por tipo de sensor (stable_sort):\n";
    for_each(leituras.begin(), leituras.end(), printLeitura);
    cout << endl;

    return 0;
}
