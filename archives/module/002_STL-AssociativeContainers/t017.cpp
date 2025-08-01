#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 5 };
    string words[] = { "three", "nine", "zero", "two", "one", "four", "five", "FIVE" };

    map<int, string> m;

    for (int i = 0; i < 8; i++) {
        // se a chave já existir, o valor não será inserido (std::map ignora)
        // e se for o caso dequerer substituir o valor se a chave já existir, use m[mynumbers[i]] = words[i];        
        m.insert(pair<int, string>(mynumbers[i], words[i]));
    }

    // verifica se a chave 5 está presente
    if (m.count(5) == 1) {
        m.erase(2);  // remove a chave 2 se a chave 5 estiver presente
    }

    // imprime todas as chaves
    for (map<int, string>::iterator i = m.begin(); i != m.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }

    return 0;
}
