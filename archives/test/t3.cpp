#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> v1(tab, tab + 10);
    vector<int> v2(v1.size(), 0);

    try
    {
        // usamos '<' ao invés de '<=' para evitar acessar índice fora dos limites (v1[10] seria inválido)
        for (unsigned i = 0; i < v1.size(); ++i)
        {
            int tmp = v1[i];  // salva o valor atual

            // v1.size() - i - 1 acessa o índice simétrico ao atual (espelhamento)
            // .at() é usado aqui para lançar exceção caso o índice seja inválido
            v1[i] = v1.at(v1.size() - i - 1);

            // essa linha sobrescreve o valor que acabou de ser colocado, anulando a inversão
            v1.at(i) = tmp;

            cout << v1[i] << " ";
        }
    }
    catch (...)
    {
        // captura exceções lançadas por .at() em caso de acesso inválido
        cout << "Exception!" << endl;
    }

    return 0;
}
