#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

//  para imprimir valores de sinal
void printer(int i) {
    cout << i << " dBm, ";
}

int main() {
    // Leitura de níveis de sinal em dBm (valores simulados)
    int signalLevels[] = { -85, -90, -70, -85, -60, -75, -90, -65 };

    // Armazena os sinais em uma deque (permite inserções rápidas nas extremidades)
    deque<int> signalDeque(signalLevels, signalLevels + 8);

    // Remove duplicatas com set (útil para ver níveis únicos)
    set<int> uniqueSignals(signalLevels, signalLevels + 8);

    cout << "Sinal -75 dBm encontrado? ";
    // Busca binária em conjunto ordenado (O(log n))
    cout << (binary_search(uniqueSignals.begin(), uniqueSignals.end(), -75) ? "Sim" : "Não") << "\n";

    // Ordena o deque para permitir uso de equal_range e outras buscas
    sort(signalDeque.begin(), signalDeque.end());

    // Adiciona novo valor de sinal medido no final do deque
    cout << "Adicionando sinal -85 dBm ao deque...\n";
    signalDeque.push_back(-85);

    // Localiza todos os valores iguais a -85 dBm
    auto range = equal_range(signalDeque.begin(), signalDeque.end(), -85);

    cout << "Sinais com -85 dBm: ";
    for_each(range.first, range.second, printer);
    cout << endl;

    // exibe sinais acima de -80 dBm (melhores)
    auto thresholdIt = upper_bound(signalDeque.begin(), signalDeque.end(), -80);
    cout << "Sinais acima de -80 dBm (melhores): ";
    for_each(thresholdIt, signalDeque.end(), printer);
    cout << endl;

    return 0;
}
