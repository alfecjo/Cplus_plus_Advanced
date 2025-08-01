#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
    vector<int> v(mynumbers, mynumbers + 7);
    vector<int>::iterator it;
    int m1[] = {9, 0, 2};
    it = find_end(v.begin(), v.end(), m1, m1 + 3); // LINE I
    if (it != v.end())
        cout << "Found at position: " << it - v.begin() << endl;
    return 0;
}
