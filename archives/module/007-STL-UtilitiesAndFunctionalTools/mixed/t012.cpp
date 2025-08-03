#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
    vector<int> v1(mynumbers, mynumbers + 7);
    vector<int> v2(7);

    // Transformando v1 em v2 com lambda:
    // Se o valor for 3, converte para 6, senão multiplica por 2
    transform(v1.begin(), v1.end(), v2.begin(), [](int val)
              {
        if (val == 3)
            return 6;
        else
            return 2 * val; }); 

    // Busca o valor 6 em v2
    auto it = find(v2.begin(), v2.end(), 6);
    if (it != v2.end())
    {
        cout << *it << endl; // imprime 6
    }
    else
    {
        cout << "6 not found" << endl;
    }

    return 0;
}
