#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class A
{
  int a;
public:
  A(int a) : a(a) {}

  int getA() const { return a; }
  void setA(int a) { this->a = a; }

  bool operator==(A &b) { return a == b.a; }
};

struct Compare
{
  bool operator()(const A &a, const A &b)
  {
    return a.getA() == b.getA();
  }
};

int main()
{
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
  vector<A> v(mynumbers, mynumbers + 7);
  vector<A>::iterator it;
  A m1[] = { A(2), A(3), A(4) };

  it = search(v.begin(), v.end(), m1, m1 + 3, Compare());  // LINE I

  cout << "First found at position: " << it - v.begin() << endl;  // LINE II
  return 0;
}
