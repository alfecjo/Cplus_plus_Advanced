#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

    bool operator<(const A &b) const
    {
        return a < b.a;
    }

    bool operator==(const A &b) const
    {
        return a == b.a;
    }
};

// Functor para buscar A com mesmo valor
class Founder
{
    A val;

public:
    Founder(const A &a) : val(a) {}

    bool operator()(const A &v) const
    {
        return v.getA() == val.getA();
    }
};

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<A> v1(mynumbers, mynumbers + 7); // LINE I
    set<A> s1(mynumbers, mynumbers + 7);

    A a(5);
    Founder f(a);

    // Usando find_if no vetor
    if (find_if(v1.begin(), v1.end(), f) != v1.end())
    { // LINE III
        cout << "Found!\n";
    }
    else
    {
        cout << "Not found!\n";
    }

    return 0;
}
