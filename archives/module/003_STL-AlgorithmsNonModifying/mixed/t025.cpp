#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class A {
  int a;
public:
  A(int a) : a(a) {}

  int getA() const { return a; }
  void setA(int a) { this->a = a; }

  bool operator==(const A& other) const {
    return a == other.a;
  }
};

// Comparador personalizado para buscar elementos iguais pelo valor interno `a`
struct Equals {
  bool operator()(const A& a1, const A& a2) {
    return a1.getA() == a2.getA();  // LINE I
  }
};

int main() {
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2 };
  
  // Criar deque de objetos A
  deque<A> d;
  for (int i = 0; i < 12; ++i) {
    d.push_back(A(mynumbers[i]));
  }

  // Procurar 2 elementos consecutivos iguais a A(1)
  deque<A>::iterator it = search_n(d.begin(), d.end(), 2, A(1), Equals());  // LINE II

  if (it != d.end()) {
    cout << "Found at position: " << it - d.begin() << endl;  // LINE III
  } else {
    cout << "Not found" << endl;
  }

  return 0;
}
