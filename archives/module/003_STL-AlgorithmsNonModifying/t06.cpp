#include <iostream>
#include <map>
#include <string>
#include <cstdint> // necessário para uint8_t

using namespace std;

int main() {
    // suponha que estamos lidando com registradores de um sensor I2C
    // uint8_t representa endereços de registradores (0 a 255)
    map<uint8_t, string> sensorRegisters;

    // preenchemos o mapa com alguns endereços de registradores e suas funções
    sensorRegisters[0x00] = "Device ID";
    sensorRegisters[0x01] = "Config Register";
    sensorRegisters[0x02] = "Temperature MSB";
    sensorRegisters[0x03] = "Temperature LSB";
    sensorRegisters[0x04] = "Status Register";

    uint8_t reg = 0x02; // queremos encontrar a função do registrador 0x02

    // Usamos find para verificar se o registrador existe no mapa
    auto it = sensorRegisters.find(reg);

    if (it != sensorRegisters.end()) {
        cout << "Endereço 0x" << hex << (int)reg << " -> " << it->second << '\n';
    } else {
        cout << "Endereço 0x" << hex << (int)reg << " não encontrado no mapa.\n";
    }

    return 0;
}
