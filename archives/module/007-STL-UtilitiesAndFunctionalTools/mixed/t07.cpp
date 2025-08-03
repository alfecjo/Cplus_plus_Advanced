#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    deque<int> d1(mynumbers, mynumbers + 7);
    deque<int> d2(7); 

    transform(
        d1.begin(), d1.end(), d2.begin(),
        [](int val)
        { return 2 * (val + 1); } // substitui bind2nd(MultiAdd(), 1)
    );                

    for_each(d2.begin(), d2.end(), printer);

    return 0;
}
