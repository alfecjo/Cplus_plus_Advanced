#include <map>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end) {
  while (start != end) {
    std::cout << start->first << ":" << start->second << " ";
    start++;
  }
}

template <class T, class U>
void fillMap(map<T, T>& m, U start, U end) {
  for (; start != end; ++start) {
    m.insert(pair<T, T>(*start, *start)); // chave e valor são iguais
  }
}

int main() {
  int t[] = { 16, 10, 8, 40, 6, 15, 3, 9, 7, 2 };
  
  //  map de inteiros
  map<int, int> m1;

  // Preenche o map com os valores do vetor
  fillMap(m1, t, t + 10);
  print(m1.begin(), m1.end());
  cout << endl << endl;

  // Remove um elemento usando o iterador da chave 15
  cout << "Removing element from a certain position (iterator):\n";
  map<int, int>::iterator it = m1.find(15);
  if (it != m1.end())
    m1.erase(it); // remove {15, 15}
  print(m1.begin(), m1.end());
  cout << endl << endl;

  // Remove um elemento específico pela chave
  cout << "Removing certain value (9) from the map:\n";
  m1.erase(9); // remove {9, 9} se existir
  print(m1.begin(), m1.end());
  cout << endl << endl;

  // Remove um intervalo de elementos: de 10 até o fim
  cout << "Removing range of iterators:\n";
  m1.erase(m1.find(10), m1.end()); // remove do 10 até o último
  print(m1.begin(), m1.end());
  cout << endl << endl;

  // Remove todos os elementos do map
  cout << "Removing all the elements from the map\n";
  m1.clear(); // limpa o map
  cout << "M1 size: " << m1.size() << endl; // imprime tamanho final (0)

  return 0;
}
