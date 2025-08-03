#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printer(double i)
{
    cout << i << ", ";
}

int main()
{
    int mynumbers1[] = {3, 9, 0, 2};
    int mynumbers2[] = {6, 1, 4, 5};

    vector<double> v1(8); // agora com tamanho correto

    sort(mynumbers2, mynumbers2 + 4);
    sort(mynumbers1, mynumbers1 + 4); // LINE I

    // merge corretamente com os 5 parâmetros
    merge(mynumbers1, mynumbers1 + 4, mynumbers2, mynumbers2 + 4, v1.begin()); // LINE II

    for_each(v1.begin(), v1.end(), printer);

    return 0;
}
