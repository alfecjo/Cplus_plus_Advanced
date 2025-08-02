#include <list>
#include <iostream>
#include <iterator>  // para std::advance

using namespace std;

template <typename T>
ostream& print(T const& start, T const& end)
{
  for (T i = start; i != end; ++i)
  {
    cout << *i << " ";
  }
  return cout;
}

int main()
{
  int tab[] = {1,2,3,4,5,6,7,8,9,10};
  list<int> l1(tab, tab + 10);

  auto it = l1.begin();
  advance(it, 3);            // avança o iterador 3 posições (posição do elemento 4)

  auto it2 = it;
  advance(it2, 1);           // it2 aponta para a próxima posição após it

  l1.erase(it, it2);         // apaga o elemento na posição 3 (o '4')

  print(l1.begin(), l1.end()) << endl;

  l1.clear();                // limpa toda a lista

  cout << l1.size() << endl; // imprime 0 pois lista está vazia

  return 0;
}
