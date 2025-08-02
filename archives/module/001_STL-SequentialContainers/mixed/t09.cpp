#include <list>
#include <iostream>

using namespace std;

template <typename T>
ostream& print(const T& start, const T& end)
{
  T tmp = start;
  for (; tmp != end; ++tmp)
  {
    cout << *tmp << " ";
  }
  return cout;
}

int main()
{
  int tab[] = {1,2,3,4,5,6,7,8,9,10};
  
  list<int> l1(tab, tab + 10);
  list<int> l2;

  // Percorre l1 em ordem reversa e insere em l2 na ordem normal
  for (auto rit = l1.rbegin(); rit != l1.rend(); ++rit)
  {
    l2.push_back(*rit);
  }

  print(l2.begin(), l2.end()) << endl;

  return 0;
}
