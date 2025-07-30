#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
ostream& print(const T& start, const T& end) {
    T tmp = start;
    for (; tmp != end; ++tmp) {
        cout << *tmp << " ";
    }
    return cout;
}

class A {
public:
    int a;
public:
    A(int a) : a(a) {}

    friend ostream& operator<<(ostream& c, const A& o) {
        c << o.a;
        return c;
    }
};

void fill(const int table[], unsigned size, vector<A*>& v) {
    for (unsigned i = 0; i < size; ++i) {
        v.push_back(new A(table[i]));
    }
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<A*> v1;
    fill(tab, 10, v1);

    list<A> l1;
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        l1.push_front(**it); // Desreferencia o ponteiro para copiar o objeto A
    }

    print(l1.begin(), l1.end()) << endl;

    // Libera a memória alocada com new
    for (A* ptr : v1) {
        delete ptr;
    }

    return 0; // LINE I
}
