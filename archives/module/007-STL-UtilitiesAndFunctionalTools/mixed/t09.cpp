#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int Mul(int &_Left)
{
    return 2 * _Left;
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);
    vector<int> v2(7);

    // Substitui ptr_fun(Mul) por lambda equivalente
    transform(v1.begin(), v1.end(), v2.begin(), [](int x)
              { return 2 * x; });

    // Substitui bind2nd(equal_to<int>(), 7) por lambda
    auto it = find_if(v2.begin(), v2.end(), [](int x)
                      { return x == 7; });

    if (it != v2.end())
        cout << *it << endl;
    else
        cout << "Valor 7 não encontrado" << endl;

    return 0;
}
