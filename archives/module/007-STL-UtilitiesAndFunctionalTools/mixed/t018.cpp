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

  // Operador + para somar dois Pocket
  Pocket operator+(const Pocket &other) const
  {
    return Pocket(value + other.value);
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

  // Usando lambda para somar Pocket(0) a cada elemento (equivale ao bind2nd com Add e 0)
  transform(v1.begin(), v1.end(), v2.begin(),
            [](const Pocket &p)
            {
              return p + Pocket(0);
            }); 

  for_each(v2.rbegin(), v2.rend(), printer);

  return 0;
}
