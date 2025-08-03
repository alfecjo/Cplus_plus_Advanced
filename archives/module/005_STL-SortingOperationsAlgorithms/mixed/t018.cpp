#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// simula um "envelope" para os dados coletados via I2C
template <typename T>
class Pocket {
    T value;
public:
    Pocket(T value) : value(value) {}
    T getValue() const { return value; }

    // Comparação padrão (para sort)
    bool operator<(const Pocket<T>& other) const {
        return value < other.value;
    }
};

// para imprimir os dados
template <typename T>
ostream& operator<<(ostream& stream, const Pocket<T>& pocket) {
    stream << pocket.getValue() << "°C";
    return stream;
}

// função para impressão no loop
void printPocket(const Pocket<float>& p) {
    cout << p << ", ";
}

// Simula leitura I2C (em sistemas reais, usaria HAL_I2C_Receive)
vector<float> readTemperaturesFromI2C() {
    return {24.5, 23.8, 25.1, 24.9, 26.3, 23.1, 25.0, 24.2};
}

int main() {
    // Simula a coleta de dados dos sensores via I2C
    vector<float> rawData = readTemperaturesFromI2C();

    // armazena os dados em objetos Pocket
    vector<Pocket<float>> tempData;
    for (float t : rawData)
        tempData.emplace_back(t);

    // Ordena os dados de forma crescente
    sort(tempData.begin(), tempData.end());

    // Imprime os dados ordenados
    cout << "Temperaturas ordenadas via I2C: ";
    for_each(tempData.begin(), tempData.end(), printPocket);
    cout << endl;

    return 0;
}
