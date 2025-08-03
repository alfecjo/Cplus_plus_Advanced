#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

int main() {
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(t) / sizeof(t[0]);

    // ---------- COPY ----------
    cout << "=== std::copy ===\n";

    vector<int> v1(t, t + n);
    deque<int> d1(n); // destino com espaço reservado

    cout << "Source collection:\n";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << "\n";

    cout << "Target collection before copy:\n";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << "\n";

    copy(v1.begin(), v1.end(), d1.begin());

    cout << "Target collection after copy:\n";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << "\n\n";

    // ---------- COPY_BACKWARD ----------
    cout << "=== std::copy_backward ===\n";

    vector<int> v2(t, t + n);
    deque<int> d2(n);

    cout << "Source collection:\n";
    for_each(v2.begin(), v2.end(), print<int>);
    cout << "\n";

    cout << "Target collection before copy_backward:\n";
    for_each(d2.begin(), d2.end(), print<int>);
    cout << "\n";

    copy_backward(v2.begin(), v2.end(), d2.end());

    cout << "Target collection after copy_backward:\n";
    for_each(d2.begin(), d2.end(), print<int>);
    cout << "\n";

    return 0;
}
