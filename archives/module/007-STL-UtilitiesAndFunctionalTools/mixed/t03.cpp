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
    int mynumbers1[] = {3, 9, 0, 2, 1, 4, 5};
    int mynumbers2[] = {9, 0, 2, 1, 4, 5, 3};

    vector<int> v1(mynumbers1, mynumbers1 + 7);
    vector<int> v2(mynumbers1, mynumbers1 + 7);
    vector<int> v3(mynumbers2, mynumbers2 + 7); // v3 será sobrescrita

    // Subtraindo cada elemento de v1 com o elemento correspondente em v2.rbegin()
    transform(
        v1.begin(), v1.end(), // 1ª sequência
        v2.rbegin(),          // 2ª sequência (reversa)
        v3.begin(),           // saída
        [](int a, int b)
        { return a - b; } // lambda que substitui minus<int>()
    );

    for_each(v3.rbegin(), v3.rend(), printer); // imprime v3 de trás para frente

    return 0;
}
