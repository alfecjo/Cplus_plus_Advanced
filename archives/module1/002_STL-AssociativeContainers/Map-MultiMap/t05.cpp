#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    // Inserindo pares únicos (chave, valor)
    m[1] = "um";
    m[2] = "dois";
    m[3] = "três";

    // buscar a chave 2 usando equal_range
    auto range = m.equal_range(2);

    cout << "map.equal_range(2):\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << "  " << it->first << " => " << it->second << endl;
    }

    // no teste de consistência tentando chave inexistente
    range = m.equal_range(5);
    if (range.first == range.second)
        cout << "Chave 5 não encontrada no map.\n";

    return 0;
}
