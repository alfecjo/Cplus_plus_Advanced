#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2};
    vector<int> v1(mynumbers, mynumbers + 12);
    set<int> s1(mynumbers, mynumbers + 12);
    v1.push_back(10);                                                                                       // LINE I
    pair<set<int>::iterator, vector<int>::iterator> resultSet = mismatch(s1.begin(), s1.end(), v1.begin()); // LINE II
    cout << *resultSet.first << ", " << *resultSet.second << endl;                                          // LINE III

    return 0;
}
