#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 2, 2, 5 };
    vector<int> v(mynumbers, mynumbers + 7);
    vector<int>::iterator it = v.begin();

    while ((it = adjacent_find(it, v.end())) != v.end()) {  // LINE I
        cout << it - v.begin() << ", ";
        it--;  // loop infinito
        // it++; incrementa o iterador para evitar loop infinito
    }

    cout << endl;
    return 0;
}
