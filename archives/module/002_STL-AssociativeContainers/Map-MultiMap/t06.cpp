#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> mm;

    // nnserindo múltiplos pares com mesma chave
    mm.insert({2, "dois"});
    mm.insert({2, "segundo dois"});
    mm.insert({3, "três"});

    // buscar a chave 2 usando equal_range
    auto range = mm.equal_range(2);

    // percorrendo o intervalo retornado
    cout << "multimap.equal_range(2):\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << "  " << it->first << " => " << it->second << endl;
    }

    // Chave que não existe
    range = mm.equal_range(5);
    if (range.first == range.second)
        cout << "Chave 5 não encontrada no multimap.\n";

    return 0;
}
