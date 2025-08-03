#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Pocket
{
  int value;

public:
  Pocket(int value) : value(value) {}

  int getValue() const
  {
    return value;
  }

  operator int() const
  {
    return value;
  }

  bool operator<(const Pocket &_Right) const
  {
    return value < _Right.value;
  }

  Pocket operator+(int rhs) const
  {
    return Pocket(value + rhs);
  }
};

ostream &operator<<(ostream &stream, const Pocket &pocket)
{
  stream << pocket.getValue();
  return stream;
}

void printer(Pocket i) 
{
  cout << i << ", ";
}

int main()
{
  Pocket mynumbers1[] = {3, 9, 0, 2, 1, 4, 5};

  vector<Pocket> v1(mynumbers1, mynumbers1 + 7);
  vector<Pocket> v2(7, Pocket(0));

  // Usando lambda para somar 1 a cada Pocket (substituindo Add e bind2nd)
  transform(v1.begin(), v1.end(), v2.begin(),
            [](const Pocket &p)
            {
              return p + 1; // chama operator+(int)
            });             

  for_each(v2.rbegin(), v2.rend(), printer);

  return 0;
}
