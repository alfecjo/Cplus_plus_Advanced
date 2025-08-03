#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

/*
  Algoritmos de ordenação e busca aplicados a coleções (sequências)
  - Este exemplo demonstra como aplicar operações de ordenação (`sort`)
    e de busca (`includes`) sobre coleções como `deque`, que podem representar
    buffers circulares usados em sistemas embarcados ou de telecomunicações.
  - Tais buffers são usados frequentemente para armazenar amostras de sinais
    ou pacotes de dados em sistemas em tempo real.
*/

// para imprimir uma coleção
template <class T>
void print(T start, T end) {
  for (; start != end; ++start) {
    cout << *start << " ";
  }
}

// para ordenar em ordem decrescente
int compare(int a, int b) {
  return b < a;
}

//  para exibir mensagem baseada no resultado da busca
void printMessage(bool value) {
  if (value) {
    cout << "A coleção d1 contém todos os elementos da coleção d2!\n";
  } else {
    cout << "A coleção d1 NÃO contém todos os elementos da coleção d2!\n";
  }
}

int main() {
  // Suponha que estas sequências representem amostras coletadas em buffers
  int t1[] = {1, 10, 3, 4, 6, 8, 9, 2, 5, 7};  // Ex: buffer de amostras
  int t2[] = {8, 4, 5, 6};                    // Subconjunto a ser verificado

  // Inicializando deques com os dados dos arrays
  deque<int> d1(t1, t1 + 10);
  deque<int> d2(t2, t2 + 4);

  cout << "Coleções de origem:\n";
  cout << "d1: ";
  print(d1.begin(), d1.end());
  cout << endl;
  cout << "d2: ";
  print(d2.begin(), d2.end());
  cout << endl;

  cout << "Tentando realizar busca com coleções não ordenadas:\n";
  // includes exige coleções ordenadas — este uso pode causar comportamento indefinido
  printMessage(includes(d1.begin(), d1.end(), d2.begin(), d2.end()));
  cout << endl;

  cout << "Ordenação é necessária - ordem crescente:\n";
  sort(d1.begin(), d1.end());  // Ordenando d1
  sort(d2.begin(), d2.end());  // Ordenando d2
  cout << "d1: ";
  print(d1.begin(), d1.end());
  cout << endl;
  cout << "d2: ";
  print(d2.begin(), d2.end());
  cout << endl;
  cout << "Executando busca:\n";
  printMessage(includes(d1.begin(), d1.end(), d2.begin(), d2.end()));
  cout << endl;

  cout << "Ordenação é necessária - ordem decrescente:\n";
  sort(d1.begin(), d1.end(), compare);
  sort(d2.begin(), d2.end(), compare);
  cout << "d1: ";
  print(d1.begin(), d1.end());
  cout << endl;
  cout << "d2: ";
  print(d2.begin(), d2.end());
  cout << endl;
  cout << "Executando busca:\n";
  printMessage(includes(d1.begin(), d1.end(), d2.begin(), d2.end(), compare));
  cout << endl;

  return 0;
}
