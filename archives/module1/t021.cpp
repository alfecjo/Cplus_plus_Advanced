#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int mynumbers[] = { 3, 9, 0, 2, 1 };
    string words[] = { "three", "nine", "zero", "two", "one" };

    //  um multimap (permite chaves duplicadas)
    multimap<int, string> m;

    // os 4 primeiros pares duas vezes cada (total 8 inserções)
    for (int i = 0; i < 4; i++)
    {
        // inserindo a primeira vez
        m.insert(pair<int, string>(mynumbers[i], words[i]));
        // inserindo a segunda vez
        m.insert(pair<int, string>(mynumbers[i], words[i]));
    }

    // m[0] = "ten"; isso NÃO é permitido em multimap. O operador [] só está disponível para `map`, não `multimap`.
    // para substituir ou inserir valores em um `multimap`, é preciso usar `insert()` ou `erase()` + `insert()`.

    // Se quisermos substituir os valores da chave 0, devemos apagar todos os elementos com chave 0 e inserir "ten":
    m.erase(0); // remove todas as ocorrências com chave 0
    m.insert(pair<int, string>(0, "ten"));

    // e agora iteramos e imprimimos os valores (por extenso)
    for (multimap<int, string>::iterator i = m.begin(); i != m.end(); i++)
        cout << i->second << ", ";

    return 0;
}
