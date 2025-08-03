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

    vector<int> v1(8); // 4 de cada array
    vector<int> v2(8); // resultado da fusão

    sort(mynumbers1, mynumbers1 + 4);
    sort(mynumbers2, mynumbers2 + 4);

    // copiando 4 de cada um
    copy(mynumbers1, mynumbers1 + 4, v1.begin());
    copy(mynumbers2, mynumbers2 + 4, v1.begin() + 4); // imediatamente após os 4 anteriores

    sort(v1.begin(), v1.end()); // ordenar os 8 elementos juntos

    // dividir ao meio para fusão: metade 1 e metade 2
    merge(v1.begin(), v1.begin() + 4, v1.begin() + 4, v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), printer); // mostrar v2
    cout << endl;

    return 0;
}

