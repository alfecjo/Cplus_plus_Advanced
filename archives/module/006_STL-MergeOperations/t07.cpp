#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// para imprimir coleções (útil para debug em sistemas embarcados e sinais capturados)
template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        std::cout << *start << " ";
    }
    std::cout << endl;
}

int main()
{
    // Vetor de inteiros simulando amostras de um sinal digital (ex: nível de tensão)
    int t1[] = {1, 10, 3, 4, 6, 8, 9, 2, 5, 7};

    // Inicializa uma fila de dados com as amostras (poderia ser lido de um ADC em sistemas embarcados)
    deque<int> d1(t1, t1 + 10);

    cout << "Análise de extremos em sinais:\n";

    // demonstra o uso básico de min e max entre dois valores (poderia representar dois valores lidos)
    cout << "min(4, 3): " << min(4, 3) << endl;
    cout << "max(4, 3): " << max(4, 3) << endl
         << endl;

    // Impressão da coleção de amostras
    cout << "Coleção de amostras (sinal discreto):\n";
    cout << "d1: ";
    print(d1.begin(), d1.end());

    // Identificação de picos e vales (útil para processamento de sinais ou análise de comunicação)
    cout << "Valor mínimo (ponto mais baixo): " << *(min_element(d1.begin(), d1.end())) << endl;
    cout << "Valor máximo (ponto mais alto): " << *(max_element(d1.begin(), d1.end())) << endl;

    /*
     * Aplicações:
     * - Em sistemas embarcados: encontrar variações de umidade, temperatura ou corrente.
     * - Em sinais de RF: detectar picos de potência em uma banda.
     * - Em protocolos de telecom: determinar intensidade de sinal em RSSI ao longo do tempo.
     */

    return 0;
}
