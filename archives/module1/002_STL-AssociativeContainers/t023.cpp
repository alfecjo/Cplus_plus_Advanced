#include <iostream>
#include <map>
#include <string>
using namespace std;

// class A com comparação para poder ser usada como chave...
class A {
  int a;
public:
  A(int a): a(a) {}

  int getA() const {
    return a;
  }

  // operador < necessário para multimap ordenar os objetos de A
  bool operator<(const A& other) const {
    return this->a < other.a;
  }
};

int main() {
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
  string words[]   = { "three", "nine", "zero", "two", "one", "four", "five" };

  multimap<A, string> m;

  // Inserindo pares no multimap
  for (int i = 0; i < 7; i++)
    m.insert(pair<A, string>(A(mynumbers[i]), words[i]));

  // removendo todos os pares com chaves entre 2 (inclusive) e 5 (exclusivo)
  // Nota para exclarecer: isso depende da comparação implementada no operador <
  m.erase(m.lower_bound(A(2)), m.upper_bound(A(5)));

  // imprimindo os valores restantes
  for (auto it = m.begin(); it != m.end(); ++it)
    cout << it->second << ", ";

  cout << endl;

  return 0;
}
