#include <deque>
#include <iostream>

using namespace std;

template <typename Iterator>
ostream& print(Iterator start, Iterator end)
{
  for (; start != end; ++start)
  {
    cout << *start << " ";
  }
  return cout;
}

int main ()
{
  int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  deque<int> d1(tab, tab + 10);
  deque<int> d2;
  deque<int>::iterator it;

  for (it = d1.begin(); it != d1.end(); ++it)
  {
    int idx = it - d1.begin();
    d2.push_back(d1[d1.size() - 1 - idx]);  // acessa do fim para o início
  }

  print(d2.begin(), d2.end()) << endl;  // imprime d2 do começo ao fim
  return 0;
}

