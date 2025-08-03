#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

class Sample {
    int amplitude;
public:
    Sample(int amplitude) : amplitude(amplitude) {}
    int getAmplitude() const { return amplitude; }
    bool operator<(const Sample& other) const {
        return amplitude < other.amplitude;
    }
};

ostream& operator<<(ostream& os, const Sample& sample) {
    os << sample.getAmplitude();
    return os;
}

void printSample(Sample s) {
    cout << s << " ";
}

int main() {
    // amostras de sinal digital quantizado (valores arbitrários)
    int rawData[] = { 5, 3, 7, 3, 10, 5, 3, 7, 8, 5, 3 };
    deque<Sample> signal(rawData, rawData + sizeof(rawData) / sizeof(rawData[0]));

    // Valor crítico que queremos localizar
    int criticalValue = 3;

    cout << "Sinal original:\n";
    for_each(signal.begin(), signal.end(), printSample);
    cout << "\n\n";

    // Ordena as amostras para usar equal_range
    sort(signal.begin(), signal.end());

    // busca o range de amostras com valor crítico
    auto range = equal_range(signal.begin(), signal.end(), Sample(criticalValue));

    cout << "Amostras com valor crítico (" << criticalValue << "):\n";
    for_each(range.first, range.second, printSample);
    cout << "\n\n";

    //  Calcular quantas amostras críticas existem
    int countCritical = distance(range.first, range.second);
    cout << "Número de amostras críticas encontradas: " << countCritical << endl;

    return 0;
}
