#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

/*
Algoritmos de Ordenação: sort vs stable_sort

- sort: Reordena os elementos usando um algoritmo eficiente, porém não estável.
        Isso significa que elementos com valores iguais podem trocar de posição.

- stable_sort: Também ordena os elementos, mas preserva a ordem relativa
               entre elementos com valores iguais. Isso é útil quando você
               precisa manter um segundo critério implícito (como a ordem de chegada).


- vector: Vetor dinâmico, com acesso aleatório e memória contígua.
- deque: Fila de duas pontas, permite inserções/remoções eficientes nas extremidades.
- array: Array de tamanho fixo (std::array), com tamanho conhecido em tempo de compilação.

Este exemplo demonstra como sort e stable_sort se comportam
quando aplicados a containers diferentes contendo objetos com valores repetidos.
*/

struct SensorReading
{
    string id; // Identificador do sensor
    int value; // Valor medido (por exemplo: pressão, temperatura, sinal)

    // para permitir ordenação crescente por valor
    bool operator<(const SensorReading &other) const
    {
        return value < other.value;
    }
};

// para facilitar a impressão de leituras do sensor
ostream &operator<<(ostream &os, const SensorReading &r)
{
    os << "[" << r.id << ": " << r.value << "]";
    return os;
}

// função auxiliar para imprimir qualquer container de SensorReading
template <typename Container>
void printContainer(const string &label, const Container &readings)
{
    cout << label << ": ";
    for (const auto &r : readings)
        cout << r << " ";
    cout << "\n";
}

int main()
{
    // Dados simulando leituras de sensores com valores repetidos
    vector<SensorReading> v = {{"T1", 70}, {"T2", 65}, {"T3", 70}, {"T4", 60}};
    deque<SensorReading> d(v.begin(), v.end());
    array<SensorReading, 4> a = {{{"T1", 70}, {"T2", 65}, {"T3", 70}, {"T4", 60}}};

    // Cópias dos containers originais para aplicar stable_sort mais tarde
    auto v_unsorted = v;
    auto d_unsorted = d;
    auto a_unsorted = a;

    // aplicando sort (ordenação não estável)
    sort(v.begin(), v.end());
    sort(d.begin(), d.end());
    sort(a.begin(), a.end());

    // Imprimindo resultados após sort (pode mudar ordem de elementos com mesmo valor)
    printContainer("vector + sort", v);
    printContainer("deque + sort", d);
    printContainer("array + sort", a);

    // Aplicando stable_sort (preserva a ordem relativa dos elementos com mesmo valor)
    stable_sort(v_unsorted.begin(), v_unsorted.end());
    stable_sort(d_unsorted.begin(), d_unsorted.end());
    stable_sort(a_unsorted.begin(), a_unsorted.end());

    // Imprimindo resultados após stable_sort
    printContainer("\nvector + stable_sort", v_unsorted);
    printContainer("deque + stable_sort", d_unsorted);
    printContainer("array + stable_sort", a_unsorted);

    return 0;
}
