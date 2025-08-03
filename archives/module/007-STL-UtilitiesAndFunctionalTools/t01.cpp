#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Processamento de leituras de sensores usando STL moderno.

   Substituímos `ptr_fun` e `bind2nd` por expressões `lambda`:
   - Mais legíveis, seguras e flexíveis.
   - Compatíveis com código moderno e C++11+.
*/

int main()
{
    vector<int> leituras = {15, 7, 22, 10, 30, 5, 12};

    cout << "Leituras originais: ";
    for (int v : leituras)
        cout << v << " ";
    cout << "\n";

    // 1) Filtrar leituras maiores que 10 usando lambda
    int limite = 10;
    cout << "Leituras > 10: ";
    for (int v : leituras)
    {
        if ([limite](int valor)
            { return valor > limite; }(v))
        {
            cout << v << " ";
        }
    }
    cout << "\n";

    // 2) Subtrair 5 de cada leitura usando transform e lambda
    int offset = 5;
    vector<int> ajustadas(leituras.size());

    transform(
        leituras.begin(),
        leituras.end(),
        ajustadas.begin(),
        [offset](int valor)
        { return valor - offset; });

    cout << "Leituras após subtrair 5: ";
    for (int v : ajustadas)
        cout << v << " ";
    cout << "\n";

    return 0;
}
