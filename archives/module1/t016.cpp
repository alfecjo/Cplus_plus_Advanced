#include <iostream>
#include <map>
#include <string>

using namespace std;

class A {
    int a;

public:    
    A(int a) : a(a) {}

    int getA() const {
        return a;
    }

    // operador de comparação necessário para usar como chave em map
    bool operator < (const A& b) const {
        return a < b.a;
    }
};

int main() {
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
    string words[]   = {"three", "nine", "zero", "two", "one", "four", "five"};

    map<A, string> m;

    // Inserindo pares (A, string) no map
    for (int i = 0; i < 7; i++) {
        m.insert(pair<A, string>(A(mynumbers[i]), words[i]));
    }

    // Remove as chaves entre 3 e 4 (inclusive 3, exclusivo 4)
    m.erase(m.lower_bound(A(3)), m.upper_bound(A(4)));

    // Exibe os valores restantes do map
    for (map<A, string>::iterator i = m.begin(); i != m.end(); i++) {
        cout << i->second << ", ";
    }

    return 0;
}
