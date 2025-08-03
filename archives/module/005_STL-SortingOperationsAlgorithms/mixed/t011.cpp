#include <deque>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class BitError {
    int position;
public:
    BitError(int pos) : position(pos) {}
    int getPosition() const { return position; }

    bool operator<(const BitError &rhs) const {
        return position < rhs.position;
    }
};

ostream& operator<<(ostream &out, const BitError &err) {
    out << "Erro no bit: " << err.getPosition();
    return out;
}

void showError(BitError e) {
    cout << e << endl;
}

int main() {
    srand(time(0));

    const int totalBits = 100;
    deque<BitError> errors;

    // simula erro em 10 posições aleatórias
    for (int i = 0; i < 10; ++i) {
        int errPos = rand() % totalBits;
        errors.push_back(BitError(errPos));
    }

    sort(errors.begin(), errors.end());  // ordena erros por posição

    // Verifica se há erro no bit 42
    pair<deque<BitError>::iterator, deque<BitError>::iterator> result = equal_range(errors.begin(), errors.end(), BitError(42));

    if (result.first != result.second) {
        cout << "Erro encontrado no bit 42:\n";
        for_each(result.first, result.second, showError);
    } else {
        cout << "Nenhum erro no bit 42\n";
    }

    return 0;
}
