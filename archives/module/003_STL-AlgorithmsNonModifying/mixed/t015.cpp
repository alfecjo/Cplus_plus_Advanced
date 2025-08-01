#include <iostream>
#include <algorithm>
#include <set>
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

    void setA(int a)
    {
        this->a = a;
    }

    bool operator<(const A &b) const
    {
        return a < b.a;
    }
};

struct Compare
{
    bool operator()(const A &a) const
    {
        return a.getA() < 6;
    }
};

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2};

    // Criar um vetor de A para inicializar o set
    vector<A> v;
    for (int i = 0; i < 12; i++)
    {
        v.push_back(A(mynumbers[i]));
    }

    set<A> d(v.begin(), v.end());

    int count = count_if(d.begin(), d.end(), Compare());

    cout << count << endl;

    return 0;
}
