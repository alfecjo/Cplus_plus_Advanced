#include <list>
#include <iostream>

using namespace std;

template <typename T>
ostream & print(T start, T end)  // Removi o const para permitir iteração
{
  for (; start != end; ++start)
  {
    cout << *start << " ";
  }
  return cout;
}

int main()
{
  int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  list<int> l1(tab, tab + 10);
  list<int> l2;

  // Preenchendo l2 com os elementos de l1 em ordem inversa
  for (list<int>::reverse_iterator rit = l1.rbegin(); rit != l1.rend(); ++rit)
  {
    l2.push_back(*rit);
  }

  print(l2.begin(), l2.end()) << endl;
  return 0;
}
