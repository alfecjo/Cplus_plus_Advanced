#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class A {
    int a;
public:
    A(int a): a(a) {}

    operator int() const {
        return a;
    }

    // Adicionando comparação para std::set e std::equal funcionar corretamente
    bool operator<(const A& other) const {
        return a < other.a;
    }

    bool operator==(const A& other) const {
        return a == other.a;
    }
};

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2 };

    // std::set remove duplicatas automaticamente e exige operator<
    set<A> s(mynumbers, mynumbers + 12);

    // std::equal verifica se os elementos são iguais entre os dois intervalos
    bool result = equal(s.begin(), s.end(), s.begin());

    cout << boolalpha << result << endl; // deve imprimir "true"

    return 0;
}
