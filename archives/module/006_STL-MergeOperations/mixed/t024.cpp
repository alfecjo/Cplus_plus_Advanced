#include <deque>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>  // Necessário para std::includes

using namespace std;

// Classe que encapsula um valor inteiro
class Pocket {
    int value;

public:
    Pocket(int value) : value(value) {}

    int getValue() const {
        return value;
    }

    // Operador de comparação necessário para ordenação e set
    bool operator<(const Pocket &_Right) const {
        return value < _Right.value;
    }
};

// Operador de saída para impressão
ostream &operator<<(ostream &stream, const Pocket &pocket) {
    stream << pocket.getValue();
    return stream;
}

int main() {
    // Inicializa dois arrays de objetos Pocket
    Pocket mynumbers1[] = { 3, 9, 0, 2, 1, 4, 5 };
    Pocket mynumbers2[] = { Pocket(3), Pocket(2), Pocket(4), Pocket(1) };

    // Cria deque e set com base em mynumbers1
    deque<Pocket> d1(mynumbers1, mynumbers1 + 7);
    set<Pocket> s1(mynumbers1, mynumbers1 + 7);

    // Ordena o deque (necessário para std::includes)
    sort(d1.begin(), d1.end());

    // Ordena parte dos arrays
    sort(mynumbers1, mynumbers1 + 5); // Só os 5 primeiros
    sort(mynumbers2, mynumbers2 + 4);

    // Verifica se todos os elementos de mynumbers1[0..3] estão em d1
    bool result1 = includes(d1.begin(), d1.end(), mynumbers1, mynumbers1 + 4);

    // Verifica se todos os elementos de mynumbers2 estão no set s1
    bool result2 = includes(s1.begin(), s1.end(), mynumbers2, mynumbers2 + 4);

    cout << result1 << ", " << result2 << endl;

    return 0;
}
