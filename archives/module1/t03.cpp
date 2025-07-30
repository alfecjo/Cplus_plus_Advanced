#include <iostream>
#include <set>
#include <list>

using namespace std;

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 4 };

    
    list<int> v(mynumbers, mynumbers + 8);

    set<int> s1(v.begin(), v.end());

    if (s1.count(4) == 2) {
        s1.erase(4);
    }

    for (set<int>::iterator i = s1.begin(); i != s1.end(); i++) {
        cout << *i << ", ";
    }

    return 0;
}
