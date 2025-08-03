#include <vector>
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
    vector<int> v1(mynumbers, mynumbers + 7);
    vector<int> v2(7);

    // Usando lambda para aplicar a operação (-1 + x)
    transform(v1.begin(), v1.end(), v2.begin(),
              [](int x)
              { return -1 + x; }); // Equivalente a bind1st(Add(), -1)

    for_each(v2.rbegin(), v2.rend(), printer);
    return 0;
}
