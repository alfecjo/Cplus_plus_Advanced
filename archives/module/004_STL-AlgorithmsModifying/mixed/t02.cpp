#include <iostream>
#include <algorithm> // Biblioteca que contém funções como copy_backward e for_each
#include <vector>

using namespace std; // Evita escrever std:: o tempo todo

void printer(int i)
{
    cout << i << ", ";
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);

    // em LINE I
    // Aqui usamos copy_backward, mas com v1.rend().
    // Isso **funciona** em compiladores como o g++, MAS:
    // É conceitualmente incorreto! v1.rend() é um *reverse iterator* (não um iterator normal).
    // A função copy_backward espera iteradores normais (não reversos).
    // Compila porque v1.rend().base() pode ser implicitamente convertido em um iterator direto,
    // mas o resultado pode ser **indefinido** ou inesperado.
    copy_backward(mynumbers, mynumbers + 7, v1.rend()); //  Evitar isso!

    // Versão correta: copia os elementos do array para o final de v1
    copy_backward(mynumbers, mynumbers + 7, v1.end()); // Lógica correta e segura

    // Aplica a função printer para cada elemento de v1
    for_each(v1.begin(), v1.end(), printer); // LINE II

    return 0;
}
