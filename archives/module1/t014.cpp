#include <iostream>
#include <map>     
#include <vector>  
#include <string>  

using namespace std;

int main()
{    
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    
    string words[] = { "three", "nine", "zero", "two", "one", "four", "five" };

    // chave é int e o valor é string
    map<int, string> m;

    // inserção dos pares (chave, valor) no map usando insert()
    for (int i = 0; i < 7; i++)
        m.insert(pair<int, string>(mynumbers[i], words[i])); 

    // aqui o valor associado à chave 0 é sobrescrito para "ten"
    m[0] = "ten";

    // Tentativa de inserir o par (1, "eleven")
    // eessa inserção falha porque a chave 1 já existe, e insert() não sobrescreve
    m.insert(pair<int, string>(1, "eleven")); 

    // impressão dos valores armazenados no map, em ordem crescente das chaves
    for (map<int, string>::iterator i = m.begin(); i != m.end(); i++)
        cout << i->second << ", ";

    return 0;
}
