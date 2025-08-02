#include <iostream>
#include <algorithm> // Para uso de funções como fill, fill_n, for_each
#include <vector>

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

int main()
{
    vector<int> v1(7, 1); // v1 = [1, 1, 1, 1, 1, 1, 1]

    // Preenche com o valor 8 os elementos a partir da 4ª posição (índice 3) até a penúltima (índice 5)
    fill(v1.begin() + 3, v1.end() - 1, 8); // v1 = [1, 1, 1, 8, 8, 1, 1]

    // Preenche 2 elementos a partir da 5ª posição (índice 4) com o valor 7
    fill_n(v1.begin() + 4, 2, 7); // v1 = [1, 1, 1, 8, 7, 7, 1]

    // Imprime os elementos do vetor usando a função printer
    for_each(v1.begin(), v1.end(), printer); // Saída: 1, 1, 1, 8, 7, 7, 1,

    return 0;
}
