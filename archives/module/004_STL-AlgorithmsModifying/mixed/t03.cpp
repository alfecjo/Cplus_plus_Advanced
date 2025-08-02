#include <iostream>
#include <algorithm> // Necessário para usar copy_backward e for_each
#include <vector>

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);

    // copy_backward copia os elementos do array [início, fim)
    // para dentro do vector, começando de trás para frente (do fim para o início).
    //
    // Neste caso, estamos copiando os elementos do array 'mynumbers'
    // para dentro do mesmo vector 'v1', sobrescrevendo os valores de v1.
    //
    // A cópia é feita de trás para frente, começando no final de v1 (v1.end()).
    copy_backward(mynumbers, mynumbers + 7, v1.end());

    // for_each aplica a função printer em cada elemento de v1.
    // Isso imprime todos os elementos do vector no terminal.
    for_each(v1.begin(), v1.end(), printer);

    return 0;
}
