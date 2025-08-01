#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

/*
std::find não funciona diretamente com std::map porque o iterador da map é para pair<const int, int>.
Além disso, std::find compara os pares inteiros, mas std::map tem métodos próprios para busca eficiente.
Para buscar uma chave em std::map, o jeito certo é usar o método m.find(key).
*/

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
    map<int, int> m;
    for (int i = 0; i < 7; i++)
    {
        m[i] = mynumbers[i];
    }

    int key_to_find = 4;

    auto it = m.find(key_to_find); // Usar método find do map para buscar chave 4

    if (it != m.end())
        cout << "Found key: " << it->first << ", value: " << it->second << endl;
    else
        cout << "Not found!\n";

    return 0;
}
