#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

  // Inicializa um vector com os números
  vector<int> v(mynumbers, mynumbers + 7);

  // Cria um set com os elementos do vector
  set<int> s1(v.begin(), v.end());

  // Insere os mesmos elementos novamente (sem efeito, pois set não permite duplicados)
  s1.insert(v.begin(), v.end());

  // Insere um novo elemento
  s1.insert(10);

  // Remove os elementos entre 4 (inclusive) e 6 (exclusive)
  s1.erase(s1.lower_bound(4), s1.upper_bound(6));

  // Insere os mesmos elementos novamente (sem efeito, pois set não permite duplicados)
  s1.insert(v.begin(), v.end());

  // Itera e imprime os elementos restantes
  for (set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
    cout << *i << ", ";

  cout << endl;

  return 0;
}
