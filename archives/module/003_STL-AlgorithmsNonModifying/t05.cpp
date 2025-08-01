#include <cstdint>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Simulação de sensores: cada sensor possui um ID e um valor de leitura
int main() {
    // mapa de sensores (ID -> Leitura). Ex: Sensor 1 => 22.5°C
    map<uint8_t, float> sensores;

    // populando o mapa com valores fictícios de sensores
    sensores[1] = 22.5f;     // Temperatura ambiente
    sensores[2] = 101.3f;    // Pressão em kPa
    sensores[3] = 3.3f;      // Tensão em volts
    sensores[4] = 0.8f;      // Corrente em amperes

    // ID do sensor que queremos verificar (simulação de busca)
    uint8_t idBusca = 3;

    // Usando find() para procurar o sensor com ID 3
    auto it = sensores.find(idBusca);

    if (it != sensores.end()) {
        // Sensor encontrado: it->first é o ID, it->second é o valor
        cout << "Sensor encontrado:\n";
        cout << "ID: " << static_cast<int>(it->first)
             << " | Leitura: " << it->second << endl;
    } else {
        // Sensor não existe no mapa
        cout << "Sensor com ID " << static_cast<int>(idBusca) << " não encontrado!" << endl;
    }

    cout << "\nListando todos os sensores:\n";
    for (const auto& par : sensores) {
        cout << "Sensor ID " << static_cast<int>(par.first)
             << " => " << par.second << endl;
    }

    return 0;
}
