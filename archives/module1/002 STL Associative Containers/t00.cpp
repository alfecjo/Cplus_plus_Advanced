#include <iostream>
#include <set>
#include <vector>
#include <functional> // para greater<int>

using namespace std;

int main ()
{
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    vector<int> v(mynumbers, mynumbers + 7);

    set<int> set1(v.begin(), v.end());

    set<int, greater<int>> set2(v.begin(), v.end()); // ordenação decrescente

    for (set<int, greater<int>>::iterator i = set2.begin(); i != set2.end(); ++i)
        cout << *i << " ";

    //cout << endl;

    for (set<int>::iterator i = set1.begin(); i != set1.end(); ++i)
        cout << *i << ", ";

    cout << endl;

    return 0;
}
