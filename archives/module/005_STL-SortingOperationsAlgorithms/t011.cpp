#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// função para imprimir qualquer faixa de elementos
template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
}

// Função de comparação para ordenar em ordem decrescente
bool compare(int a, int b)
{
    return b < a;
}

// Impressão
void printMessage(bool found, int element)
{
    if (found)
    {
        cout << "Leitura de sinal [" << element << "] foi encontrada no buffer!\n";
    }
    else
    {
        cout << "Leitura de sinal [" << element << "] não está presente no buffer!\n";
    }
}

int main()
{
    // Simulando um buffer de sinais analógicos captados por um sensor
    int rawReadings[] = {1, 10, 8, 4, 5, 6, 3, 9, 7, 2};

    // Armazenando essas leituras em uma estrutura double-ended queue (deque)
    deque<int> signalBuffer(rawReadings, rawReadings + 10);

    cout << "Leituras brutas do sensor:\n";
    print(signalBuffer.begin(), signalBuffer.end());
    cout << "\n\n";

    // Ordenação em ordem crescente (recomendado para análise de tendência)
    cout << "Ordenando as leituras em ordem crescente (mais fria para mais quente):\n";
    sort(signalBuffer.begin(), signalBuffer.end());
    print(signalBuffer.begin(), signalBuffer.end());
    cout << "\n\n";

    // Buscar um valor específico (ex: verificar se temperatura 5 foi registrada)
    cout << "Procurando por uma leitura de sinal [5] no buffer ordenado:\n";
    printMessage(binary_search(signalBuffer.begin(), signalBuffer.end(), 5), 5);

    cout << "\n--------------------------------------------------\n";

    // Tentando buscar com o buffer ainda ordenado em ordem crescente, mas usando um comparador errado
    cout << "Tentando procurar [5] com critério errado (esperando ordem decrescente):\n";
    printMessage(binary_search(signalBuffer.begin(), signalBuffer.end(), 5, compare), 5);

    cout << "\n--------------------------------------------------\n";

    // agora sim, ordenando corretamente em ordem decrescente
    cout << "Ordenando o buffer em ordem decrescente (para análise reversa ou priorização de sinais altos):\n";
    sort(signalBuffer.begin(), signalBuffer.end(), compare);
    print(signalBuffer.begin(), signalBuffer.end());
    cout << "\n\n";

    // agora buscando novamente com o comparador certo
    cout << " Procurando por uma leitura de sinal [5] com buffer ordenado de forma decrescente:\n";
    printMessage(binary_search(signalBuffer.begin(), signalBuffer.end(), 5, compare), 5);

    return 0;
}
