#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
    return a == b;
}

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    vector<int> v(mynumbers, mynumbers + 7);
    vector<int>::iterator it = v.begin();
    int m1[] = { 9, 0, 2 };

    while ((it = find_first_of(it, v.end(), m1, m1 + 3)) != v.end()) { // LINE I
        cout << it - v.begin() << ", ";                                // LINE II
        it++;
    }
    cout << endl;
    return 0;
}
