#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

// Functor que adiciona um valor fixo a outro
struct AddValue {
    int v;
    AddValue(int val) : v(val) {}

    int operator()(int a) const {
        return a + v;
    }
};

// Functor que calcula a média de dois inteiros
struct Average {
    double operator()(int a, double b) const {
        return (a + b) / 2.0;
    }
};

int main() {
    int t[] = {1,2,3,4,5,6,7,8,9,10};
    size_t n = sizeof(t) / sizeof(t[0]);

    vector<int> v1(t, t + n);
    list<double> l1(v1.size());

    // ---------- Transform: adicionando 10 ----------
    cout << "=== Adicionando 10 a cada elemento ===\n";
    cout << "v1 (original): ";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << "\n";

    transform(v1.begin(), v1.end(), l1.begin(), AddValue(10));

    cout << "l1 (resultado): ";
    for_each(l1.begin(), l1.end(), print<double>);
    cout << "\n\n";

    // Transform: somando 10 no próprio vetor ----------
    cout << "=== Adicionando 10 novamente (modificando v1) ===\n";
    transform(v1.begin(), v1.end(), v1.begin(), AddValue(10));

    cout << "v1 (atualizado): ";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << "\n\n";

    //  Transform: média entre v1 e l1 reverso ----------
    cout << "=== Média entre v1 e l1 (reverso) ===\n";
    list<int> l2(l1.size()); // destino da média

    transform(v1.begin(), v1.end(), l1.rbegin(), l2.begin(), Average());

    cout << "l2 (média): ";
    for_each(l2.begin(), l2.end(), print<double>);
    cout << "\n";

    return 0;
}
