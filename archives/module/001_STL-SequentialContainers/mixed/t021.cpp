#include <vector>
#include <iostream>

using namespace std;

// Template para imprimir um intervalo
template <typename T>
ostream & print (const T & start, const T & end)
{
  T tmp = start;
  for (; tmp != end; ++tmp)
  {
    cout << *tmp << " ";    // imprime objeto com operator<<
  }
  return cout;
}

// Classe A com um campo 'a' e construtor
class A
{
public:
  int a;
  A(int a): a(a) {}
};

// Corrigido: parâmetros do operator<< devem ser (ostream&, const A&)
ostream & operator<< (ostream &c, const A &o)
{
  c << o.a;
  return c;
}

int main()
{
  int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  // Criando um vetor de objetos A usando o array de inteiros
  vector<A> v1;
  for (int i = 0; i < 10; ++i)
  {
    v1.push_back(A(tab[i]));
  }

  // Imprime os elementos de v1
  print(v1.begin(), v1.end()) << endl;

  return 0;
}
