#include <iostream>
#include <set>
#include <vector>
using namespace std;

class A {
  int a;
public:
    A(int val) : a(val) {}

  // Getter, Java é filho de C++ kkk
  int getA() const { return a; }

  // sobrecarga no perador para permitir ordenação no set
  bool operator<(const A& other) const {
    return a < other.a;
  }
};

int main() {
  
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 6 };

  // cria vetor de objetos A
  vector<A> v(mynumbers, mynumbers + 8);

  // Cria set com os elementos do vetor (set n permite duplicatas)
  set<A> s1(v.begin(), v.end());  

  // Insere os mesmos elementos novamente (sem efeito no set)
  s1.insert(v.begin(), v.end());

  // remove elementos com valor entre 3 e 6 (exclusivo)
  // significa: retorna um iterador para o primeiro elemento >= 3 e
  // retorna um iterador para o primeiro elemento > 5...
  s1.erase(s1.lower_bound(A(3)), s1.upper_bound(A(5)));

  // Imprime os valores restantes no set
  for (set<A>::iterator i = s1.begin(); i != s1.end(); ++i)
    cout << i->getA() << " ";

  cout << endl;

  return 0;
}
