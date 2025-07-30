#include <vector>
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

class A
{
public:
    int a;
    A(int a) : a(a) {}
};

ostream& operator<<(ostream& c, const A& o)
{
    c << o.a;
    return c;
}

int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    
    vector<A> v1;
    for (int i = 0; i < 10; ++i)
    {
        v1.push_back(A(tab[i]));
    }

    print(v1.begin(), v1.end()) << endl;

    return 0;
}
