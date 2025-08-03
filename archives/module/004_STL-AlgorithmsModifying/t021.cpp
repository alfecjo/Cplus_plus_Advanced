#include <iostream>
#include <vector>
#include <algorithm>

// Imprime os elementos da coleção
template <typename T>
void print(const T& collection) {
    for (const auto& val : collection)
        std::cout << val << " ";
    std::cout << '\n';
}

// Functor para verificar se o número é negativo
struct IsNegative {
    bool operator()(int n) const {
        return n < 0;
    }
};

int main() {
    std::vector<int> values = { 3, -1, 4, -5, 2, -3, 0, 6, -8, 7 };

    std::cout << "Coleção original:\n";
    print(values);
    std::cout << '\n';

    // -------- std::partition (não preserva ordem) --------
    std::cout << "[1] Particionamento comum (não preserva a ordem):\n";

    auto part_it = std::partition(values.begin(), values.end(), IsNegative{});

    std::cout << "Após partition (negativos primeiro):\n";
    print(values);

    std::cout << "Parte negativa: ";
    print(std::vector<int>(values.begin(), part_it));

    std::cout << "Parte não-negativa: ";
    print(std::vector<int>(part_it, values.end()));

    std::cout << '\n';

    // -------- std::stable_partition (preserva ordem) --------
    std::cout << "[2] Particionamento estável (preserva a ordem):\n";

    // Restaurando os dados originais
    values = { 3, -1, 4, -5, 2, -3, 0, 6, -8, 7 };

    auto stable_it = std::stable_partition(values.begin(), values.end(), IsNegative{});

    std::cout << "Após stable_partition:\n";
    print(values);

    std::cout << "Parte negativa: ";
    print(std::vector<int>(values.begin(), stable_it));

    std::cout << "Parte não-negativa: ";
    print(std::vector<int>(stable_it, values.end()));

    return 0;
}
