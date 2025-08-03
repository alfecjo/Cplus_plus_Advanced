#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Canais permitidos pela ANATEL (disponíveis no momento)
    int canaisDisponiveis[] = {100, 102, 105, 107, 109};

    // Canais que a estação quer alocar (requeridos)
    int canaisRequeridos[] = {102, 105, 107};

    // Ordenar os dois conjuntos (obrigatório para usar includes)
    sort(canaisDisponiveis, canaisDisponiveis + 5);
    sort(canaisRequeridos, canaisRequeridos + 3);

    // Guardar os canais disponíveis em um set (evita duplicatas, ordenado)
    set<int> canaisPermitidos(canaisDisponiveis, canaisDisponiveis + 5);

    // Guardar os canais requeridos em um deque
    deque<int> canaisDesejados(canaisRequeridos, canaisRequeridos + 3);

    // Usar includes para verificar se todos os canais desejados estão permitidos
    bool todosPermitidosSet = includes(
        canaisPermitidos.begin(), canaisPermitidos.end(),
        canaisRequeridos, canaisRequeridos + 3
    );

    bool todosPermitidosDeque = includes(
        canaisDesejados.begin(), canaisDesejados.end(),
        canaisRequeridos, canaisRequeridos + 3
    );

    // Resultado
    cout << "Verificação usando set: " << (todosPermitidosSet ? "Permitido" : "Negado") << endl;
    cout << "Verificação usando deque: " << (todosPermitidosDeque ? "Permitido" : "Negado") << endl;

    return 0;
}
