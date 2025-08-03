#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l1 = {1, 2, 3, 4, 5};
    list<int> l2(l1.size());

    cout << "Source collection:\n";
    cout << "l1: ";
    print(l1.begin(), l1.end());

    cout << "Adicionando 10 a cada elemento usando lambda\n";

    // alternativa moderna com lambda:
    transform(l1.begin(), l1.end(), l2.begin(), [](int x)
              { return x + 10; });

    cout << "l1 + 10: ";
    print(l2.begin(), l2.end());

    return 0;
}
