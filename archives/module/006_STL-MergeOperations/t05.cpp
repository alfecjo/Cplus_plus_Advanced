#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// Função utilitária para impressão genérica
template <class T>
void print(T start, T end) {
    for (; start != end; ++start) {
        cout << *start << " MHz ";
    }
    cout << endl;
}

// Comparador para ordenação descendente
bool descending(int a, int b) {
    return b < a;
}

int main() {
    // Simulação de canais detectados pelos módulos embarcados A e B
    int channelsA[] = { 902, 915, 920, 868, 433, 2400, 2450 };
    int channelsB[] = { 433, 868, 915, 928, 2420 };

    // Armazenamento com deque
    deque<int> moduleA(channelsA, channelsA + 7);
    deque<int> moduleB(channelsB, channelsB + 5);
    deque<int> result(moduleA.size() + moduleB.size());

    cout << "Frequências detectadas pelos módulos:\n";
    cout << "Módulo A: ";
    print(moduleA.begin(), moduleA.end());

    cout << "Módulo B: ";
    print(moduleB.begin(), moduleB.end());
    cout << endl;

    // Importante: operações de conjunto exigem vetores ordenados
    sort(moduleA.begin(), moduleA.end());
    sort(moduleB.begin(), moduleB.end());

    cout << "Operações de análise espectral:\n";

    // União: todos os canais ocupados pelos dois módulos
    auto endIt = set_union(moduleA.begin(), moduleA.end(),
                           moduleB.begin(), moduleB.end(),
                           result.begin());
    cout << "Frequências totais ocupadas (união): ";
    print(result.begin(), endIt);

    // Interseção: canais comuns entre os dois módulos
    endIt = set_intersection(moduleA.begin(), moduleA.end(),
                             moduleB.begin(), moduleB.end(),
                             result.begin());
    cout << "Frequências comuns (interseção): ";
    print(result.begin(), endIt);

    // Diferença: canais usados pelo módulo A mas não pelo B
    endIt = set_difference(moduleA.begin(), moduleA.end(),
                           moduleB.begin(), moduleB.end(),
                           result.begin());
    cout << "Frequências exclusivas do módulo A: ";
    print(result.begin(), endIt);

    // Diferença simétrica: canais únicos de cada módulo
    endIt = set_symmetric_difference(moduleA.begin(), moduleA.end(),
                                     moduleB.begin(), moduleB.end(),
                                     result.begin());
    cout << "Frequências únicas de cada módulo (diferença simétrica): ";
    print(result.begin(), endIt);

    cout << "\n--- Análise Descendente ---\n";

    sort(moduleA.begin(), moduleA.end(), descending);
    sort(moduleB.begin(), moduleB.end(), descending);

    cout << "Módulo A: ";
    print(moduleA.begin(), moduleA.end());

    cout << "Módulo B: ";
    print(moduleB.begin(), moduleB.end());
    cout << endl;

    // União descendente
    endIt = set_union(moduleA.begin(), moduleA.end(),
                      moduleB.begin(), moduleB.end(),
                      result.begin(), descending);
    cout << "União descendente: ";
    print(result.begin(), endIt);

    // Interseção descendente
    endIt = set_intersection(moduleA.begin(), moduleA.end(),
                             moduleB.begin(), moduleB.end(),
                             result.begin(), descending);
    cout << "Interseção descendente: ";
    print(result.begin(), endIt);

    return 0;
}
