#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // permite apenas uma entrada por chave
    map<int, string> myMap = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"}
    };

    // permite múltiplas entradas com a mesma chave
    multimap<int, string> myMultiMap = {
        {2, "Two"},
        {2, "Deux"},
        {3, "Three"},
        {3, "Tres"},
        {3, "Trois"},
        {3, "Drei"},
        {4, "Four"}
    };

    // Escolhemos uma chave para buscar
    int key = 3;

    cout << "Using equal_range on map:\n";
    auto rangeMap = myMap.equal_range(key);
    if (rangeMap.first != rangeMap.second) {
        // Existe exatamente um par com essa chave...
        cout << "Key " << key << ": " << rangeMap.first->second << endl;
    } else {
        // Chave não encontrada
        cout << "Key " << key << " not found in map.\n";
    }

    cout << "\nUsing equal_range on multimap:\n";
    auto rangeMultiMap = myMultiMap.equal_range(key);
    if (rangeMultiMap.first != rangeMultiMap.second) {
        cout << "Entries with key " << key << ":\n";
        for (auto it = rangeMultiMap.first; it != rangeMultiMap.second; ++it) {
            cout << " - " << it->second << endl;
        }
    } else {
        cout << "Key " << key << " not found in multimap.\n";
    }

    return 0;
}
