#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Pocket
{
    int value;

public:
    Pocket(int value) : value(value) {}

    int getValue() const { return value; }

    operator int() const { return value; }

    bool operator<(const Pocket &_Right) const
    {
        return value < _Right.value;
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
    Pocket mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
    vector<Pocket> v1(mynumbers, mynumbers + 7);

    // Usando lambda para somar 1 a cada Pocket, modificando o vetor
    for_each(v1.begin(), v1.end(), [](Pocket &p)
             { p = Pocket(p.getValue() + 1); }); 

    for_each(v1.rbegin(), v1.rend(), printer);

    return 0;
}
