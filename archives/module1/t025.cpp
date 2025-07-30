#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    string words[] = { "three", "nine", "zero", "two", "one", "four", "five" };

    multimap<int, string> m;

    // deve usar insert para inserir pares em multimap
    for (int i = 0; i < 3; i++)
        m.insert(pair<int, string>(mynumbers[i], words[i]));  

    // Itera e imprime as chaves inseridas
    for (multimap<int, string>::iterator i = m.begin(); i != m.end(); ++i)
        cout << i->first << " ";  

    return 0;
}
