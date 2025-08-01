#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Compare {
    bool operator()(int a) const {
        return a > 0;
    }
};

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2 };
    vector<int> v(mynumbers, mynumbers + 12);

    int count = std::count_if(v.begin(), v.end(), Compare());  // Usa count_if com o predicado
    cout << count << endl;
    return 0;
}
