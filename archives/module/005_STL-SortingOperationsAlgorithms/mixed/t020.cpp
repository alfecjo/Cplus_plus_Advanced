#include <deque>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// class que representa uma medição digital do sensor
class Pocket
{
  int value;

public:
  Pocket(int value) : value(value) {}

  int getValue() const {
    return value;
  }

  // Operador < para comparação crescente
  bool operator<(const Pocket& _Right) const {
    return value < _Right.value;
  }

  // Operador > para comparação decrescente (útil para sort com greater)
  bool operator>(const Pocket& _Right) const {
    return value > _Right.value;
  }
};

// Operador para imprimir objetos Pocket
ostream& operator<<(ostream& stream, const Pocket& pocket) {
  stream << pocket.getValue();
  return stream;
}

// Função para imprimir um Pocket na saída padrão
void printer(Pocket i) {
  cout << i << ", ";
}

int main() {
  // valores simulados de medições digitais de sensor
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

  // inserção das medições no deque
  deque<Pocket> d1(mynumbers, mynumbers + 7);

  // simula uma nova medição chegando (valor 3)
  d1.push_back(3);

  // Ordenar as medições em ordem decrescente (do maior para o menor)
  sort(d1.begin(), d1.end(), greater<Pocket>()); 

  // Buscar o intervalo de medições que têm valor igual a 3
  pair<deque<Pocket>::iterator, deque<Pocket>::iterator> result = 
      equal_range(d1.begin(), d1.end(), Pocket(3), greater<Pocket>()); 

  // Imprimir todas as medições iguais a 3 encontradas
  cout << "Medições com valor 3 encontradas:\n";
  for_each(result.first, result.second, printer);
  cout << "\n";

  return 0;
}
