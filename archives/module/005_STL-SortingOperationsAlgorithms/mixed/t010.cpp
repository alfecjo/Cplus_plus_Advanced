#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip> // Para formatar saída

using namespace std;

class Bit {
  int value;

public:
  Bit(int value = 0) : value(value % 2) {}

  int getValue() const {
    return value;
  }

  bool operator<(const Bit& other) const {
    return value < other.value;
  }

  bool operator!=(const Bit& other) const {
    return value != other.value;
  }

  friend ostream& operator<<(ostream& os, const Bit& b) {
    os << b.value;
    return os;
  }
};

// Função para imprimir um bit
void printer(Bit b) {
  cout << b << " ";
}

// Função que simula a introdução de erro com uma probabilidade
deque<Bit> transmitWithNoise(const deque<Bit>& original, double errorRate) {
  deque<Bit> received;
  for (Bit b : original) {
    double r = (double)rand() / RAND_MAX;
    if (r < errorRate) {
      // Introduz erro invertendo o bit
      received.push_back(Bit(!b.getValue()));
    } else {
      received.push_back(b);
    }
  }
  return received;
}

int main() {
  srand(time(0)); // Inicializa gerador de números aleatórios

  // Simulando bits transmitidos
  deque<Bit> transmitted;
  for (int i = 0; i < 20; ++i) {
    transmitted.push_back(Bit(rand() % 2));
  }

  // Transmite com 10% de erro
  double ber_simulado = 0.10;
  deque<Bit> received = transmitWithNoise(transmitted, ber_simulado);

  // Impressão dos sinais
  cout << "Transmitted: ";
  for_each(transmitted.begin(), transmitted.end(), printer);
  cout << "\nReceived:    ";
  for_each(received.begin(), received.end(), printer);

  // Calculando erros
  int errors = 0;
  for (size_t i = 0; i < transmitted.size(); ++i) {
    if (transmitted[i] != received[i]) {
      errors++;
    }
  }

  double ber = (double)errors / transmitted.size();
  cout << "\n\nTotal Errors: " << errors;
  cout << "\nBER (Bit Error Rate): " << fixed << setprecision(2) << ber * 100 << "%\n";

  return 0;
}
