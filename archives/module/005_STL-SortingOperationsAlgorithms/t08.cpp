#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// Função para imprimir os elementos de um intervalo
template <class T>
void print(T start, T end) {
    for (; start != end; ++start) {
        cout << *start << " ";
    }
}

// Comparador para ordenação decrescente
bool descending(int a, int b) {
    return b < a;
}

int main() {
    // Amostras simuladas de um sensor de temperatura digitalizado (em graus Celsius)
    int raw_samples[] = {23, 25, 21, 20, 22, 24, 26, 27, 19, 22};
    deque<int> signal(raw_samples, raw_samples + 10);

    cout << "Sinal original (amostras brutas):\n";
    print(signal.begin(), signal.end());
    cout << "\n\n";

    // Ordenação crescente
    cout << "Ordenando o sinal em ordem crescente:\n";
    sort(signal.begin(), signal.end());
    print(signal.begin(), signal.end());
    cout << "\n\n";

    // Identificando a faixa aceitável entre 20 e 25 °C
    cout << "Filtrando amostras dentro da faixa [20, 25] °C:\n";
    auto it_low = lower_bound(signal.begin(), signal.end(), 20);
    auto it_high = upper_bound(signal.begin(), signal.end(), 25);
    print(it_low, it_high);
    cout << "\n\n";

    // encontrando todos os valores iguais a 22 °C
    cout << "Buscando todas as ocorrências de 22 °C:\n";
    auto range = equal_range(signal.begin(), signal.end(), 22);
    print(range.first, range.second);
    cout << "\n\n";

    // ordenação decrescente
    cout << "Ordenando o sinal em ordem decrescente:\n";
    sort(signal.begin(), signal.end(), descending);
    print(signal.begin(), signal.end());
    cout << "\n\n";

    // filtrando novamente usando o comparador reverso (descendente)
    cout << "Filtrando a faixa [25, 22] °C com ordem decrescente:\n";
    it_low = lower_bound(signal.begin(), signal.end(), 25, descending);
    it_high = upper_bound(signal.begin(), signal.end(), 22, descending);
    print(it_low, it_high);
    cout << "\n\n";

    return 0;
}
