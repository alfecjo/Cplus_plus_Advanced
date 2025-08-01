#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Founder {
public:
    int val;
    Founder(int v) : val(v) {}
    bool operator()(int v) {
        return v == val;
    } // Functor para find_if
};

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    vector<int> v1(mynumbers, mynumbers + 7);

    // Usando find_if com functor
    auto it = find_if(v1.begin(), v1.end(), Founder(7));

    if (it != v1.end()) {
        cout << "Found!\n";
    } else {
        cout << "Not found!\n";
    }

    return 0;
}
