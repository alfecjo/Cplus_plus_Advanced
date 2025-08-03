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

    // Aplica lambda: v2[i] = -1 + v1[i]
    transform(v1.begin(), v1.end(), v2.begin(),
              [](int value)
              { return -1 + value; });

    for_each(v2.rbegin(), v2.rend(), printer);

    return 0;
}
