#include <iostream>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

// Classe para representar um nível de sinal em dBm
class SignalLevel {
    int value; // nível de sinal em dBm

public:
    SignalLevel(int v) : value(v) {}

    int getValue() const { return value; }

    // Operador para ordenação em containers ordenados
    bool operator<(const SignalLevel& other) const {
        return value < other.value;
    }

    // Operador para comparação de igualdade (necessário para busca)
    bool operator==(const SignalLevel& other) const {
        return value == other.value;
    }
};

// Operador para imprimir níveis de sinal
ostream& operator<<(ostream& os, const SignalLevel& s) {
    os << s.getValue() << " dBm";
    return os;
}

// Função para imprimir elementos genéricos
template<typename T>
void print(const T& val) {
    cout << val << " ";
}

int main() {
    // Simulação de níveis de sinal medidos (pode conter repetidos)
    int raw_signals[] = {-70, -65, -80, -70, -75, -60, -65, -85};

    // 1. Armazenar sinais únicos em um conjunto ordenado (set) — elimina repetidos
    set<SignalLevel> unique_signals(raw_signals, raw_signals + 8);

    cout << "Níveis de sinal únicos (ordenados): ";
    for_each(unique_signals.begin(), unique_signals.end(), print<SignalLevel>);
    cout << "\n\n";

    // 2. Verificar se um nível específico foi medido (busca binária no set)
    SignalLevel query(-70);
    bool found = binary_search(unique_signals.begin(), unique_signals.end(), query);
    cout << "Nível " << query << (found ? " foi medido.\n\n" : " não foi medido.\n\n");

    // 3. Usar deque para armazenar todos os sinais, incluindo repetidos
    deque<SignalLevel> all_signals(raw_signals, raw_signals + 8);

    // 4. Ordenar o deque para permitir operações de busca e intervalo
    sort(all_signals.begin(), all_signals.end());

    cout << "Todos os sinais ordenados (com repetidos): ";
    for_each(all_signals.begin(), all_signals.end(), print<SignalLevel>);
    cout << "\n\n";

    // 5. Encontrar o intervalo dos sinais iguais a -65 dBm usando equal_range
    SignalLevel target(-65);
    auto range = equal_range(all_signals.begin(), all_signals.end(), target);

    cout << "Intervalo de sinais iguais a " << target << ": ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 6. Contar quantos sinais iguais a -65 dBm foram medidos
    int count_65 = distance(range.first, range.second);
    cout << "Quantidade de medições em " << target << ": " << count_65 << "\n";

    return 0;
}
