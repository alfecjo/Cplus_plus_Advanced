#include <iostream>
#include <vector>
#include <algorithm> // para remove e remove_if

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

// Functor para remover números ímpares
struct IsOdd {
    bool operator()(int x) const {
        return x % 2 != 0;
    }
};

int main() {
    vector<int> signal = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "🔹 Sinal original:\n";
    for_each(signal.begin(), signal.end(), print<int>);
    cout << "\n\n";

    // Exemplo com remove: remove todos os valores iguais a 5
    cout << "Removendo valor 5 (com std::remove):\n";
    auto new_end = remove(signal.begin(), signal.end(), 5);

    // Apaga fisicamente do vetor usando erase
    signal.erase(new_end, signal.end());

    cout << "Sinal após remoção do valor 5:\n";
    for_each(signal.begin(), signal.end(), print<int>);
    cout << "\n\n";

    // Exemplo com remove_if: remove todos os valores ímpares
    cout << "Removendo valores ímpares (com std::remove_if):\n";
    new_end = remove_if(signal.begin(), signal.end(), IsOdd());

    signal.erase(new_end, signal.end());

    cout << "Sinal após remoção dos ímpares:\n";
    for_each(signal.begin(), signal.end(), print<int>);
    cout << "\n\n";

    return 0;
}
