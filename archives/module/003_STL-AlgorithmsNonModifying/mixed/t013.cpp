#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2 };
    deque<int> d(mynumbers, mynumbers + 12);

    int count6 = count(d.begin(), d.end(), 6);  // LINE I

    cout << count6 << endl;

    return 0;
}
