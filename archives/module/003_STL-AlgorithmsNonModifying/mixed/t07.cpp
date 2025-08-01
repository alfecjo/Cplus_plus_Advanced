#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class A
{
  int a;

public:
  A(int a) : a(a) {}

  int getA() const
  {
    return a;
  }

  bool operator==(const A &b) const
  {
    return a == b.a;
  }
};

struct Comparer
{
  bool operator()(const A &a, const A &b) const
  {
    return a.getA() == b.getA();
  }
};

int main()
{
  int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
  vector<A> v(mynumbers, mynumbers + 7);

  A m1[] = {A(2), A(3), A(4)};

  auto it = find_end(v.begin(), v.end(), m1, m1 + 3, Comparer());

  if (it != v.end())
    cout << "Found at position: " << it - v.begin() << endl;
  else
    cout << "Not found" << endl;

  return 0;
}
