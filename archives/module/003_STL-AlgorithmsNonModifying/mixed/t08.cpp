#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    vector<int> v(mynumbers, mynumbers + 7);
    vector<int>::iterator it;
    int m1[] = { 9, 0, 2 };
    it = find_first_of(v.begin(), v.end(), m1, m1 + 3);    // LINE I
    cout << "First found at position: " << it - v.begin() << endl;    // LINE II
    return 0;
}
