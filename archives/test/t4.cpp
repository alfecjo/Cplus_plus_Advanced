#include <deque>
#include <iostream>

using namespace std;

// aceita iteradores por valor: print(T start, T end)
// e não por referência: print(T & start, T & end), para permitir rbegin()/rend()...
// se não, haveria erro em // LINE II
template <typename T>
ostream& print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
    return cout;
}

int main()
{
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> d1(tab, tab + 10);
    deque<int> d2;
    deque<int>::iterator it;

    for (it = d1.begin(); it != d1.end(); ++it)
    {
        // transfere os elementos de d1 para d2 em ordem invertida
        d2.push_back(d1[d1.end() - it - 1]); // LINE I
    }

    // imprime d2 de trás para frente, resultando na mesma ordem original de d1
    print(d2.rbegin(), d2.rend()) << endl; // LINE II

    return 0;
}
