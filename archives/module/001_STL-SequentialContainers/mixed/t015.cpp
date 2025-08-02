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
    A(int a) : a(a) {}

    friend ostream& operator<<(ostream& c, const A& o) {
        c << o.a;
        return c;
    }
};

void fill(const int table[], unsigned size, vector<A*>& v) {
    for (unsigned i = 0; i < size; ++i) {
        v.push_back(new A(table[i])); // cria objetos dinamicamente
    }
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<A*> v1;
    fill(tab, 10, v1);

    list<A> l1;
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        l1.push_front(**it);  // adiciona cópia do objeto apontado em l1
    }

    print(l1.begin(), l1.end()) << endl;

    // Agora, liberar a memória dos objetos alocados dinamicamente
    for (auto ptr : v1) {
        delete ptr;  // desaloca cada objeto criado com new
    }
    v1.clear();  // limpa o vetor de ponteiros

    return 0;
}
