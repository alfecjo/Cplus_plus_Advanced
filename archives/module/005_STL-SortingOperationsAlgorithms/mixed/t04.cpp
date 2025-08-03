#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

int main()
{
    // amostras digitalizadas de um sinal (níveis de amplitude quantizada)
    int signal_samples[] = {3, 9, 0, 3, 2, 1, 4, 5};

    // Coloca as amostras em um deque
    deque<int> signal(signal_samples, signal_samples + 7);

    // Ordena as amostras para facilitar a busca
    sort(signal.begin(), signal.end());

    // insere um novo nível de referência (amplitude 3)
    signal.push_back(3); // Esse valor pode representar, por exemplo, um patamar esperado no sinal

    // Busca o intervalo de valores iguais a 3
    pair<deque<int>::iterator, deque<int>::iterator> result =
        equal_range(signal.begin(), signal.end(), 3);

    cout << "Níveis de sinal iguais ao nível de referência (3): ";
    for_each(result.first, result.second, printer);
    cout << endl;

    return 0;
}
