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

    // Substituindo bind1st(ptr_fun(Add()), 1) por lambda:
    transform(v1.begin(), v1.end(), v2.begin(), [](int right)
              {
                  return 1 + right; // equivalente a Add(1, right)
              });

    for_each(v2.begin(), v2.end(), printer);

    return 0;
}
