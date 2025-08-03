#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

bool maiorQue(int valor, int limite)
{
    return valor > limite;
}

int subtrairOffset(int valor, int offset)
{
    return valor - offset;
}

int main()
{
    std::vector<int> leituras = {8, 12, 15, 7, 20, 5};

    // Filtro: maior que 10
    auto filtro = std::bind(maiorQue, std::placeholders::_1, 10);
    int count = std::count_if(leituras.begin(), leituras.end(), filtro);
    std::cout << "Valores maiores que 10: " << count << std::endl;

    // Subtrai offset 5 de cada leitura
    auto subtrai = std::bind(subtrairOffset, std::placeholders::_1, 5);
    std::transform(leituras.begin(), leituras.end(), leituras.begin(), subtrai);

    std::cout << "Leituras após subtrair offset 5: ";
    for (int v : leituras)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
