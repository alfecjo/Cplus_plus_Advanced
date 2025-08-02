#include <list>
#include <iostream>

using namespace std;

// Função template para imprimir elementos de uma sequência entre iteradores start e end
template <typename T>
ostream& print(const T& start, const T& end) {
  T tmp = start;
  for (; tmp != end; ++tmp) {
    cout << *tmp << " ";  // imprime o valor apontado pelo iterador
  }
  return cout;
}

class A {
public:
  int a;

  // Construtor que inicializa o atributo a
  A(int a) : a(a) {}
};

// Sobrecarga do operador << para imprimir objetos do tipo A
ostream& operator<<(ostream& c, const A& o) {
  c << o.a;
  return c;
}

int main() {
  int tab[] = { 1,2,3,4,5,6,7,8,9,10 };

  // Cria lista l1 de objetos A a partir dos valores do array tab
  list<A> l1(tab, tab + 10);

  // Lista vazia l2 para armazenar os elementos de l1 em ordem invertida
  list<A> l2;

  // Iterador para percorrer a lista l1
  list<A>::iterator it;

  for (it = l1.begin(); it != l1.end(); ++it) {
    // Erro original: você estava inserindo o iterador 'it' em vez do objeto *it
    // Correção: inserir o objeto apontado pelo iterador (it) usando *it
    l2.push_front(*it);
  }

  // Imprime os elementos da lista l2
  print(l2.begin(), l2.end()) << endl;

  return 0;
}
