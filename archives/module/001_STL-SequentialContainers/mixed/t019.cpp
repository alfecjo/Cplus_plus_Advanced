#include <vector>
#include <iostream>

using namespace std;

// Função de impressão de qualquer intervalo de iteradores
template <typename T>
ostream &print(T start, T end) {
  for (T i = start; i != end; ++i) {
    cout << *i << " ";
  }
  return cout;
}

int main() {
  int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> v1(tab, tab + 10);

  // Remover o elemento de índice 3 (o número 4)
  vector<int>::iterator it = v1.begin() + 3; // use iterator e não const_iterator
  v1.erase(it); // remove apenas um elemento

  print(v1.begin(), v1.end()); // imprime os elementos restantes
  cout << endl;

  // Verifica se está vazio e imprime o tamanho
  cout << "Está vazio? " << (v1.empty() ? "Sim" : "Não") << endl;
  cout << "Tamanho atual: " << v1.size() << endl;

  return 0;
}
