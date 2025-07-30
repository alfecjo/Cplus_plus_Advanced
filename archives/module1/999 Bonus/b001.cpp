#include <iostream>
#include <set>

using namespace std;

class Sensor {
public:
    int id;
    float leitura;

    // construtor com dois parâmetros
    Sensor(int id_, float leitura_) : id(id_), leitura(leitura_) {}

    int getID() const { return id; }
    float getLeitura() const { return leitura; }

    // operador de comparação para std::set
    // definee como os sensores serão ordenados e o que é considerado duplicado
    bool operator<(const Sensor& outro) const {
        return id < outro.id;  // ordenação e unicidade baseada no ID
    }
};

// não é membro da classe Sensor (função global),
// logo, não tem acesso direto a membros privados da classe (a menos que seja friend).
void printSensores(const set<Sensor>& sensores) {
    for (const auto& sensor : sensores) {
        cout << "Sensor ID: " << sensor.getID()
             << ", Leitura: " << sensor.getLeitura() << endl;
    }
}

int main() {
    // std::set garante elementos únicos e ordenados
    set<Sensor> sensores;  

    // inserindo sensores (note que o ID 3 é duplicado e será ignorado)
    sensores.insert(Sensor(3, 24.5f));
    sensores.insert(Sensor(1, 18.2f));
    sensores.insert(Sensor(7, 30.1f));
    sensores.insert(Sensor(3, 26.7f));  // (ID já existe)

    // exibe todos os sensores do conjunto
    printSensores(sensores);

    return 0;
}

/*Quando os sensores enviam seus dados para um servidor (via UART, MQTT, LoRa, etc.), 
você precisa identificar de onde vêm os dados.

usar Sensor ID como chave em um std::set garante que:
 os dados não se repitam (caso um mesmo sensor envie dados duas vezes por erro).
 os dados estejam ordenados por ID, facilitando indexação e visualização.
 Você possa fazer buscas rápidas (ex: find, lower_bound, etc.).
*/