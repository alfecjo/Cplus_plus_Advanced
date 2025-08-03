#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class SignalLevel {
  int dBm; // nível do sinal em decibéis miliwatts

public:
  SignalLevel(int dBm) : dBm(dBm) {}

  int getValue() const { return dBm; }

  // comparador para ordenação crescente
  bool operator<(const SignalLevel& other) const {
    return dBm < other.dBm;
  }
};

ostream& operator<<(ostream& os, const SignalLevel& s) {
  os << s.getValue() << " dBm";
  return os;
}

void printer(const SignalLevel& s) {
  cout << s << ", ";
}

int main() {
  // simulando leituras de sinal de sensores em um sistema embarcado
  int raw_measurements[] = { -70, -85, -60, -90, -75, -65, -88, -60, -70 };

  // armazenando sinais em deque
  deque<SignalLevel> signals(raw_measurements, raw_measurements + sizeof(raw_measurements)/sizeof(int));

  // ordena os sinais (crescente: sinal mais fraco para mais forte)
  sort(signals.begin(), signals.end());

  cout << "Níveis de sinal ordenados (mais fraco -> mais forte):\n";
  for_each(signals.begin(), signals.end(), printer);
  cout << "\n\n";

  // Cria um set com os sinais únicos (ordenado automaticamente)
  set<SignalLevel> uniqueSignals(signals.begin(), signals.end());

  // verifica se um sinal de -75 dBm está presente usando binary_search no set
  bool found75 = binary_search(uniqueSignals.begin(), uniqueSignals.end(), SignalLevel(-75));

  cout << "Sinal -75 dBm " << (found75 ? "encontrado" : "não encontrado") << " no conjunto de sinais únicos.\n";

  // Usa equal_range para obter o intervalo de sinais iguais a -60 dBm no deque
  auto range = equal_range(signals.begin(), signals.end(), SignalLevel(-60));

  cout << "Ocorrências do sinal -60 dBm: ";
  for_each(range.first, range.second, printer);
  cout << "\n\n";

  // Filtra e imprime sinais considerados fracos (abaixo de -80 dBm)
  cout << "Sinais fracos (abaixo de -80 dBm): ";
  for (const auto& s : signals) {
    if (s.getValue() < -80)
      cout << s << ", ";
  }
  cout << "\n";

  return 0;
}
