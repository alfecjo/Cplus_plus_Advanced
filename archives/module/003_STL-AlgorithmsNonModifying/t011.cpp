#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Verifica se todos os elementos são positivos
    bool allPositive = std::all_of(data.begin(), data.end(), [](int n) { return n > 0; });

    // Conta quantos elementos são maiores que 2
    int countGreater = std::count_if(data.begin(), data.end(), [](int n) { return n > 2; });

    std::cout << "Todos positivos? " << (allPositive ? "Sim" : "Não") << "\n";
    std::cout << "Quantidade maior que 2: " << countGreater << "\n";
    return 0;
}
