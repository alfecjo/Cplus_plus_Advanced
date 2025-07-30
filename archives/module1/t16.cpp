#include <vector>
#include <iostream>

using namespace std;

template <typename T>
ostream& print(T start, T end) {
    for (; start != end; ++start) {
        cout << *start << " ";
    }
    return cout;
}

int main() {
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v1(tab, tab + 10);
    vector<int> v2;

    // Copiando v1 para v2 em ordem inversa
    for (auto rit = v1.rbegin(); rit != v1.rend(); ++rit) {
        v2.push_back(*rit);
    }

    print(v2.begin(), v2.end()) << endl;

    return 0;
}
