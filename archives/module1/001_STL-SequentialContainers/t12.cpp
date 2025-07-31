#include <list>
#include <iostream>

using namespace std;

template <typename T>
ostream & print(const T &start, const T &end)
{
  T tmp = start;
  for (; tmp != end; ++tmp)
  {
    cout << *tmp << " ";
  }
  return cout;
}

class A
{
public:
  int a;
  A(int a) : a(a) {}
};

ostream & operator<< (ostream & c, const A & o)
{
  c << o.a;
  return c;
}

int main()
{
  int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  // Corrigido: transformar cada int em A
  list<A> l1;
  for (int i : tab)
    l1.push_back(A(i));

  list<A> l2;
  for (list<A>::iterator it = l1.begin(); it != l1.end(); ++it)
  {
    l2.push_front(*it);  // Corrigido: inserir o objeto apontado, não o iterador
  }

  print(l2.begin(), l2.end()) << endl;
  return 0;
}
