#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class A
{
    int a;

public:
    A(int a) : a(a)
    {
    }

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
    } // LINE I
};

struct Compare
{
    bool operator()(A a)
    {
        return (a.getA() < 6);
    }
};


    int
    main()
    {
        int mynumbers[] = {3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2};
        set<A> d(mynumbers, mynumbers + 12);
        int count = count_if(d.begin(), d.end(), Compare()); // LINE II
        cout << count << endl;
        return 0;
    }
