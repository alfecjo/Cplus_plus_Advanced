#include <iostream>
#include <set>
#include <vector>

using namespace std;

class A {
    int a;

public:
    A(int a) : a(a) {}

    int getA() const {
        return a;
    }

    // conversão para int (usada aqui implicitamente)
    operator int() const {
        return a;
    }

    // na sobrecarga há ordenação reversa (maior valor vem primeiro)
    bool operator<(const A &b) const {
        return b.a < a;  // inverte a ordem
    }
    // para fixar: o < visualmente falando, em set<A> tem ligação 
    // conceitual com o operator<, mesmo que não seja o mesmo símbolo em termos de sintaxe.
    // isso é um conceito, e conceito significa +/- compreensão que alguém tem de uma coisa!
};

int main() {
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    set<A> s(mynumbers, mynumbers + 7);               // valores únicos ordenados (ordem decrescente)
    multiset<A> s1(s.begin(), s.end());               // permite duplicatas
    s1.insert(s.begin(), s.end());                    // duplicando os elementos

    // embora: upper_bound(2) vem antes de lower_bound(5) devido à ordem reversa, más não altera o resultado
    // apenas semântica, pois o intervalo é [2, 5) (2 exclusivo, 5 exclusivo)
    s1.erase(s1.lower_bound(5), s1.upper_bound(2));   // de 2 exclusivo até 5 exclusivo

    for (multiset<A>::iterator i = s1.begin(); i != s1.end(); ++i) {
        cout << i->getA() << ", ";
    }

    cout << endl;
    return 0;
}

// A classe A agora tem um operador de conversão implícita para int,
// permitindo que objetos de A sejam tratados como inteiros em contextos onde isso é necessário.
// a ordenação foi ajustada para garantir que os maiores valores venham primeiro.