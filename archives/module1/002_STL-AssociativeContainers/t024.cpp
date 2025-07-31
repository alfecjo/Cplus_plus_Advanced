#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    // Arrays com chaves e valores
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 5 };
    string words[] = { "three", "nine", "zero", "two", "one", "four", "five", "fiveandhalf" };

    multimap<int, string> m;

    // Inserção de pares no multimap
    for (int i = 0; i < 8; i++)
        m.insert(pair<int, string>(mynumbers[i], words[i]));

    // verifica quantas entradas com chave 5 existem
    if (m.count(5) == 1) // este teste será FALSO, pois há duas entradas com chave 5
        m.erase(2); // Este trecho NÃO será executado (count(5) != 1)

    // Impressão das chaves
    for (multimap<int, string>::iterator i = m.begin(); i != m.end(); i++)
        cout << i->first << ", ";

    return 0;
}
