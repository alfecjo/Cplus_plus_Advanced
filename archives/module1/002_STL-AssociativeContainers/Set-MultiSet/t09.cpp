#include <iostream>
#include <set>
#include <functional>   // set já inclui <functional>, mas é uma boa prática incluí-lo
                        // explicitamente quando se usa comparadores personalizados

using namespace std;

int main()
{

    set<int> valuesAscending = {-1, 5, -3, 2};
    set<int, greater<int>> valuesDescending = {-1, 5, -3, 2};

    valuesAscending.insert(10);
    valuesDescending.insert(10);
    valuesAscending.erase(-3);
    valuesDescending.erase(-3);
    valuesAscending.insert(0);
    valuesDescending.insert(0);

    for (auto value : valuesAscending)
        cout << value << " ";
    cout << endl;

    for (auto value : valuesDescending)
        cout << value << " ";
    cout << endl;

    return 0;
}
