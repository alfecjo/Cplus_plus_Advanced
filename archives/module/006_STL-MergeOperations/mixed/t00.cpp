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
    int mynumbers1[] = {3, 9, 0, 2};
    int mynumbers2[] = {6, 1, 4, 5};

    // O vetor v1 precisa ter tamanho igual à soma dos tamanhos dos dois arrays: 4 + 4 = 8
    vector<int> v1(8);

    // Ordenando os dois arrays separadamente
    sort(mynumbers1, mynumbers1 + 4); // mynumbers1: 0 2 3 9
    sort(mynumbers2, mynumbers2 + 4); // mynumbers2: 1 4 5 6

    // Merge das duas sequências ordenadas no vetor v1
    merge(mynumbers1, mynumbers1 + 4,
          mynumbers2, mynumbers2 + 4,
          v1.begin());

    // Imprimindo resultado
    for_each(v1.begin(), v1.end(), printer);
    cout << endl;

    return 0;
}
