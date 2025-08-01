#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class A {
    int a;
public:
    A(int a) : a(a) {}

    int getA() const { return a; }

    void setA(int a) { this->a = a; }

    // Correção aqui: igualdade verdadeira quando os valores são iguais
    bool operator ==(const A &b) const {
        return this->a == b.a;
    }
};

// Functor que dobra o valor do objeto A
struct doubler {
    void operator()(A &a) {
        a.setA(a.getA() * 2);
    }
};

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    vector<A> v1(mynumbers, mynumbers + 7);

    for_each(v1.begin(), v1.end(), doubler()); // dobra os valores

    vector<A>::iterator it = find(v1.begin(), v1.end(), A(7));

    if (it != v1.end()) {
        cout << "Encontrado: " << it->getA() << endl;
    } else {
        cout << "Valor 7 não encontrado." << endl;
    }

    return 0;
}
